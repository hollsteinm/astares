#ifndef ASSET_H
#define ASSET_H

#include "../reflection/Reflection.h"

DECL_CLASS_BASE(Asset) {
	DECL_BODY(Asset)

	friend class AssetManager;


	public:
		Asset(long id);

		long GetAssetId() const;

		virtual bool ImportFromFile(String filename);

		friend void Assign(Asset* asset, long id);

	private:
		long AssetId;
};


#endif