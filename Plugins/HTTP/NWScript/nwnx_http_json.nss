/// @addtogroup http
/// @{
/// @file nwnx_http_json.nss
/// @brief Helper script for constructing json data for NWNX_HTTP_Client_SendRequest()

/// @brief Create a new JSON object.
/// @param isArray TRUE is the object is an array.
/// @return A unique identifier for this object.
int NWNX_HTTP_JSON_NewObject(int isArray = FALSE);

/// @brief Create a new JSON array.
/// @return A unique identifier for this array.
int NWNX_HTTP_JSON_NewArray();

/// @brief Add a JSON object to a JSON object.
/// @param nJSONObjectId The JSON object you're adding to.
/// @param sKey The key name for this object.
/// @param nJSONSubObjectID The JSON object being added.
void NWNX_HTTP_JSON_ObjectAddObject(int nJSONObjectId, string sKey, int nJSONSubObjectID);

/// @brief Add a JSON array to a JSON object.
/// @param nJSONObjectId The JSON object you're adding to.
/// @param sKey The key name for this array.
/// @param nJSONArrayID The JSON array being added.
void NWNX_HTTP_JSON_ObjectAddArray(int nJSONObjectId, string sKey, int nJSONArrayID);

/// @brief Add a string to a JSON object.
/// @param nJSONObjectId The JSON object you're adding to.
/// @param sKey The key name for this string.
/// @param sValue The string value being added.
void NWNX_HTTP_JSON_ObjectAddString(int nJSONObjectId, string sKey, string sValue);

/// @brief Add an integer to a JSON object.
/// @param nJSONObjectId The JSON object you're adding to.
/// @param sKey The key name for this integer.
/// @param nInt The integer value being added.
void NWNX_HTTP_JSON_ObjectAddInt(int nJSONObjectId, string sKey, int nInt);

/// @brief Add a float to a JSON object.
/// @param nJSONObjectId The JSON object you're adding to.
/// @param sKey The key name for this float.
/// @param fFloat The float value being added.
void NWNX_HTTP_JSON_ObjectAddFloat(int nJSONObjectId, string sKey, float fFloat);

/// @brief Add a boolean to a JSON object.
/// @param nJSONObjectId The JSON object you're adding to.
/// @param sKey The key name for this boolean.
/// @param bBool The boolean value being added.
void NWNX_HTTP_JSON_ObjectAddBool(int nJSONObjectId, string sKey, int bBool);

/// @brief Add a NULL value to a JSON object.
/// @param nJSONObjectId The JSON object you're adding to.
/// @param sKey The key name for this NULL value.
void NWNX_HTTP_JSON_ObjectAddNULL(int nJSONObjectId, string sKey);

/// @brief Internal command to get amount of elements in a JSON array
/// @param nJSONArrayID The JSON array being counted.
/// @return The number of elements.
int NWNX_HTTP_JSON_GetArrayElementCount(int nJSONArrayID);

/// @brief Internal command to update the element counter fpr a JSON array
/// @param nJSONArrayID The JSON array being updated
void NWNX_HTTP_JSON_UpdateArrayElementCount(int nJSONArrayID);

/// @brief Add a JSON object to the front of a JSON array.
/// @param nJSONArrayID The JSON array the element is being inserted.
/// @param nJSONObjectId The JSON object being inserted.
void NWNX_HTTP_JSON_ArrayInsertObject(int nJSONArrayID, int nJSONObjectId);

/// @brief Add an array to the front of a JSON array.
/// @param nJSONArrayID The JSON array the element is being inserted.
/// @param nJSONSubArrayID The JSON array being inserted.
void NWNX_HTTP_JSON_ArrayInsertArray(int nJSONArrayID, int nJSONSubArrayID);

/// @brief Add a string to the front of a JSON array.
/// @param nJSONArrayID The JSON array the element is being inserted.
/// @param sElement The string value being inserted.
void NWNX_HTTP_JSON_ArrayInsertString(int nJSONArrayID, string sElement);

/// @brief Add an integer to the front of a JSON array.
/// @param nJSONArrayID The JSON array the element is being inserted.
/// @param nElement The integer value being inserted.
void NWNX_HTTP_JSON_ArrayInsertInt(int nJSONArrayID, int nElement);

/// @brief Add a float to the front of a JSON array.
/// @param nJSONArrayID The JSON array the element is being inserted.
/// @param fElement The float value being inserted.
void NWNX_HTTP_JSON_ArrayInsertFloat(int nJSONArrayID, float fElement);

/// @brief Add a boolean to the front of a JSON array.
/// @param nJSONArrayID The JSON array the element is being inserted.
/// @param bBool The boolean value being added.
void NWNX_HTTP_JSON_ArrayInsertBool(int nJSONArrayID, int bBool);

/// @brief Add a NULL value to the front of a JSON array.
/// @param nJSONArrayID The JSON array the element is being inserted.
void NWNX_HTTP_JSON_ArrayInsertNULL(int nJSONArrayID);

/// @brief Returns a json string representation of a JSON object.
/// @param nJSONObjectID The JSON object to dump as a string.
/// @return A string representation of the json object.
string NWNX_HTTP_JSON_GetJSONString(int nJSONObjectID);

/// @}
int NWNX_HTTP_JSON_NewObject(int isArray = FALSE)
{
    object oModule = GetModule();

    if (!GetLocalInt(oModule, "NWNX_JSON_TABLE_INIT"))
    {
        string table = "CREATE TABLE IF NOT EXISTS json_build ( json_object_id INTEGER PRIMARY KEY, json_text TEXT )";
        sqlquery sqlQuery = SqlPrepareQueryObject(oModule, table);
        SqlStep(sqlQuery);

        table = "CREATE TABLE IF NOT EXISTS json_array_element_counter ( json_array_id INTEGER PRIMARY KEY, count INTEGER DEFAULT 1)";
        sqlQuery = SqlPrepareQueryObject(oModule, table);
        SqlStep(sqlQuery);
        SetLocalInt(oModule, "NWNX_JSON_TABLE_INIT", 1);
    }

    string insert = "INSERT INTO json_build VALUES (NULL, @object_type)";
    sqlquery sqlQuery = SqlPrepareQueryObject(oModule, insert);
    SqlBindString(sqlQuery, "@object_type", isArray ? "[]" : "{}");
    SqlStep(sqlQuery);

    string stmt = "SELECT LAST_INSERT_ROWID()";
    sqlQuery = SqlPrepareQueryObject(oModule, stmt);
    SqlStep(sqlQuery);

    return SqlGetInt(sqlQuery, 0);
}

int NWNX_HTTP_JSON_NewArray()
{
    return NWNX_HTTP_JSON_NewObject(TRUE);
}

void NWNX_HTTP_JSON_ObjectAddObject(int nJSONObjectId, string sKey, int nJSONSubObjectID)
{
    string stmt = "UPDATE json_build SET json_text = json_insert(json_text, @key, (SELECT json(json_text) "+
                  "FROM json_build WHERE json_object_id = @json_subobject_id)) WHERE json_object_id = @json_object_id";
    sqlquery sqlQuery = SqlPrepareQueryObject(GetModule(), stmt);
    SqlBindString(sqlQuery, "@key", "$."+sKey);
    SqlBindInt(sqlQuery, "@json_subobject_id", nJSONSubObjectID);
    SqlBindInt(sqlQuery, "@json_object_id", nJSONObjectId);
    SqlStep(sqlQuery);
}

void NWNX_HTTP_JSON_ObjectAddArray(int nJSONObjectId, string sKey, int nJSONArrayID)
{
    NWNX_HTTP_JSON_ObjectAddObject(nJSONObjectId, sKey, nJSONArrayID);
}

void NWNX_HTTP_JSON_ObjectAddString(int nJSONObjectId, string sKey, string sValue)
{
    string stmt = "UPDATE json_build SET json_text = json_insert(json_text, @key, @string_value) WHERE json_object_id = @json_object_id";
    sqlquery sqlQuery = SqlPrepareQueryObject(GetModule(), stmt);
    SqlBindString(sqlQuery, "@key", "$." + sKey);
    SqlBindString(sqlQuery, "@string_value", sValue);
    SqlBindInt(sqlQuery, "@json_object_id", nJSONObjectId);
    SqlStep(sqlQuery);
}

void NWNX_HTTP_JSON_ObjectAddInt(int nJSONObjectId, string sKey, int nInt)
{
    string stmt = "UPDATE json_build SET json_text = json_insert(json_text, @key, @int_value) WHERE json_object_id = @json_object_id";
    sqlquery sqlQuery = SqlPrepareQueryObject(GetModule(), stmt);
    SqlBindString(sqlQuery, "@key", "$." + sKey);
    SqlBindInt(sqlQuery, "@int_value", nInt);
    SqlBindInt(sqlQuery, "@json_object_id", nJSONObjectId);
    SqlStep(sqlQuery);
}

void NWNX_HTTP_JSON_ObjectAddFloat(int nJSONObjectId, string sKey, float fFloat)
{
    string stmt = "UPDATE json_build SET json_text = json_insert(json_text, @key, @float_value) WHERE json_object_id = @json_object_id";
    sqlquery sqlQuery = SqlPrepareQueryObject(GetModule(), stmt);
    SqlBindString(sqlQuery, "@key", "$." + sKey);
    SqlBindFloat(sqlQuery, "@float_value", fFloat);
    SqlBindInt(sqlQuery, "@json_object_id", nJSONObjectId);
    SqlStep(sqlQuery);
}

void NWNX_HTTP_JSON_ObjectAddBool(int nJSONObjectId, string sKey, int bBool)
{
    string stmt = "UPDATE json_build SET json_text = json_insert(json_text, @key, json(@bool_value)) WHERE json_object_id = @json_object_id";
    sqlquery sqlQuery = SqlPrepareQueryObject(GetModule(), stmt);
    SqlBindString(sqlQuery, "@key", "$." + sKey);
    SqlBindString(sqlQuery, "@bool_value", bBool ? "true" : "false");
    SqlBindInt(sqlQuery, "@json_object_id", nJSONObjectId);
    SqlStep(sqlQuery);
}

void NWNX_HTTP_JSON_ObjectAddNULL(int nJSONObjectId, string sKey)
{
    string stmt = "UPDATE json_build SET json_text = json_insert(json_text, @key, json(NULL)) WHERE json_object_id = @json_object_id";
    sqlquery sqlQuery = SqlPrepareQueryObject(GetModule(), stmt);
    SqlBindString(sqlQuery, "@key", "$." + sKey);
    SqlBindInt(sqlQuery, "@json_object_id", nJSONObjectId);
    SqlStep(sqlQuery);
}

int NWNX_HTTP_JSON_GetArrayElementCount(int nJSONArrayID)
{
    int array_element_count = 0;
    string stmt = "SELECT count FROM json_array_element_counter WHERE json_array_id = @json_array_id";
    sqlquery sqlQuery = SqlPrepareQueryObject(GetModule(), stmt);
    SqlBindInt(sqlQuery, "@json_array_id", nJSONArrayID);
    if (SqlStep(sqlQuery)) 
        array_element_count = SqlGetInt(sqlQuery, 0);
    return array_element_count;
}

void NWNX_HTTP_JSON_UpdateArrayElementCount(int nJSONArrayID)
{
    string stmt = "INSERT INTO json_array_element_counter(json_array_id) VALUES (@json_array_id) ON CONFLICT(json_array_id) DO UPDATE SET count = count + 1";
    sqlquery sqlQuery = SqlPrepareQueryObject(GetModule(), stmt);
    SqlBindInt(sqlQuery, "@json_array_id", nJSONArrayID);
    SqlStep(sqlQuery);
}

void NWNX_HTTP_JSON_ArrayInsertObject(int nJSONArrayID, int nJSONObjectId)
{
    int array_element_count = NWNX_HTTP_JSON_GetArrayElementCount(nJSONArrayID);

    string stmt = "UPDATE json_build SET json_text = json_insert(json_text, @key, (SELECT json(json_text) "+
                  "FROM json_build WHERE json_object_id = @json_object_id)) WHERE json_object_id = @json_array_id";
    sqlquery sqlQuery = SqlPrepareQueryObject(GetModule(), stmt);
    SqlBindString(sqlQuery, "@key", "$["+IntToString(array_element_count)+"]");
    SqlBindInt(sqlQuery, "@json_object_id", nJSONObjectId);
    SqlBindInt(sqlQuery, "@json_array_id", nJSONArrayID);
    SqlStep(sqlQuery);

    NWNX_HTTP_JSON_UpdateArrayElementCount(nJSONArrayID);
}

void NWNX_HTTP_JSON_ArrayInsertArray(int nJSONArrayID, int nJSONSubArrayID)
{
    NWNX_HTTP_JSON_ArrayInsertObject(nJSONArrayID, nJSONSubArrayID);
}

void NWNX_HTTP_JSON_ArrayInsertString(int nJSONArrayID, string sElement)
{
    int array_element_count = NWNX_HTTP_JSON_GetArrayElementCount(nJSONArrayID);

    string stmt = "UPDATE json_build SET json_text = json_insert(json_text, @key, @string_value) WHERE json_object_id = @json_array_id";
    sqlquery sqlQuery = SqlPrepareQueryObject(GetModule(), stmt);
    SqlBindString(sqlQuery, "@key", "$["+IntToString(array_element_count)+"]");
    SqlBindString(sqlQuery, "@string_value", sElement);
    SqlBindInt(sqlQuery, "@json_array_id", nJSONArrayID);
    SqlStep(sqlQuery);

    NWNX_HTTP_JSON_UpdateArrayElementCount(nJSONArrayID);
}

void NWNX_HTTP_JSON_ArrayInsertInt(int nJSONArrayID, int nElement)
{
    int array_element_count = NWNX_HTTP_JSON_GetArrayElementCount(nJSONArrayID);

    string stmt = "UPDATE json_build SET json_text = json_insert(json_text, @key, @int_value) WHERE json_object_id = @json_array_id";
    sqlquery sqlQuery = SqlPrepareQueryObject(GetModule(), stmt);
    SqlBindString(sqlQuery, "@key", "$["+IntToString(array_element_count)+"]");
    SqlBindInt(sqlQuery, "@int_value", nElement);
    SqlBindInt(sqlQuery, "@json_array_id", nJSONArrayID);
    SqlStep(sqlQuery);

    NWNX_HTTP_JSON_UpdateArrayElementCount(nJSONArrayID);
}

void NWNX_HTTP_JSON_ArrayInsertFloat(int nJSONArrayID, float fElement)
{
    int array_element_count = NWNX_HTTP_JSON_GetArrayElementCount(nJSONArrayID);

    string stmt = "UPDATE json_build SET json_text = json_insert(json_text, @key, @float_value) WHERE json_object_id = @json_array_id";
    sqlquery sqlQuery = SqlPrepareQueryObject(GetModule(), stmt);
    SqlBindString(sqlQuery, "@key", "$["+IntToString(array_element_count)+"]");
    SqlBindFloat(sqlQuery, "@float_value", fElement);
    SqlBindInt(sqlQuery, "@json_array_id", nJSONArrayID);
    SqlStep(sqlQuery);

    NWNX_HTTP_JSON_UpdateArrayElementCount(nJSONArrayID);
}

void NWNX_HTTP_JSON_ArrayInsertBool(int nJSONArrayID, int bBool)
{
    int array_element_count = NWNX_HTTP_JSON_GetArrayElementCount(nJSONArrayID);

    string stmt = "UPDATE json_build SET json_text = json_insert(json_text, @key, json(@bool_value)) WHERE json_object_id = @json_array_id";
    sqlquery sqlQuery = SqlPrepareQueryObject(GetModule(), stmt);
    SqlBindString(sqlQuery, "@key", "$["+IntToString(array_element_count)+"]");
    SqlBindString(sqlQuery, "@bool_value", bBool ? "true" : "false");
    SqlBindInt(sqlQuery, "@json_array_id", nJSONArrayID);
    SqlStep(sqlQuery);

    NWNX_HTTP_JSON_UpdateArrayElementCount(nJSONArrayID);
}

void NWNX_HTTP_JSON_ArrayInsertNULL(int nJSONArrayID)
{
    int array_element_count = NWNX_HTTP_JSON_GetArrayElementCount(nJSONArrayID);

    string stmt = "UPDATE json_build SET json_text = json_insert(json_text, @key, json(NULL)) WHERE json_object_id = @json_array_id";
    sqlquery sqlQuery = SqlPrepareQueryObject(GetModule(), stmt);
    SqlBindString(sqlQuery, "@key", "$["+IntToString(array_element_count)+"]");
    SqlBindInt(sqlQuery, "@json_array_id", nJSONArrayID);
    SqlStep(sqlQuery);

    NWNX_HTTP_JSON_UpdateArrayElementCount(nJSONArrayID);
}

string NWNX_HTTP_JSON_GetJSONString(int nJSONObjectID)
{
    string stmt = "SELECT json(json_text) FROM json_build WHERE json_object_id = @json_object_id";
    sqlquery sqlQuery = SqlPrepareQueryObject(GetModule(), stmt);
    SqlBindInt(sqlQuery, "@json_object_id", nJSONObjectID);
    string sJSON = "{}";
    if ( SqlStep(sqlQuery) ) 
    {
        sJSON = SqlGetString(sqlQuery, 0);
    }
    return sJSON;
}
