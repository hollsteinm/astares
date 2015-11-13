#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include "Array.h"
#include "Pointer.h"
#include "../reflection/Reflection.h"
#include "Asset.h"


struct ILogger;


DECL_CLASS_BASE(AssetManager) {
	DECL_BODY(AssetManager)

public:
	virtual Asset* LoadExternalContent(long typeId, String filename);
	virtual void WriteRegistryToDisk(String filename);
	virtual void LoadRegistryFromDisk(String filename);

	Asset* operator[](int index);
	Asset* Get(int index);

	void SetLogger(ILogger* logger);

private:
	Array<ObjectPtr<Asset>> Registry;
	long currId = 0;

protected:
	ILogger* logger;
};

#endif