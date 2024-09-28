#!/bin/bash
NWNXLIB_SWG="${NWNXLIB_SWG:-NWNXLib.i}"
FIRST_INCLUDES=(${FIRST_INCLUDES[@]:-"API/CExoPackedFile.hpp" "API/CCallbackHandlerBase.hpp" "API/CGameObject.hpp" "API/CRes.hpp" "API/CResStruct.hpp" "API/CResGFF.hpp" "API/CNWSObject.hpp" "API/CNWTile.hpp" "API/CNWTileSet.hpp" "API/CVirtualMachineCmdImplementer.hpp" "API/STR_RES_HEADER_OLD.hpp" "API/CAurObjectVisualTransformData.hpp" "API/CNWMessage.hpp" "API/CExoFile.hpp" "API/CExoFile.hpp" "API/CGameEffectApplierRemover.hpp" "API/CNWItem.hpp" "API/CBaseExoApp.hpp" "API/CNWArea.hpp"})
EXCLUDES=(${EXCLUDES[@]:-"Functions.hpp" "FunctionsLinux.hpp" "CExoArrayList.hpp"})

FIND_ARGS=()
for exclude in "${EXCLUDES[@]}"; do
    FIND_ARGS+=('!' '-name' "*$exclude")
done

echo "%{" > $NWNXLIB_SWG
echo "#include \"External/sqlite3/include/sqlite3.h\"" >> $NWNXLIB_SWG
echo "#include \"External/sqlite3/sqlite_modern_cpp/sqlite_modern_cpp.h\"" >> $NWNXLIB_SWG

find ../../../NWNXLib/API -type f -name '*.hpp' "${FIND_ARGS[@]}" -printf '#include "%P"\n' | sort >> $NWNXLIB_SWG
echo "%}" >> $NWNXLIB_SWG

echo "%include NamespaceUsings.i" >> $NWNXLIB_SWG
echo "%include sqlite3.i" >> $NWNXLIB_SWG

for include in "${FIRST_INCLUDES[@]}"
do
    echo "%include \"$include\"" >> $NWNXLIB_SWG
done

find ../../../NWNXLib/API -type f -name '*.hpp' "${FIND_ARGS[@]}" -printf '%%include "%P"\n' | sort >> $NWNXLIB_SWG
