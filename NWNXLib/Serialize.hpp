//
// Helper library to serialize/deserialize game objects.
//

#include <string>
#include <vector>

#include "API/CGameObject.hpp"

namespace NWNXLib {

//
// bStripPCFlags - A serialized PC creature will have the bIsPC set to false,
// so that when deserialized as a new CGameObject, it becomes destroyable.
//
std::vector<uint8_t> SerializeGameObject(API::CGameObject *pObject, bool bStripPCFlags = true);
std::string SerializeGameObjectB64(API::CGameObject *pObject, bool bStripPCFlags = true);

//
// A deserialized object is added to the world at its location when it was serialized
// The location may not be valid, so it is best to explictly move the object immediately
// afterwards. The new object has a unique ObjectID
//
API::CGameObject *DeserializeGameObject(const std::vector<uint8_t>& serialized);
API::CGameObject *DeserializeGameObjectB64(const std::string& serializedB64);

bool AcquireDeserializedItem(API::CGameObject *pItem, API::CGameObject *pOwner, float x, float y, float z);

} // NWNXLib
