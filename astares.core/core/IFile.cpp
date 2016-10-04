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
	bool Read(cstring& out) override;
	bool Write(const cstring& in) override;
	bool Append(const cstring& in) override;
	bool Delete() override;
	bool Create() override;
	cstring Expand() override;
	cstring SafeWriteDir() override;
	bool OpenReadStream(std::ifstream& out, FileMode mode = FileMode::Binary) override;
	bool OpenWriteStream(std::ofstream& out, FileMode mode = FileMode::Binary) override;
	bool OpenReadWriteStream(std::fstream& out, FileMode mode = FileMode::Binary) override;
private:
	cstring filepath;
};

class File {

public:
	static void Init(cstring company, cstring project);

	static bool Read(cstring filepath, cstring& out);
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
	filepath = std::string().append(path, strlen(path)).c_str();
}

StaticFileWrapper::~StaticFileWrapper()
{}

void StaticFileWrapper::Init(cstring company, cstring project) 
{ 
	return File::Init(company, project); 
}

bool StaticFileWrapper::Read(cstring& out) 
{ 
	return File::Read(filepath, out); 
}

bool StaticFileWrapper::Write(const cstring& out) 
{
	return File::Write(filepath, out); 
}

bool StaticFileWrapper::Append(const cstring& in) 
{
	return File::Append(filepath, in); 
}

bool StaticFileWrapper::Delete() 
{
	return File::Delete(filepath); 
}

bool StaticFileWrapper::Create() 
{
	return File::Create(filepath); 
}

cstring StaticFileWrapper::Expand() 
{ 
	return File::Expand(filepath); 
}

cstring StaticFileWrapper::SafeWriteDir() 
{
	return File::SafeWriteDir(); 
}

bool StaticFileWrapper::OpenReadStream(std::ifstream& out, FileMode mode)
{ 
	return File::OpenReadStream(filepath, out, mode); 
}

bool StaticFileWrapper::OpenWriteStream(std::ofstream& out, FileMode mode)
{
	return File::OpenWriteStream(filepath, out, mode);
}

bool StaticFileWrapper::OpenReadWriteStream(std::fstream& out, FileMode mode)
{
	return File::OpenReadWriteStream(filepath, out, mode);
}

IFile* IFile::MakeFile(cstring path) 
{ 
	FilePtrs.push_back(std::make_unique<StaticFileWrapper>(path));
	return FilePtrs.back().get();
}

const cstring File::ContentDir = "Content/";

cstring File::Company = "";
cstring File::Project = "";

void File::Init(cstring company, cstring project) {
	Company = company;
	Project = project;
}

bool File::Read(cstring filepath, cstring& out){
	SDL_RWops* fandle = SDL_RWFromFile(filepath, "r");
	if (fandle != nullptr) {
		auto length = SDL_RWseek(fandle, 0, RW_SEEK_END);
		SDL_RWclose(fandle);
		fandle = SDL_RWFromFile(filepath, "r");
		std::string result;
		if (length > 0 && length < (int64)((uint32)~0)) {
			char* data = new char[(uint32)length];
			memset(data, 0, (size_t)length);
			auto read = SDL_RWread(fandle, data, sizeof(char), (size_t)length);
			result.append(data, (uint32)length);
			delete[] data;
			SDL_RWclose(fandle);
			out = result.c_str();
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
		int32 length = strnlen_s(out, 320);
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