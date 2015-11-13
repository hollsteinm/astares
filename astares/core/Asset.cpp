#include "Asset.h"

Asset::Asset() :
 AssetId(-1)
{
	CTOR_REGISTER(Asset)
}

Asset::~Asset() {

}

Asset::Asset(long id) {
	AssetId = id;
}

bool Asset::ImportFromFile(String filename) {
	return false;
}

long Asset::GetAssetId() const{
	return AssetId;
}

REFLECTION_BEGIN(Asset)
	PARENT(Object)
	FIELD(long, AssetId)
REFLECTION_END(Asset)