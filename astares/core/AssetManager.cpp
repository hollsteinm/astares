#include "AssetManager.h"
#include "ObjectFactory.h"
#include <sstream>
#include "File.h"
#include "../log/ILogger.h"

AssetManager::AssetManager() {
	CTOR_REGISTER(AssetManager)
}

AssetManager::~AssetManager() {
	Registry.clear();
}

Asset* AssetManager::LoadExternalContent(long typeId, String filename) {
	Asset* asset = (Asset*)ObjectFactory::Get().CreateNew(typeId);
	if (asset != nullptr) {
		String fullpath = File::Expand(filename);
		if (asset->ImportFromFile(fullpath)) {
			Assign(asset, currId++);
			Registry.push_back(ObjectPtr<Asset>(asset));
		}
		else {
			delete asset;
			asset = nullptr;
			if (logger != nullptr){
				logger->Warn("Unable to load asset from %s", fullpath.c_str());
			}
		}
	}
	else {
		if (logger != nullptr){
			logger->Warn("Invalid typeId %i", typeId);
		}
	}
	return asset;
}

void AssetManager::WriteRegistryToDisk(String filename) {
	std::stringstream str;
	String fullpath = File::Expand(filename);
	if (Write(str)){
		if (!File::Write(fullpath, str.str())){
			if (logger != nullptr){
				logger->Warn("Unable to save asset registry to %s", fullpath.c_str());
			}
		}
		str.clear();
	}
	else {
		if (logger != nullptr) {
			logger->Error("Could not write serialization buffer!");
		}
	}
}

void AssetManager::LoadRegistryFromDisk(String filename) {
	String dat;
	String fullpath = File::Expand(filename);
	if (File::Read(fullpath, dat)){
		std::stringstream str(dat);
		if (!Read(str)){
			if (logger != nullptr) {
				logger->Error("Could not read serialization buffer: %s", dat.c_str());
			}
		}
		else {
			str.clear();
		}
	}
	else {
		if (logger != nullptr){
			logger->Warn("Unable to load asset registry from %s", fullpath.c_str());
		}
	}
}

void AssetManager::SetLogger(ILogger* logger) {
	this->logger = logger;
}

void Assign(Asset* asset, long id) {
	asset->AssetId = id;
}

Asset* AssetManager::operator[](int index) {
	return Registry[index].Get();
}

Asset* AssetManager::Get(int index) {
	return Registry[index].Get();
}

REFLECTION_BEGIN(AssetManager)
	PARENT(Object)
	FIELD(Array<ObjectPtr<Asset>>, Registry)
REFLECTION_END(AssetManager)