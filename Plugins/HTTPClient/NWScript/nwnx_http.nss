/// @addtogroup http HTTP
/// @brief NWNX HTTP Server and Client
/// @{
/// @file nwnx_http.nss
#include "nwnx"

const string NWNX_HTTP = "NWNX_HTTP"; ///< @private

/// @name Request Types
/// @anchor request_types
///
/// @{
const int NWNX_HTTP_REQUEST_METHOD_GET     = 0;
const int NWNX_HTTP_REQUEST_METHOD_POST    = 1;
const int NWNX_HTTP_REQUEST_METHOD_DELETE  = 2;
const int NWNX_HTTP_REQUEST_METHOD_PATCH   = 3;
const int NWNX_HTTP_REQUEST_METHOD_PUT     = 4;
const int NWNX_HTTP_REQUEST_METHOD_OPTION  = 5;
const int NWNX_HTTP_REQUEST_METHOD_HEAD    = 6;
///@}

/// @name Content Types
/// @anchor content_types
///
/// @{
const int NWNX_HTTP_CONTENT_TYPE_HTML            = 0;
const int NWNX_HTTP_CONTENT_TYPE_PLAINTEXT       = 1;
const int NWNX_HTTP_CONTENT_TYPE_JSON            = 2;
const int NWNX_HTTP_CONTENT_TYPE_FORM_URLENCODED = 3;
const int NWNX_HTTP_CONTENT_TYPE_XML             = 4;
///@}

/// @name HTTP Authentication Types
/// @anchor auth_types
///
/// @{
const int NWNX_HTTP_AUTH_TYPE_NONE         = 0;
const int NWNX_HTTP_AUTH_TYPE_BASIC        = 1;
const int NWNX_HTTP_AUTH_TYPE_DIGEST       = 2;
const int NWNX_HTTP_AUTH_TYPE_BEARER_TOKEN = 3;
///@}

/// A structure for an HTTP Client Request
struct NWNX_HTTP_Client_Request
{
    int nRequestMethod; ///< A @ref request_types "Request Type"
    string sTag; ///< A unique tag for this request
    string sHost; ///< The host domain name/IP address
    string sPath; ///< The path for the url (include the leading /)
    string sData; ///< The data being sent
    int nContentType; ///< A @ref content_types "Content Type"
    int nAuthType; ///< An @ref auth_types "Authentication Type"
    string sAuthUserOrToken; ///< The authentication username or token
    string sAuthPassword; ///< The authentication password (ignored if just using a token)
    int nPort; ///< The host port
    string sHeaders; ///< Pipe (|) delimited header pairs, e.g. "User-Agent: My NWNX HTTP Client|Accept: application/vnd.github.v3+json"
};

/// @brief Sends an http method to the given host.
/// @param s The structured NWNX_HTTP_Client_Request information.
/// @return A unique identifier for the request for later access in the REQUEST_ID event data.
int NWNX_HTTP_Client_SendRequest(struct NWNX_HTTP_Client_Request s);

/// @brief Returns an NWNX_HTTP_Client_Request structure
/// @param nRequestId The request id returned from NWNX_HTTP_Client_SendRequest()
/// @return The structured NWNX_HTTP_Client_Request information
struct NWNX_HTTP_Client_Request NWNX_HTTP_Client_GetRequest(int nRequestId);

/// @}

int NWNX_HTTP_Client_SendRequest(struct NWNX_HTTP_Client_Request s)
{
    string sFunc = "Client_SendRequest";
    NWNX_PushArgumentString(NWNX_HTTP, sFunc, s.sHeaders);
    NWNX_PushArgumentInt(NWNX_HTTP, sFunc, s.nPort);
    NWNX_PushArgumentString(NWNX_HTTP, sFunc, s.sAuthPassword);
    NWNX_PushArgumentString(NWNX_HTTP, sFunc, s.sAuthUserOrToken);
    NWNX_PushArgumentInt(NWNX_HTTP, sFunc, s.nAuthType);
    NWNX_PushArgumentString(NWNX_HTTP, sFunc, s.sData);
    NWNX_PushArgumentInt(NWNX_HTTP, sFunc, s.nContentType);
    NWNX_PushArgumentString(NWNX_HTTP, sFunc, s.sPath);
    NWNX_PushArgumentString(NWNX_HTTP, sFunc, s.sHost);
    NWNX_PushArgumentInt(NWNX_HTTP, sFunc, s.nRequestMethod);
    NWNX_PushArgumentString(NWNX_HTTP, sFunc, s.sTag);
    NWNX_CallFunction(NWNX_HTTP, sFunc);

    return NWNX_GetReturnValueInt(NWNX_HTTP, sFunc);
}

struct NWNX_HTTP_Client_Request NWNX_HTTP_Client_GetRequest(int nRequestId)
{

    string sFunc = "Client_GetRequest";

    NWNX_PushArgumentInt(NWNX_HTTP, sFunc, nRequestId);
    NWNX_CallFunction(NWNX_HTTP, sFunc);

    struct NWNX_HTTP_Client_Request s;

    s.sTag             = NWNX_GetReturnValueString(NWNX_HTTP, sFunc);
    s.nRequestMethod   = NWNX_GetReturnValueInt(NWNX_HTTP, sFunc);
    s.sHost            = NWNX_GetReturnValueString(NWNX_HTTP, sFunc);
    s.sPath            = NWNX_GetReturnValueString(NWNX_HTTP, sFunc);
    s.nContentType     = NWNX_GetReturnValueInt(NWNX_HTTP, sFunc);
    s.sData            = NWNX_GetReturnValueString(NWNX_HTTP, sFunc);
    s.nAuthType        = NWNX_GetReturnValueInt(NWNX_HTTP, sFunc);
    s.sAuthUserOrToken = NWNX_GetReturnValueString(NWNX_HTTP, sFunc);
    s.sAuthPassword    = NWNX_GetReturnValueString(NWNX_HTTP, sFunc);
    s.nPort            = NWNX_GetReturnValueInt(NWNX_HTTP, sFunc);
    s.sHeaders         = NWNX_GetReturnValueString(NWNX_HTTP, sFunc);

    return s;
}
