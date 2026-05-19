@page bridge Readme
@ingroup bridge

This is a work in progress.

This plugin aims to provide a way to communicate between different server instances, including cross-server chat messages and shared player lists.

Disclaimer: I haven't been able to test many of the possible scenarios and the current code is a working prototype. Use the plugin at your own risk.

## Working features

* Shared shout, DM and tell messages between servers
* Shared player lists between servers

## Planned features

* API to access this plugin's features through HTTP/HTTPs
* Discord integration
* Expose functions to NWScript
* Add callback support (nwscripts) for custom events

## Environment Variables
|Name | Description | Default value|
|-----|-------------|--------------|
|NWNX_BRIDGE_CLIENT| Controls whether this is a client or the master server | true |
|NWNX_BRIDGE_PORT | Port to use | 8888|
|NWNX_BRIDGE_KEY_PATH | Path to the private key file | "key.pem" |
|NWNX_BRIDGE_CERT_PATH | Path to the certificate file | "cert.pem" |
|NWNX_BRIDGE_SELFSIGN_CERT | Allow generation of self-signed certificates | false |
|NWNX_BRIDGE_PASSWORD | Password to use as added security | empty |
|NWNX_BRIDGE_HOST | Host to connect to. Only used by clients | empty |

## Environment example
### Master server
```
NWNX_BRIDGE_SKIP=false
NWNX_BRIDGE_CLIENT=false
NWNX_BRIDGE_PORT=8888
NWNX_BRIDGE_KEY_PATH=
NWNX_BRIDGE_CERT_PATH=
NWNX_BRIDGE_SELFSIGN_CERT=1
NWNX_BRIDGE_PASSWORD=password
```

### Client
```
NWNX_BRIDGE_SKIP=false
NWNX_BRIDGE_CLIENT=true
NWNX_BRIDGE_PORT=8888
NWNX_BRIDGE_HOST=nwserver
NWNX_BRIDGE_PASSWORD=password
```