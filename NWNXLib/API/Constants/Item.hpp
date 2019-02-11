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
        Trumpet                                    = 92,
        MoonOnAStick                               = 92,
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
        Invalid                                    = 255,
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
        constexpr const char* TYPE_STRINGS[] =
        {
            "Shortsword",
            "Longsword",
            "Battleaxe",
            "Bastard Sword",
            "Light Flail",
            "Warhammer",
            "Heavy Crossbow",
            "Light Crossbow",
            "Longbow",
            "Light Mace",
            "Halberd",
            "Shortbow",
            "Twobladed Sword",
            "Greatsword",
            "Small Shield",
            "Torch",
            "Armor",
            "Helmet",
            "Greataxe",
            "Amulet",
            "Arrow",
            "Belt",
            "Dagger",
            "Miscellaneous Small",
            "Bolt",
            "Boots",
            "Bullet",
            "Club",
            "Miscellaneous Medium",
            "Dart",
            "Dire Mace",
            "Double Axe",
            "Miscellaneous Large",
            "Heavy Flail",
            "Gloves",
            "Light Hammer",
            "Handaxe",
            "Healers Kit",
            "Kama",
            "Katana",
            "Kukri",
            "Miscellaneous Tall",
            "Magic Rod",
            "Magic Staff",
            "Magic Wand",
            "Morning Star",
            "Potions",
            "Quarter Staff",
            "Rapier",
            "Ring",
            "Scimitar",
            "Scroll",
            "Scythe",
            "Large Shield",
            "Tower Shield",
            "Short Spear",
            "Shuriken",
            "Sickle",
            "Sling",
            "Thieves Tools",
            "Throwing Axe",
            "Trap Kit",
            "Key",
            "Large Box",
            "Miscellaneous Wide",
            "Creature Slashing Weapon",
            "Creature Piercing Weapon",
            "Creature Bludgeoning Weapon",
            "Creature Slashing/Piercing Weapon",
            "Creature Item",
            "Book",
            "Spell Scroll",
            "Gold",
            "Gem",
            "Bracer",
            "Miscellaneous Thin",
            "Cloak",
            "Grenade",
            "Encampment",
            "Lance",
            "Trumpet",
            "Moon-on-a-Stick",
            "Trident",
            "Blank Potion",
            "Blank Scroll",
            "Blank Wand",
            "Enchanted Potion",
            "Enchanted Scroll",
            "Enchanted Wand",
            "Dwarven Waraxe",
            "Crafting Material Medium",
            "Crafting Material Small",
            "Whip",
            "Crafting Base",
        };
        constexpr const char* TYPE_STRINGS_CEP[] =
        {
            "[CEP] Trident",
            "[CEP] Heavy Pick",
            "[CEP] Light Pick",
            "[CEP] Sai",
            "[CEP] Nunchaku",
            "[CEP] Falchion",
            "[CEP] Small Box",
            "[CEP] Miscellaneous Medium2",
            "[CEP] Sap",
            "[CEP] Assassin Dagger",
            "[CEP] Katar",
            "[CEP] Miscellaneous Small2",
            "[CEP] HeavyMace",
            "[CEP] Maul",
            "[CEP] Mercurial Longsword",
            "[CEP] Mercurial Greatsword",
            "[CEP] Double Scimitar",
            "[CEP] Goad",
            "[CEP] Windfire Wheel",
            "[CEP] Double Pick",
            "[CEP] Flowers",
            "[CEP] Cloak",
        };
        if (value <= CraftBase)
            return TYPE_STRINGS[value];
        if (value >= CEP_Trident && value <= CEP_Cloak)
            return TYPE_STRINGS_CEP[value - CEP_Trident];
        return "(invalid)";
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
        ArmorModel_LightFoot      =  1,
        ArmorModel_RightShin      =  2,
        ArmorModel_LightShin      =  3,
        ArmorModel_LightThigh     =  4,
        ArmorModel_RightThigh     =  5,
        ArmorModel_Pelvis         =  6,
        ArmorModel_Torso          =  7,
        ArmorModel_Belt           =  8,
        ArmorModel_Neck           =  9,
        ArmorModel_RightForearm   = 10,
        ArmorModel_LightForearm   = 11,
        ArmorModel_RightBicep     = 12,
        ArmorModel_LightBicep     = 13,
        ArmorModel_RightShoulder  = 14,
        ArmorModel_LightShoulder  = 15,
        ArmorModel_RightHand      = 16,
        ArmorModel_LightHand      = 17,
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
            "Armor Model: Light Foot",
            "Armor Model: Right Shin",
            "Armor Model: Light Shin",
            "Armor Model: Light Thigh",
            "Armor Model: Right Thigh",
            "Armor Model: Pelvis",
            "Armor Model: Torso",
            "Armor Model: Belt",
            "Armor Model: Neck",
            "Armor Model: Right Forearm",
            "Armor Model: Light Forearm",
            "Armor Model: Right Bicep",
            "Armor Model: Light Bicep",
            "Armor Model: Right Shoulder",
            "Armor Model: Light Shoulder",
            "Armor Model: Right Hand",
            "Armor Model: Light Hand",
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


}
