#include "catch.hpp"
#include <core\IFile.h>
#include <fstream>

TEST_CASE("File", "[core]") {
	auto file = astares::IFile::MakeFile("test.txt");
	file->Init("TestCompany", "UnitTests");
	const char* testString = "testing testing, 123";
	char* data = nullptr;
	std::unique_ptr<char> scoped(data);

	SECTION("File Management") {
		SECTION("Create a file") {
			REQUIRE(file->Create());
		}

		SECTION("Writing") {
			REQUIRE(file->Write(testString));
		}

		SECTION("Reading") {
			
			astares::uint64 size;
			REQUIRE(file->Read(data, size));
			REQUIRE(size == strnlen_s(testString, size));
			REQUIRE(strcmp(data, testString) == 0);
		}

		SECTION("Streaming Files") {
			SECTION("Writing") {
				std::ofstream out;
				REQUIRE(file->OpenWriteStream(out));
				out << std::string(testString, strlen(testString));
			}

			SECTION("Reading") {
				std::ifstream in;
				REQUIRE(file->OpenReadStream(in));
				std::stringstream buffer;
				buffer << in.rdbuf();
				std::string test(buffer.str());
				REQUIRE(test == testString);
			}

			SECTION("Read/Write") {
				std::fstream inout;
				REQUIRE(file->OpenReadWriteStream(inout));
			}
		}

		SECTION("Delete a file") {
			REQUIRE(file->Delete());
		}
	}
}