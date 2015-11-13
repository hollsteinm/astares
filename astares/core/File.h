#ifndef FILE_H
#define FILE_H

#include "../core/String.h"

class File {

public:
	static void Init(String company, String project);

	static bool Read(String filepath, String& out);
	static bool Write(String filepath, String out);
	static bool Append(String filepath, String in);
	static bool Delete(String filepath);
	static bool Create(String filepath);

	static String Expand(String filepath);
	static String SafeWriteDir();


private:
	static const String ContentDir;
	static String Company;
	static String Project;
};


#endif