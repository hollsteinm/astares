#include "File.h"
#include <SDL.h>

const String File::ContentDir = "Content/";

String File::Company = "";
String File::Project = "";

void File::Init(String company, String project) {
	Company = company;
	Project = project;
}

bool File::Read(String filepath, String& out){
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

static bool DoWrite(String filepath, String out, const char* mode) {
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

bool File::Write(String filepath, String out){
	return DoWrite(filepath, out, "w");
}

bool File::Append(String filepath, String in){
	return DoWrite(filepath, in, "a");
}

bool File::Delete(String filepath){
	return std::remove(filepath.c_str()) == 0;
}

bool File::Create(String filepath){
	SDL_RWops* fandle = SDL_RWFromFile(filepath.c_str(), "w");
	if (fandle != nullptr) {
		SDL_RWclose(fandle);
		return true;
	}
	else {
		return false;
	}
}

String File::Expand(String filepath) {
	if (filepath[0] == '/' || filepath[0] == '\\'){
		filepath = filepath.substr(1, filepath.size());
	}

	return SafeWriteDir().append(ContentDir).append(filepath);
}

String File::SafeWriteDir(){
	char* path = SDL_GetPrefPath(Company.c_str(), Project.c_str());
	if (path != nullptr) {
		int size = strlen(path);
		String result(path, size);
		return result;
	}
	else {
		return "./";
	}
}