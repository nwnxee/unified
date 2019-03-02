# Regex Plugin Reference

## Description

Provide regular expression functions. Due to the complications with using backslashes in nwscript, a configurable substring to use instead of backslashes is available. The default is a double exclamation point.

## Environment Variables

| Variable Name     |  Type                   | Default Value                      |
| ----------------- | :---------------------: | ---------------------------------- |
| `BACKSLASH_SUBSTRING`      | string                  | !!             |
