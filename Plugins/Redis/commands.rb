require 'json'
require 'pp'
require 'docopt'

$args = Docopt::docopt(<<HEREDOC)
heredoc
Usage:
  commands.rb [options]

Options:
  --prefix=<prefix>         Prefix all commands with a string [default: NWNX_Redis_]
  --postfix=<postfix>       Postfix commands [default: ].
  -c --cast=<cast>          Cast types to nwscript natives [default: true]
HEREDOC
$args.freeze

# Set to false to not autocast arguments to redis commands
# Setting this to true neccessarily disables default values for arguments
CastArguments = $args["--cast"] == "true"
CastReturnValues = $args["--cast"] == "true"
DefaultArgumentValues = true

RetDefCasts = {
  "float" => "return StringToFloat(%s);",
  "int" => "return StringToInt(%s);",
  "string" => "return %s;"
}
ArgCasts = {
  "float" => "FloatToString(%s, 0)",
  "int" => "IntToString(%s)"
}
TypeDefaultValues = {
  "float" => "0.0",
  "int" => 0,
  "string" => "\"\"",
}

template = "%s %s("

json = JSON.parse(IO.read("redis-doc/commands.json"))

class String
  def wrap character = "\n * ", length = 74
    #scan(/.{#{length}}|.+/).map { |x| x.strip }.join(character)
    scan(/\S.{0,#{length}}\S(?=\s|$)|\S+/).join(character)
  end
end

def type_to_nwn type
  case type
    when "key", "string", "posix time", "pattern", "enum", "type", "value"
      "string"
    when "integer"
      CastArguments ? "int" : "string"
    when "double"
      CastArguments ? "float" : "string"
    else
      fail "Unknown type: #{type.inspect}"
    end
end

def name_to_nwn name
  name.gsub(/[^a-zA-Z0-9_]/, "_").
    gsub("string", "str").
    gsub("int", "integer").
    gsub("float", "flt").
    gsub("void", "vd")
end

failed = []

json = json.map do |cmd, c|
  args = []

  cmd = cmd.gsub(" ", "-")

  markdown = IO.read("redis-doc/commands/%s.md" % cmd.downcase) #rescue ""

    cmd = cmd.gsub("-", "_")

  annotated_retdef = nil
  retdef = if markdown =~ /@(.+)-reply[^a-z]/
    annotated_retdef = $1
    case $1
      when "simple-string", "bulk-string" then "string"
      when "integer" then "int"
      when "nil" then "void"
      when "array" then "int" # size of array
      else
        fail $1
    end
  else
    # fail cmd
    "string"
  end
    retdef = "string" unless CastReturnValues

  # Don't export pubsub commands because they will just break the command
  # connection with no way to receive those events.
  next if %w{
    SUBSCRIBE PSUBSCRIBE UNSUBSCRIBE PUNSUBSCRIBE
  }.index(cmd)

  # expand all grouped optional arguments into invidual ones
  if c['arguments']
    taken = []
    c['arguments'] = c['arguments'].map do |h|
      x = []

      if h['name'].is_a?(Array)
        h['name'].each_with_index do |hh, idx|
          prefix = h['command'] ? h['command'].downcase + '_' : ''
          fail if prefix == 'addr'
          x << {
            "name" => prefix + h['name'][idx],
            "type" => h['type'][idx],
            "optional" => h['optional']
          }
        end
      else
        # if it's a sub-command/key thing, prefix it to avoid namespace clobbering
        if h['command'] and h['name']
          h['name'] = h['command'].downcase + '_' + h['name']
        elsif h['name']
          cnt = taken.count(h['name'])
          postfix = cnt > 0 ? '_' + cnt.to_s : ''
          taken << h['name']
          h['name'] = h['name'] + postfix
        end
        # h['name'] = h['name'] + "idx"
        x << h
      end

      x
    end.flatten(1)
  end

  if c['arguments']
    args = c['arguments'].map do |h|
          if h['name'] && h['type']
              [ type_to_nwn(h["type"]), name_to_nwn(h["name"]), h["enum"], h["optional"], h["type"] ]
          elsif h['command']
              # subcommands
              failed << "Skipping sub-command: #{cmd}/#{h} - not supported yet."
              nil
          else
              failed << "Skipping #{cmd}, cannot parse argument: #{h} - not supported yet."
              nil
          end
    end.compact
    end

  funame = "%s%s%s" % [$args["--prefix"], cmd.gsub(" ", "_"), $args["--postfix"]]

  retdefcast = RetDefCasts[CastReturnValues ? retdef : "string"] || "%s;"

  body = ""
  body += "  NWNXPushString(\"NWNX_Redis\", \"Deferred\", \"%s\");\n" % cmd
  args.each do |aa|
    body += "  "
    # Optional values are kind of broken, because integer values aren't nullable,
    # so all values are still strings.
    body += "if (%s != \"\") " % [aa[1]] if aa[3] && !CastArguments

    if aa[3] && DefaultArgumentValues
      body += "if (%s != %s) " % [aa[1], TypeDefaultValues[aa[0]]]
    end

    body += "NWNXPushString(\"NWNX_Redis\", \"Deferred\", %s);\n" % [(ArgCasts[aa[0]] || "%s") % aa[1]]
  end
    body += "  NWNXCall(\"NWNX_Redis\", \"Deferred\");\n"

  body += "  return " + "NWNXPopInt(\"NWNX_Redis\", \"Deferred\");"
  # body += "  " + retdefcast % "NWNXPopString(\"NWNX_Redis\", \"Deferred\")" #"  return %s(redisCommand());" % retdefcast

  optional = false
  argdef = args.map{|a|
    optional = true if a[3]
    v = "\t"
    v << "// Redis type: %s\n\t" % a[4] if (a[4] != a[1] && a[4] != a[0])
    v << "%s %s" % [a[0], a[1]]
    # Optional values are kind of broken, because integer values aren't nullable.
    v << " = %s" % [TypeDefaultValues[a[0]] || "\"\"" ] if optional && DefaultArgumentValues
    v
  }.join(",\n")

  argdef = argdef == "" ? argdef : "\n#{argdef}\n"

  impl = "%s %s(%s) {\n" % ["int", funame, argdef]
  impl += "%s\n" % body
  impl += "}\n"

  head  = "/**\n"
  head += " * %s\n" % cmd
  head += " *\n * %s\n" % c['summary'] if c['summary'].wrap
  head += " *\n * Time complexity: %s\n" % c['complexity'].wrap if c['complexity']

  args.each do |a|
    next unless a[2]
    head += "\n * - Valid values for %s: %s\n" % [a[1], a[2].map{|v| v.inspect}.join(", ")]
  end

  head += " * Annotated return value: %s\n" % annotated_retdef

  head += " */\n"
  head += "%s %s(%s);" % ["int", funame, argdef]

  {
    :head => head,
    :impl => impl,
  }
end.compact


if $args["--prefix"] == "NWNX_Redis_"
    puts "/// @ingroup redis"
    puts "/// @brief Autogenerated redis commands for NWNX usage. Autogenerated on: #{Time.now}\n"
    puts "/// @{"
    puts "/// @file nwnx_redis.nss"
    puts "/// @name Redis Commands"
end
puts "#include \"nwnx_redis_lib\""
puts "\n\n"

failed.each do |e|
  puts "// " + e
end

json.each do |ha|
  puts ha[:head]
  puts ""
end

puts "\n\n// Implementation below\n"

json.each do |ha|
  puts ha[:impl]
  puts ""
end
if $args["--prefix"] == "NWNX_Redis_"
    puts "/// @}"
    puts "/// @}"
end
