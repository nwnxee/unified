/// @addtogroup data Data
/// @brief Provides a number of data structures for NWN code to use (simulated arrays)
/// @{
/// @file nwnx_data.nss

const int INVALID_INDEX = -1;
const int TYPE_FLOAT = 0;
const int TYPE_INTEGER = 1;
const int TYPE_OBJECT = 2;
const int TYPE_STRING = 3;

/// @defgroup data_array_at Array At
/// @brief Returns the element at the index.
/// @ingroup data
/// @param obj The object.
/// @param tag The tag.
/// @param index The index.
/// @return The element of associated type.
/// @{
string Array_At_Str(string tag, int index, object obj=OBJECT_INVALID);
float  Array_At_Flt(string tag, int index, object obj=OBJECT_INVALID);
int    Array_At_Int(string tag, int index, object obj=OBJECT_INVALID);
object Array_At_Obj(string tag, int index, object obj=OBJECT_INVALID);
/// @}


/// Clears the entire array, such that size==0.
void Array_Clear(string tag, object obj=OBJECT_INVALID);

/// @defgroup data_array_contains Array Contains
/// @brief Checks if array contains the element.
/// @ingroup data
/// @param obj The object.
/// @param tag The tag.
/// @param element The element.
/// @return TRUE if the collection contains the element.
/// @{
int Array_Contains_Flt(string tag, float  element, object obj=OBJECT_INVALID);
int Array_Contains_Int(string tag, int    element, object obj=OBJECT_INVALID);
int Array_Contains_Obj(string tag, object element, object obj=OBJECT_INVALID);
int Array_Contains_Str(string tag, string element, object obj=OBJECT_INVALID);
/// @}

/// Copies the array of name otherTag over the array of name tag.
void Array_Copy(string tag, string otherTag, object obj=OBJECT_INVALID);

/// Erases the element at index, and shuffles any elements from index size-1 to index + 1 left.
void Array_Erase(string tag, int index, object obj=OBJECT_INVALID);

/// @defgroup data_array_find Array Find
/// @brief Get the index at which the element is located.
/// @ingroup data
/// @param obj The object.
/// @param tag The tag.
/// @param element The element.
/// @return Returns the index at which the element is located, or ARRAY_INVALID_INDEX.
/// @{
int Array_Find_Flt(string tag, float  element, object obj=OBJECT_INVALID);
int Array_Find_Int(string tag, int    element, object obj=OBJECT_INVALID);
int Array_Find_Obj(string tag, object element, object obj=OBJECT_INVALID);
int Array_Find_Str(string tag, string element, object obj=OBJECT_INVALID);
/// @}

/// @defgroup data_array_insert Array Insert
/// @brief Inserts the element at the index, where size > index >= 0.
/// @ingroup data
/// @param obj The object.
/// @param tag The tag.
/// @param index The index.
/// @param element The element.
/// @{
void Array_Insert_Flt(string tag, int index, float  element, object obj=OBJECT_INVALID);
void Array_Insert_Int(string tag, int index, int    element, object obj=OBJECT_INVALID);
void Array_Insert_Obj(string tag, int index, object element, object obj=OBJECT_INVALID);
void Array_Insert_Str(string tag, int index, string element, object obj=OBJECT_INVALID);
/// @}

/// @defgroup data_array_pushback Array Pushback
/// @brief Pushes an element to the back of the collection.
/// @remark Functionally identical to an insert at index size-1.
/// @ingroup data
/// @param obj The object.
/// @param tag The tag.
/// @param element The element.
/// @{
void Array_PushBack_Flt(string tag, float  element, object obj=OBJECT_INVALID);
void Array_PushBack_Int(string tag, int    element, object obj=OBJECT_INVALID);
void Array_PushBack_Obj(string tag, object element, object obj=OBJECT_INVALID);
void Array_PushBack_Str(string tag, string element, object obj=OBJECT_INVALID);
/// @}

/// Resizes the array. If the array is shrinking, it chops off elements at the ned.
void Array_Resize(string tag, int size, object obj=OBJECT_INVALID);

/// Reorders the array such each possible permutation of elements has equal probability of appearance.
void Array_Shuffle(string tag, object obj=OBJECT_INVALID);

/// Returns the size of the array.
int Array_Size(string tag, object obj=OBJECT_INVALID);

/// Sorts the collection based on descending order.
void Array_SortAscending(string tag, int type=TYPE_STRING, object obj=OBJECT_INVALID);

/// Sorts the collection based on descending order.
void Array_SortDescending(string tag, int type=TYPE_STRING, object obj=OBJECT_INVALID);

/// @defgroup data_array_set Array Set
/// @brief Sets the element at the index, where size > index >= 0.
/// @ingroup data
/// @param obj The object.
/// @param tag The tag.
/// @param index The index.
/// @param element The element.
/// @{
void Array_Set_Flt(string tag, int index, float  element, object obj=OBJECT_INVALID);
void Array_Set_Int(string tag, int index, int    element, object obj=OBJECT_INVALID);
void Array_Set_Obj(string tag, int index, object element, object obj=OBJECT_INVALID);
void Array_Set_Str(string tag, int index, string element, object obj=OBJECT_INVALID);
/// @}

/// @}

//
// Local Utility Functions.
//
string GetTableName(string tag, object obj=OBJECT_INVALID) {
    if (obj == OBJECT_INVALID)
        obj = GetModule();
    return "array_" + ObjectToString(obj) + "_" + tag;
}

string GetTableCreateString(string tag, object obj=OBJECT_INVALID) {
    if (obj == OBJECT_INVALID)
        obj = GetModule();
    // for simplicy sake, everything is turned into a string.  Possible enhancement
    // to create specific tables for int/float/whatever.
    return "CREATE TABLE IF NOT EXISTS " + GetTableName(tag, obj) + " ( ind INTEGER PRIMARY KEY, value TEXT)";
}

int TableExists(string tag, object obj=OBJECT_INVALID) {
    if (obj == OBJECT_INVALID)
        obj = GetModule();
    string stmt = "SELECT name FROM sqlite_master WHERE type = 'table' AND name = '" + GetTableName(tag, obj) + "'";
    sqlquery sqlQuery = SqlPrepareQueryObject(GetModule(), stmt);
    return SqlStep(sqlQuery);
}

void ExecuteStatement(string statement, object obj=OBJECT_INVALID) {
    if (obj == OBJECT_INVALID)
        obj = GetModule();
    // There's no direct "execute this.."  everything has to be prepared then executed.
    //WriteTimestampedLogEntry("SQL: " + statement);
    sqlquery sqlQuery = SqlPrepareQueryObject(GetModule(), statement);
    SqlStep(sqlQuery);
}

void CreateArrayTable(string tag, object obj=OBJECT_INVALID) {
    if (obj == OBJECT_INVALID)
        obj = GetModule();
    string createStatement = GetTableCreateString(tag, obj);
    ExecuteStatement(createStatement, obj);
}

// Get the table row count.  Returns -1 on error (0 is a valid number of rows in a table)
int GetRowCount(string tag, object obj=OBJECT_INVALID) {
    if (obj == OBJECT_INVALID)
        obj = GetModule();
    CreateArrayTable(tag, obj);
    string stmt = "SELECT COUNT(1) FROM " + GetTableName(tag, obj);
    sqlquery sqlQuery = SqlPrepareQueryObject(GetModule(), stmt);
    if ( SqlStep(sqlQuery) ) {
        return SqlGetInt(sqlQuery, 0);
    }
    return -1;
}


////////////////////////////////////////////////////////////////////////////////
// return the value contained in location "index"
string Array_At_Str(string tag, int index, object obj=OBJECT_INVALID)
{
    if (obj == OBJECT_INVALID)
        obj = GetModule();
    if (!TableExists(tag, obj)) {
        CreateArrayTable(tag, obj);
    }
    string stmt = "SELECT value FROM "+GetTableName(tag, obj)+" WHERE ind = @ind";
    sqlquery sqlQuery = SqlPrepareQueryObject(GetModule(), stmt);
    if ( SqlStep(sqlQuery) ) {
        return SqlGetString(sqlQuery, 0);
    }
    return "";
}

float Array_At_Flt(string tag, int index, object obj=OBJECT_INVALID)
{
    string st = Array_At_Str(tag, index, obj);
    if (st == "") {
        return 0.0;
    }
    return StringToFloat(st);
}

int Array_At_Int(string tag, int index, object obj=OBJECT_INVALID)
{
    string st = Array_At_Str(tag, index, obj);
    if (st == "") {
        return 0;
    }
    return StringToInt(st);
}

object Array_At_Obj(string tag, int index, object obj=OBJECT_INVALID)
{
    string st = Array_At_Str(tag, index, obj);
    if (st == "") {
        return OBJECT_INVALID;
    }
    return StringToObject(st);
}

void Array_Clear(string tag, object obj=OBJECT_INVALID)
{
    ExecuteStatement("delete from "+GetTableName(tag, obj), obj);
}

////////////////////////////////////////////////////////////////////////////////
// Return true/value (1/0) if the array contains the value "element"
int Array_Contains_Str(string tag, string element, object obj=OBJECT_INVALID)
{
    if (obj == OBJECT_INVALID)
        obj = GetModule();
    WriteTimestampedLogEntry("looking for " + element + " in " + GetTableName(tag, obj));
    CreateArrayTable(tag, obj);
    string stmt = "SELECT COUNT(1) FROM "+GetTableName(tag, obj)+" WHERE value = @element";
    string v = "";
    sqlquery sqlQuery = SqlPrepareQueryObject(GetModule(), stmt);
    //WriteTimestampedLogEntry("Error returned: " + SqlGetError(sqlQuery));
    SqlBindString(sqlQuery, "@element", element);
    //WriteTimestampedLogEntry("Error returned: " + SqlGetError(sqlQuery));

    //WriteTimestampedLogEntry("SQL: " + stmt);
    int pos = -1;
    if ( SqlStep(sqlQuery) ) {
        pos = SqlGetInt(sqlQuery, 0);
        //WriteTimestampedLogEntry("Return value was " + IntToString(pos));
        if (pos > 0) {
            return TRUE;
        }
    }
    return FALSE;
}

int Array_Contains_Flt(string tag, float element, object obj=OBJECT_INVALID)
{
    return Array_Contains_Str(tag, FloatToString(element), obj);
}

int Array_Contains_Int(string tag, int element, object obj=OBJECT_INVALID)
{
    return Array_Contains_Str(tag, IntToString(element), obj);
}

int Array_Contains_Obj(string tag, object element, object obj=OBJECT_INVALID)
{
    return Array_Contains_Str(tag, ObjectToString(element), obj);
}


////////////////////////////////////////////////////////////////////////////////
void Array_Copy(string tag, string otherTag, object obj=OBJECT_INVALID)
{
    if (obj == OBJECT_INVALID)
        obj = GetModule();
    CreateArrayTable(otherTag, obj);
    ExecuteStatement("insert into "+GetTableName(otherTag, obj)+" select * from "+GetTableName(tag, obj), obj);
}

////////////////////////////////////////////////////////////////////////////////
void Array_Erase(string tag, int index, object obj=OBJECT_INVALID)
{
    if (obj == OBJECT_INVALID)
        obj = GetModule();
    ExecuteStatement("DELETE FROM "+GetTableName(tag, obj)+" WHERE ind = " + IntToString(index), obj);
    ExecuteStatement("UPDATE "+GetTableName(tag, obj)+" SET ind = ind - 1 WHERE ind > " + IntToString(index), obj);
}

////////////////////////////////////////////////////////////////////////////////
// return the index in the array containing "element"
// if not found, return INVALID_INDEX
int Array_Find_Str(string tag, string element, object obj=OBJECT_INVALID)
{
    if (obj == OBJECT_INVALID)
        obj = GetModule();
    int tmp = -1;
    string stmt = "SELECT MIN(ind) FROM "+GetTableName(tag, obj)+" WHERE value = @element";
    sqlquery sqlQuery = SqlPrepareQueryObject(GetModule(), stmt);
    SqlBindString(sqlQuery, "@element", element);
    if ( SqlStep(sqlQuery) ) {
        tmp = SqlGetInt(sqlQuery, 0);
        WriteTimestampedLogEntry("Returned value = " + IntToString(tmp));
        return tmp;
    }
    return INVALID_INDEX;
}

int Array_Find_Flt(string tag, float element, object obj=OBJECT_INVALID)
{
    return Array_Find_Str(tag, FloatToString(element), obj);
}

int Array_Find_Int(string tag, int element, object obj=OBJECT_INVALID)
{
    return Array_Find_Str(tag, IntToString(element), obj);
}

int Array_Find_Obj(string tag, object element, object obj=OBJECT_INVALID)
{
    return Array_Find_Str(tag, ObjectToString(element), obj);
}

////////////////////////////////////////////////////////////////////////////////
// Insert a new element into position 'index'.  If index is beyond the number of rows in the array,
// this will quietly fail.  This could be changed if you wanted to support sparse
// arrays.
void Array_Insert_Str(string tag, int index, string element, object obj=OBJECT_INVALID)
{
    int rows = GetRowCount(tag, obj);
    if (obj == OBJECT_INVALID)
        obj = GetModule();
    if (index < rows) {
        ExecuteStatement("UPDATE "+GetTableName(tag, obj)+" SET ind = ind + 1 WHERE ind >= "+IntToString(index), obj);
        ExecuteStatement("INSERT INTO "+GetTableName(tag, obj)+" VALUES ( " + IntToString(index) + ", '" + element + "')", obj);
    }
}

void Array_Insert_Flt(string tag, int index, float element, object obj=OBJECT_INVALID)
{
    Array_Insert_Str(tag, index, FloatToString(element), obj);
}

void Array_Insert_Int(string tag, int index, int element, object obj=OBJECT_INVALID)
{
    Array_Insert_Str(tag, index, IntToString(element), obj);
}

void Array_Insert_Obj(string tag, int index, object element, object obj=OBJECT_INVALID)
{
    Array_Insert_Str(tag, index, ObjectToString(element), obj);
}

////////////////////////////////////////////////////////////////////////////////
// Insert a new element at the end of the array.
void Array_PushBack_Str(string tag, string element, object obj=OBJECT_INVALID)
{
    if (obj == OBJECT_INVALID)
        obj = GetModule();
    int rowCount = GetRowCount(tag, obj);
    ExecuteStatement("INSERT INTO "+GetTableName(tag, obj)+" VALUES ( " + IntToString(rowCount) + ", '" + element + "')", obj);
}

void Array_PushBack_Flt(string tag, float element, object obj=OBJECT_INVALID)
{
    Array_PushBack_Str(tag, FloatToString(element), obj);
}

void Array_PushBack_Int(string tag, int element, object obj=OBJECT_INVALID)
{
    Array_PushBack_Str(tag, IntToString(element), obj);
}

void Array_PushBack_Obj(string tag, object element, object obj=OBJECT_INVALID)
{
    Array_PushBack_Str(tag, ObjectToString(element), obj);
}

////////////////////////////////////////////////////////////////////////////////
// Cuts the array off at size 'size'.  Elements beyond size are removed.
void Array_Resize(string tag, int size, object obj=OBJECT_INVALID)
{
    if (obj == OBJECT_INVALID)
        obj = GetModule();
    ExecuteStatement("delete from "+GetTableName(tag, obj)+" where ind >= " + IntToString(size), obj);
}

////////////////////////////////////////////////////////////////////////////////
void Array_Shuffle(string tag, object obj=OBJECT_INVALID)
{
    if (obj == OBJECT_INVALID)
        obj = GetModule();

    string table = GetTableName(tag, obj);
    ExecuteStatement("CREATE TABLE " +table+ "_temp AS SELECT ROW_NUMBER() OVER(ORDER BY RANDOM())-1, value FROM " +table, obj);
    ExecuteStatement("DELETE FROM " +table , obj);
    ExecuteStatement("INSERT INTO " +table+ " SELECT * FROM " +table+ "_temp", obj);
    ExecuteStatement("DROP TABLE " +table+ "_TEMP", obj);
}

////////////////////////////////////////////////////////////////////////////////
int Array_Size(string tag, object obj=OBJECT_INVALID)
{
    return GetRowCount(tag, obj);
}

////////////////////////////////////////////////////////////////////////////////
// Sort the array by value according to 'direciton' (ASC or DESC)
// Note that this is a lexical sort, so sorting an array of ints or floats will have
// odd results
void Array_Sort(string tag, string direction, int type, object obj=OBJECT_INVALID)
{
    string table = GetTableName(tag, obj);
    if (obj == OBJECT_INVALID)
        obj = GetModule();

    // default orderBy for strings.
    string orderBy = "ORDER BY value " + direction;
    switch(type) {
        case TYPE_INTEGER:
            orderBy = "ORDER BY CAST(value AS INTEGER)" + direction;
            break;
        case TYPE_FLOAT:
            orderBy = "ORDER BY CAST(value AS DECIMAL)" + direction;
            break;
    }
    ExecuteStatement("CREATE TABLE " +table+  "_temp AS SELECT ROW_NUMBER() OVER(" + orderBy + ")-1, value FROM " +table, obj);
    ExecuteStatement("DELETE FROM " +table, obj);
    ExecuteStatement("INSERT INTO " +table+ " SELECT * FROM " +table+ "_temp", obj);
    ExecuteStatement("DROP TABLE " +table+ "_temp", obj);
}

void Array_SortAscending(string tag, int type=TYPE_STRING, object obj=OBJECT_INVALID)
{
    Array_Sort(tag, "ASC", type, obj);
}

void Array_SortDescending(string tag, int type=TYPE_STRING, object obj=OBJECT_INVALID)
{
    Array_Sort(tag, "DESC", type, obj);
}

////////////////////////////////////////////////////////////////////////////////
// Set the value of array index 'index' to a 'element'
// This will quietly eat values if index > array size
void Array_Set_Str(string tag, int index, string element, object obj=OBJECT_INVALID)
{
     if (obj == OBJECT_INVALID)
        obj = GetModule();
    int rows = GetRowCount(tag, obj);
    if (index < rows) {
        ExecuteStatement("UPDATE "+GetTableName(tag, obj)+" SET value = '"+element+"' WHERE ind = "+IntToString(index), obj);
    }
}

void Array_Set_Flt(string tag, int index, float element, object obj=OBJECT_INVALID)
{
    Array_Set_Str(tag, index, FloatToString(element), obj);
}

void Array_Set_Int(string tag, int index, int element, object obj=OBJECT_INVALID)
{
    Array_Set_Str(tag, index, IntToString(element), obj);
}

void Array_Set_Obj(string tag, int index, object element, object obj=OBJECT_INVALID)
{
    Array_Set_Str(tag, index, ObjectToString(element), obj);
}

void Array_Debug_Dump(string tag, string title = "xxx", object obj=OBJECT_INVALID) {
    if (title != "xxx") {
        WriteTimestampedLogEntry("== " + title + " ======================================");
    }
    WriteTimestampedLogEntry("Table name = " + GetTableName(tag, obj));
    string stmt = "SELECT ind, value FROM " + GetTableName(tag, obj);
    sqlquery sqlQuery = SqlPrepareQueryObject(GetModule(), stmt);
    int    ind = -1;
    string value = "";
    while ( SqlStep(sqlQuery) ) {
        ind = SqlGetInt(sqlQuery, 0);
        value = SqlGetString(sqlQuery, 1);
        WriteTimestampedLogEntry(tag + "[" + IntToString(ind) + "] = " + value);
    }
}


