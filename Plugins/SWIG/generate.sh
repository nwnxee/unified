#!/bin/bash
NWNXLIB_SWG="${NWNXLIB_SWG:-NWNXLib.i}"
FIRST_INCLUDES=(${FIRST_INCLUDES[@]:-"Functions.hpp" "API/CExoPackedFile.hpp" "API/CCallbackHandlerBase.hpp" "API/CGameObject.hpp" "API/CRes.hpp" "API/CResStruct.hpp" "API/CResGFF.hpp" "API/CNWSObject.hpp" "API/CNWTile.hpp" "API/CNWTileSet.hpp" "API/CVirtualMachineCmdImplementer.hpp" "API/STR_RES_HEADER_OLD.hpp" "API/CAurObjectVisualTransformData.hpp" "API/CNWSClient.hpp" "API/CNWMessage.hpp" "API/CExoFile.hpp" "API/CNWSClient.hpp" "API/CExoFile.hpp" "API/CGameEffectApplierRemover.hpp" "API/CNWItem.hpp" "API/CBaseExoApp.hpp" "API/CNWArea.hpp"})

echo "%{" > $NWNXLIB_SWG
find ../../../NWNXLib/API -type f -name '*.hpp' -printf '#include "%P"\n' | sort >> $NWNXLIB_SWG
echo "%}" >> $NWNXLIB_SWG

for include in "${FIRST_INCLUDES[@]}"
do
    echo "%include \"$include\"" >> $NWNXLIB_SWG
done

find ../../../NWNXLib/API -type f -name '*.hpp' -printf '%%include "%P"\n' | sort >> $NWNXLIB_SWG

swig ${@:1}
