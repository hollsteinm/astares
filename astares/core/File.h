#ifndef FILE_H
#define FILE_H

#include <string>

class File {

public:
	static void Init(std::string company, std::string project);

	static bool Read(std::string filepath, std::string& out);
	static bool Write(std::string filepath, std::string out);
	static bool Append(std::string filepath, std::string in);
	static bool Delete(std::string filepath);
	static bool Create(std::string filepath);

	static std::string Expand(std::string filepath);
	static std::string SafeWriteDir();


private:
	static const std::string ContentDir;
	static std::string Company;
	static std::string Project;
};


#endif