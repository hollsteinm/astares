#include "catch.hpp"
#include <core\IConfig.h>

TEST_CASE("Config", "[core]") {
	auto config = astares::IConfig::MakeConfig("test.config");
	std::string testString = "(Section)\r\n\t[\r\n\t\tString0 = Value0\r\n\t\tboolean0 = yes\r\n\t\tVariable0 = 12\r\n\t\tFloat0 = 12.04\r\n\t]";

	SECTION("Parse") {
		config->Parse(testString.c_str());
		REQUIRE(config->HasSection("Section"));
		REQUIRE(config->HasSetting("String0"));
		REQUIRE(config->HasSetting("boolean0"));
		REQUIRE(config->HasSetting("Variable0"));
		REQUIRE(config->HasSetting("Float0"));
	}

	SECTION("Conversion") {
		config->Parse(testString.c_str());
		config->MoveSection("Section");

		SECTION("Boolean") {
			REQUIRE(config->AsBool("boolean0"));
		}

		SECTION("String") {
			REQUIRE(config->AsString("String0") == "Value0");
		}

		SECTION("Int") {
			REQUIRE(config->AsInt("Variable0") == 12);
		}

		SECTION("Float") {
			REQUIRE(config->AsFloat("Float0") == Approx(12.04f));
		}
	}
}