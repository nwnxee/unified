/// @addtogroup data Data
/// @brief Provides a number of data structures for NWN code to use (simulated arrays)
/// @{
/// @file nwnx_data.nss
#include "nwnx"

const string NWNX_Data = "NWNX_Data"; ///< @private

const int NWNX_DATA_INVALID_INDEX = -1;
const int NWNX_DATA_TYPE_FLOAT = 0;
const int NWNX_DATA_TYPE_INTEGER = 1;
const int NWNX_DATA_TYPE_OBJECT = 2;
const int NWNX_DATA_TYPE_STRING = 3;

/// @defgroup data_array_at Array At
/// @brief Returns the element at the index.
/// @ingroup data
/// @param obj The object.
/// @param tag The tag.
/// @param index The index.
/// @return The element of associated type.
/// @{
float NWNX_Data_Array_At_Flt(object obj, string tag, int index);
int NWNX_Data_Array_At_Int(object obj, string tag, int index);
object NWNX_Data_Array_At_Obj(object obj, string tag, int index);
string NWNX_Data_Array_At_Str(object obj, string tag, int index);
/// @}


/// Clears the entire array, such that size==0.
void NWNX_Data_Array_Clear(int type, object obj, string tag);

/// @defgroup data_array_contains Array Contains
/// @brief Checks if array contains the element.
/// @ingroup data
/// @param obj The object.
/// @param tag The tag.
/// @param element The element.
/// @return TRUE if the collection contains the element.
/// @{
int NWNX_Data_Array_Contains_Flt(object obj, string tag, float element);
int NWNX_Data_Array_Contains_Int(object obj, string tag, int element);
int NWNX_Data_Array_Contains_Obj(object obj, string tag, object element);
int NWNX_Data_Array_Contains_Str(object obj, string tag, string element);
/// @}

/// Copies the array of name otherTag over the array of name tag.
void NWNX_Data_Array_Copy(int type, object obj, string tag, string otherTag);

/// Erases the element at index, and shuffles any elements from index size-1 to index + 1 left.
void NWNX_Data_Array_Erase(int type, object obj, string tag, int index);

/// @defgroup data_array_find Array Find
/// @brief Get the index at which the element is located.
/// @ingroup data
/// @param obj The object.
/// @param tag The tag.
/// @param element The element.
/// @return Returns the index at which the element is located, or ARRAY_INVALID_INDEX.
/// @{
int NWNX_Data_Array_Find_Flt(object obj, string tag, float element);
int NWNX_Data_Array_Find_Int(object obj, string tag, int element);
int NWNX_Data_Array_Find_Obj(object obj, string tag, object element);
int NWNX_Data_Array_Find_Str(object obj, string tag, string element);
/// @}

/// @defgroup data_array_insert Array Insert
/// @brief Inserts the element at the index, where size > index >= 0.
/// @ingroup data
/// @param obj The object.
/// @param tag The tag.
/// @param index The index.
/// @param element The element.
/// @{
void NWNX_Data_Array_Insert_Flt(object obj, string tag, int index, float element);
void NWNX_Data_Array_Insert_Int(object obj, string tag, int index, int element);
void NWNX_Data_Array_Insert_Obj(object obj, string tag, int index, object element);
void NWNX_Data_Array_Insert_Str(object obj, string tag, int index, string element);
/// @}

/// @defgroup data_array_pushback Array Pushback
/// @brief Pushes an element to the back of the collection.
/// @remark Functionally identical to an insert at index size-1.
/// @ingroup data
/// @param obj The object.
/// @param tag The tag.
/// @param element The element.
/// @{
void NWNX_Data_Array_PushBack_Flt(object obj, string tag, float element);
void NWNX_Data_Array_PushBack_Int(object obj, string tag, int element);
void NWNX_Data_Array_PushBack_Obj(object obj, string tag, object element);
void NWNX_Data_Array_PushBack_Str(object obj, string tag, string element);
/// @}

/// Resizes the array. If the array is shrinking, it chops off elements at the ned.
void NWNX_Data_Array_Resize(int type, object obj, string tag, int size);

/// Reorders the array such each possible permutation of elements has equal probability of appearance.
void NWNX_Data_Array_Shuffle(int type, object obj, string tag);

/// Returns the size of the array.
int NWNX_Data_Array_Size(int type, object obj, string tag);

/// Sorts the collection based on descending order.
void NWNX_Data_Array_SortAscending(int type, object obj, string tag);

/// Sorts the collection based on descending order.
void NWNX_Data_Array_SortDescending(int type, object obj, string tag);

/// @defgroup data_array_set Array Set
/// @brief Sets the element at the index, where size > index >= 0.
/// @ingroup data
/// @param obj The object.
/// @param tag The tag.
/// @param index The index.
/// @param element The element.
/// @{
void NWNX_Data_Array_Set_Flt(object obj, string tag, int index, float element);
void NWNX_Data_Array_Set_Int(object obj, string tag, int index, int element);
void NWNX_Data_Array_Set_Obj(object obj, string tag, int index, object element);
void NWNX_Data_Array_Set_Str(object obj, string tag, int index, string element);
/// @}

/// @}

float NWNX_Data_Array_At_Flt(object obj, string tag, int index)
{
    string sFunc = "ArrayAt";
    NWNX_PushArgumentInt(NWNX_Data, sFunc, index);
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, NWNX_DATA_TYPE_FLOAT);
    NWNX_CallFunction(NWNX_Data, sFunc);
    return NWNX_GetReturnValueFloat(NWNX_Data, sFunc);
}

int NWNX_Data_Array_At_Int(object obj, string tag, int index)
{
    string sFunc = "ArrayAt";
    NWNX_PushArgumentInt(NWNX_Data, sFunc, index);
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, NWNX_DATA_TYPE_INTEGER);
    NWNX_CallFunction(NWNX_Data, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Data, sFunc);
}

object NWNX_Data_Array_At_Obj(object obj, string tag, int index)
{
    string sFunc = "ArrayAt";
    NWNX_PushArgumentInt(NWNX_Data, sFunc, index);
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, NWNX_DATA_TYPE_OBJECT);
    NWNX_CallFunction(NWNX_Data, sFunc);
    return NWNX_GetReturnValueObject(NWNX_Data, sFunc);
}

string NWNX_Data_Array_At_Str(object obj, string tag, int index)
{
    string sFunc = "ArrayAt";
    NWNX_PushArgumentInt(NWNX_Data, sFunc, index);
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, NWNX_DATA_TYPE_STRING);
    NWNX_CallFunction(NWNX_Data, sFunc);
    return NWNX_GetReturnValueString(NWNX_Data, sFunc);
}

void NWNX_Data_Array_Clear(int type, object obj, string tag)
{
    string sFunc = "ArrayClear";
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, type);
    NWNX_CallFunction(NWNX_Data, sFunc);
}

int NWNX_Data_Array_Contains_Flt(object obj, string tag, float element)
{
    string sFunc = "ArrayContains";
    NWNX_PushArgumentFloat(NWNX_Data, sFunc, element);
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, NWNX_DATA_TYPE_FLOAT);
    NWNX_CallFunction(NWNX_Data, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Data, sFunc);
}

int NWNX_Data_Array_Contains_Int(object obj, string tag, int element)
{
    string sFunc = "ArrayContains";
    NWNX_PushArgumentInt(NWNX_Data, sFunc, element);
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, NWNX_DATA_TYPE_INTEGER);
    NWNX_CallFunction(NWNX_Data, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Data, sFunc);
}

int NWNX_Data_Array_Contains_Obj(object obj, string tag, object element)
{
    string sFunc = "ArrayContains";
    NWNX_PushArgumentObject(NWNX_Data, sFunc, element);
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, NWNX_DATA_TYPE_OBJECT);
    NWNX_CallFunction(NWNX_Data, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Data, sFunc);
}

int NWNX_Data_Array_Contains_Str(object obj, string tag, string element)
{
    string sFunc = "ArrayContains";
    NWNX_PushArgumentString(NWNX_Data, sFunc, element);
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, NWNX_DATA_TYPE_STRING);
    NWNX_CallFunction(NWNX_Data, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Data, sFunc);
}

void NWNX_Data_Array_Copy(int type, object obj, string tag, string otherTag)
{
    string sFunc = "ArrayCopy";
    NWNX_PushArgumentString(NWNX_Data, sFunc, otherTag);
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, type);
    NWNX_CallFunction(NWNX_Data, sFunc);
}

void NWNX_Data_Array_Erase(int type, object obj, string tag, int index)
{
    string sFunc = "ArrayErase";
    NWNX_PushArgumentInt(NWNX_Data, sFunc, index);
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, type);
    NWNX_CallFunction(NWNX_Data, sFunc);
}

int NWNX_Data_Array_Find_Flt(object obj, string tag, float element)
{
    string sFunc = "ArrayFind";
    NWNX_PushArgumentFloat(NWNX_Data, sFunc, element);
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, NWNX_DATA_TYPE_FLOAT);
    NWNX_CallFunction(NWNX_Data, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Data, sFunc);
}

int NWNX_Data_Array_Find_Int(object obj, string tag, int element)
{
    string sFunc = "ArrayFind";
    NWNX_PushArgumentInt(NWNX_Data, sFunc, element);
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, NWNX_DATA_TYPE_INTEGER);
    NWNX_CallFunction(NWNX_Data, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Data, sFunc);
}

int NWNX_Data_Array_Find_Obj(object obj, string tag, object element)
{
    string sFunc = "ArrayFind";
    NWNX_PushArgumentObject(NWNX_Data, sFunc, element);
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, NWNX_DATA_TYPE_OBJECT);
    NWNX_CallFunction(NWNX_Data, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Data, sFunc);
}

int NWNX_Data_Array_Find_Str(object obj, string tag, string element)
{
    string sFunc = "ArrayFind";
    NWNX_PushArgumentString(NWNX_Data, sFunc, element);
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, NWNX_DATA_TYPE_STRING);
    NWNX_CallFunction(NWNX_Data, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Data, sFunc);
}

void NWNX_Data_Array_Insert_Flt(object obj, string tag, int index, float element)
{
    string sFunc = "ArrayInsert";
    NWNX_PushArgumentFloat(NWNX_Data, sFunc, element);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, index);
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, NWNX_DATA_TYPE_FLOAT);
    NWNX_CallFunction(NWNX_Data, sFunc);
}

void NWNX_Data_Array_Insert_Int(object obj, string tag, int index, int element)
{
    string sFunc = "ArrayInsert";
    NWNX_PushArgumentInt(NWNX_Data, sFunc, element);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, index);
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, NWNX_DATA_TYPE_INTEGER);
    NWNX_CallFunction(NWNX_Data, sFunc);
}

void NWNX_Data_Array_Insert_Obj(object obj, string tag, int index, object element)
{
    string sFunc = "ArrayInsert";
    NWNX_PushArgumentObject(NWNX_Data, sFunc, element);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, index);
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, NWNX_DATA_TYPE_OBJECT);
    NWNX_CallFunction(NWNX_Data, sFunc);
}

void NWNX_Data_Array_Insert_Str(object obj, string tag, int index, string element)
{
    string sFunc = "ArrayInsert";
    NWNX_PushArgumentString(NWNX_Data, sFunc, element);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, index);
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, NWNX_DATA_TYPE_STRING);
    NWNX_CallFunction(NWNX_Data, sFunc);
}

void NWNX_Data_Array_PushBack_Flt(object obj, string tag, float element)
{
    string sFunc = "ArrayPushBack";
    NWNX_PushArgumentFloat(NWNX_Data, sFunc, element);
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, NWNX_DATA_TYPE_FLOAT);
    NWNX_CallFunction(NWNX_Data, sFunc);
}

void NWNX_Data_Array_PushBack_Int(object obj, string tag, int element)
{
    string sFunc = "ArrayPushBack";
    NWNX_PushArgumentInt(NWNX_Data, sFunc, element);
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, NWNX_DATA_TYPE_INTEGER);
    NWNX_CallFunction(NWNX_Data, sFunc);
}

void NWNX_Data_Array_PushBack_Obj(object obj, string tag, object element)
{
    string sFunc = "ArrayPushBack";
    NWNX_PushArgumentObject(NWNX_Data, sFunc, element);
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, NWNX_DATA_TYPE_OBJECT);
    NWNX_CallFunction(NWNX_Data, sFunc);
}

void NWNX_Data_Array_PushBack_Str(object obj, string tag, string element)
{
    string sFunc = "ArrayPushBack";
    NWNX_PushArgumentString(NWNX_Data, sFunc, element);
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, NWNX_DATA_TYPE_STRING);
    NWNX_CallFunction(NWNX_Data, sFunc);
}

void NWNX_Data_Array_Resize(int type, object obj, string tag, int size)
{
    string sFunc = "ArrayResize";
    NWNX_PushArgumentInt(NWNX_Data, sFunc, size);
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, type);
    NWNX_CallFunction(NWNX_Data, sFunc);
}

void NWNX_Data_Array_Shuffle(int type, object obj, string tag)
{
    string sFunc = "ArrayShuffle";
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, type);
    NWNX_CallFunction(NWNX_Data, sFunc);
}

int NWNX_Data_Array_Size(int type, object obj, string tag)
{
    string sFunc = "ArraySize";
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, type);
    NWNX_CallFunction(NWNX_Data, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Data, sFunc);
}

void NWNX_Data_Array_SortAscending(int type, object obj, string tag)
{
    string sFunc = "ArraySortAscending";
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, type);
    NWNX_CallFunction(NWNX_Data, sFunc);
}

void NWNX_Data_Array_SortDescending(int type, object obj, string tag)
{
    string sFunc = "ArraySortDescending";
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, type);
    NWNX_CallFunction(NWNX_Data, sFunc);
}

void NWNX_Data_Array_Set_Flt(object obj, string tag, int index, float element)
{
    string sFunc = "ArraySet";
    NWNX_PushArgumentFloat(NWNX_Data, sFunc, element);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, index);
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, NWNX_DATA_TYPE_FLOAT);
    NWNX_CallFunction(NWNX_Data, sFunc);
}

void NWNX_Data_Array_Set_Int(object obj, string tag, int index, int element)
{
    string sFunc = "ArraySet";
    NWNX_PushArgumentInt(NWNX_Data, sFunc, element);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, index);
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, NWNX_DATA_TYPE_INTEGER);
    NWNX_CallFunction(NWNX_Data, sFunc);
}

void NWNX_Data_Array_Set_Obj(object obj, string tag, int index, object element)
{
    string sFunc = "ArraySet";
    NWNX_PushArgumentObject(NWNX_Data, sFunc, element);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, index);
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data,sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, NWNX_DATA_TYPE_OBJECT);
    NWNX_CallFunction(NWNX_Data, sFunc);
}

void NWNX_Data_Array_Set_Str(object obj, string tag, int index, string element)
{
    string sFunc = "ArraySet";
    NWNX_PushArgumentString(NWNX_Data, sFunc, element);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, index);
    NWNX_PushArgumentString(NWNX_Data, sFunc, tag);
    NWNX_PushArgumentObject(NWNX_Data, sFunc, obj);
    NWNX_PushArgumentInt(NWNX_Data, sFunc, NWNX_DATA_TYPE_STRING);
    NWNX_CallFunction(NWNX_Data, sFunc);
}
