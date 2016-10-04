#include "catch.hpp"
#include <core\IFile.h>
#include <fstream>

TEST_CASE("File", "[core]") {
	auto file = astares::IFile::MakeFile("test.txt");
	file->Init("TestCompany", "UnitTests");
	std::string testString = "testing testing, 123";

	SECTION("File Management") {
		SECTION("Create a file") {
			REQUIRE(file->Create());
		}

		SECTION("Writing") {
			REQUIRE(file->Write(testString.c_str()));
		}

		SECTION("Reading") {
			astares::cstring in;
			REQUIRE(file->Read(in));
			REQUIRE(in == testString);
		}

		SECTION("Streaming Files") {
			SECTION("Writing") {
				std::ofstream out;
				REQUIRE(file->OpenWriteStream(out));
				out << testString;
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