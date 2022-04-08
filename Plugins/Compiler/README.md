@addtogroup compiler Compiler
@page compiler Readme
@ingroup compiler

Compiles all Neverwinter source files from the specified directory to the specified output directory, before shutting down the server.

## Environment Variables

| Variable Name | Value | Default | Notes |
| ------------- | :---: | ------- | ----- |
| `NWNX_COMPILER_SRC_DIR` | string | Unset | The directory containing the source .nss files.
| `NWNX_COMPILER_OUT_DIR` | string | Unset | The directory to output the compiled .ncs files.
| `NWNX_COMPILER_CLEAN_COMPILE` | true/false | false | Cleans all .ncs files from the output directory.
| `NWNX_COMPILER_CONTINUE_ON_ERROR` | true/false | false | Continue processing scripts after a compiler error.
| `NWNX_COMPILER_EXIT_ON_COMPLETE` | true/false | true | After completing compilation, shuts down the server.
| `NWNX_COMPILER_DEBUG_LEVEL` | int | 0 | CScriptCompiler->SetCompileDebugLevel()
| `NWNX_COMPILER_SYMBOLIC_OUTPUT` | int | 0 | CScriptCompiler->SetCompileSymbolicOutput()
| `NWNX_COMPILER_GENERATE_DEBUGGER_OUTPUT` | int | 0 | CScriptCompiler->SetGenerateDebuggerOutput()
| `NWNX_COMPILER_OPTIMIZE_BINARY_CODE_LENGTH` | true/false | true | CScriptCompiler->SetOptimizeBinaryCodeLength()
