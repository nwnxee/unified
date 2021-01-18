@page http Readme
@ingroup http

## Introduction
The HTTP Plugin provides access to both a Server and Client to accept and perform requests and return responses.

## Environment Variables

| Variable Name                     |  Type      | Default Value      |
| ----------------------------------| :--------: | ------------------ |
| NWNX_HTTP_CLIENT_REQUEST_TIMEOUT  | int        | 2000               |
| NWNX_HTTP_SERVER                  | bool       | false              |
| NWNX_HTTP_SERVER_PORT             | int        | 8686               |
| NWNX_HTTP_SERVER_ROOT_STATUS      | int        | 403 (Forbidden)    |
| NWNX_HTTP_SERVER_ROOT_HTML        | string     | ```<html><head><title>Welcome to nwnx http!</title></head><body><h1>Welcome to nwnx http!</h1></body></html>```              |
| NWNX_HTTP_SERVER_USE_SSL          | bool       | false              |
| NWNX_HTTP_SERVER_SSL_CERT_FILE    | string     | ./cert.pem         |
| NWNX_HTTP_SERVER_SSL_KEY_FILE     | string     | ./key.pem          |
| NWNX_HTTP_SERVER_EVENT_URL        | string     |                    |
| NWNX_HTTP_SERVER_RESPONSE_TIMEOUT | int        | 1000               |
| NWNX_HTTP_RPC                     | bool       | false              |
| NWNX_HTTP_SERVER_RPC_URL          | string     | /rpc               |
| NWNX_HTTP_SERVER_RPC_AUTH_TOKEN   | string     |                    |

## Setup
### Client
The Client commands are functional by simply loading the plugin. 
### Server
The server will run when `NWNX_HTTP_SERVER` is set to `true`.
It will be accessible by default on port 8686 (configured with `NWNX_HTTP_SERVER_PORT`) but further
configuration is necessary as by default visiting http://your.host:8686 will return a `403 Forbidden` error.

If you wish your server to return information when visiting the root level then you must set the
`NWNX_HTTP_SERVER_ROOT_STATUS` to `200`. By default this returns a simple "Welcome to nwnx http" web page, 
but this content can be controlled with the `NWNX_HTTP_SERVER_ROOT_HTML` environment variable.

The server can also be configured to run on https by setting `NWNX_HTTP_USE_SSL` to `true` and placing
a `cert.pem` and `key.pem` in the same folder as your `NWNX_HTTP.so`. Alternatively, you can configure 
the name and path to the certificate and private key with the 
`NWNX_HTTP_SERVER_SSL_CERT_FILE` and `NWNX_HTTP_SERVER_SSL_KEY_FILE` environment variables. 
**Remember that the user that runs the nwn-server must be able to read both these files.**

### RPC
In addition to the regular GET protocol that the Server handles, the plugin includes a more robust RPC Server that handles 
a POST request event which can accept form-urlencoded or json data. To enable this RPC server set `NWNX_HTTP_RPC` to `true`.

The RPC server supports an authentication token by setting the `NWNX_HTTP_SERVER_RPC_AUTH_TOKEN` environment variable to a 
value of your choosing. Optionally you can simply set the `NWNX_HTTP_SERVER_RPC_URL` to an obscure URL much like Discord
does with their webhooks. An example command to produce either this token or url is 
`ruby -rsecurerandom -e 'puts SecureRandom.hex(32)`. You can set both or either but you must set at least one.

If you do not set an `NWNX_HTTP_SERVER_RPC_URL` environment variable then the url will be `/rpc`.

## Events
### Server Event Setup
The true utility of the HTTP Server is broadcasting a call to the `NWNX_ON_HTTP_SERVER_GET` event. The builder begins
by setting an environment variable `NWNX_HTTP_SERVER_EVENT_URL` for a path wildcard that accepts requests,
for example `/nwnx/(.*)`. When this is set and an http client visits http://your.site:8686/nwnx/testing an
`NWNX_ON_HTTP_SERVER_GET` event will be signalled. The Event Data is the path `PATH` and a unique integer `REQUEST_ID`.
Once the event is sent to your nwscript you build the response you wish to return and then send it back with the
`NWNX_HTTP_Server_SendResponse()` command.

Here's an example of the functionality.
1. In your `on_module_load.nss` script subscribe to the `NWNX_ON_HTTP_SERVER_GET` event, for example:
   `NWNX_Events_SubscribeEvent("NWNX_ON_HTTP_SERVER_GET", "event_http_get");`
2. In your `event_http_get.nss` script you would have something like below:
```c
#include "nwnx_events"
#include "nwnx_http"

void main()
{
    object oModule = OBJECT_SELF;
    if (NWNX_Events_GetCurrentEvent() == "NWNX_ON_HTTP_SERVER_GET")
    {
        int nRequestId = StringToInt(NWNX_Events_GetEventData("REQUEST_ID"));
        string sPath = NWNX_Events_GetEventData("PATH");
        if (sPath == "/nwnx/testing")
            NWNX_HTTP_Server_SendResponse(nRequestId, "<html><head><title>Testing</title></head><body>This is a test</body></html>");
    }
```
### RPC Event Setup
Much like the HTTP Server, the RPC Server signals an `NWNX_ON_HTTP_SERVER_POST` event. The data included with this event
includes `REQUEST_ID` and either `JSON_DATA` or if using form-urlencoded data it sends `PARAM_COUNT` and `PARAM_KEY_#` and
`PARAM_VALUE_#` pairs for the builder to loop through in the event handler script.

Here's an example of an RPC event handler.
1. In your `on_module_load.nss` script subscribe to the `NWNX_ON_HTTP_SERVER_POST` event, for example:
   `NWNX_Events_SubscribeEvent("NWNX_ON_HTTP_SERVER_POST", "event_http_post");`
2. In your `event_http_post.nss` script you would have something like below. Please note that extracting data
   from json is not the intention of this tutorial and the example below is quite sophisticated. 
   You may wish to use the PARAM_COUNT and looping through PARAM_KEY/VALUE pairs instead but this example is given as a reference
   point for understanding how to use sqlite to get json data.

```c
#include "nwnx_events"
#include "nwnx_http"

void main()
{
    object oModule = OBJECT_SELF;
    if (NWNX_Events_GetCurrentEvent() == "NWNX_ON_HTTP_SERVER_POST")
    {
        int nRequestId = StringToInt(NWNX_Events_GetEventData("REQUEST_ID"));
        string sJSONData = NWNX_Events_GetEventData("JSON_DATA");
        object oModule = GetModule();
        
        // Find the json for the functions
        string stmt = "SELECT json_extract(@json_data, @key)";
        sqlquery sqlQuery = SqlPrepareQueryObject(oModule, stmt);
        SqlBindString(sqlQuery, "@json_data", sJSON_Data);
        SqlBindString(sqlQuery, "@key", "$.function");
        string sFunction = "";
        if ( SqlStep(sqlQuery) )
            sFunction = SqlGetString(sqlQuery, 0);
        
        // Find all functions
        stmt = "SELECT key, value FROM json_tree(@json_data) WHERE parent = (SELECT id FROM json_tree(@json_data) WHERE key = 'function')";
        sqlQuery = SqlPrepareQueryObject(oModule, stmt);
        SqlBindString(sqlQuery, "@json_data", sJSON_Data);
        string sResponse = "";
        while (SqlStep(sqlQuery))
        {
            string sFunction = SqlGetString(sqlQuery, 0);
            string sData = SqlGetString(sqlQuery, 1);
            if (sFunction == "SendMessageToPC")
            {
                // Find the key value pairs for this function
                string subStmt = "SELECT * FROM json_tree(@sub_data) WHERE atom IS NOT NULL";
                sqlquery subSqlQuery = SqlPrepareQueryObject(oModule, subStmt);
                SqlBindString(subSqlQuery, "@sub_data", sData);
                while (SqlStep(subSqlQuery))
                {
                    string sName = SqlGetString(subSqlQuery, 0);
                    object oPC = GetPCWithCommunityName(sName);
                    string sMessage = SqlGetString(subSqlQuery, 1);
                    SendMessageToPC(oPC, sMessage);
                    sResponse = sResponse + " " + GetName(oPC);
                }
            }
        }        
        NWNX_HTTP_Server_SendResponse(nRequestId, "Message sent to player(s): " + sResponse);
    }
```
3. The builder sends the following request to his server:
```shell
curl -i http://localhost:8686/b547bd34f896325c4f8f28ec34f895105c38b427fdaf2 -H 'Content-Type: application/json' --data-binary @- << EOF
{
    "function": {
        "SendMessageToPC": {
            "players": [
                { "orth": "Log off." }
            ]
        }
    }
}
EOF
```
4. The builder receives the response: `Message sent to player(s): <PCName>`

## Client Usage
The HTTP Client contains two functions, `NWNX_HTTP_Client_SendRequest()` and `NWNX_HTTP_Client_GetRequest()` and broadcasts two events,
`NWNX_ON_HTTP_CLIENT_SUCCESS` and `NWNX_ON_HTTP_CLIENT_FAILED`.

The builder constructs an `NWNX_HTTP_Client_Request` struct with the appropriate information
then passes that struct into `NWNX_HTTP_Client_SendRequest()` which will return a unique request identifier. The
request is then sent to the host and upon success or failure the respective event is called.

The event data sent is `REQUEST_ID`, `STATUS` and `RESPONSE`. The `REQUEST_ID` 
event data is the integer returned with `NWNX_HTTP_Client_SendRequest()`. The structure for that
request can then be queried via `NWNX_HTTP_Client_GetRequest()`. The `STATUS` event data is the
server HTTP status return code, (usually 200 on success) and the `RESPONSE` is the body of text
the server returned.

Additionally the event data includes Rate Limit information that some servers provide. These are `RATELIMIT_LIMIT` which is how
many requests you can send in a given time period, `RATELIMIT_REMAINING` is how many requests you have left in that
time period and `RATELIMIT_RESET` is an epoch timestamp when the request limit is reset again. There is also `RETRY_AFTER` which
some servers provide which is how long in seconds before you can send another request.

### JSON Helper
The plugin includes a helper library to construct JSON objects for client requests, `nwnx_http_json.nss`.

### Example Client Requests
Here is an example of posting an issue to a github repository.
```c
   int githubJSON = NWNX_HTTP_JSON_NewObject();
   NWNX_HTTP_JSON_ObjectAddString(githubJSON, "title", "Testing HTTP Client");
   NWNX_HTTP_JSON_ObjectAddString(githubJSON, "body", "Text message. You can use Markdown here. *Italic* **bold** __underline__ ~~strikeout~~ [hyperlink](https://google.com) `code`");
   NWNX_HTTP_JSON_ObjectAddString(githubJSON, "assignee", NWNX_Util_GetEnvironmentVariable("GITHUB_USERNAME"));
   int labelsArray = NWNX_HTTP_JSON_NewArray();
   NWNX_HTTP_JSON_ArrayInsertString(labelsArray, "bug");
   NWNX_HTTP_JSON_ArrayInsertString(labelsArray, "help wanted");
   NWNX_HTTP_JSON_ObjectAddArray(githubJSON, "labels", labelsArray);
   string sJSON = NWNX_HTTP_JSON_GetJSONString(githubJSON);
   
   struct NWNX_HTTP_Client_Request stGithubPost;
   stGithubPost.nRequestMethod = NWNX_HTTP_REQUEST_METHOD_POST;
   stGithubPost.sHost = "api.github.com";
   stGithubPost.sPath = NWNX_Util_GetEnvironmentVariable("GITHUB_REPO_PATH") + "/issues";
   stGithubPost.sData = sJSON;
   stGithubPost.nAuthType = NWNX_HTTP_AUTH_TYPE_BASIC;
   stGithubPost.sAuthUserOrToken = NWNX_Util_GetEnvironmentVariable("GITHUB_USERNAME");
   stGithubPost.sAuthPassword = NWNX_Util_GetEnvironmentVariable("GITHUB_NWN_PAT");
   stGithubPost.sHeaders = "Accept: application/vnd.github.v3+json";
   NWNX_HTTP_Client_SendRequest(stGithubPost);
```

Here's an example of insulting a PC when they enter an area
```c
   struct NWNX_HTTP_Client_Request stInsultGen;
   stInsultGen.nRequestMethod = NWNX_HTTP_REQUEST_METHOD_GET;
   stInsultGen.sHost = "evilinsult.com";
   stInsultGen.sPath = "/generate_insult.php";
   stInsultGen.oObject = GetEnteringObject();
   stInsultGen.sTag = "INSULT_ENTERING_PC";
   int nClientRequestId = NWNX_HTTP_Client_SendRequest(stInsultGen);
   SetLocalObject(GetModule(), "INSULTED_" + IntToString(nClientRequestId), GetEnteringObject());
```

Then set up an event:
```c
    if (NWNX_Events_GetCurrentEvent() == "NWNX_ON_HTTP_CLIENT_SUCCESS")
    {
        int nRequestId = StringToInt(NWNX_Events_GetEventData("REQUEST_ID"));
        struct NWNX_HTTP_Client_Request sRequest = NWNX_HTTP_Client_GetRequest(nRequestId);
        if (sRequest.sTag == "INSULT_ENTERING_PC")
        {
            string sResponse = NWNX_Events_GetEventData("RESPONSE");
            object oInsulted = GetLocalObject(GetModule(), "INSULTED_" + IntToString(nClientRequestId));
            SendMessageToPC(oInsulted, sResponse);
            DeleteLocalObject(GetModule(), "INSULTED_" + IntToString(nClientRequestId));
        }
    }
```
