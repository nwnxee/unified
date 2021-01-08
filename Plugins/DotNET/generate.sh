#!/bin/bash
SWG="${SWG:-DotNET.i}"
PLUGIN="${PLUGIN:-NWNX_DotNET}"
NWNXLIB_SWG="${NWNXLIB_SWG:-NWNXLib.i}"
NWNXLIB_ROOT="${NWNXLIB_ROOT:-../../NWNXLib/API}"
NAMESPACE="${NAMESPACE:-NWN.Native.API}"
OUTDIR="${OUTDIR:-./Interop}"
INTEROP_FILE="${INTEROP_FILE:-DotNETInterop.cpp}"
INCLUDES=(${INCLUDES[@]:-"API/CExoPackedFile.hpp" "API/CCallbackHandlerBase.hpp" "API/CGameObject.hpp" "API/CRes.hpp" "API/CResStruct.hpp" "API/CResGFF.hpp" "API/CNWSObject.hpp" "API/CNWTile.hpp" "API/CNWTileSet.hpp" "API/CVirtualMachineCmdImplementer.hpp" "API/STR_RES_HEADER_OLD.hpp"})
EXCLUDES=(${EXCLUDES[@]:-"Functions.hpp" "FunctionsLinux.hpp" "nwn_api.hpp" "PlatformIntrinsicsProvider.hpp" "StorageShard.hpp" "out_of_space_error.hpp" "DestroyHelper.hpp" "StartupConfig.hpp" "StorageShardAllocParams.hpp" "CNetLayerWindow.hpp" "CExoResFile.hpp" "CExoIdentity.hpp" "CExoInput*.hpp" "*Internal.hpp" "CNWAnimBase.hpp" "CExoApp.hpp" "CNWSAnimBase.hpp" "CNWSSound.hpp" "CNWSScriptVarTable.hpp" "CNWSScriptVar.hpp"})

FIND_ARGS=()
for exclude in "${EXCLUDES[@]}"; do
    FIND_ARGS+=('!' '-name' "*$exclude")
done

echo "%{" > $NWNXLIB_SWG
find ../../NWNXLib/API -type f -name '*.hpp' "${FIND_ARGS[@]}" -printf '#include "%P"\n' >> $NWNXLIB_SWG
echo "%}" >> $NWNXLIB_SWG

for include in "${INCLUDES[@]}"
do
    echo "%include \"$include\"" >> $NWNXLIB_SWG
done

find ../../NWNXLib/API -type f -name '*.hpp' "${FIND_ARGS[@]}" -printf '%%include "%P"\n' >> $NWNXLIB_SWG

mkdir -p $OUTDIR
swig -v -c++ -fcompact -csharp -dllimport $PLUGIN -namespace $NAMESPACE -o $INTEROP_FILE -outdir $OUTDIR -I$NWNXLIB_ROOT $SWG