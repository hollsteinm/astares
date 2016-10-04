#ifndef FILE_H
#define FILE_H

#include "../astares.core.h"
#include "Types.h"

namespace astares {

	BETTER_ENUM(FileMode, int8,
		Text,
		Binary)

	struct ASTARESCORE_API IFile {
	public:
		IFile();

		virtual ~IFile();

		virtual	void Init(cstring company, cstring project) = 0;
		virtual	bool Read(cstring& out) = 0;
		virtual	bool Write(const cstring& in) = 0;
		virtual	bool Append(const cstring& in) = 0;
		virtual	bool Delete() = 0;
		virtual	bool Create() = 0;
		virtual	cstring Expand() = 0;
		virtual	cstring SafeWriteDir() = 0;
		virtual	bool OpenReadStream(std::ifstream& out, FileMode mode = FileMode::Binary) = 0;
		virtual	bool OpenWriteStream(std::ofstream& out, FileMode mode = FileMode::Binary) = 0;
		virtual	bool OpenReadWriteStream(std::fstream& out, FileMode mode = FileMode::Binary) = 0;

		void operator=(const IFile& rhs);
		static IFile* MakeFile(cstring path);
	};
}
#endif