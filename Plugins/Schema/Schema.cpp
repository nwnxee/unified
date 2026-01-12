#include "Schema.hpp"

JSRuntime* Schema::Schema::global_rt = nullptr;
JSContext* Schema::Schema::global_ctx = nullptr;

static Schema::Schema* g_plugin;

NWNX_PLUGIN_ENTRY NWNXLib::Plugin* PluginLoad(NWNXLib::Services::ProxyServiceList* services) {
    g_plugin = new Schema::Schema(services);
    return g_plugin;
}

namespace Schema {

Schema::Schema(NWNXLib::Services::ProxyServiceList* services) : Plugin(services) {
    #define REGISTER(func) \
        NWNXLib::ScriptAPI::RegisterEvent(PLUGIN_NAME, #func, \
            [](ArgumentStack&& args){ return Schema::func(std::move(args)); })

    REGISTER(ValidateSchema);
    REGISTER(ValidateInstance);
    REGISTER(ValidateInstanceByID);
    REGISTER(IsRegistered);
    REGISTER(RemoveSchema);
    REGISTER(ClearCache);
    REGISTER(RegisterMetaSchema);

    #undef REGISTER
}

Schema::~Schema() {
    if (global_ctx) {
        JS_FreeContext(global_ctx);
        global_ctx = nullptr;
    }
    if (global_rt) {
        JS_FreeRuntime(global_rt);
        global_rt = nullptr;
    }
}

JSContext* Schema::GetContext() {
    if (!global_ctx) {
        global_rt = JS_NewRuntime();
        global_ctx = JS_NewContext(global_rt);
        
        js_std_init_handlers(global_rt);
        js_std_add_helpers(global_ctx, 0, NULL);

        const char* js = R"(
            globalThis.processErrors = function(errors, data, verbosity) {
                
                // Verbosity Level 0 (silent)
                if (verbosity <= 0) return undefined;

                if (!errors || !Array.isArray(errors)) return [];
                
                // Level 2: Debug Verbosity (Maximum/Raw output)
                if (verbosity >= 2) return errors;

                const getNested = (obj, path) => {
                    if (!path || path === "/" || path === "") return obj;
                    return path.split('/').filter(Boolean).reduce((acc, part) => acc && acc[part], obj);
                };

                const results = [];
                const applicators = ["anyOf", "allOf", "oneOf", "if", "then", "else"];
                const customPaths = new Set(errors.filter(e => e.keyword === "errorMessage").map(e => e.instancePath));

                errors.forEach(err => {
                    const fullPath = err.instancePath || "/";
                    
                    // Level 0 (Basic) Noise Filtering
                    if (verbosity === 0) {
                        if (applicators.includes(err.keyword) || (customPaths.has(fullPath) && err.keyword !== "errorMessage")) {
                            return;
                        }
                    }

                    const parts = fullPath.split('/').filter(Boolean);
                    let targetPath = fullPath;
                    let leafKey = "root"; 

                    if (parts.length > 0) {
                        const lastPart = parts[parts.length - 1];
                        if (isNaN(lastPart)) {
                            leafKey = lastPart;
                            targetPath = "/" + parts.slice(0, -1).join("/");
                        }
                    }

                    // Level 1: Moderate Verbosity (Placeholder for your future designated keys)
                    // Currently behaves like Level 0 but includes more technical keywords
                    if (verbosity === 1 && applicators.includes(err.keyword)) {
                        // (Optionally add logic here for your designated moderate keys)
                    }

                    let entry = results.find(r => r.instancePath === targetPath);
                    if (!entry) {
                        entry = {
                            instancePath: targetPath,
                            instance: getNested(data, targetPath),
                            errors: {} 
                        };
                        results.push(entry);
                    }

                    if (!entry.errors[leafKey]) entry.errors[leafKey] = [];
                    if (!entry.errors[leafKey].includes(err.message)) {
                        entry.errors[leafKey].push(err.message);
                    }
                });

                // Convert single-error arrays to simple strings
                results.forEach(entry => {
                    for (const key in entry.errors) {
                        if (entry.errors[key].length === 1) {
                            entry.errors[key] = entry.errors[key][0];
                        }
                    }
                });

                return results;
            };

            globalThis.deepEqual = function(a, b) {
                if (a === b) return true;
                
                if (a && b && typeof a === 'object' && typeof b === 'object') {
                    if (Array.isArray(a)) {
                        if (!Array.isArray(b)) return false;
                        if (a.length !== b.length) return false;
                        for (let i = 0; i < a.length; i++) {
                            if (!globalThis.deepEqual(a[i], b[i])) return false;
                        }
                        return true;
                    }
                    
                    if (Array.isArray(b)) return false;
                    
                    const keys = Object.keys(a);
                    if (keys.length !== Object.keys(b).length) return false;
                    
                    for (const key of keys) {
                        if (!Object.prototype.hasOwnProperty.call(b, key)) return false;
                        if (!globalThis.deepEqual(a[key], b[key])) return false;
                    }
                    return true;
                }
                
                return false;
            };

            globalThis.registerSchema = function(s, overwrite) {
                const id = s.$id;
                
                if (!id) {
                     if (globalThis.ajv.validateSchema(s)) {
                         return { valid: true };
                     } else {
                         return { valid: false, errors: globalThis.ajv.errors };
                     }
                }

                // Explicit URI validation for $id
                // Use regex instead of URL() constructor to avoid dependency on specific JS environment capabilities
                // Checks for scheme followed by colon
                if (!/^[a-zA-Z][a-zA-Z0-9+.-]*:[^\s]*$/.test(id)) {
                    return { valid: false, errors: [{ message: "Schema $id '" + id + "' is not a valid absolute URI." }] };
                }
    
                const existing = globalThis.ajv.getSchema(id);
                if (existing) {
                    if (globalThis.deepEqual(s, existing.schema)) {
                         return { valid: true };
                    }
                    
                    if (globalThis.ajv.validateSchema(s)) {
                         if (overwrite) {
                             globalThis.ajv.removeSchema(id);
                             globalThis.ajv.compile(s);
                             return { valid: true };
                         } else {
                             return { valid: true };
                         }
                    } else {
                        return { valid: false, errors: globalThis.ajv.errors };
                    }
                }
    
                if (globalThis.ajv.validateSchema(s)) {
                     globalThis.ajv.compile(s);
                     return { valid: true };
                }
                return { valid: false, errors: globalThis.ajv.errors };
            };
        )";

        // Evaluate the initialization script
        JS_Eval(global_ctx, js, strlen(js), "<init>", JS_EVAL_TYPE_GLOBAL);

        // Load AJV from the embedded header
        JS_Eval(global_ctx, (const char*)ajv_runtime_min_js, ajv_runtime_min_js_len, "ajv.js", JS_EVAL_TYPE_GLOBAL);
        
        LOG_DEBUG("Schema validation initialized");
    }

    return global_ctx;
}

json Schema::Schema::JSValueToJSON(JSValue val) {
    JSContext *ctx = Schema::GetContext();

    // Stringify the result inside JS to ensure complex error objects are captured
    JSValue jsonStrVal = JS_JSONStringify(ctx, val, JS_UNDEFINED, JS_UNDEFINED);
    const char* cStr = JS_ToCString(ctx, jsonStrVal);
    
    // Parse into nlohmann::json. If cStr is null, return a fallback error.
    json result = json::parse(cStr ? cStr : "{\"valid\": false, \"errors\": \"Engine Error\"}");
    
    JS_FreeCString(ctx, cStr);
    JS_FreeValue(ctx, jsonStrVal);
    return result;
}

NWNX_EXPORT ArgumentStack Schema::IsRegistered(ArgumentStack&& args) {
    const auto schemaId = args.extract<std::string>();

    JSContext *ctx = Schema::GetContext();
    JSValue global = JS_GetGlobalObject(ctx);
    JS_SetPropertyStr(ctx, global, "schemaID", JS_NewString(ctx, schemaId.c_str()));
    JS_FreeValue(ctx, global); 

    const char* js = "!!globalThis.ajv.getSchema(globalThis.schemaID)";
    JSValue resVal = JS_Eval(ctx, js, strlen(js), "<eval>", JS_EVAL_TYPE_GLOBAL);
    int32_t isFound = JS_ToBool(ctx, resVal);
    JS_FreeValue(ctx, resVal);

    LOG_DEBUG("IsRegistered(): schema [%s] %s", schemaId.c_str(), isFound ? "found" : "not found");
    return isFound;
}

NWNX_EXPORT ArgumentStack Schema::RemoveSchema(ArgumentStack&& args) {
    const auto schemaId = args.extract<std::string>();

    JSContext *ctx = Schema::GetContext();
    JSValue global = JS_GetGlobalObject(ctx);
    JS_SetPropertyStr(ctx, global, "schemaID", JS_NewString(ctx, schemaId.c_str()));
    JS_FreeValue(ctx, global);

    const char* js = R"(
        (function() {
            const id = globalThis.schemaID;
            const exists = !!globalThis.ajv.getSchema(id);
            if (exists) {
                globalThis.ajv.removeSchema(id);
            }
            return exists;
        })()
    )";
    JSValue resVal = JS_Eval(ctx, js, strlen(js), "<eval>", JS_EVAL_TYPE_GLOBAL);
    int32_t isFound = JS_ToBool(ctx, resVal);
    JS_FreeValue(ctx, resVal);

    LOG_DEBUG("RemoveSchema(): schema [%s] %s", schemaId.c_str(), isFound ? "removed" : "not found");
    return isFound;
}

NWNX_EXPORT ArgumentStack Schema::ClearCache(ArgumentStack&&) {
    const char* js = R"(
        (function() {
            globalThis.ajv.removeSchema(); 
            return Object.keys(globalThis.ajv._schemas).length === 0;
        })()
    )";
    
    JSContext *ctx = GetContext();
    JSValue resVal = JS_Eval(ctx, js, strlen(js), "<eval>", JS_EVAL_TYPE_GLOBAL);
    int32_t isEmpty = JS_ToBool(ctx, resVal);
    JS_FreeValue(ctx, resVal);

    JSContext *ctx_p;
    while (JS_ExecutePendingJob(global_rt, &ctx_p) > 0);

    if (isEmpty) {
        LOG_DEBUG("ClearCache(): cached schemas cleared");
    } else {
        LOG_DEBUG("ClearCache(): failed to clear cached schemas");
    }

    return isEmpty;
}

NWNX_EXPORT ArgumentStack Schema::RegisterMetaSchema(ArgumentStack&& args) {
    const auto schema = args.extract<JsonEngineStructure>();
    std::string schemaDump = schema.m_shared->m_json.dump();

    JSContext *ctx = Schema::GetContext();
    JSValue global = JS_GetGlobalObject(ctx);
    JS_SetPropertyStr(ctx, global, "schema", JS_NewString(ctx, schemaDump.c_str()));
    JS_FreeValue(ctx, global);

    const char* js = R"(
        (function() {
            try {
                const s = JSON.parse(globalThis.schema);
                if (!s.$id) {
                     return { valid: false, errors: [{ message: "Meta-schema must have an $id." }] };
                }
                
                globalThis.ajv.addMetaSchema(s);
                return { valid: true };
            } catch(e) {
                // If addMetaSchema fails (e.g. invalid schema), AJV throws
                return { valid: false, errors: [{ message: e.message }] };
            }
        })()
    )";

    JSValue resVal = JS_Eval(ctx, js, strlen(js), "<eval>", JS_EVAL_TYPE_GLOBAL);
    json result = JSValueToJSON(resVal);
    JS_FreeValue(ctx, resVal);

    if (result["valid"].get<bool>()) {
        LOG_DEBUG("RegisterMetaSchema(): Metaschema %s registered successfully", 
            schema.m_shared->m_json.value("$id", "UNKNOWN").c_str());
    } else {
        LOG_DEBUG("RegisterMetaSchema(): Failed to register metaschema: %s", 
            result.contains("errors") ? result["errors"].dump().c_str() : "UNKNOWN_ERROR");
    }

    return { JsonEngineStructure(std::move(result), "") };
}

NWNX_EXPORT ArgumentStack Schema::ValidateSchema(ArgumentStack&& args) {
    const auto schema = args.extract<JsonEngineStructure>();
    const auto overwrite = args.extract<int32_t>();
    
    std::string schemaDump = schema.m_shared->m_json.dump();

    JSContext *ctx = Schema::GetContext();
    JSValue global = JS_GetGlobalObject(ctx);
    JS_SetPropertyStr(ctx, global, "schema", JS_NewString(ctx, schemaDump.c_str()));
    JS_SetPropertyStr(ctx, global, "overwrite", JS_NewBool(ctx, overwrite != 0));
    JS_FreeValue(ctx, global);

    const char* js = R"(
        (function() {
            try {
                const s = JSON.parse(globalThis.schema);
                const result = globalThis.registerSchema(s, globalThis.overwrite);
                
                if (result.valid) {
                    return { valid: true };
                }
                
                return {
                    valid: false,
                    errors: result.errors
                };
            } catch(e) {
                return { valid: false, errors: [{ message: e.message }] };
            }
        })()
    )";

    JSValue resVal = JS_Eval(ctx, js, strlen(js), "<eval>", JS_EVAL_TYPE_GLOBAL);
    json result = JSValueToJSON(resVal);
    JS_FreeValue(ctx, resVal);

    if (result["valid"].get<bool>()) {
        LOG_DEBUG("ValidateSchema(): schema [%s] validated and registered successfully", 
            schema.m_shared->m_json.value("$id", "UNNAMED").c_str());
    } else {
        LOG_DEBUG("ValidateSchema(): schema [%s] validation failed: %s", 
            schema.m_shared->m_json.value("$id", "UNNAMED").c_str(), 
            result.contains("errors") ? result["errors"].dump().c_str() : "SILENT");
    }
    
    return { JsonEngineStructure(std::move(result), "") };
}

NWNX_EXPORT ArgumentStack Schema::ValidateInstance(ArgumentStack&& args) {
    const auto instance = args.extract<JsonEngineStructure>();
    const auto schema = args.extract<JsonEngineStructure>();
    const auto verbosity = args.extract<int32_t>(); 
    
    std::string instanceDump = instance.m_shared->m_json.dump();
    std::string schemaDump = schema.m_shared->m_json.dump();    

    JSContext *ctx = Schema::GetContext();
    JSValue global = JS_GetGlobalObject(ctx);
    JS_SetPropertyStr(ctx, global, "schema", JS_NewString(ctx, schemaDump.c_str()));
    JS_SetPropertyStr(ctx, global, "instance", JS_NewString(ctx, instanceDump.c_str()));
    JS_SetPropertyStr(ctx, global, "verbosity", JS_NewInt32(ctx, verbosity));
    JS_FreeValue(ctx, global);

    const char* js = R"(
        (function() {
            try {
                const s = JSON.parse(globalThis.schema);
                const d = JSON.parse(globalThis.instance);
                const vLevel = (typeof globalThis.verbosity === 'number') ? globalThis.verbosity : 1;

                const result = globalThis.registerSchema(s, false);
                
                if (!result.valid) {
                    const fail = { valid: false };
                    if (vLevel > 0) fail.errors = result.errors;
                    return fail;
                }

                const v = s.$id ? globalThis.ajv.getSchema(s.$id) : globalThis.ajv.compile(s);
                const valid = v(d);
                const errs = v.errors;

                if (!s.$id) globalThis.ajv.removeSchema(s);
                if (valid) return { valid: true };

                const output = { valid: false };
                const processedErrors = globalThis.processErrors(errs, d, vLevel);
                if (processedErrors !== undefined) output.errors = processedErrors;
                return output;
            } catch(e) { 
                const fail = { valid: false };

                if ((globalThis.verbosity || 0) <= 0) return fail;

                // Level 1+: Descriptive functional error reporting
                const isParseError = e.message.toLowerCase().includes("json") || 
                                    e.message.toLowerCase().includes("unexpected token");
                const errorType = isParseError ? "Input Error" : "Engine Fault";
                
                fail.errors = "[" + errorType + "]: " + e.message;

                // Level 2: Include the JS stack trace for developer debugging
                if (globalThis.verbosity >= 2 && e.stack) {
                    fail.errors["stack"] = e.stack;
                }
                
                return fail; 
            }
        })()
    )";

    JSValue resVal = JS_Eval(ctx, js, strlen(js), "<eval>", JS_EVAL_TYPE_GLOBAL);
    json result = JSValueToJSON(resVal);
    JS_FreeValue(ctx, resVal);

    std::string schemaId = schema.m_shared->m_json.value("$id", "UNNAMED");
    if (result["valid"].get<bool>()) {
        LOG_DEBUG("ValidateInstance(): validation successful for schema [%s]", schemaId.c_str());
    } else {
        LOG_DEBUG("ValidateInstance(): validation failed for schema [%s]: %s", 
            schemaId.c_str(), 
            result.contains("errors") ? result["errors"].dump().c_str() : "SILENT");
    }

    return { JsonEngineStructure(std::move(result), "") };
}

NWNX_EXPORT ArgumentStack Schema::ValidateInstanceByID(ArgumentStack&& args) {
    const auto instance = args.extract<JsonEngineStructure>();
    const auto schemaId = args.extract<std::string>();
    const auto verbosity = args.extract<int32_t>();
    
    std::string instanceDump = instance.m_shared->m_json.dump();

    JSContext *ctx = Schema::GetContext();
    JSValue global = JS_GetGlobalObject(ctx);
    JS_SetPropertyStr(ctx, global, "schemaID", JS_NewString(ctx, schemaId.c_str()));
    JS_SetPropertyStr(ctx, global, "instance", JS_NewString(ctx, instanceDump.c_str()));
    JS_SetPropertyStr(ctx, global, "verbosity", JS_NewInt32(ctx, verbosity));
    JS_FreeValue(ctx, global);

    const char* js = R"(
        (function() {
            try {
                const s = globalThis.schemaID;
                const i = JSON.parse(globalThis.instance);
                const vLevel = (typeof globalThis.verbosity === 'number') ? globalThis.verbosity : 1;

                let v = globalThis.ajv.getSchema(s);
                if (!v) {
                    const fail = { valid: false };
                    if (vLevel > 0) {
                        fail.errors = "Schema ID '" + s + "' not found in registry.";
                    }
                    return fail;
                }

                if (v(i)) return { valid: true };

                const output = { valid: false };
                const processedErrors = globalThis.processErrors(v.errors, i, vLevel);
                if (processedErrors !== undefined) output.errors = processedErrors;
                return output;
            } catch(e) { 
                const fail = { valid: false };
                
                // Level 0: Silent
                if ((globalThis.verbosity || 0) <= 0) return fail;

                // Level 1+: Descriptive functional error reporting
                const isParseError = e.message.toLowerCase().includes("json") || 
                                    e.message.toLowerCase().includes("unexpected token");
                const errorType = isParseError ? "Input Error" : "Engine Fault";
                
                fail.errors = "[" + errorType + "]: " + e.message;

                // Level 2: Debug stack trace
                if (globalThis.verbosity >= 2 && e.stack) {
                    fail.errors["stack"] = e.stack;
                }
                
                return fail; 
            }
        })()
    )";

    JSValue resVal = JS_Eval(ctx, js, strlen(js), "<eval>", JS_EVAL_TYPE_GLOBAL);
    json result = JSValueToJSON(resVal);
    JS_FreeValue(ctx, resVal);

    if (result["valid"].get<bool>()) {
        LOG_DEBUG("ValidateInstanceByID(): validation successful for schema ID: %s", schemaId.c_str());
    } else {
        LOG_DEBUG("ValidateInstanceByID(): validation failed for schema ID: %s. Errors: %s", 
            schemaId.c_str(), 
            result.contains("errors") ? result["errors"].dump().c_str() : "SILENT");
    }

    return { JsonEngineStructure(std::move(result), "") };
}
};
