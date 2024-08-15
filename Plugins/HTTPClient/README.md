@page httpclient Readme
@ingroup httpclient

## Introduction
The HTTPClient Plugin provides access to an HTTP Client to perform requests and return responses.

## Environment Variables

| Variable Name                     |  Type      | Default Value      |
| ----------------------------------| :--------: | ------------------ |
| NWNX_HTTPCLIENT_REQUEST_TIMEOUT  | int        | 2000               |

## Setup
### Client
The Client commands are functional by simply loading the plugin. 

## Client Usage
The HTTP Client contains two functions, `NWNX_HTTPClient_SendRequest()` and `NWNX_HTTPClient_GetRequest()` and broadcasts two events,
`NWNX_ON_HTTPCLIENT_SUCCESS` and `NWNX_ON_HTTPCLIENT_FAILED`.

The builder constructs an `NWNX_HTTPClient_Request` struct with the appropriate information
then passes that struct into `NWNX_HTTPClient_SendRequest()` which will return a unique request identifier. The
request is then sent to the host and upon success or failure the respective event is called.

The event data sent is `REQUEST_ID`, `STATUS` and `RESPONSE`. The `REQUEST_ID` 
event data is the integer returned with `NWNX_HTTPClient_SendRequest()`. The structure for that
request can then be queried via `NWNX_HTTPClient_GetRequest()`. The `STATUS` event data is the
server HTTP status return code, (usually 200 on success) and the `RESPONSE` is the body of text
the server returned.

Additionally the event data includes Rate Limit information that some servers provide. These are `RATELIMIT_LIMIT` which is how
many requests you can send in a given time period, `RATELIMIT_REMAINING` is how many requests you have left in that
time period and `RATELIMIT_RESET` is an epoch timestamp when the request limit is reset again. There is also `RETRY_AFTER` which
some servers provide which is how long in seconds before you can send another request.

### Example Client Requests
Here is an example of posting an issue to a github repository.
```c
    json githubJSON = JsonObject();
    githubJSON = JsonObjectSet(githubJSON, "title", JsonString(GetModuleName() + " NWN Bug Report via "+sAuthorName));
    githubJSON = JsonObjectSet(githubJSON, "body", JsonString(sMessage+"<br>Area Name: **"+ GetName(oArea) +
         "**<br>Area Tag: **"+ GetTag(oArea) +
         "**<br>Location: **" + NWNXLocationToString(GetLocation(oReporter)) +
         "**<br>Tile Model: **" + sTileModel + "**"));
    githubJSON = JsonObjectSet(githubJSON, "assignee", JsonString(NWNX_Util_GetEnvironmentVariable("GITHUB_USERNAME")));
    json jLabels = JsonArray();
    jLabels = JsonArrayInsert(jLabels, JsonString("bug"));
    jLabels = JsonArrayInsert(jLabels, JsonString("help wanted"));
    githubJSON = JsonObjectSet(githubJSON, "labels", jLabels);


    struct NWNX_HTTPClient_Request stGithubPost;
    stGithubPost.nRequestMethod = NWNX_HTTPCLIENT_REQUEST_METHOD_POST;
    stGithubPost.sHost = "api.github.com";
    stGithubPost.sPath = NWNX_Util_GetEnvironmentVariable("GITHUB_REPO_PATH") + "/issues";
    stGithubPost.sData = JsonDump(githubJSON);
    stGithubPost.nAuthType = NWNX_HTTPCLIENT_AUTH_TYPE_BASIC;
    stGithubPost.sAuthUserOrToken = NWNX_Util_GetEnvironmentVariable("GITHUB_USERNAME");
    stGithubPost.sAuthPassword = NWNX_Util_GetEnvironmentVariable("GITHUB_NWN_PAT");
    stGithubPost.sHeaders = "Accept: application/vnd.github.v3+json";
    stGithubPost.nContentType = NWNX_HTTPCLIENT_CONTENT_TYPE_JSON;
    NWNX_HTTPClient_SendRequest(stGithubPost);
```

Here's an example of insulting a PC when they enter an area
```c
   struct NWNX_HTTPClient_Request stInsultGen;
   stInsultGen.nRequestMethod = NWNX_HTTPCLIENT_REQUEST_METHOD_GET;
   stInsultGen.sHost = "evilinsult.com";
   stInsultGen.sPath = "/generate_insult.php";
   stInsultGen.oObject = GetEnteringObject();
   stInsultGen.sTag = "INSULT_ENTERING_PC";
   int nClientRequestId = NWNX_HTTPClient_SendRequest(stInsultGen);
   SetLocalObject(GetModule(), "INSULTED_" + IntToString(nClientRequestId), GetEnteringObject());
```

Then set up an event:
```c
    if (NWNX_Events_GetCurrentEvent() == "NWNX_ON_HTTPCLIENT_SUCCESS")
    {
        int nRequestId = StringToInt(NWNX_Events_GetEventData("REQUEST_ID"));
        struct NWNX_HTTPClient_Request sRequest = NWNX_HTTPClient_GetRequest(nRequestId);
        if (sRequest.sTag == "INSULT_ENTERING_PC")
        {
            string sResponse = NWNX_Events_GetEventData("RESPONSE");
            object oInsulted = GetLocalObject(GetModule(), "INSULTED_" + IntToString(nClientRequestId));
            SendMessageToPC(oInsulted, sResponse);
            DeleteLocalObject(GetModule(), "INSULTED_" + IntToString(nClientRequestId));
        }
    }
```
