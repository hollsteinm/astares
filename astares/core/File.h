#ifndef FILE_H
#define FILE_H

#include "Types.h"

BETTER_ENUM(FileMode, int8, 
	Text,
	Binary)

class File {

public:
	static void Init(string company, string project);

	static bool Read(string filepath, string& out);
	static bool Write(string filepath, string out);
	static bool Append(string filepath, string in);
	static bool Delete(string filepath);
	static bool Create(string filepath);

	static string Expand(string filepath);
	static string SafeWriteDir();

	static std::istream& ReadStream(string path, FileMode mode = FileMode::Binary);
	static std::ostream& WriteStream(string path, FileMode mode = FileMode::Binary);


private:
	static const string ContentDir;
	static string Company;
	static string Project;
};


#endif