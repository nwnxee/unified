const string NWNX_Schema = "NWNX_Schema";

/// @anchor schema_output_verbosity
/// @name Schema Output Verbosity Levels
/// @{
const int NWNX_SCHEMA_OUTPUT_VERBOSITY_SILENT = 0;
const int NWNX_SCHEMA_OUTPUT_VERBOSITY_NORMAL = 1;
const int NWNX_SCHEMA_OUTPUT_VERBOSITY_DEBUG = 2;
/// @}

/// @brief Checks if a schema id is registered and ready to use for
///     instance validation.
/// @param sSchemaId The schema id to check. This should be the value of
///     the `$id` property in the schema and must a valid uri.
/// @return TRUE if the schema id exists and is ready for validation.
int NWNX_Schema_GetIsRegistered(string sSchemaId);

/// @brief Removes a schema from the cache.
/// @param sSchemaId The schema id to remove.
/// @return TRUE if the schema was successfully removed, FALSE if the
///     schema was not removed or could not be found.
int NWNX_Schema_RemoveSchema(string sSchemaId);

/// @brief Completely resets the schema engine's cache.
/// @return TRUE if the cache was successfully cleared.
int NWNX_Schema_ClearCache();

/// @brief Register a metaschema.
/// @param jSchema The metaschema to register.
/// @return A json object containing validation results.
json NWNX_Schema_RegisterMetaSchema(json jSchema);

/// @brief Validates jSchema against its metaschema.
/// @param jSchema Schema to validate.
/// @param bReplaceExisting If TRUE, replaces any existing schema with the same $id.
/// @return A json object containing validation results.
/// @note jSchema must contain the $schema key defining the uri of its metaschema and
///     must contain the $id key defining a valid schema identification uri.
json NWNX_Schema_ValidateSchema(json jSchema, int bReplaceExisting = FALSE);

/// @brief Validates a data instance against a schema.
/// @param jInstance Instance to validate.
/// @param jSchema Schema to validate instance against.
/// @param nVerbosity Verbosity level for output, use @ref schema_output_verbosity "Schema Output Verbosity Levels".
/// @return A json object containing validation results.
json NWNX_Schema_ValidateInstance(json jInstance, json jSchema, int nVerbosity = NWNX_SCHEMA_OUTPUT_VERBOSITY_NORMAL);

/// @brief Validates a data instance against a schema id.
/// @param jInstance Instance to validate.
/// @param sSchemaId Schema id.
/// @param nVerbosity Verbosity level for output, use @ref schema_output_verbosity "Schema Output Verbosity Levels".
/// @return A json object containing validation results.
json NWNX_Schema_ValidateInstanceByID(json jInstance, string sSchemaId, int nVerbosity = NWNX_SCHEMA_OUTPUT_VERBOSITY_NORMAL);

int NWNX_Schema_GetIsRegistered(string sSchemaId)
{
    NWNXPushString(sSchemaId);
    NWNXCall(NWNX_Schema, "IsRegistered");
    return NWNXPopInt();
}

int NWNX_Schema_RemoveSchema(string sSchemaId)
{
    NWNXPushString(sSchemaId);
    NWNXCall(NWNX_Schema, "RemoveSchema");
    return NWNXPopInt();
}

int NWNX_Schema_ClearCache()
{
    NWNXCall(NWNX_Schema, "ClearCache");
    return NWNXPopInt();
}

json NWNX_Schema_RegisterMetaSchema(json jSchema)
{
    NWNXPushJson(jSchema);
    NWNXCall(NWNX_Schema, "RegisterMetaSchema");
    return NWNXPopJson();
}

json NWNX_Schema_ValidateSchema(json jSchema, int bReplaceExisting = FALSE)
{
    NWNXPushInt(bReplaceExisting);
    NWNXPushJson(jSchema);
    NWNXCall(NWNX_Schema, "ValidateSchema");
    return NWNXPopJson();
}

json NWNX_Schema_ValidateInstance(json jInstance, json jSchema, int nVerbosity = NWNX_SCHEMA_OUTPUT_VERBOSITY_NORMAL)
{
    NWNXPushInt(nVerbosity);
    NWNXPushJson(jSchema);
    NWNXPushJson(jInstance);
    NWNXCall(NWNX_Schema, "ValidateInstance");
    return NWNXPopJson();
}

json NWNX_Schema_ValidateInstanceByID(json jInstance, string sSchemaId, int nVerbosity = NWNX_SCHEMA_OUTPUT_VERBOSITY_NORMAL)
{
    NWNXPushInt(nVerbosity);
    NWNXPushString(sSchemaId);
    NWNXPushJson(jInstance);
    NWNXCall(NWNX_Schema, "ValidateInstanceByID");
    return NWNXPopJson();
}
