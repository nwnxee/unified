@page schema Readme
@ingroup schema 

This plugin brings the power of [AJV](https://ajv.js.org/) and its schema management and validation capabilities to NWN.  AJV is a javascript-based schema validation engine which can validate custom schema against [json-schema.org](https://json-schema.org)'s published metaschema, or user instances against their respective custom schema.  This plugin uses a bit of a complicated approach to schema validation in that a javascript engine is instantiated to leverage the schema validation process.  This method was selected because cpp-only validation engines were far behind javascript-based implementations, in some cases by years, and plagued with bugs and implementation issues.  Additionlly, given that javascript/json is the language of the web, javascript-based validation engines are kept current with json methodologies and rules as they are published, whereas cpp-based engines lag far behind.

- [Terminology](#terminology)
  - [Document](#document)
  - [Schema](#schema)
  - [Metaschema] (#metaschema)
  - [Instance](#instance)
  - [Validation](#validation)
- [Setup](#setup)
  - [NWNX](#nwnx)
  - [NWScript](#nwscript)
- [Verbosity Levels](#verbosity-levels)
- [Common Functions](#common-functions)
  - [Schema Validation](#schema-validation)
  - [Instance Validation](#instance-validation)
- [Uncommon Functions](#uncommon-functions)
- [Examples](#examples)
  - [Custom Metaschema Validation](#validating-a-custom-or-extended-metaschema)
  - [Custom Schema Validation](#validating-a-custom-schema-against-a-metaschema)
  - [Instance Validation](#validating-an-instance-against-a-custom-schema)
  - [NWScript Snippet](#nwscript-snippets)
- [Updating AJV and QuickJS](#updating-ajv-and-quickjs)

# Terminology
### Document
`document` is any json object, but usually refers to an `instance` or any other piece of json data being described or validated by a schema.

### Schema
`schema` is a document used to describe the structure, constraints and annotations of json a document called the `instance`.  The `schema` itself conforms to the structure and constraints defined in its [metaschema](#metaschema), usually published by json-schema.org and identified in the schema's `$schema` key.  `schema`s must be a json object or boolean value.

### Metaschema
`metaschema` is a document used to describe the structure, contstraints and annotations of a schema.

### Instance
`instance` is a document that is being described by a schema and usually contains real, working data and values.

### Validation
`validation` passes when the values and structure contained in the `instance` meet the structure and constraints imposed by its schema.  This is also true when validating a schema document itself against its metaschema.

# Setup
### NWNX
Ensure the `schema` plugin is not skipped in your nwserver's environmental file, or wherever you establish your nwnx plugin configuration:
`NWNX_SCHEMA_SKIP=FALSE`
### NWScript
Add `#include "nwnx_schema"` to your nwscript file and you've harnessed the power of schema validation.
# Verbosity Levels
Validation output verbosity can be controlled in specific circumstances.  There are three levels of output verbosity available:
```c
const int NWNX_SCHEMA_OUTPUT_VERBOSITY_SILENT = 0;
const int NWNX_SCHEMA_OUTPUT_VERBOSITY_NORMAL = 1;
const int NWNX_SCHEMA_OUTPUT_VERBOSITY_DEBUG = 2;
```
These verbosities are only avaialable for instance validation; schem and metaschema validation will always return at maximum verbosity.  Examples of output at various levels is demonstrated below.
# Common Functions
### Metaschema Validation
This plugin organically includes [json-schema.org's](https://json-schema.org) metaschema drafts [6](https://json-schema.org/draft-06), [7](https://json-schema.org/draft-07), [2019-09](https://json-schema.org/draft/2019-09) and [2020-12](https://json-schema.org/draft/2020-12).  Generally, this will be enough to satisfy most use cases and these schema never need to be added.  However, if a creator needs to extend a standard metaschema, or create one from scratch, it can be added with `NWNX_Schema_RegisterMetaSchema()`.  This function will return the results of the schema validation.  Custom or extended metaschema must contain both `$schema`, to identify the controlling metaschema, and `$id` to provide a unique identifier for the metaschema.
>**WARNING** Metaschema must be added through this function.  Attempting to add metaschema through `NWNX_Schema_ValidateSChema()` may result in undefined behavior.
```c
/// @brief Register a metaschema.
/// @param jSchema The metaschema to register.
/// @return A json object containing validation results.
json NWNX_Schema_RegisterMetaSchema(json jSchema);
```
### Schema Validation
Creators can add custom schema that, once loaded, will remain compiled and available for use throughout the server's session.  The schema cache is volatile and will not survive a full nwnx reset/restart.  Custom schema should be validated during the `OnModuleLoad` event if the schema is commonly used.  One-off, or rarely used schema, do not need to be validated until they are used.  

The system can validate a custom schema against a metaschema, whether that metaschema is a published standard or a user-supplied metaschema.  `NWNX_Schema_ValidateSchema()` is designed to validate and add a custom schema to the cache, not to add custom or extended metaschema.  To add a custom or extended metaschema, see [Metaschema Validation](#metaschema-validation).
```c
/// @brief Validates jSchema against its metaschema.
/// @param jSchema Schema to validate.
/// @param bReplaceExisting If TRUE, replaces any existing schema with the same $id.
/// @return A json object containing validation results.
/// @note jSchema must contain the $schema key defining the uri of its metaschema and
///     must contain the $id key defining a valid schema identification uri.
json NWNX_Schema_ValidateSchema(json jSchema, int bReplaceExisting = FALSE);
```
### Instance Validation
An instance can be validated by schema or by schema ID.  Schema passed through `NWNX_Schema_ValidateInstance()` do not have be be pre-validated.  If a schema is passed through this function that was not previously validated, the schema will be validated and cached if the schema contains a valid `$id` uri.  Otherwise, it will be validated and, if valid, will be used to validate the passed instance.  If the schema is invalid, the results of the schema validation will be returned.  If the schema is valid, the results of the instance validation will be returned.

>**WARNING** If a schema which contains an `$id` that is already registered to the cache, but is not the same schema that created the orginal registration, is passed, the cached schema will not be overwritten.  However, the passed schema may still be used to validate the passed instance, if the schema is valid.  To modify a schema that has already been cached, used `NWNX_Schema_ValidateSchema()` and set `bReplaceExisting` to `TRUE`.
```c
/// @brief Validates a data instance against a schema.
/// @param jInstance Instance to validate.
/// @param jSchema Schema to validate instance against.
/// @param nVerbosity Verbosity level for output, use @ref schema_output_verbosity "Schema Output Verbosity Levels".
/// @return A json object containing validation results.
json NWNX_Schema_ValidateInstance(json jInstance, json jSchema, int nVerbosity = NWNX_SCHEMA_OUTPUT_VERBOSITY_NORMAL);
```
To validate an instance against a published metaschema or against a custom user schema which has already been validated and cached, the `$id` of the schema can be provided instead of the full schema.  If the passed `$id` cannot be found in the schema cache, the validation will fail.
```c
/// @brief Validates a data instance against a schema id.
/// @param jInstance Instance to validate.
/// @param sSchemaId Schema id.
/// @param nVerbosity Verbosity level for output, use @ref schema_output_verbosity "Schema Output Verbosity Levels".
/// @return A json object containing validation results.
json NWNX_Schema_ValidateInstanceByID(json jInstance, string sSchemaId, int nVerbosity = NWNX_SCHEMA_OUTPUT_VERBOSITY_NORMAL);
```
# Uncommon Functions
- ***These functions are available for troubleshooting or debugging, but are generally not needed in the course of normal operations***

Individual schema can be removed from the validated schema cache.
```c
/// @brief Remove a schema from the validation cache.
/// @param sSchemaID The $id of the schema to be removed.
void NWNX_Schema_RemoveSchema(string sKey);
```
Clear the entire validated schema cache.
```c
/// @brief Clear the validated schema cache.
void NWNX_Schema_ClearCache();
```
Check is a schema has been registered.
```c
/// @brief Checks if a schema id is registered and ready to use for
///     instance validation.
/// @param sSchemaId The schema id to check. This should be the value of
///     the `$id` property in the schema and must a valid uri.
/// @return TRUE if the schema id exists and is ready for validation.
int NWNX_Schema_GetIsRegistered(string sSchemaId);
```
# Examples

### Validating a custom or extended metaschema
A custom metaschema can be validated against its controlling metaschema.  In this case, 2020-12 draft is being extended to require the `title` property be defined.
```json
{
    "$id": "https://example.com/meta-extended",
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "allOf": [
        {
            "$ref": "https://json-schema.org/draft/2020-12/schema"
        }
    ],
    "required": [
        "title"
    ]
}
```
To add this metaschema to the cache, use code similar to this in nwscript:
```c
json jMeta = JsonParse(r"
    {
        ""$id"": ""https://example.com/meta-extended"",
        ""$schema"": ""https://json-schema.org/draft/2020-12/schema"",
        ""allOf"": [
            { ""$ref"": ""https://json-schema.org/draft/2020-12/schema"" }
        ],
        ""required"": [""title""]
    }
");

json result = NWNX_Schema_RegisterMetaSchema(jMeta);
```
Once added, this metaschema can be used to validate custom schema.

### Validating a custom schema against a metaschema
The following valid user-generated schema can be supplied to the validation engine to determine whether it is valid against the metaschema defined in its `$schema` key.  The following schema is invalid against the metaschema described in the last example because it is missing the required `title` property.

```json
{
    "$id": "https://example.com/invalid-person",
    "$schema": "https://example.com/meta-extended",
    "description": "Missing the required title field",
    "type": "object"
}
```
The returned result is a json object containing the boolean key `valid` and, if necessary, a key `errors` contains human-readable information for identifying the errors in the schema.  In this case, the schema is invalid, so the result is:
```json
{
    "errors": [
        {
            "data": {
                "$id": "https://example.com/invalid-person",
                "$schema": "https://example.com/meta-extended",
                "description": "Missing the required title field",
                "type": "object"
            },
            "instancePath": "",
            "keyword": "required",
            "message": "must have required property 'title'",
            "params": {
                "missingProperty": "title"
            },
            "parentSchema": {
                "$id": "https://example.com/meta-extended",
                "$schema": "https://json-schema.org/draft/2020-12/schema",
                "allOf": [
                    {
                        "$ref": "https://json-schema.org/draft/2020-12/schema"
                    }
                ],
                "required": [
                    "title"
                ]
            },
            "schema": [
                "title"
            ],
            "schemaPath": "#/required"
        }
    ],
    "valid": false
}
```
As you can see, the resulting `errors` component is quite involved.  Error generated when validating metaschema or schema are always returned at the maximum verbosity level and cannot be returned at a lower level.  This is designed to ensure these advanced fucntions can always provide the data necessary for debugging.
### Validating an instance against a custom schema
Below is a simple schema that can be used to validate an instance.
```json
{
    "$id": "https://example.com/person",
    "description": "A person schema",
    "properties": {
        "age": {
            "minimum": 0,
            "type": "integer"
        },
        "name": {
            "type": "string"
        }
    },
    "required": [
        "name"
    ],
    "type": "object"
}
```
This is an instance that validates successfully against the schema.
```json
{
    "age": 30,
    "name": "John Doe"
}
```
and results in the expected return:
```json
{"valid":true}
```
This is an instance that fails validation against the schema.
```json
{
    "name": 123,
    "age": -5
}
```
and provides the following error set:
```json
{
    "errors": [
        {
            "errors": {
                "age": "must be >= 0",
                "name": "must be string"
            },
            "instance": {
                "age": -5,
                "name": 123
            },
            "instancePath": "/"
        }
    ],
    "valid": false
}
```
If the user selected `NWNX_SCHEMA_OUTPUT_VERBOSITY_SILENT`, the following would have been returned:
```json
{
    "valid": false
}
```
If the user selected `NWNX_SCHEMA_OUTPUT_VERBOSITY_DEBUG`, the following would have been returned:
```json
{
    "errors": [
        {
            "data": -5,
            "instancePath": "/age",
            "keyword": "minimum",
            "message": "must be >= 0",
            "params": {
                "comparison": ">=",
                "limit": 0
            },
            "parentSchema": {
                "minimum": 0,
                "type": "integer"
            },
            "schema": 0,
            "schemaPath": "#/properties/age/minimum"
        },
        {
            "data": 123,
            "instancePath": "/name",
            "keyword": "type",
            "message": "must be string",
            "params": {
                "type": "string"
            },
            "parentSchema": {
                "type": "string"
            },
            "schema": "string",
            "schemaPath": "#/properties/name/type"
        }
    ],
    "valid": false
}
```
The various verbosity levels are exceptionally useful during debugging complicated instances failing against complicated schema, such as debugging nui window instances.
# NWScript Snippets
A common implementation will be to return an `int` (`TRUE`/`FALSE`) instead of a validation results object.  The following is a simple example of that implementation.  This snippet assumes the `urn:nwn:player_character` custom schema from the [instance validation](#validating-an-instance-against-a-custom-schema) example above has been registered to the schema cache.
```c
if (!NWNXGetIsAvailable())
     return FALSE;

json jInstance = JsonParse(r"
{
    ""age"": 30,
    ""name"": ""John Doe""
}
");
json jResult = NWNX_Schema_ValidateInstanceByID(jInstance, "urn:nwn:player_character");
return JsonObjectGet(jResult, "valid") == JSON_TRUE;
```
# Updating AJV and QuickJS
Technology continuously improves and along with it, the software to support it.  [AJV](https://ajv.js.org/) and [QuickJS](https://github.com/quickjs-ng/quickjs) are no different, with both products being updated within the last week.  To make updating these support systems easier, there are update scripts in the schema plugin's `external` folder.

> If using `Windows`, these update scripts must be run in `bash`.

- `external/update-external.sh` OS-aware updating utility that will update required `AJV` and `QuickJS` files into their respective subfolders, and bundle the `AJV` files into the required javascript bundle file.  The `xxd` command in `CMakeLists.txt` uses this bundle to build the required `#include` during the nwnx/image build process.
- `external/ajv/update-ajv.sh` OS-aware updating utility that will update only `AJV` files and bundle them into the required javascript bundle file.
- `external/quickjs/update-quickjs.sh` OS-aware updating utility that will update only the `QuickJS` files.

> None of these updates require `node` or other background software be present on the updating system.
