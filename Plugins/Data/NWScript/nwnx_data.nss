/// @addtogroup data Data
/// @brief Provides a number of data structures for NWN code to use (simulated arrays)
/// @{
/// @file nwnx_data.nss

#include "inc_array"

// All these calls just pass through to the Array code in inc_array to provide
// an NWNX_Data compatible API for ease of transition.

const int NWNX_DATA_INVALID_INDEX = INVALID_INDEX;
const int NWNX_DATA_TYPE_FLOAT = TYPE_FLOAT;
const int NWNX_DATA_TYPE_INTEGER = TYPE_INTEGER;
const int NWNX_DATA_TYPE_OBJECT = TYPE_OBJECT;
const int NWNX_DATA_TYPE_STRING = TYPE_STRING;

/// @defgroup data_array_at Array At
/// @brief Returns the element at the index.
/// @ingroup data
/// @param obj The object.
/// @param tag The tag.
/// @param index The index.
/// @return The element of associated type.
/// @{
string NWNX_Data_Array_At_Str(object obj, string tag, int index);
float  NWNX_Data_Array_At_Flt(object obj, string tag, int index);
int    NWNX_Data_Array_At_Int(object obj, string tag, int index);
object NWNX_Data_Array_At_Obj(object obj, string tag, int index);
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
int NWNX_Data_Array_Contains_Flt(object obj, string tag, float  element);
int NWNX_Data_Array_Contains_Int(object obj, string tag, int    element);
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
int NWNX_Data_Array_Find_Flt(object obj, string tag, float  element);
int NWNX_Data_Array_Find_Int(object obj, string tag, int    element);
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
void NWNX_Data_Array_Insert_Flt(object obj, string tag, int index, float  element);
void NWNX_Data_Array_Insert_Int(object obj, string tag, int index, int    element);
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
void NWNX_Data_Array_PushBack_Flt(object obj, string tag, float  element);
void NWNX_Data_Array_PushBack_Int(object obj, string tag, int    element);
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
void NWNX_Data_Array_Set_Flt(object obj, string tag, int index, float  element);
void NWNX_Data_Array_Set_Int(object obj, string tag, int index, int    element);
void NWNX_Data_Array_Set_Obj(object obj, string tag, int index, object element);
void NWNX_Data_Array_Set_Str(object obj, string tag, int index, string element);
/// @}

/// @}

////////////////////////////////////////////////////////////////////////////////
// return the value contained in location "index"
string NWNX_Data_Array_At_Str(object obj, string tag, int index)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    return Array_At_Str(tag, index, obj);
}

float NWNX_Data_Array_At_Flt(object obj, string tag, int index)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    return Array_At_Flt(tag, index, obj);
}

int NWNX_Data_Array_At_Int(object obj, string tag, int index)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    return Array_At_Int(tag, index, obj);
}

object NWNX_Data_Array_At_Obj(object obj, string tag, int index)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    return Array_At_Obj(tag, index, obj);
}

void NWNX_Data_Array_Clear(int type, object obj, string tag)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    Array_Clear(tag, obj);
}

////////////////////////////////////////////////////////////////////////////////
// Return true/value (1/0) if the array contains the value "element"
int NWNX_Data_Array_Contains_Str(object obj, string tag, string element)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    return Array_Contains_Str(tag, element, obj);
}

int NWNX_Data_Array_Contains_Flt(object obj, string tag, float element)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    return Array_Contains_Flt(tag, element, obj);
}

int NWNX_Data_Array_Contains_Int(object obj, string tag, int element)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    return Array_Contains_Int(tag, element, obj);
}

int NWNX_Data_Array_Contains_Obj(object obj, string tag, object element)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    return Array_Contains_Obj(tag, element, obj);
}


////////////////////////////////////////////////////////////////////////////////
void NWNX_Data_Array_Copy(int type, object obj, string tag, string otherTag)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    Array_Copy(tag, otherTag, obj);
}

////////////////////////////////////////////////////////////////////////////////
void NWNX_Data_Array_Erase(int type, object obj, string tag, int index)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    Array_Erase(tag, index, obj);
}

////////////////////////////////////////////////////////////////////////////////
// return the index in the array containing "element"
// if not found, return NWNX_DATA_INVALID_INDEX
int NWNX_Data_Array_Find_Str(object obj, string tag, string element)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    return Array_Find_Str(tag, element, obj);
}

int NWNX_Data_Array_Find_Flt(object obj, string tag, float element)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    return Array_Find_Flt(tag, element, obj);
}

int NWNX_Data_Array_Find_Int(object obj, string tag, int element)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    return Array_Find_Int(tag, element, obj);
}

int NWNX_Data_Array_Find_Obj(object obj, string tag, object element)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    return Array_Find_Obj(tag, element, obj);
}

////////////////////////////////////////////////////////////////////////////////
// Insert a new element into position 'index'.  If index is beyond the number of rows in the array,
// this will quietly fail.  This could be changed if you wanted to support sparse
// arrays.
void NWNX_Data_Array_Insert_Str(object obj, string tag, int index, string element)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    Array_Insert_Str(tag, index, element, obj);
}

void NWNX_Data_Array_Insert_Flt(object obj, string tag, int index, float element)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    Array_Insert_Flt(tag, index, element, obj);
}

void NWNX_Data_Array_Insert_Int(object obj, string tag, int index, int element)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    Array_Insert_Int(tag, index, element, obj);
}

void NWNX_Data_Array_Insert_Obj(object obj, string tag, int index, object element)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    Array_Insert_Obj(tag, index, element, obj);
}

////////////////////////////////////////////////////////////////////////////////
// Insert a new element at the end of the array.
void NWNX_Data_Array_PushBack_Str(object obj, string tag, string element)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    Array_PushBack_Str(tag, element, obj);
}

void NWNX_Data_Array_PushBack_Flt(object obj, string tag, float element)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    Array_PushBack_Flt(tag, element, obj);
}

void NWNX_Data_Array_PushBack_Int(object obj, string tag, int element)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    Array_PushBack_Int(tag, element, obj);
}

void NWNX_Data_Array_PushBack_Obj(object obj, string tag, object element)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    Array_PushBack_Obj(tag, element, obj);
}

////////////////////////////////////////////////////////////////////////////////
// Cuts the array off at size 'size'.  Elements beyond size are removed.
void NWNX_Data_Array_Resize(int type, object obj, string tag, int size)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    Array_Resize(tag, size, obj);
}

////////////////////////////////////////////////////////////////////////////////
void NWNX_Data_Array_Shuffle(int type, object obj, string tag)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    Array_Shuffle(tag, obj);
}

////////////////////////////////////////////////////////////////////////////////
int NWNX_Data_Array_Size(int type, object obj, string tag)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    return Array_Size(tag, obj);
}

////////////////////////////////////////////////////////////////////////////////
// Sort the array by value according to 'direciton' (ASC or DESC)
// Note that this is a lexical sort, so sorting an array of ints or floats will have
// odd results
void NWNX_Data_Array_Sort(object obj, string tag, string direction)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    Array_Sort(tag, direction, TYPE_STRING, obj);
}

void NWNX_Data_Array_SortAscending(int type, object obj, string tag)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    Array_SortAscending(tag, TYPE_STRING, obj);
}

void NWNX_Data_Array_SortDescending(int type, object obj, string tag)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    Array_SortDescending(tag, TYPE_STRING, obj);
}

////////////////////////////////////////////////////////////////////////////////
// Set the value of array index 'index' to a 'element'
// This will quietly eat values if index > array size
void NWNX_Data_Array_Set_Str(object obj, string tag, int index, string element)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    Array_Set_Str(tag, index, element, obj);
}

void NWNX_Data_Array_Set_Flt(object obj, string tag, int index, float element)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    Array_Set_Flt(tag, index, element, obj);
}

void NWNX_Data_Array_Set_Int(object obj, string tag, int index, int element)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    Array_Set_Int(tag, index, element, obj);
}

void NWNX_Data_Array_Set_Obj(object obj, string tag, int index, object element)
{
	WriteTimestampedLogEntry("WARNING:  NWNX_Data is deprecated.  You should migrate to Array (see inc_array)");
    Array_Set_Obj(tag, index, element, obj);
}
