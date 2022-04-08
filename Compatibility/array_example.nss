//#include "inc_array"
#include "nwnx_time"

// nwnx_data also includes inc_array, so don't double dip.
#include "nwnx_data"

void Log(string msg) 
{
    WriteTimestampedLogEntry(msg);
}

void TestArrayOnModule() 
{

    string array = "test";

    // By default, temporary arrays are created on the module.
    Array_PushBack_Str(array, "BItem1");
    Array_PushBack_Str(array, "AItem2");
    Array_PushBack_Str(array, "AItem3");
    Array_PushBack_Str(array, "BItem2");
    Array_Debug_Dump(array, "After first load");

    int foo = Array_Find_Str(array, "AItem3");
    Log("Found element AItem3 at index = " + IntToString(foo));

    Array_Set_Str(array, 2, "Suck it up...");
    Array_Debug_Dump(array, "After set 2 = 'Suck it up...'");

    Array_Erase(array, 1);
    Array_Debug_Dump(array, "After delete 1");

    Array_PushBack_Str(array, "MItem1");
    Array_PushBack_Str(array, "QItem2");
    Array_PushBack_Str(array, "NItem3");
    Array_PushBack_Str(array, "KItem2");

    Array_Debug_Dump(array, "After add more");
    Array_SortAscending(array);

    Array_Debug_Dump(array, "After sort");

    Array_Shuffle(array);
    Array_Debug_Dump(array, "After shuffle");

    Log( (Array_Contains_Str(array, "NItem3")) ? "Passed.. found it"  : "Failed.. should have found it" );
    Log( (Array_Contains_Str(array, "KItem2")) ? "Passed.. found it"  : "Failed.. should have found it" );
    Log( (Array_Contains_Str(array, "xxxxxx")) ? "Failed.. not found" : "Passed.. should not exist" );

    Array_Clear(array);
    // Load up the array with 100 entries
    int i;
	
    struct NWNX_Time_HighResTimestamp b;
    b = NWNX_Time_GetHighResTimeStamp();
    Log("Start Time: " + IntToString(b.seconds) + "." + IntToString(b.microseconds));
    for (i=0; i<1000; i++) 
    {
        Array_PushBack_Str(array, IntToString(d100()) + " xxx " + IntToString(i));
    }
    b = NWNX_Time_GetHighResTimeStamp();
    Log("Loaded 1000: " + IntToString(b.seconds) + "." + IntToString(b.microseconds));
    Array_Shuffle(array);
    b = NWNX_Time_GetHighResTimeStamp();
    Log("Shuffled 1000: " + IntToString(b.seconds) + "." + IntToString(b.microseconds));
    for (i=5; i<995; i++) 
    {
        // Delete the third entry a bunch of times
        Array_Erase(array, 3);
    }
    b = NWNX_Time_GetHighResTimeStamp();
    Log("Delete ~990: " + IntToString(b.seconds) + "." + IntToString(b.microseconds));
    Array_Debug_Dump(array, "After mass insert/delete");

}

void TestArrayOnChicken() 
{
    string array="chicken";
    // Let's create an array "on" our favorite creature: the deadly nw_chicken
    // Note - arrays aren't really attached to the item, but the module, and they
    // are tagged with the objects string representation.
    object oCreature = CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation());
    if (!GetIsObjectValid(oCreature))
    {
        Log("NWNX_Creature test: Failed to create creature");
        return;
    }

    Array_PushBack_Str(array, "BItem1", oCreature);
    Array_PushBack_Str(array, "AItem2", oCreature);
    Array_PushBack_Str(array, "AItem3", oCreature);
    Array_PushBack_Str(array, "BItem2", oCreature);
    Array_Debug_Dump(array, "After Chicken array load", oCreature);

}

void TestNWNXArray() 
{
    Log("");
    Log("Start NWNX_Data test.");
    string array = "test2";

    NWNX_Data_Array_PushBack_Str(GetModule(), array, "XItem1");
    NWNX_Data_Array_PushBack_Str(GetModule(), array, "ZItem2");
    NWNX_Data_Array_PushBack_Str(GetModule(), array, "ZItem3");
    NWNX_Data_Array_PushBack_Str(GetModule(), array, "XItem2");
    Array_Debug_Dump(array, "After first load");

    int foo = NWNX_Data_Array_Find_Str(GetModule(), array, "ZItem3");
    Log("Found element AItem3 at index = " + IntToString(foo));

    NWNX_Data_Array_Set_Str(GetModule(), array, 2, "Suck it up...");
    Array_Debug_Dump(array, "After set 2 = 'Suck it up...'");

    NWNX_Data_Array_Erase(NWNX_DATA_TYPE_STRING, GetModule(), array, 1);
    Array_Debug_Dump(array, "After delete 1");

    NWNX_Data_Array_PushBack_Str(GetModule(), array, "MItem1");
    NWNX_Data_Array_PushBack_Str(GetModule(), array, "QItem2");
    NWNX_Data_Array_PushBack_Str(GetModule(), array, "NItem3");
    NWNX_Data_Array_PushBack_Str(GetModule(), array, "KItem2");

    Array_Debug_Dump(array, "After add more");
    NWNX_Data_Array_SortAscending(NWNX_DATA_TYPE_STRING, GetModule(), array);

    Array_Debug_Dump(array, "After sort");

}

// Uncomment and assign to some event click.
/* */
void main() 
{
    Log("Start");

    TestArrayOnModule();

    TestArrayOnChicken();

    TestNWNXArray();
}
/* */
