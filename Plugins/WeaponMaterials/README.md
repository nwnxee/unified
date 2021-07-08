@addtogroup weaponmaterials WeaponMaterials
@page weaponmaterials Readme
@ingroup weaponmaterials

Implements damage reductions based on weapon materials as per PnP rules.

## Usage
### New damage types
Damage types are needed to create mappings between materials and damage resistance/reduction effects.

To create new damage types based on materials, simply add the new damage types to `iprp_damagetype.2da`. The `Material` column will take a default value of 0 if empty. The value in this column should match an index in `iprp_material.2da`. Name is the StrRef to be used when displaying the material name. You can use the same StrRef used in `iprp_material.2da`.

Example iprp_damagetype.2da:

```
2DA V2.0                               
                                       
           Name   Label         Cost    Material
0          1031   Bludgeoning   1.25    0
1          1032   Piercing      1.25    0
2          1033   Slashing      1.25    0
3          ****   Subdual       ****    0
4          ****   Physical      ****    0
5          62487  Magical       0.35    0
6          1027   Acid          0.35    0
7          1029   Cold          0.4     0
8          5155   Divine        0.4     0
9          1030   Electrical    0.45    0
10         1028   Fire          0.5     0
11         5158   Negative      0.5     0
12         5159   Positive      0.5     0
13         111776   Adamantine  0.5     1
14         111780   ColdIron    0.5     5
15         111782   Darksteel   0.5     7
16         111786   Mithral     0.5     11
17         111788   Silver      0.5     13
18         111789   AlchSilver  0.5     14

```

### New damage reductions

Damage reductions for materials work exactly like damage soaking in the form X/+Y where +Y will be a material instead of a numeric value to overcome. Only weapons with that material property will ignore X/Material reductions.

See the previous section for info on the Name and Material columns.

Example `iprp_protection.2da`:
```
2DA V2.0                            
                                    
           Name   Label      Cost   Material
0          1045   Bonus+1    1.25   
1          1046   Bonus+2    1.75   
2          1047   Bonus+3    2.25   
3          1048   Bonus+4    2.5    
4          1049   Bonus+5    2.75   
5          1050   Bonus+6    4      
6          1051   Bonus+7    5      
7          1052   Bonus+8    6      
8          1053   Bonus+9    7      
9          1054   Bonus+10   8      
10         1954   Bonus+11   10     
11         1992   Bonus+12   12     
12         2113   Bonus+13   14     
13         2119   Bonus+14   16     
14         2139   Bonus+15   18     
15         2163   Bonus+16   20     
16         2164   Bonus+17   22     
17         2187   Bonus+18   24     
18         2191   Bonus+19   26     
19         2192   Bonus+20   28     
20         111776   Adamantine  2.75    1
21         111780   ColdIron    2.75    5
22         111782   Darksteel   2.75    7
23         111786   Mithral     2.75    11
24         111788   Silver      2.75    13
25         111789   AlchSilver  2.75    14
```

### New damage resistances
Damage resistance uses damage types (`iprp_damagetype.2da`) to define the kind of damage that will be reduced. No other input is neede to make resistances work.

NOTE: Damage resistances are added for completeness, it's recommended to use damage reductions only. PnP rules state that material reductions act the same way as damage reductions against non-magical weapons.

### Damage vulnerability/immunity
WIP.