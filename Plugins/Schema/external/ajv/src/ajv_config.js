import Ajv2020 from "ajv/dist/2020";
import addFormats from "ajv-formats";
import ajvErrors from "ajv-errors";

import draft7Meta from "ajv/dist/refs/json-schema-draft-07.json";
import draft6Meta from "ajv/dist/refs/json-schema-draft-06.json";

const ajv = new Ajv2020({ 
    allErrors: true, 
    strict: false,
    verbose: true
});

ajv.addMetaSchema(draft7Meta);
ajv.addMetaSchema(draft6Meta);

addFormats(ajv);
ajvErrors(ajv);

globalThis.ajv = ajv;
globalThis.compiledSchemas = {};
