#include "nwnx"

const int NWNX_DATA_INVALID_INDEX = -1;
const int NWNX_DATA_TYPE_FLOAT = 0;
const int NWNX_DATA_TYPE_INTEGER = 1;
const int NWNX_DATA_TYPE_OBJECT = 2;
const int NWNX_DATA_TYPE_STRING = 3;

// ------ ARRAY API ------

// Returns the element at the index.
float NWNX_Data_Array_At_Flt(object obj, string tag, int index);
int NWNX_Data_Array_At_Int(object obj, string tag, int index);
object NWNX_Data_Array_At_Obj(object obj, string tag, int index);
string NWNX_Data_Array_At_Str(object obj, string tag, int index);

// Clears the entire array, such that size==0.
void NWNX_Data_Array_Clear(int type, object obj, string tag);

// Returns TRUE if the collection contains the element.
int NWNX_Data_Array_Contains_Flt(object obj, string tag, float element);
int NWNX_Data_Array_Contains_Int(object obj, string tag, int element);
int NWNX_Data_Array_Contains_Obj(object obj, string tag, object element);
int NWNX_Data_Array_Contains_Str(object obj, string tag, string element);

// Copies the array of name otherTag over the array of name tag.
void NWNX_Data_Array_Copy(int type, object obj, string tag, string otherTag);

// Erases the element at index, and shuffles any elements from index size-1 to index + 1 left.
void NWNX_Data_Array_Erase(int type, object obj, string tag, int index);

// Returns the index at which the element is located, or ARRAY_INVALID_INDEX.
int NWNX_Data_Array_Find_Flt(object obj, string tag, float element);
int NWNX_Data_Array_Find_Int(object obj, string tag, int element);
int NWNX_Data_Array_Find_Obj(object obj, string tag, object element);
int NWNX_Data_Array_Find_Str(object obj, string tag, string element);

// Inserts the element at the index, where size > index >= 0.
void NWNX_Data_Array_Insert_Flt(object obj, string tag, int index, float element);
void NWNX_Data_Array_Insert_Int(object obj, string tag, int index, int element);
void NWNX_Data_Array_Insert_Obj(object obj, string tag, int index, object element);
void NWNX_Data_Array_Insert_Str(object obj, string tag, int index, string element);

// Pushes an element to the back of the collection.
// Functionally identical to an insert at index size-1.
void NWNX_Data_Array_PushBack_Flt(object obj, string tag, float element);
void NWNX_Data_Array_PushBack_Int(object obj, string tag, int element);
void NWNX_Data_Array_PushBack_Obj(object obj, string tag, object element);
void NWNX_Data_Array_PushBack_Str(object obj, string tag, string element);

// Resizes the array. If the array is shrinking, it chops off elements at the ned.
void NWNX_Data_Array_Resize(int type, object obj, string tag, int size);

// Reorders the array such each possible permutation of elements has equal probability of appearance.
void NWNX_Data_Array_Shuffle(int type, object obj, string tag);

// Returns the size of the array.
int NWNX_Data_Array_Size(int type, object obj, string tag);

// Sorts the collection based on descending order.
void NWNX_Data_Array_SortAscending(int type, object obj, string tag);

// Sorts the collection based on descending order.
void NWNX_Data_Array_SortDescending(int type, object obj, string tag);

//
// ------
//

float NWNX_Data_Array_At_Flt(object obj, string tag, int index)
{
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_AT", index);
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_AT", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_AT", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_AT", NWNX_DATA_TYPE_FLOAT);
    NWNX_CallFunction("NWNX_Data", "ARRAY_AT");
    return NWNX_GetReturnValueFloat("NWNX_Data", "ARRAY_AT");
}

int NWNX_Data_Array_At_Int(object obj, string tag, int index)
{
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_AT", index);
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_AT", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_AT", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_AT", NWNX_DATA_TYPE_INTEGER);
    NWNX_CallFunction("NWNX_Data", "ARRAY_AT");
    return NWNX_GetReturnValueInt("NWNX_Data", "ARRAY_AT");
}

object NWNX_Data_Array_At_Obj(object obj, string tag, int index)
{
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_AT", index);
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_AT", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_AT", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_AT", NWNX_DATA_TYPE_OBJECT);
    NWNX_CallFunction("NWNX_Data", "ARRAY_AT");
    return NWNX_GetReturnValueObject("NWNX_Data", "ARRAY_AT");
}

string NWNX_Data_Array_At_Str(object obj, string tag, int index)
{
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_AT", index);
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_AT", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_AT", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_AT", NWNX_DATA_TYPE_STRING);
    NWNX_CallFunction("NWNX_Data", "ARRAY_AT");
    return NWNX_GetReturnValueString("NWNX_Data", "ARRAY_AT");
}

void NWNX_Data_Array_Clear(int type, object obj, string tag)
{
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_CLEAR", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_CLEAR", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_CLEAR", type);
    NWNX_CallFunction("NWNX_Data", "ARRAY_CLEAR");
}

int NWNX_Data_Array_Contains_Flt(object obj, string tag, float element)
{
    NWNX_PushArgumentFloat("NWNX_Data", "ARRAY_CONTAINS", element);
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_CONTAINS", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_CONTAINS", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_CONTAINS", NWNX_DATA_TYPE_FLOAT);
    NWNX_CallFunction("NWNX_Data", "ARRAY_CONTAINS");
    return NWNX_GetReturnValueInt("NWNX_Data", "ARRAY_CONTAINS");
}

int NWNX_Data_Array_Contains_Int(object obj, string tag, int element)
{
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_CONTAINS", element);
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_CONTAINS", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_CONTAINS", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_CONTAINS", NWNX_DATA_TYPE_INTEGER);
    NWNX_CallFunction("NWNX_Data", "ARRAY_CONTAINS");
    return NWNX_GetReturnValueInt("NWNX_Data", "ARRAY_CONTAINS");
}

int NWNX_Data_Array_Contains_Obj(object obj, string tag, object element)
{
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_CONTAINS", element);
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_CONTAINS", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_CONTAINS", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_CONTAINS", NWNX_DATA_TYPE_OBJECT);
    NWNX_CallFunction("NWNX_Data", "ARRAY_CONTAINS");
    return NWNX_GetReturnValueInt("NWNX_Data", "ARRAY_CONTAINS");
}

int NWNX_Data_Array_Contains_Str(object obj, string tag, string element)
{
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_CONTAINS", element);
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_CONTAINS", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_CONTAINS", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_CONTAINS", NWNX_DATA_TYPE_STRING);
    NWNX_CallFunction("NWNX_Data", "ARRAY_CONTAINS");
    return NWNX_GetReturnValueInt("NWNX_Data", "ARRAY_CONTAINS");
}

void NWNX_Data_Array_Copy(int type, object obj, string tag, string otherTag)
{
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_COPY", otherTag);
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_COPY", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_COPY", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_COPY", type);
    NWNX_CallFunction("NWNX_Data", "ARRAY_COPY");
}

void NWNX_Data_Array_Erase(int type, object obj, string tag, int index)
{
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_ERASE", index);
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_ERASE", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_ERASE", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_ERASE", type);
    NWNX_CallFunction("NWNX_Data", "ARRAY_ERASE");
}

int NWNX_Data_Array_Find_Flt(object obj, string tag, float element)
{
    NWNX_PushArgumentFloat("NWNX_Data", "ARRAY_FIND", element);
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_FIND", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_FIND", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_FIND", NWNX_DATA_TYPE_FLOAT);
    NWNX_CallFunction("NWNX_Data", "ARRAY_FIND");
    return NWNX_GetReturnValueInt("NWNX_Data", "ARRAY_FIND");
}

int NWNX_Data_Array_Find_Int(object obj, string tag, int element)
{
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_FIND", element);
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_FIND", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_FIND", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_FIND", NWNX_DATA_TYPE_INTEGER);
    NWNX_CallFunction("NWNX_Data", "ARRAY_FIND");
    return NWNX_GetReturnValueInt("NWNX_Data", "ARRAY_FIND");
}

int NWNX_Data_Array_Find_Obj(object obj, string tag, object element)
{
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_FIND", element);
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_FIND", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_FIND", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_FIND", NWNX_DATA_TYPE_OBJECT);
    NWNX_CallFunction("NWNX_Data", "ARRAY_FIND");
    return NWNX_GetReturnValueInt("NWNX_Data", "ARRAY_FIND");
}

int NWNX_Data_Array_Find_Str(object obj, string tag, string element)
{
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_FIND", element);
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_FIND", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_FIND", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_FIND", NWNX_DATA_TYPE_STRING);
    NWNX_CallFunction("NWNX_Data", "ARRAY_FIND");
    return NWNX_GetReturnValueInt("NWNX_Data", "ARRAY_FIND");
}

void NWNX_Data_Array_Insert_Flt(object obj, string tag, int index, float element)
{
    NWNX_PushArgumentFloat("NWNX_Data", "ARRAY_INSERT", element);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_INSERT", index);
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_INSERT", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_INSERT", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_INSERT", NWNX_DATA_TYPE_FLOAT);
    NWNX_CallFunction("NWNX_Data", "ARRAY_INSERT");
}

void NWNX_Data_Array_Insert_Int(object obj, string tag, int index, int element)
{
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_INSERT", element);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_INSERT", index);
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_INSERT", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_INSERT", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_INSERT", NWNX_DATA_TYPE_INTEGER);
    NWNX_CallFunction("NWNX_Data", "ARRAY_INSERT");
}

void NWNX_Data_Array_Insert_Obj(object obj, string tag, int index, object element)
{
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_INSERT", element);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_INSERT", index);
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_INSERT", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_INSERT", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_INSERT", NWNX_DATA_TYPE_OBJECT);
    NWNX_CallFunction("NWNX_Data", "ARRAY_INSERT");
}

void NWNX_Data_Array_Insert_Str(object obj, string tag, int index, string element)
{
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_INSERT", element);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_INSERT", index);
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_INSERT", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_INSERT", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_INSERT", NWNX_DATA_TYPE_STRING);
    NWNX_CallFunction("NWNX_Data", "ARRAY_INSERT");
}

void NWNX_Data_Array_PushBack_Flt(object obj, string tag, float element)
{
    NWNX_PushArgumentFloat("NWNX_Data", "ARRAY_PUSH_BACK", element);
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_PUSH_BACK", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_PUSH_BACK", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_PUSH_BACK", NWNX_DATA_TYPE_FLOAT);
    NWNX_CallFunction("NWNX_Data", "ARRAY_PUSH_BACK");
}

void NWNX_Data_Array_PushBack_Int(object obj, string tag, int element)
{
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_PUSH_BACK", element);
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_PUSH_BACK", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_PUSH_BACK", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_PUSH_BACK", NWNX_DATA_TYPE_INTEGER);
    NWNX_CallFunction("NWNX_Data", "ARRAY_PUSH_BACK");
}

void NWNX_Data_Array_PushBack_Obj(object obj, string tag, object element)
{
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_PUSH_BACK", element);
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_PUSH_BACK", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_PUSH_BACK", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_PUSH_BACK", NWNX_DATA_TYPE_OBJECT);
    NWNX_CallFunction("NWNX_Data", "ARRAY_PUSH_BACK");
}

void NWNX_Data_Array_PushBack_Str(object obj, string tag, string element)
{
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_PUSH_BACK", element);
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_PUSH_BACK", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_PUSH_BACK", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_PUSH_BACK", NWNX_DATA_TYPE_STRING);
    NWNX_CallFunction("NWNX_Data", "ARRAY_PUSH_BACK");
}

void NWNX_Data_Array_Resize(int type, object obj, string tag, int size)
{
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_RESIZE", size);
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_RESIZE", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_RESIZE", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_RESIZE", type);
    NWNX_CallFunction("NWNX_Data", "ARRAY_RESIZE");
}

void NWNX_Data_Array_Shuffle(int type, object obj, string tag)
{
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_SHUFFLE", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_SHUFFLE", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_SHUFFLE", type);
    NWNX_CallFunction("NWNX_Data", "ARRAY_SHUFFLE");
}

int NWNX_Data_Array_Size(int type, object obj, string tag)
{
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_SIZE", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_SIZE", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_SIZE", type);
    NWNX_CallFunction("NWNX_Data", "ARRAY_SIZE");
    return NWNX_GetReturnValueInt("NWNX_Data", "ARRAY_SIZE");
}

void NWNX_Data_Array_SortAscending(int type, object obj, string tag)
{
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_SORT_ASCENDING", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_SORT_ASCENDING", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_SORT_ASCENDING", type);
    NWNX_CallFunction("NWNX_Data", "ARRAY_SORT_ASCENDING");
}

void NWNX_Data_Array_SortDescending(int type, object obj, string tag)
{
    NWNX_PushArgumentString("NWNX_Data", "ARRAY_SORT_DESCENDING", tag);
    NWNX_PushArgumentObject("NWNX_Data", "ARRAY_SORT_DESCENDING", obj);
    NWNX_PushArgumentInt("NWNX_Data", "ARRAY_SORT_DESCENDING", type);
    NWNX_CallFunction("NWNX_Data", "ARRAY_SORT_DESCENDING");
}
