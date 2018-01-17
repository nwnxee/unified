#!/usr/bin/env ruby

$pkg = "org.nwnx.nwnx2.jvm.constants"
$path = "java/src/org/nwnx/nwnx2/jvm/constants/"
$group_size = 3


$const = ARGV.shift or fail "Need consts.nss as argument"
$const = IO.readlines($const)

$const = $const.map {|x| x.strip}.map {|x|
  if x =~ /^(int|string|float)\s*([A-Z0-9_]+)\s*=\s*(.+);/
    a = case $3
      when "TRUE", "FALSE" ; "boolean"
      else case $1
        when "string" ; "String"
        else $1
      end
    end
    b = $2
    c = $3

   [a, b, case c
      when "TRUE" ; true
      when "FALSE" ; false
      else c
    end]
  else
    nil
  end
}.compact.sort {|a,b| a[1] <=> b[1]}

def dump_file filename, classname, prefix, consts
  File.open(filename, "w") {|f|
    f.puts "package #{$pkg};"
    f.puts ""
    if prefix != ""
      f.puts <<EOD
/**
 * This class contains all unique constants beginning with "#{prefix}".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
EOD
    end
    f.puts "public final class #{classname} {"
    f.puts "  private #{classname}() {}"
    f.puts ""

    consts.each {|(a,b,c)|
      f.puts "  public final static #{a} #{b} = #{c}#{"f" if a == "float" && c !~ /f$/};"
    }
    f.puts ""

    f.puts "  public static String nameOf(int value) {"
      consts.each {|(a,b,c)|
        f.puts "    if (value == #{c}) return #{(classname + "." + b).inspect};" if a == "int"
      }
    f.puts "    return \"%s.(not found: \" + value + \")\";" % classname
    f.puts "  }"
    f.puts ""

    f.puts "  public static String nameOf(float value) {"
      consts.each {|(a,b,c)|
        f.puts "    if (value == #{c}) return #{(classname + "." + b).inspect};" if a == "float"
      }
    f.puts "    return \"%s.(not found: \" + value + \")\";" % classname
    f.puts "  }"
    f.puts ""

    f.puts "  public static String nameOf(String value) {"
      consts.each {|(a,b,c)|
        f.puts "    if (value == #{c.inspect}) return #{(classname + "." + b).inspect};" if a == "string"
      }
    f.puts "    return \"%s.(not found: \" + value + \")\";" % classname
    f.puts "  }"
    f.puts "}"
  }
end

dump_file $path + "All.java", "All", "", $const

$group = {}

$const.each {|(a,b,c)|
  tok = b.split("_")
  for i in 0..tok.size do
    pa = tok[0,i].join("_")
    next if pa == ""
    $group[pa] ||= []
    bv = b.gsub(pa + "_", "")
    bv = case bv
      when /^[1-9]/ ; "_" + bv
      else ; bv
    end
    $group[pa] << [a,bv,c]
  end
}

$group.each {|k,v|
  v.reject! {|(a,b,c)| v.select {|(aa,bb,cc)| bb == b}.size > 1}
  v = v.reject {|(a,b,c)| b !~ /^[A-Z]/ }
  $group.delete(k) if v.size < $group_size
}

$group.each {|k,v|
  b = k.split("_").map {|x| x.capitalize }.join("")
  dump_file $path + b + ".java", b, k, v.sort {|a,b| a[1] <=> b[1]}
}
