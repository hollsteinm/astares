#include "Config.h"
#include "File.h"
#include <ctype.h>

const char Config::SectionStartToken = '[';
const char Config::SectionEndToken = ']';
const char Config::SettingSplitToken = '=';
const char Config::SectionNameStartToken = '(';
const char Config::SectionNameEndToken = ')';
/**
(Name0)
[
	Variable0 = Value0
	Variable1 = Value1
]
**/

Config::Config(const std::string& filepath) :
	CurrentSection("")
{
	std::string potentialContent;
	if (Load(filepath, potentialContent)) {
		Parse(potentialContent);
	}
}

Config::~Config() {

}

Config& Config::MoveSection(std::string section) {
	CurrentSection = section;
	return *this;
}

bool Config::HasSetting(std::string setting) const {
	if (HasSection(CurrentSection)) {
		return Configurations.at(CurrentSection).find(setting) != Configurations.at(CurrentSection).cend();
	}
	else {
		return false;
	}
}

bool Config::HasSection(std::string section) const {
	return Configurations.find(section) != Configurations.cend();
}

bool Config::AsBool(std::string setting) const {
	if (HasSetting(setting)) {
		auto set = Configurations.at(CurrentSection).at(setting);
		int32 i = 0;
		int32 sz = set.size();
		while (i < sz) {
			set[i] = tolower(set[i++]);
		}
		if (set == "false" || set == "no" || set == "off") {
			return false;
		}
		else if (set == "true" || set == "yes" || set == "on") {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

std::string Config::AsString(std::string setting) const {
	if (HasSetting(setting)) {
		return Configurations.at(CurrentSection).at(setting);
	}
	else {
		return "";
	}
}

f32 Config::AsFloat(std::string setting) const {
	if (HasSetting(setting)) {
		return (f32)atof(Configurations.at(CurrentSection).at(setting).c_str());
	}
	else {
		return 0.0f;
	}
}

int32 Config::AsInt(std::string setting) const {
	if (HasSetting(setting)) {
		return atoi(Configurations.at(CurrentSection).at(setting).c_str());
	}
	else {
		return 0;
	}
}

bool Config::Load(std::string filename, std::string& content) {
	return File::Read(File::SafeWriteDir().append(filename), content);
}

void Config::Parse(std::string content) {
	uint32 index = 0;

	while (index < content.size()) {
		char next = content[index++];

		switch (next)
		{
		case SectionStartToken:
		{
			next = content[index++];

			while (next != SectionEndToken) {

				while (next == '\r' || next == '\n' || next == ' ') {
					next = content[index++];
				}

				std::string str;
				do {
					str.push_back(next);
					next = content[index++];
				} while (next != '=');

				next = content[index++];

				std::string ct;
				do {
					ct.push_back(next);
					next = content[index++];
				} while (next != '\n' && next != '\r' && next != ' ' && next != SectionEndToken);

				Configurations[CurrentSection][str] = ct;
			}

			break;
		}

		case SectionNameStartToken:
		{
			std::string str;
			next = content[index++];
			do{
				str.push_back(next);
				next = content[index++];
			} while (next != SectionNameEndToken);
			CurrentSection = str;
			Configurations[str] = std::map<std::string, std::string>();
			break;
		}
			break;
		default:
			break;
		}
	}
}

bool Config::Save(std::string filename, std::string content) {
	return File::Write(File::SafeWriteDir().append(filename), content);
}