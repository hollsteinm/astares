#include "File.h"
#include <SDL.h>
#include <fstream>

const string File::ContentDir = "Content/";

string File::Company = "";
string File::Project = "";

void File::Init(string company, string project) {
	Company = company;
	Project = project;
}

bool File::Read(string filepath, string& out){
	SDL_RWops* fandle = SDL_RWFromFile(filepath.c_str(), "r");
	if (fandle != nullptr) {
		long length = (long)SDL_RWseek( fandle, 0, RW_SEEK_END );
		SDL_RWclose(fandle);
		fandle = SDL_RWFromFile(filepath.c_str(), "r");
		if (length > 0) {
			char* data = new char[length];
			memset(data, 0, length);

			int32 read = SDL_RWread(fandle, data, sizeof(char), length);

			out.append(data, length);
			delete[] data;
			SDL_RWclose(fandle);

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

static bool DoWrite(string filepath, string out, const char* mode) {
	SDL_RWops* fandle = SDL_RWFromFile(filepath.c_str(), mode);
	if (fandle != nullptr) {
		int32 length = out.size();
		const char* data = out.c_str();
		SDL_RWwrite(fandle, data, sizeof(char), length);
		SDL_RWclose(fandle);
		return true;
	}
	else {
		return false;
	}
}

bool File::Write(string filepath, string out){
	return DoWrite(filepath, out, "w");
}

bool File::Append(string filepath, string in){
	return DoWrite(filepath, in, "a");
}

bool File::Delete(string filepath){
	return std::remove(filepath.c_str()) == 0;
}

bool File::Create(string filepath){
	SDL_RWops* fandle = SDL_RWFromFile(filepath.c_str(), "w");
	if (fandle != nullptr) {
		SDL_RWclose(fandle);
		return true;
	}
	else {
		return false;
	}
}

string File::Expand(string filepath) {
	if (filepath[0] == '/' || filepath[0] == '\\'){
		filepath = filepath.substr(1, filepath.size());
	}

	return SafeWriteDir().append(ContentDir).append(filepath);
}

string File::SafeWriteDir(){
	char* path = SDL_GetPrefPath(Company.c_str(), Project.c_str());
	if (path != nullptr) {
		int32 size = strlen(path);
		string result(path, size);
		return result;
	}
	else {
		return "./";
	}
}

std::istream& File::ReadStream(string path, FileMode mode) {
	switch (mode._value)
	{
	case FileMode::Binary:
		return std::ifstream(path, std::ios::in | std::ios::binary);
	case FileMode::Text:
	default:
		return std::ifstream(path);
		break;
	}
}

std::ostream& File::WriteStream(string path, FileMode mode) {
	switch (mode._value)
	{
	case FileMode::Binary:
		return std::ofstream(path, std::ios::out | std::ios::binary);
	case FileMode::Text:
	default:
		return std::ofstream(path);
		break;
	}
}