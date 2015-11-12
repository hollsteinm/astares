#include "File.h"
#include <SDL.h>

const std::string File::ContentDir = "Content/";

std::string File::Company = "";
std::string File::Project = "";

void File::Init(std::string company, std::string project) {
	Company = company;
	Project = project;
}

bool File::Read(std::string filepath, std::string& out){
	SDL_RWops* fandle = SDL_RWFromFile(filepath.c_str(), "r");
	if (fandle != nullptr) {
		long length = (long)SDL_RWseek( fandle, 0, RW_SEEK_END );
		SDL_RWclose(fandle);
		fandle = SDL_RWFromFile(filepath.c_str(), "r");
		if (length > 0) {
			char* data = new char[length];
			memset(data, 0, length);

			int read = SDL_RWread(fandle, data, sizeof(char), length);

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

static bool DoWrite(std::string filepath, std::string out, const char* mode) {
	SDL_RWops* fandle = SDL_RWFromFile(filepath.c_str(), mode);
	if (fandle != nullptr) {
		int length = out.size();
		const char* data = out.c_str();
		SDL_RWwrite(fandle, data, sizeof(char), length);
		SDL_RWclose(fandle);
		return true;
	}
	else {
		return false;
	}
}

bool File::Write(std::string filepath, std::string out){
	return DoWrite(filepath, out, "w");
}

bool File::Append(std::string filepath, std::string in){
	return DoWrite(filepath, in, "a");
}

bool File::Delete(std::string filepath){
	return std::remove(filepath.c_str()) == 0;
}

bool File::Create(std::string filepath){
	SDL_RWops* fandle = SDL_RWFromFile(filepath.c_str(), "w");
	if (fandle != nullptr) {
		SDL_RWclose(fandle);
		return true;
	}
	else {
		return false;
	}
}

std::string File::Expand(std::string filepath) {
	if (filepath[0] == '/' || filepath[0] == '\\'){
		filepath = filepath.substr(1, filepath.size());
	}

	return SafeWriteDir().append(ContentDir).append(filepath);
}

std::string File::SafeWriteDir(){
	char* path = SDL_GetPrefPath(Company.c_str(), Project.c_str());
	if (path != nullptr) {
		int size = strlen(path);
		std::string result(path, size);
		return result;
	}
	else {
		return "./";
	}
}