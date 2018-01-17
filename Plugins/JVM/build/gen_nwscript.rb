#!/usr/bin/env ruby

require 'yaml'
# require './build/fids'

$core_package = "org.nwnx.nwnx2.jvm"
$core_classprefix = "org_nwnx_nwnx2_jvm_"
$core_classpath = "org/nwnx/nwnx2/jvm/"

require_relative 'enums'

TypeMapIce = {
  'int' => 'jint',
  'float' => 'jfloat',
  'bool' => 'jboolean',
  'void' => 'void',
  'action' => nil,
  'talent' => nil,
  'event' => nil,

  'string' => 'jstring',
  '_ret string' => 'jstring',

  '_ret object' => 'jobject',
  'object' => 'jobject',
  '_ret effect' => 'jobject',
  'effect' => 'jobject',
  '_ret itemproperty' => 'jobject',
  'itemproperty' => 'jobject',
  '_ret location' => 'jobject',
  'location' => 'jobject',
  '_ret vector' => 'jobject',
  'vector' => 'jobject'
}

TypeMap = {
  'int' => 'int',
  'string' => 'String',
  'float' => 'float',
  'void' => 'void',
  'bool' => 'boolean',

  'action' => nil,
  'talent' => nil,
  'event' => nil,

  'object' => 'NWObject',
  'effect' => 'NWEffect',
  'itemproperty' => 'NWItemProperty',
  'location' => 'NWLocation',
  'vector' => 'NWVector',
}
TypeRXStr = ("(" + TypeMap.keys.join("|") + ")").freeze

ArgumentRename = {
  'SetPlotFlag nPlotFlag' => 'bPlotFlag',
  'SetItemCursedFlag nCursed' => 'bCursed',
  'SetStolenFlag nStolenFlag' => 'bStolenFlag',
  'SetUseableFlag nUseableFlag' => 'bUseableFlag',
  'SetTrapRecoverable nRecoverable' => 'bRecoverable',
  'SetTrapOneShot nOneShot' => 'bOneShot',
  'SetTrapDisarmable nDisarmable' => 'bDisarmable',
  'SetTrapDetectable nDetectable' => 'bDetectable',
  'SetTrapActive nActive' => 'bActive',
  'SetPanelButtonFlash nEnableFlash' => 'bEnableFlash',
  'SetMapPinEnabled nEnabled' => 'bEnabled',
  'SetLockLockable nLockable' => 'bLockable',
  'SetLockKeyRequired nKeyRequired' => 'bKeyRequired',
  'SetEncounterActive nNewValue' => 'bNewValue',

  'JumpToObject nWalkStraightLineToPoint' => 'bWalkStraightLineToPoint',
  'GetSkillRank nBaseSkillRank' => 'bBaseSkillRank',
  'GetPCPublicCDKey nSinglePlayerCDKey' => 'bSinglePlayerCDKey',
  'GetNearestTrapToObject nTrapDetected' => 'bTrapDetected',

  'EffectVisualEffect nMissEffect' => 'bMissEffect',
  'EffectSummonCreature nUseAppearAnimation' => 'bUseAppearAnimation',
  'EffectPolymorph nLocked' => 'bLocked',
  'EffectDeath nSpectacularDeath' => 'bSpectacularDeath',
  'EffectDeath nDisplayFeedback' => 'bDisplayFeedback',

  'ClearAllActions nClearCombatState' => 'bClearCombatState',

  'GetFirstObjectInShape nShape' => 'nShapeType',
  'GetNextObjectInShape nShape' => 'nShapeType',
  'nRace' => 'nIPRacialType',
  'CreateTrapAtLocation nFaction' => 'nStandardFaction',
  'CreateTrapOnObject nFaction' => 'nStandardFaction',
  'SetCutsceneMode nInCutscene' => 'bInCutscene',
  'SetCutsceneMode nLeftClickingEnabled' => 'bLeftClickingEnabled',

  'GetActionMode nMode' => 'nActionMode',

  'EffectAbilityIncrease nAbilityToIncrease' => 'nAbility',
  'GetAbilityScore nAbilityType' => 'nAbility',
  'GetAbilityScore nBaseAbilityScore' => 'bBaseAbilityScore',
  'EffectConcealment nMissType' => 'nMissChanceType',
  'EffectSwarm nLooping' => 'bLooping',
#  Matches the regular consts
#  'ItemPropertyAbilityBonus nAbility' => 'nIPAbility',
#  'ItemPropertyDecreaseAbility nAbility' => 'nIPAbility',

  'ItemPropertyACBonusVsAlign nAlignGroup' => 'nIPAlignGroup',
  'ItemPropertyACBonusVsSAlign nAlign' => 'nAlignment',
  'ItemPropertyAttackBonusVsAlign nAlignGroup' => 'nIPAlignGroup',
  'ItemPropertyDamageBonusVsAlign nAlignGroup' => 'nIPAlignGroup',
  'ItemPropertyDamageBonusVsSAlign nAlign' => 'nAlignment',
  'ItemPropertyEnhancementBonusVsAlign nAlignGroup' => 'nIPAlignGroup',
  'ItemPropertyEnhancementBonusVsSAlign nAlign' => 'nAlignment',
  'ItemPropertyLimitUseByAlign nAlignGroup' => 'nIPAlignGroup',

  'ItemPropertyACBonusVsDmgType nDamageType' => 'nIPDamageType',
  'ItemPropertyDamageBonus nDamageType' => 'nIPDamageType',
  'ItemPropertyDamageBonusVsAlign nDamageType' => 'nIPDamageType',
  'ItemPropertyDamageBonusVsRace nDamageType' => 'nIPDamageType',
  'ItemPropertyDamageBonusVsSAlign nDamageType' => 'nIPDamageType',
  'ItemPropertyDamageImmunity nDamageType' => 'nIPDamageType',
  'ItemPropertyDamageResistance nDamageType' => 'nIPDamageType',
  'ItemPropertyDamageVulnerability nDamageType' => 'nIPDamageType',
  'ItemPropertyExtraMeleeDamageType nDamageType' => 'nIPDamageType',
  'ItemPropertyExtraRangeDamageType nDamageType' => 'nIPDamageType',

  'ItemPropertyTrap nTrapType' => 'nIPTrapType',

  'EffectACIncrease nModifyType' => 'nACModifyType',
  'EffectACDecrease nModifyType' => 'nACModifyType',

  'SetActionMode nMode' => 'nActionMode',
  'SetActionMode nStatus' => 'bStatus',

  'EffectAttackIncrease nModifierType' => 'nAttackBonus',
  'EffectAttackDecrease nModifierType' => 'nAttackBonus',

  'ItemPropertyImmunityMisc nImmunityType' => 'nIPMiscImmunityType',
  'ItemPropertySpellImmunitySchool nSchool' => 'nIPSpellSchool',

  'EffectBeam nBodyPart' => 'nCreaturePart',
  'GetCreatureBodyPart nPart' => 'nCreaturePart',
  'SetCreatureBodyPart nPart' => 'nCreaturePart',

  'SetHiddenWhenEquipped nValue' => 'bValue',

}

ArgumentTypeDef = {
  'SetTileMainLightColor nMainLight1Color' => 'TileMainLightColor',
  'SetTileMainLightColor nMainLight2Color' => 'TileMainLightColor',
  'SetTileSourceLightColor nSourceLight1Color' => 'TileSourceLightColor',
  'SetTileSourceLightColor nSourceLight2Color' => 'TileSourceLightColor',
}

ArgumentDropWith = {
  'getAC nForFutureUse' => '1'
}

ReturnRename = {
  'getItemHasItemProperty' => 'bool',
  'getCommandable' => 'bool',
  'getIdentified' => 'bool',
  'getImmortal' => 'bool',
  'getLastPerceptionHeard' => 'bool',
  'getLastPerceptionInaudible' => 'bool',
  'getLastPerceptionSeen' => 'bool',
  'getLastPerceptionVanished' => 'bool',
  'getLastSpellHarmful' => 'bool',
  'getLockKeyRequired' => 'bool',
  'getLockLockable' => 'bool',
  'getLocked' => 'bool',
  'getLootable' => 'bool',
  'getObjectHeard' => 'bool',
  'getObjectSeen' => 'bool',

  'getTrapActive' => 'bool',
  'getTrapFlagged' => 'bool',
  'getTrapDetectable' => 'bool',
  'getTrapDetectedBy' => 'bool',
  'getTrapDisarmable' => 'bool',
  'getTrapOneShot' => 'bool',
  'getTrapRecoverable' => 'bool',
  'getWeaponRanged' => 'bool',

  'getFactionEqual' => 'bool',
  'getCutsceneMode' => 'bool',
  'getActionMode' => 'bool',

  'getHiddenWhenEquipped' => 'bool'
}
DisabledReturnRenames = {

  'getObjectType' => 'ObjectType',
  'getEffectDurationType' => 'DurationType',
  'getItemPropertyDurationType' => 'DurationType',
  'getRacialType' => 'RacialType',

  'getTileMainLight1Color' => 'TileMainLightColor',
  'getTileMainLight2Color' => 'TileMainLightColor',
  'getTileSourceLight1Color' => 'TileSourceLightColor',
  'getTileSourceLight2Color' => 'TileSourceLightColor',

  'getWeather' => 'Weather',
  'getMetaMagicFeat' => 'MetaMagic',
  'getGender' => 'Gender',

  'getEffectSubType' => 'EffectSubType',
  'getEffectType' => 'EffectType',
  'reflexSave' => 'SavingThrowResult',
  'willSave' => 'SavingThrowResult',
  'fortitudeSave' => 'SavingThrowResult',

  'touchAttackMelee' => 'AttackResult',
  'touchAttackRanged' => 'AttackResult',

  'getPhenoType' => 'PhenoType',

  'getLastAttackMode' => 'CombatMode',
  'getLastAttackType' => 'SpecialAttack',
  'getLastAssociateCommand' => 'AssociateCommand',

  'getCreatureSize' => 'CreatureSize',
  'getAssociateType' => 'AssociateType',

  'getCurrentAction' => 'Action',

  'getAlignmentLawChaos' => 'Alignment',
  'getAlignmentGoodEvil' => 'Alignment',
  'getAILevel' => 'AILevel',
}

ArgumentTypeDef.clear
# ReturnRename.clear
Enums.clear

DontDoAtAll = %w{
  abs acos asin atan cos fabs log pow random sin sqrt tan
  d2 d3 d4 d6 d8 d10 d12 d20 d100
  yardsToMeters feetToMeters
  getSubString getStringUpperCase getStringRight getStringLowerCase getStringLength
  getStringLeft findSubString insertString testStringAgainstPattern
  intToHexString intToString intToFloat
  floatToString floatToInt
  stringToFloat stringToInt
  getFacingFromLocation getAreaFromLocation getPositionFromLocation

  spawnScriptDebugger

  location vector
}

DontExport = %w{
  badBadReplaceMeThisDoesNothing
  objectToString
}
DontExportDisabled = %w{
  printFloat printInteger printObject printString printVector
}

ExceptionReturnValue = {
  'void' => '',
  'int' => '0',
  'float' => '0.0',
  'bool' => 'JNI_FALSE'
}
ExceptionReturnValue.default = 'NULL'

RX = %r{ ( \n// .+? ) \n \s* #{TypeRXStr} \s+ (.+?) \s* \((.*?)\) \s* ; }xm

$fun = {}

$funs = []
$funIds = {} # name => id

File.open("build/nwscript.nss", "r") {|_f|
  ln = 0
  s = _f.read

  # Strip off everything before the function prototypes
  _, s = s.split('string sLanguage = "nwscript";', 2)

  s.gsub!('[0.0,0.0,0.0]', "_DEFAULT_VECTOR_")

  fid = -1

  post = s
  while m = RX.match(post)
    post = m.post_match

    comment = "line #{ln}: #{s}"

    doc, ret, function, params = $1.strip, $2.strip, $3.strip, $4.strip
    fid += 1

    next if DontDoAtAll.index(function)

    in_list = false
    doc = doc.split("\r\n").map {|x|
      x.gsub(%r{^\s*//\s*}, "").strip
    }.map {|x|
      x.gsub(%r{- ([^:]+)(: (.+))?}) {|v|
        vxa = if ArgumentRename[function + " " + $1]
          ArgumentRename[function + " " + $1]
        else $1 end
        "@param " + vxa + ($3 ? " " + $3 : "")
      }
    }

    params = params.split(/,\s*/).map {|p|
      p =~ /^ \s* #{TypeRXStr} \s+ (.+?) (?:\s*=\s*(.+?))? $/x or fail "cannot parse #{p.inspect} (in #{s.inspect})"
      [$1.strip, $2.strip, $3 == '_DEFAULT_VECTOR_' ? '[0.0,0.0,0.0]' : $3]
    }

    catch (:skip) {
      params = params.map {|(type, name, default)|
        t = TypeMap[type] or begin
          $stderr.puts "#{function}: parameter #{name}: cannot resolve type #{type.inspect}, will not export"
          throw :skip
        end

        if ArgumentRename[function + " " + name]
          name = ArgumentRename[function + " " + name]
        elsif ArgumentRename[name]
          name = ArgumentRename[name]
        end

      # Try to detect boolean argument values
        type = "bool" if type == "int" && name =~ /^b[A-Z]/

        if name =~ /^n(.+)$/ && Enums[$1]
          type = $1
          name = "t#{$1}"
        end

        if ArgumentTypeDef[function + " " + name]
          type = ArgumentTypeDef[function + " " + name]
        end

        [type, name, default]
      }

      TypeMap[ret] != nil or begin
        $stderr.puts "#{function} retval #{ret.inspect}: cannot resolve, will not export"
        throw :skip
      end

      # Java semantics: first letter is downcase ..
      function[0,1] = function[0,1].downcase

      # Try to detect boolean result values
      ret = 'bool' if 'int' == ret && function =~ /^get(Is|Has)/ || function =~ /^isIn/ || function =~ /^get.+?Flag$/

      ret = ReturnRename[function] if ReturnRename[function]

      $funs << b = [ret, function, params, doc]
      $funIds[function] = fid
    }
  end
}

# $funs.sort! {|a,b| a[1] <=> b[1] }

# File.open("funs.yaml", "w") do |f|
#   x = $funs.map {|(ret, function, params, doc)|
#     {
#       :fid => FIDS[function],
#       :name => function,
#       :result => ret,
#       :arguments => params,
#       :doc => doc,
#     }
#   }
#   YAML.dump(x, f)
# end if false


# Enums.each {|type, values|
#   File.open("java/src/#{$core_classpath}/#{type}.java", "w") do |f|
#     f.puts "package #{$core_package};"
#     f.puts ""
#     f.puts "public enum #{type} {"
#     f.puts "  " + values.values.join(", ")
#     f.puts "}"
#   end
# }


# First, generate the .ice file
File.open("java/src/#{$core_classpath}NWScript.java", "w") do |f|
  f.puts <<EOF
// Generated on #{Time.now.to_s}

package #{$core_package};

import java.util.Vector;

public class NWScript {
    public NWScript() { }

    private native static synchronized int popInteger();
    private native static synchronized void pushInteger(int value);
    private native static synchronized float popFloat();
    private native static synchronized void pushFloat(float value);
    private native static synchronized String popString();
    private native static synchronized void pushString(String value);
    private native static synchronized NWObject popObject();
    private native static synchronized void pushObject(NWObject oObject);
    private native static synchronized NWVector popVector();
    private native static synchronized void pushVector(NWVector value);
    private native static synchronized NWLocation popLocation();
    private native static synchronized void pushLocation(NWLocation value);
    private native static synchronized NWEffect popEffect();
    private native static synchronized void pushEffect(NWEffect value);
    private native static synchronized NWItemProperty popItemProperty();
    private native static synchronized void pushItemProperty(NWItemProperty value);
    private native static synchronized void callFunction(int fid, int argc);
    private native static synchronized boolean canCallVM();

EOF
  f.puts IO.read("build/Iterators.java")

  $funs.each_with_index {|(ret,function,params,doc)|
    next unless ret

    fid = $funIds[function] or raise "Function ID not registered."

    next if DontExport.index(function)

    catch (:skip) {
      ret = TypeMap[ret] if TypeMap[ret]
      p1 = params.map {|type, name, default|
        if false # ArgumentDropWith["#{function} #{name}"]
          nil
        else
          type = TypeMap[type] if TypeMap[type]
          "%s %s" % [type, name]
        end
      }.compact

      doc = "/**\n     * " + doc.join("\n     * ") + "\n     */"

      keys = ""
      ex = ['NWNotInContextException']
      ex << 'NWInvalidEffectException' if params.select {|t,n,d| t == "effect"}.size > 0
      ex << 'NWInvalidItemPropertyException' if params.select {|t,n,d| t == "itemproperty"}.size > 0

      f.puts ""
      f.puts "    #{doc}"
      f.puts "    public static synchronized #{ret} #{function}(#{p1.join(", ")}) throws #{ex.join(", ")} {"
      f.puts "        if (!canCallVM()) throw new NWNotInContextException(\"Not on VM thread while calling #{function}\");"
      params.reverse.each do |type, name, default|
        case type
          when "object";       f.puts "        pushObject(#{name});"
          when "int";          f.puts "        pushInteger(#{name});"
          when "float";        f.puts "        pushFloat(#{name});"
          when "bool";         f.puts "        pushInteger(#{name} ? 1 : 0);"
          when "string";       f.puts "        pushString(#{name});"
          when "location";     f.puts "        pushLocation(#{name});"
          when "vector";       f.puts "        pushVector(#{name});"
          when "effect";       f.puts "        pushEffect(#{name});"
          when "itemproperty"; f.puts "        pushItemProperty(#{name});"
          else
            fail "#{type} unhandled in #{params.inspect}"
      # f.puts "        #{type.inspect} #{name} #{default}"
        end
      end
      f.puts "        callFunction(#{fid}, #{params.size});"
      case ret
        when "NWObject";      f.puts "        return popObject();"
        when "int";           f.puts "        return popInteger();"
        when "float";         f.puts "        return popFloat();"
        when "bool";          f.puts "        return popInteger();"
        when "String";        f.puts "        return popString();"
        when "boolean";       f.puts "        return popInteger() > 0;"
        when "NWItemProperty";f.puts "        return popItemProperty();"
        when "NWEffect";      f.puts "        return popEffect();"
        when "NWLocation";    f.puts "        return popLocation();"
        when "NWVector";      f.puts "        return popVector();"
        when "void"
        else
          fail "unhandled ret: #{ret}"
        end
      f.puts "    }"
    }
  }
  f.puts ""
  # f.puts IO.read("NWScript_addon.java")
  f.puts "}"
end

File.open("java/src/#{$core_classpath}Action.java", "w") do |f|
  f.puts "// Generated on #{Time.now.to_s} from #{$path}"
  f.puts ""
  f.puts "package #{$core_package};"
  f.puts ""
  f.puts "import java.lang.Runnable;"
  f.puts ""
  f.puts <<EOF
/**
 * This singleton-class provides convenient wrappers around all
 * NWScript action-type method calls that modify the action queue.
 */
EOF
  f.puts "public final class Action {"
  f.puts "    private Action() {}"
  f.puts <<EOF

    /**
     * Clears all actions for the given object.
     */
    public final static void clear(NWObject objectSelf, final boolean combatToo) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.clearAllActions(combatToo);
            }
        });
    }
EOF
  $funs.each {|(ret,function,params, doc)|
    next unless function =~ /^action(.+?)$/
    action = $1
    action[0,1] = action[0,1].downcase
    paramA = params.map {|type, name, default|
      if ArgumentDropWith["#{function} #{name}"]
        nil
      else
        type = TypeMap[type] if TypeMap[type]
        "final %s %s" % [type, name]
      end
    }.compact.join(", ")
    paramC = paramA.split(", ").map {|x| x.split(" ", 3)[-1]}.join(", ")

    doc = "/**\n     * " + doc.join("\n     * ") + "\n     */"

    f.puts ""
    f.puts "    #{doc}"
    f.puts "    public final static void %s(NWObject objectSelf%s%s) {" % [ action, paramA.size > 0 ? ", " : "", paramA ]
    f.puts "        Scheduler.assign(objectSelf, new Runnable() {"
    f.puts "            @Override public void run() {"
    f.puts "                NWScript.%s(%s);" % [ function, paramC ]
    f.puts "            }"
    f.puts "        });"
    f.puts "    }"
  }
  f.puts "}"
end
