/// @addtogroup httpclient HTTPClient
/// @brief NWNX HTTPClient
/// @{
/// @file nwnx_httpclient.nss

const string NWNX_HTTPClient = "NWNX_HTTPClient"; ///< @private

/// @name Request Types
/// @anchor request_types
///
/// @{
const int NWNX_HTTPCLIENT_REQUEST_METHOD_GET     = 0;
const int NWNX_HTTPCLIENT_REQUEST_METHOD_POST    = 1;
const int NWNX_HTTPCLIENT_REQUEST_METHOD_DELETE  = 2;
const int NWNX_HTTPCLIENT_REQUEST_METHOD_PATCH   = 3;
const int NWNX_HTTPCLIENT_REQUEST_METHOD_PUT     = 4;
const int NWNX_HTTPCLIENT_REQUEST_METHOD_OPTION  = 5;
const int NWNX_HTTPCLIENT_REQUEST_METHOD_HEAD    = 6;
///@}

/// @name Content Types
/// @anchor content_types
///
/// @{
const int NWNX_HTTPCLIENT_CONTENT_TYPE_HTML            = 0;
const int NWNX_HTTPCLIENT_CONTENT_TYPE_PLAINTEXT       = 1;
const int NWNX_HTTPCLIENT_CONTENT_TYPE_JSON            = 2;
const int NWNX_HTTPCLIENT_CONTENT_TYPE_FORM_URLENCODED = 3;
const int NWNX_HTTPCLIENT_CONTENT_TYPE_XML             = 4;
///@}

/// @name HTTP Authentication Types
/// @anchor auth_types
///
/// @{
const int NWNX_HTTPCLIENT_AUTH_TYPE_NONE         = 0;
const int NWNX_HTTPCLIENT_AUTH_TYPE_BASIC        = 1;
const int NWNX_HTTPCLIENT_AUTH_TYPE_DIGEST       = 2;
const int NWNX_HTTPCLIENT_AUTH_TYPE_BEARER_TOKEN = 3;
///@}

/// A structure for an HTTP Client Request
struct NWNX_HTTPClient_Request
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
/// @param s The structured NWNX_HTTPClient_Request information.
/// @return A unique identifier for the request for later access in the REQUEST_ID event data.
int NWNX_HTTPClient_SendRequest(struct NWNX_HTTPClient_Request s);

/// @brief Returns an NWNX_HTTP_Client_Request structure
/// @param nRequestId The request id returned from NWNX_HTTPClient_SendRequest()
/// @return The structured NWNX_HTTPClient_Request information
struct NWNX_HTTPClient_Request NWNX_HTTPClient_GetRequest(int nRequestId);

/// @}

int NWNX_HTTPClient_SendRequest(struct NWNX_HTTPClient_Request s)
{
    NWNXPushString(s.sHeaders);
    NWNXPushInt(s.nPort);
    NWNXPushString(s.sAuthPassword);
    NWNXPushString(s.sAuthUserOrToken);
    NWNXPushInt(s.nAuthType);
    NWNXPushString(s.sData);
    NWNXPushInt(s.nContentType);
    NWNXPushString(s.sPath);
    NWNXPushString(s.sHost);
    NWNXPushInt(s.nRequestMethod);
    NWNXPushString(s.sTag);
    NWNXCall(NWNX_HTTPClient, "SendRequest");
    return NWNXPopInt();
}

struct NWNX_HTTPClient_Request NWNX_HTTPClient_GetRequest(int nRequestId)
{
    NWNXPushInt(nRequestId);
    NWNXCall(NWNX_HTTPClient, "GetRequest");

    struct NWNX_HTTPClient_Request s;

    s.sTag             = NWNXPopString();
    s.nRequestMethod   = NWNXPopInt();
    s.sHost            = NWNXPopString();
    s.sPath            = NWNXPopString();
    s.nContentType     = NWNXPopInt();
    s.sData            = NWNXPopString();
    s.nAuthType        = NWNXPopInt();
    s.sAuthUserOrToken = NWNXPopString();
    s.sAuthPassword    = NWNXPopString();
    s.nPort            = NWNXPopInt();
    s.sHeaders         = NWNXPopString();

    return s;
}
