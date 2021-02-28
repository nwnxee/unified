#pragma once
#include <cstdint>

namespace NWNXLib::API::Constants {

namespace InventorySlot
{
    enum TYPE
    {
        Head                 =  0,
        Chest                =  1,
        Boots                =  2,
        Arms                 =  3,
        RightHand            =  4,
        LeftHand             =  5,
        Cloak                =  6,
        LeftRing             =  7,
        RightRing            =  8,
        Neck                 =  9,
        Belt                 = 10,
        Arrows               = 11,
        Bullets              = 12,
        Bolts                = 13,
        CreatureWeaponLeft   = 14,
        CreatureWeaponRight  = 15,
        CreatureWeaponBite   = 16,
        CreatureArmour       = 17,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 17;
    static_assert(MAX == CreatureArmour);

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Head",
            "Chest",
            "Boots",
            "Arms",
            "Right Hand",
            "Left Hand",
            "Cloak",
            "Left Ring",
            "Right Ring",
            "Neck",
            "Belt",
            "Arrows",
            "Bullets",
            "Bolts",
            "Creature Weapon Left",
            "Creature Weapon Right",
            "Creature Weapon Bite",
            "Creature Armour",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace EquipmentSlot
{
    enum TYPE
    {
        None                 = 0,
        Head                 = (1 <<  0),
        Chest                = (1 <<  1),
        Boots                = (1 <<  2),
        Arms                 = (1 <<  3),
        RightHand            = (1 <<  4),
        LeftHand             = (1 <<  5),
        Cloak                = (1 <<  6),
        LeftRing             = (1 <<  7),
        RightRing            = (1 <<  8),
        Neck                 = (1 <<  9),
        Belt                 = (1 << 10),
        Arrows               = (1 << 11),
        Bullets              = (1 << 12),
        Bolts                = (1 << 13),
        CreatureWeaponLeft   = (1 << 14),
        CreatureWeaponRight  = (1 << 15),
        CreatureWeaponBite   = (1 << 16),
        CreatureArmour       = (1 << 17),
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = (1 << 18) - 1;

    constexpr const char* ToString(const unsigned value)
    {
        switch (value)
        {
            case None:                 return "None";
            case Head:                 return "Head";
            case Chest:                return "Chest";
            case Boots:                return "Boots";
            case Arms:                 return "Arms";
            case RightHand:            return "Right Hand";
            case LeftHand:             return "Left Hand";
            case Cloak:                return "Cloak";
            case LeftRing:             return "Left Ring";
            case RightRing:            return "Right Ring";
            case Neck:                 return "Neck";
            case Belt:                 return "Belt";
            case Arrows:               return "Arrows";
            case Bullets:              return "Bullets";
            case Bolts:                return "Bolts";
            case CreatureWeaponLeft:   return "Creature Weapon Left";
            case CreatureWeaponRight:  return "Creature Weapon Right";
            case CreatureWeaponBite:   return "Creature Weapon Bite";
            case CreatureArmour:       return "Creature Armour";
            case MAX:                  return "All";
        }
        return (value < MAX) ? "Multiple" : "(invalid)";
    }
}

namespace BaseItem
{
    enum TYPE
    {
        Shortsword                                 = 0,
        Longsword                                  = 1,
        Battleaxe                                  = 2,
        BastardSword                               = 3,
        LightFlail                                 = 4,
        Warhammer                                  = 5,
        HeavyCrossbow                              = 6,
        LightCrossbow                              = 7,
        Longbow                                    = 8,
        LightMace                                  = 9,
        Halberd                                    = 10,
        Shortbow                                   = 11,
        TwobladedSword                             = 12,
        Greatsword                                 = 13,
        SmallShield                                = 14,
        Torch                                      = 15,
        Armor                                      = 16,
        Helmet                                     = 17,
        Greataxe                                   = 18,
        Amulet                                     = 19,
        Arrow                                      = 20,
        Belt                                       = 21,
        Dagger                                     = 22,
        MiscSmall                                  = 24,
        Bolt                                       = 25,
        Boots                                      = 26,
        Bullet                                     = 27,
        Club                                       = 28,
        MiscMedium                                 = 29,
        Dart                                       = 31,
        DireMace                                   = 32,
        DoubleAxe                                  = 33,
        MiscLarge                                  = 34,
        HeavyFlail                                 = 35,
        Gloves                                     = 36,
        LightHammer                                = 37,
        Handaxe                                    = 38,
        HealersKit                                 = 39,
        Kama                                       = 40,
        Katana                                     = 41,
        Kukri                                      = 42,
        MiscTall                                   = 43,
        MagicRod                                   = 44,
        MagicStaff                                 = 45,
        MagicWand                                  = 46,
        MorningStar                                = 47,
        Potions                                    = 49,
        QuarterStaff                               = 50,
        Rapier                                     = 51,
        Ring                                       = 52,
        Scimitar                                   = 53,
        Scroll                                     = 54,
        Scythe                                     = 55,
        LargeShield                                = 56,
        TowerShield                                = 57,
        ShortSpear                                 = 58,
        Shuriken                                   = 59,
        Sickle                                     = 60,
        Sling                                      = 61,
        ThievesTools                               = 62,
        ThrowingAxe                                = 63,
        TrapKit                                    = 64,
        Key                                        = 65,
        LargeBox                                   = 66,
        MiscWide                                   = 68,
        CreatureSlashWeapon                        = 69,
        CreaturePierceWeapon                       = 70,
        CreatureBludgeWeapon                       = 71,
        CreatureSlashPierceWeapon                  = 72,
        CreatureItem                               = 73,
        Book                                       = 74,
        SpellScroll                                = 75,
        Gold                                       = 76,
        Gem                                        = 77,
        Bracer                                     = 78,
        MiscThin                                   = 79,
        Cloak                                      = 80,
        Grenade                                    = 81,
        Encampment                                 = 82,
        Lance                                      = 92,
        Trumpet                                    = 93,
        MoonOnAStick                               = 94,
        Trident                                    = 95,
        BlankPotion                                = 101,
        BlankScroll                                = 102,
        BlankWand                                  = 103,
        EnchantedPotion                            = 104,
        EnchantedScroll                            = 105,
        EnchantedWand                              = 106,
        DwarvenWaraxe                              = 108,
        CraftMaterialMedium                        = 109,
        CraftMaterialSmall                         = 110,
        Whip                                       = 111,
        CraftBase                                  = 112,
        Invalid                                    = 256,
        CEP_Trident                                = 300,
        CEP_HeavyPick                              = 301,
        CEP_LightPick                              = 302,
        CEP_Sai                                    = 303,
        CEP_Nunchaku                               = 304,
        CEP_Falchion                               = 305,
        CEP_SmallBox                               = 306,
        CEP_MiscMedium2                            = 307,
        CEP_Sap                                    = 308,
        CEP_AssassinDagger                         = 309,
        CEP_Katar                                  = 310,
        CEP_MiscSmall2                             = 311,
        CEP_HeavyMace                              = 317,
        CEP_Maul                                   = 318,
        CEP_MercurialLongSword                     = 319,
        CEP_MercurialGreatSword                    = 320,
        CEP_DoubleScimitar                         = 321,
        CEP_Goad                                   = 322,
        CEP_WindfireWheel                          = 323,
        CEP_DoublePick                             = 324,
        CEP_Flowers                                = 325,
        CEP_Cloak                                  = 349,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 65535;

    constexpr const char* ToString(const unsigned value)
    {
        switch(value)
        {
            default: return "(unknown)";
            case Shortsword: return "Shortsword";
            case Longsword: return "Longsword";
            case Battleaxe: return "Battleaxe";
            case BastardSword: return "Bastard Sword";
            case LightFlail: return "Light Flail";
            case Warhammer: return "Warhammer";
            case HeavyCrossbow: return "Heavy Crossbow";
            case LightCrossbow: return "Light Crossbow";
            case Longbow: return "Longbow";
            case LightMace: return "Light Mace";
            case Halberd: return "Halberd";
            case Shortbow: return "Shortbow";
            case TwobladedSword: return "Twobladed Sword";
            case Greatsword: return "Greatsword";
            case SmallShield: return "Small Shield";
            case Torch: return "Torch";
            case Armor: return "Armor";
            case Helmet: return "Helmet";
            case Greataxe: return "Greataxe";
            case Amulet: return "Amulet";
            case Arrow: return "Arrow";
            case Belt: return "Belt";
            case Dagger: return "Dagger";
            case MiscSmall: return "Miscellaneous Small";
            case Bolt: return "Bolt";
            case Boots: return "Boots";
            case Bullet: return "Bullet";
            case Club: return "Club";
            case MiscMedium: return "Miscellaneous Medium";
            case Dart: return "Dart";
            case DireMace: return "Dire Mace";
            case DoubleAxe: return "Double Axe";
            case MiscLarge: return "Miscellaneous Large";
            case HeavyFlail: return "Heavy Flail";
            case Gloves: return "Gloves";
            case LightHammer: return "Light Hammer";
            case Handaxe: return "Handaxe";
            case HealersKit: return "Healers Kit";
            case Kama: return "Kama";
            case Katana: return "Katana";
            case Kukri: return "Kukri";
            case MiscTall: return "Miscellaneous Tall";
            case MagicRod: return "Magic Rod";
            case MagicStaff: return "Magic Staff";
            case MagicWand: return "Magic Wand";
            case MorningStar: return "Morning Star";
            case Potions: return "Potions";
            case QuarterStaff: return "Quarter Staff";
            case Rapier: return "Rapier";
            case Ring: return "Ring";
            case Scimitar: return "Scimitar";
            case Scroll: return "Scroll";
            case Scythe: return "Scythe";
            case LargeShield: return "Large Shield";
            case TowerShield: return "Tower Shield";
            case ShortSpear: return "Short Spear";
            case Shuriken: return "Shuriken";
            case Sickle: return "Sickle";
            case Sling: return "Sling";
            case ThievesTools: return "Thieves Tools";
            case ThrowingAxe: return "Throwing Axe";
            case TrapKit: return "Trap Kit";
            case Key: return "Key";
            case LargeBox: return "Large Box";
            case MiscWide: return "Miscellaneous Wide";
            case CreatureSlashWeapon: return "Creature Slashing Weapon";
            case CreaturePierceWeapon: return "Creature Piercing Weapon";
            case CreatureBludgeWeapon: return "Creature Bludgeoning Weapon";
            case CreatureSlashPierceWeapon: return "Creature Slashing/Piercing Weapon";
            case CreatureItem: return "Creature Item";
            case Book: return "Book";
            case SpellScroll: return "Spell Scroll";
            case Gold: return "Gold";
            case Gem: return "Gem";
            case Bracer: return "Bracer";
            case MiscThin: return "Miscellaneous Thin";
            case Cloak: return "Cloak";
            case Grenade: return "Grenade";
            case Encampment: return "Encampment";
            case Lance: return "Lance";
            case Trumpet: return "Trumpet";
            case MoonOnAStick: return "Moon-on-a-Stick";
            case Trident: return "Trident";
            case BlankPotion: return "Blank Potion";
            case BlankScroll: return "Blank Scroll";
            case BlankWand: return "Blank Wand";
            case EnchantedPotion: return "Enchanted Potion";
            case EnchantedScroll: return "Enchanted Scroll";
            case EnchantedWand: return "Enchanted Wand";
            case DwarvenWaraxe: return "Dwarven Waraxe";
            case CraftMaterialMedium: return "Crafting Material Medium";
            case CraftMaterialSmall: return "Crafting Material Small";
            case Whip: return "Whip";
            case CraftBase: return "Crafting Base";

            case CEP_Trident: return "[CEP] Trident";
            case CEP_HeavyPick: return "[CEP] Heavy Pick";
            case CEP_LightPick: return "[CEP] Light Pick";
            case CEP_Sai: return "[CEP] Sai";
            case CEP_Nunchaku: return "[CEP] Nunchaku";
            case CEP_Falchion: return "[CEP] Falchion";
            case CEP_SmallBox: return "[CEP] Small Box";
            case CEP_MiscMedium2: return "[CEP] Miscellaneous Medium2";
            case CEP_Sap: return "[CEP] Sap";
            case CEP_AssassinDagger: return "[CEP] Assassin Dagger";
            case CEP_Katar: return "[CEP] Katar";
            case CEP_MiscSmall2: return "[CEP] Miscellaneous Small2";
            case CEP_HeavyMace: return "[CEP] HeavyMace";
            case CEP_Maul: return "[CEP] Maul";
            case CEP_MercurialLongSword: return "[CEP] Mercurial Longsword";
            case CEP_MercurialGreatSword: return "[CEP] Mercurial Greatsword";
            case CEP_DoubleScimitar: return "[CEP] Double Scimitar";
            case CEP_Goad: return "[CEP] Goad";
            case CEP_WindfireWheel: return "[CEP] Windfire Wheel";
            case CEP_DoublePick: return "[CEP] Double Pick";
            case CEP_Flowers: return "[CEP] Flowers";
            case CEP_Cloak: return "[CEP] Cloak";
        }
    }
}

namespace ItemAppearance
{
    enum TYPE
    {
        Color_Leather1            = -9,
        Color_Leather2            = -8,
        Color_Cloth1              = -7,
        Color_Cloth2              = -6,
        Color_Metal1              = -5,
        Color_Metal2              = -4,
        Model_Part1               = -3,
        Model_Part2               = -2,
        Model_Part3               = -1,
        ArmorModel_RightFoot      =  0,
        ArmorModel_LeftFoot       =  1,
        ArmorModel_RightShin      =  2,
        ArmorModel_LeftShin       =  3,
        ArmorModel_LeftThigh      =  4,
        ArmorModel_RightThigh     =  5,
        ArmorModel_Pelvis         =  6,
        ArmorModel_Torso          =  7,
        ArmorModel_Belt           =  8,
        ArmorModel_Neck           =  9,
        ArmorModel_RightForearm   = 10,
        ArmorModel_LeftForearm    = 11,
        ArmorModel_RightBicep     = 12,
        ArmorModel_LeftBicep      = 13,
        ArmorModel_RightShoulder  = 14,
        ArmorModel_LeftShoulder   = 15,
        ArmorModel_RightHand      = 16,
        ArmorModel_LeftHand       = 17,
        ArmorModel_Robe           = 18,
    };
    constexpr int32_t MIN   = -9;
    constexpr int32_t MAX   = 18;
    static_assert(MAX == ArmorModel_Robe);

    constexpr const char* ToString(const int value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Color: Leather 1",
            "Color: Leather 2",
            "Color: Cloth 1",
            "Color: Cloth 2",
            "Color: Metal 1",
            "Color: Metal 2",
            "Model: Part 1",
            "Model: Part 2",
            "Model: Part 3",
            "Armor Model: Right Foot",
            "Armor Model: Left Foot",
            "Armor Model: Right Shin",
            "Armor Model: Left Shin",
            "Armor Model: Left Thigh",
            "Armor Model: Right Thigh",
            "Armor Model: Pelvis",
            "Armor Model: Torso",
            "Armor Model: Belt",
            "Armor Model: Neck",
            "Armor Model: Right Forearm",
            "Armor Model: Left Forearm",
            "Armor Model: Right Bicep",
            "Armor Model: Left Bicep",
            "Armor Model: Right Shoulder",
            "Armor Model: Left Shoulder",
            "Armor Model: Right Hand",
            "Armor Model: Left Hand",
            "Armor Model: Robe",
        };

        return (value > MAX || value < MIN) ? "(invalid)" : TYPE_STRINGS[value - MIN];
    }
}


namespace ItemAppearanceType
{
    enum TYPE
    {
        SimpleModel = 0,
        WeaponColor = 1,
        WeaponModel = 2,
        ArmorModel  = 3,
        ArmorColor  = 4,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 4;
    static_assert(MAX == ArmorColor);

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "SimpleModel",
            "WeaponColor",
            "WeaponModel",
            "ArmorModel",
            "ArmorColor",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace ItemProperty
{
    enum TYPE
    {
        AbilityBonus                        = 0,
        ACBonus                             = 1,
        ACBonusVSAlignmentGroup             = 2,
        ACBonusVSDamageType                 = 3,
        ACBonusVSRacialGroup                = 4,
        ACBonusVSSpecificAlignment          = 5,
        EnhancementBonus                    = 6,
        EnhancementBonusVSAlignmentGroup    = 7,
        EnhancementBonusVSRacialGroup       = 8,
        EnhancementBonusVSSpecificAlignment = 9,
        DecreasedEnhancementModifier        = 10,
        BaseItemWeightReduction             = 11,
        BonusFeat                           = 12,
        BonusSpellSlot                      = 13,
        CastSpell                           = 15,
        DamageBonus                         = 16,
        DamageBonusVSAlignmentGroup         = 17,
        DamageBonusVSRacialGroup            = 18,
        DamageBonusVSSpecificAlignment      = 19,
        ImmunityDamageType                  = 20,
        DecreasedDamage                     = 21,
        DamageReduction                     = 22,
        DamageResistance                    = 23,
        DamageVulnerability                 = 24,
        Invalid25                           = 25,
        Darkvision                          = 26,
        DecreasedAbilityScore               = 27,
        DecreasedAC                         = 28,
        DecreasedSkillModifier              = 29,
        Invalid30                           = 30,
        Invalid31                           = 31,
        EnhancedContainerReducedWeight      = 32,
        ExtraMeleeDamageType                = 33,
        ExtraRangedDamageType               = 34,
        Haste                               = 35,
        HolyAvenger                         = 36,
        ImmunityMiscellaneous               = 37,
        ImprovedEvasion                     = 38,
        SpellResistance                     = 39,
        SavingThrowBonus                    = 40,
        SavingThrowBonusSpecific            = 41,
        Invalid42                           = 42,
        Keen                                = 43,
        Light                               = 44,
        Mighty                              = 45,
        MindBlank                           = 46,
        NoDamage                            = 47,
        OnHitProperties                     = 48,
        DecreasedSavingThrows               = 49,
        DecreasedSavingThrowsSpecific       = 50,
        Regeneration                        = 51,
        SkillBonus                          = 52,
        ImmunitySpecificSpell               = 53,
        ImmunitySpellSchool                 = 54,
        ThievesTools                        = 55,
        AttackBonus                         = 56,
        AttackBonusVSAlignmentGroup         = 57,
        AttackBonusVSRacialGroup            = 58,
        AttackBonusVSSpecificAlignment      = 59,
        DecreasedAttackModifier             = 60,
        UnlimitedAmmunition                 = 61,
        UseLimitationAlignmentGroup         = 62,
        UseLimitationClass                  = 63,
        UseLimitationRacialType             = 64,
        UseLimitationSpecificAlignment      = 65,
        UseLimitationTileset                = 66,
        VampiricRegeneration                = 67,
        Invalid68                           = 68,
        Invalid69                           = 69,
        Trap                                = 70,
        TrueSeeing                          = 71,
        OnMonsterHit                        = 72,
        TurnResistance                      = 73,
        MassiveCriticals                    = 74,
        FreedomOfMovement                   = 75,
        Poison                              = 76,
        MonsterDamage                       = 77,
        ImmunitySpellsByLevel               = 78,
        SpecialWalk                         = 79,
        HealersKit                          = 80,
        WeightIncrease                      = 81,
        OnHitCastSpell                      = 82,
        VisualEffect                        = 83,
        ArcaneSpellFailure                  = 84,
        Material                            = 85,
        Quality                             = 86,
        Additional                          = 87,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 87;
    static_assert(MAX == Additional);

    constexpr const char* ToString(const int value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Ability Bonus",
            "AC Bonus",
            "AC Bonus VS Alignment Group",
            "AC Bonus VS Damage Type",
            "AC Bonus VS Racial Group",
            "AC Bonus VS Specific Alignment",
            "Enhancement Bonus",
            "Enhancement Bonus VS Alignment Group",
            "Enhancement Bonus VS Racial Group",
            "Enhancement Bonus VS Specific Alignment",
            "Decreased Enhancement Modifier",
            "Base Item Weight Reduction",
            "Bonus Feat",
            "Bonus Spell Slot",
            "Cast Spell",
            "Damage Bonus",
            "Damage Bonus VS Alignment Group",
            "Damage Bonus VS Racial Group",
            "Damage Bonus VS Specific Alignment",
            "Immunity Damage Type",
            "Decreased Damage",
            "Damage Reduction",
            "Damage Resistance",
            "Damage Vulnerability",
            "Invalid25",
            "Darkvision",
            "Decreased Ability Score",
            "Decreased AC",
            "Decreased Skill Modifier",
            "Invalid30",
            "Invalid31",
            "Enhanced Container Reduced Weight",
            "Extra Melee Damage Type",
            "Extra Ranged Damage Type",
            "Haste",
            "Holy Avenger",
            "Immunity Miscellaneous",
            "Improved Evasion",
            "Spell Resistance",
            "Saving Throw Bonus",
            "Saving Throw Bonus Specific",
            "Invalid42",
            "Keen",
            "Light",
            "Mighty",
            "Mind Blank",
            "No Damage",
            "On Hit Properties",
            "Decreased Saving Throws",
            "Decreased Saving Throws Specific",
            "Regeneration",
            "Skill Bonus",
            "Immunity Specific Spell",
            "Immunity Spell School",
            "Thieves Tools",
            "Attack Bonus",
            "Attack Bonus VS Alignment Group",
            "Attack Bonus VS Racial Group",
            "Attack Bonus VS Specific Alignment",
            "Decreased Attack Modifier",
            "Unlimited Ammunition",
            "Use Limitation Alignment Group",
            "Use Limitation Class",
            "Use Limitation Racial Type",
            "Use Limitation Specific Alignment",
            "Use Limitation Tileset",
            "Vampiric Regeneration",
            "Invalid68",
            "Invalid69",
            "Trap",
            "True Seeing",
            "On Monster Hit",
            "Turn Resistance",
            "Massive Criticals",
            "Freedom Of Movement",
            "Poison",
            "Monster Damage",
            "Immunity Spells By Level",
            "Special Walk",
            "Healers Kit",
            "Weight Increase",
            "On Hit Cast Spell",
            "Visual Effect",
            "Arcane Spell Failure",
            "Material",
            "Quality",
            "Additional",
        };

        return (value > MAX || value < MIN) ? "(invalid)" : TYPE_STRINGS[value - MIN];
    }
}

namespace WeaponAttackType
{
    enum TYPE
    {
        MainhandWeapon = 1,
        OffhandWeapon = 2,
        CreatureLeftWeapon = 3,
        CreatureRightWeapon = 4,
        CreatureBiteWeapon = 5,
        AdditionalWeapon = 6,
        Unarmed = 7,
        AdditionalUnarmed = 8,
    };
    constexpr int32_t MIN = 1;
    constexpr int32_t MAX = 8;
    static_assert(MAX == AdditionalUnarmed);

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "(invalid)",
            "MainhandWeapon",
            "OffhandWeapon",
            "CreatureLeftWeapon",
            "CreatureRightWeapon",
            "CreatureBiteWeapon",
            "AdditionalWeapon",
            "Unarmed",
            "AdditionalUnarmed",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

}
