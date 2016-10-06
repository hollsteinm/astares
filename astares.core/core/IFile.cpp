#include "IFile.h"
#include <SDL.h>
#include <iostream>
#include <fstream>
#include <ios>

using namespace astares;

std::vector<std::unique_ptr<IFile>> FilePtrs;

IFile::~IFile()
{}

IFile::IFile()
{}

class StaticFileWrapper : public IFile
{
public:
	StaticFileWrapper(cstring path);
	~StaticFileWrapper();
	void Init(cstring company, cstring project) override;
	bool Read(char*& out, uint64& outSize) override;
	bool Write(cstring in) override;
	bool Append(cstring in) override;
	bool Delete() override;
	bool Create() override;
	cstring Expand() override;
	cstring SafeWriteDir() override;
	bool OpenReadStream(std::ifstream& out, FileMode mode = FileMode::Binary) override;
	bool OpenWriteStream(std::ofstream& out, FileMode mode = FileMode::Binary) override;
	bool OpenReadWriteStream(std::fstream& out, FileMode mode = FileMode::Binary) override;
private:
	std::string filepath;
};

class File {

public:
	static void Init(cstring company, cstring project);

	static bool Read(cstring filepath, char*& out, uint64& outSize);
	static bool Write(cstring filepath, cstring out);
	static bool Append(cstring filepath, cstring in);
	static bool Delete(cstring filepath);
	static bool Create(cstring filepath);

	static cstring Expand(cstring filepath);
	static cstring SafeWriteDir();

	static bool OpenReadStream(cstring path, std::ifstream& out, FileMode mode = FileMode::Binary);
	static bool OpenWriteStream(cstring path, std::ofstream& out, FileMode mode = FileMode::Binary);
	static bool OpenReadWriteStream(cstring path, std::fstream& out, FileMode mode = FileMode::Binary);

private:
	static const cstring ContentDir;
	static cstring Company;
	static cstring Project;
};

StaticFileWrapper::StaticFileWrapper(cstring path)
{
	auto safeDir = File::SafeWriteDir();
	filepath = std::string(safeDir, strlen(safeDir)).append(path, strlen(path));
}

StaticFileWrapper::~StaticFileWrapper()
{}

void StaticFileWrapper::Init(cstring company, cstring project) 
{ 
	return File::Init(company, project); 
}

bool StaticFileWrapper::Read(char*& out, uint64& outSize)
{ 
	return File::Read(filepath.c_str(), out, outSize); 
}

bool StaticFileWrapper::Write(cstring out) 
{
	return File::Write(filepath.c_str(), out);
}

bool StaticFileWrapper::Append(cstring in) 
{
	return File::Append(filepath.c_str(), in);
}

bool StaticFileWrapper::Delete() 
{
	return File::Delete(filepath.c_str());
}

bool StaticFileWrapper::Create() 
{
	return File::Create(filepath.c_str());
}

cstring StaticFileWrapper::Expand() 
{ 
	return File::Expand(filepath.c_str());
}

cstring StaticFileWrapper::SafeWriteDir() 
{
	return File::SafeWriteDir(); 
}

bool StaticFileWrapper::OpenReadStream(std::ifstream& out, FileMode mode)
{ 
	return File::OpenReadStream(filepath.c_str(), out, mode);
}

bool StaticFileWrapper::OpenWriteStream(std::ofstream& out, FileMode mode)
{
	return File::OpenWriteStream(filepath.c_str(), out, mode);
}

bool StaticFileWrapper::OpenReadWriteStream(std::fstream& out, FileMode mode)
{
	return File::OpenReadWriteStream(filepath.c_str(), out, mode);
}

IFile* IFile::MakeFile(cstring path) 
{ 
	FilePtrs.push_back(std::make_unique<StaticFileWrapper>(path));
	return FilePtrs.back().get();
}

const cstring File::ContentDir = "Content/";

cstring File::Company = "A";
cstring File::Project = "B";

void File::Init(cstring company, cstring project) {
	Company = company;
	Project = project;
}

bool File::Read(cstring filepath, char*& out, uint64& outSize){
	if (out != nullptr)
	{
		delete[] out;
	}
	SDL_RWops* fandle = SDL_RWFromFile(filepath, "r");
	if (fandle != nullptr) {
		auto length = SDL_RWseek(fandle, 0, RW_SEEK_END);
		SDL_RWclose(fandle);
		fandle = SDL_RWFromFile(filepath, "r");
		if (length > 0 && length < (int64)((uint32)~0)) {
			out = new char[(uint32)length + 1];
			memset(out, 0, (size_t)length + 1);
			auto read = SDL_RWread(fandle, &out[0], sizeof(char), (size_t)length);
			outSize = read;
			SDL_RWclose(fandle);
			out[length + 1] = '\0';
			return read > 0;
		}
		else {
			SDL_RWclose(fandle);
			return false;
		}
	}
	else {
		return false;
	}
}

static bool DoWrite(cstring filepath, cstring out, const char* mode) {
	SDL_RWops* fandle = SDL_RWFromFile(filepath, mode);
	if (fandle != nullptr) {
		int32 length = strnlen_s(out, INT_MAX);
		SDL_RWwrite(fandle, out, sizeof(char), length);
		SDL_RWclose(fandle);
		return true;
	}
	else {
		return false;
	}
}

bool File::Write(cstring filepath, cstring out){
	return DoWrite(filepath, out, "w");
}

bool File::Append(cstring filepath, cstring in){
	return DoWrite(filepath, in, "a");
}

bool File::Delete(cstring filepath){
	return std::remove(filepath) == 0;
}

bool File::Create(cstring filepath){
	SDL_RWops* fandle = SDL_RWFromFile(filepath, "w");
	if (fandle != nullptr) {
		SDL_RWclose(fandle);
		return true;
	}
	else {
		return false;
	}
}

cstring File::Expand(cstring filepath) {
	std::string path(filepath, strnlen_s(filepath, 320));
	if (path[0] == '/' || path[0] == '\\'){
		path = path.substr(1, path.size());
	}

	return std::string(SafeWriteDir()).append(ContentDir).append(path).c_str();
}

cstring File::SafeWriteDir(){
	char* path = SDL_GetPrefPath(Company, Project);
	if (path != nullptr) {
		return path;
	}
	else {
		return "./";
	}
}

bool File::OpenReadStream(cstring path, std::ifstream& out, FileMode mode) {
	switch (mode._value)
	{
	case FileMode::Binary:
		out = std::ifstream(path, std::ios::in | std::ios::binary);
	case FileMode::Text:
	default:
		out = std::ifstream(path);
		break;
	}
	return out.is_open();
}

bool File::OpenWriteStream(cstring path, std::ofstream& out, FileMode mode) {
	switch (mode._value)
	{
	case FileMode::Binary:
		out = std::ofstream(path, std::ios::out | std::ios::binary);
	case FileMode::Text:
	default:
		out = std::ofstream(path);
		break;
	}
	return out.is_open();
}

bool File::OpenReadWriteStream(cstring path, std::fstream& out, FileMode mode) {
	switch (mode._value)
	{
	case FileMode::Binary:
		out = std::fstream(path, std::ios::out | std::ios::in | std::ios::binary);
		break;
	case FileMode::Text:
	default:
		out = std::fstream(path);
		break;
	}
	return out.is_open();
}