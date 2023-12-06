@page nwsqliteextensions Readme
@ingroup nwsqliteextensions

Various extensions for the game's built-in sqlite database.

## Environment Variables

| Variable Name                                                 |   Value    | Notes                                                                            |
|---------------------------------------------------------------|:----------:|----------------------------------------------------------------------------------|
| `NWNX_NWSQLITEEXTENSIONS_ENABLE_DATABASE_ON_ALL_OBJECT_TYPES` | true/false | Allows SqlPrepareQueryObject() to work on all object types except areas.         |
| `NWNX_NWSQLITEEXTENSIONS_ENABLE_MERSENNE_TWISTER_FUNCTIONS`   | true/false | Enables Mersenne Twister SQLite functions. See below for more information.       |
| `NWNX_NWSQLITEEXTENSIONS_ENABLE_2DA_VIRTUAL_TABLE_MODULE`     | true/false | Enable the 2DA Virtual Table Module. See below for more information.             |

## Mersenne Twister SQLite functions

A Mersenne Twister is a general-purpose pseudorandom number generator, useful if you need a seeded RNG.

If enabled, the following functions will be available in queries:

* MT_SEED(NAME, SEED)
    * `NAME` is a non-empty string which is used as the id of the Mersenne Twister.
    * `SEED` is a positive integer value indicating the seed.
    * Returns TRUE if the seed was successfully set.
* MT_VALUE(NAME)
    * `NAME` is a non-empty string which is used as the id of the Mersenne Twister.
    * Returns the next value of the Mersenne Twister or -1 on error.
    * Can be used in place of RANDOM() to order a result set, for example.
* MT_DISCARD(NAME, AMOUNT)
    * `NAME` is a non-empty string which is used as the id of the Mersenne Twister.
    * `AMOUNT` is a positive integer value indicating the amount of values to discard.
    * Returns TRUE if the discard was successful.

### Example functions:
```c
void SqlMersenneTwisterSetSeed(string sName, int nSeed)
{
    sqlquery sql = SqlPrepareQueryObject(GetModule(), "SELECT MT_SEED(@name, @seed);");
    SqlBindString(sql, "@name", sName);
    SqlBindInt(sql, "@seed", nSeed);
    SqlStep(sql);
}

int SqlMersenneTwisterGetValue(string sName, int nMaxInteger)
{
    sqlquery sql = SqlPrepareQueryObject(GetModule(), "SELECT (MT_VALUE(@name) % @maxinteger);");
    SqlBindString(sql, "@name", sName);
    SqlBindInt(sql, "@maxinteger", nMaxInteger);
    return SqlStep(sql) ? SqlGetInt(sql, 0) : -1;
}
```

## 2DA Virtual Table Module

A SQLite Virtual Table that allows you to query 2DA data. These tables are read-only and only created in the module SQLite database.

To use it, you must first create a virtual table for a 2da using the following function:
```c
/// @brief Create a virtual table for s2DA in the module sqlite database.
/// @param s2DA The 2DA name, cannot be empty.
/// @param sColumnTypeHints A string containing type hints for the 2DA columns. See this plugin's readme file for more info.
/// @param sTableName The table name, will use the 2da name if empty.
/// @return TRUE if the virtual table was created.
int NWNX_NWSQLiteExtensions_CreateVirtual2DATable(string s2DA, string sColumnTypeHints = "", string sTableName = "");
```
The columns of the table are the columns available in the 2da, their names are case-insensitive. To get the id of a row you can use the special SQLite `rowid` column.

`****` values in the 2DA are considered `NULL` in the SQLite table.

### Column Type Hints

`sColumnTypeHints` is an optional parameter that allows you to set the datatype of a column. 

If not set SQLite will assume the column type is TEXT/string, which means that if a column has integers as data you won't be able to use `column >= 123` constraints in the `WHERE` clause and you would have to compare the value as TEXT/string: `column = '1'` etc.

Available Type Hints:

| Hint | SQLite Type | NWScript Type |
|------|-------------|---------------|
| 0    | TEXT        | string        |
| 1    | INTEGER     | int           |
| 2    | REAL        | float         |

### Example

If we look at `effecticons.2da`, we can see it has the following columns:
```
2DA V2.0

           Label                                Icon               StrRef
0          ****                                 ****               0
1          DAMAGE_RESISTANCE                    ief_DamResist      8028
2          REGENERATE                           ief_Regenerate     8029
```
From the 2DA data we can infer that the `Label` and `Icon` columns contain strings, while the `StrRef` column contains integers which means our column type hint will be `001`.

To create a virtual table for the `effecticons.2da` we would call the CreateVirtual2DATable() function as follows: `NWNX_NWSQLiteExtensions_CreateVirtual2DATable("effecticons", "001");`

Now that we created the virtual table, we can query it using the game's `Sql*` functions:

```c
void main()
{
    sqlquery sql = SqlPrepareQueryObject(GetModule(), "SELECT label FROM effecticons WHERE label IS NOT NULL AND strref >= 8030 AND strref <= 8035;");
    while (SqlStep(sql))
    {
        SendMessageToPC(GetFirstPC(), SqlGetString(sql, 0));
    }
}
```

The above will list the labels of all effect icons if their label is not null (meaning not **** in the 2da) and if their `StrRef` is between 8030 and 8035 inclusive.
