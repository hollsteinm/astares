#include "IConfig.h"
#include "IFile.h"
#include <ctype.h>
#include <algorithm>

using namespace astares;

std::vector<std::unique_ptr<IConfig>> ConfigPtrs;

IConfig::IConfig(const IConfig& rhs)
{}

IConfig::IConfig()
{}

IConfig::~IConfig()
{}

void IConfig::operator=(const IConfig& rhs)
{
}


class Config : public IConfig {
public:
	Config(cstring filepath);
	virtual ~Config();

	Config& MoveSection(cstring section) override;

	bool HasSetting(cstring setting) const override;
	bool HasSection(cstring section) const override;

	bool AsBool(cstring setting) const override;
	cstring AsString(cstring setting) const override;
	f32 AsFloat(cstring setting) const override;
	int32 AsInt(cstring setting) const override;

	void Parse(cstring content) override;

private:
	std::map<std::string, std::map<std::string, cstring>> Configurations;

	cstring CurrentSection;

	static const char SectionStartToken;
	static const char SectionEndToken;
	static const char SettingSplitToken;
	static const char SectionNameStartToken;
	static const char SectionNameEndToken;

protected:
	bool Load(cstring filename, cstring outContent);
	bool Save(cstring filename, cstring content);

};

IConfig* IConfig::MakeConfig(cstring filepath)
{
	ConfigPtrs.push_back(std::make_unique<Config>(filepath));
	return ConfigPtrs.back().get();
}

const char Config::SectionStartToken = '[';
const char Config::SectionEndToken = ']';
const char Config::SettingSplitToken = '=';
const char Config::SectionNameStartToken = '(';
const char Config::SectionNameEndToken = ')';

Config::Config(cstring filepath) :
	CurrentSection("")
{
	char potentialContent[19280] = {};
	if (Load(filepath, potentialContent)) {
		Parse(potentialContent);
	}
}

Config::~Config() {

}

Config& Config::MoveSection(cstring section) {
	CurrentSection = section;
	return *this;
}

bool Config::HasSetting(cstring setting) const {
	if (HasSection(CurrentSection)) {
		return Configurations.at(CurrentSection).find(setting) != Configurations.at(CurrentSection).cend();
	}
	else {
		return false;
	}
}

bool Config::HasSection(cstring section) const {
	return Configurations.find(section) != Configurations.cend();
}

bool Config::AsBool(cstring setting) const {
	if (HasSetting(setting)) {
		auto set = string(Configurations.at(CurrentSection).at(setting));
		std::transform(set.begin(), set.end(), set.begin(), ::tolower);
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

cstring Config::AsString(cstring setting) const {
	if (HasSetting(setting)) {
		return Configurations.at(CurrentSection).at(setting);
	}
	else {
		return "";
	}
}

f32 Config::AsFloat(cstring setting) const {
	if (HasSetting(setting)) {
		return (f32)atof(Configurations.at(CurrentSection).at(setting));
	}
	else {
		return 0.0f;
	}
}

int32 Config::AsInt(cstring setting) const {
	if (HasSetting(setting)) {
		return atoi(Configurations.at(CurrentSection).at(setting));
	}
	else {
		return 0;
	}
}

bool Config::Load(cstring filename, cstring content) {
	auto file = IFile::MakeFile(filename);
	return file->Read(content);
}

inline bool IsSpecial(char character) {
	return character == '\r' ||
		character == '\n' ||
		character == ' ' ||
		character == '\t';
}

void Config::Parse(cstring content) {
	uint32 index = 0;
	auto size = strlen(content);

	while (index < size) {
		char next = content[index++];

		switch (next)
		{
		case SectionStartToken:
		{
			next = content[index++];

			while (next != SectionEndToken) {

				while (IsSpecial(next)) {
					next = content[index++];
				}

				if (next == SectionStartToken || next == SectionEndToken) {
					break;
				}

				string str;
				do{
					str.push_back(next);
					next = content[index++];
				} while (next != SettingSplitToken && !IsSpecial(next));

				do {
					next = content[index++];
				} while (next == SettingSplitToken || IsSpecial(next));

				string ct;
				do {
					ct.push_back(next);
					next = content[index++];
				} while (!IsSpecial(next) && next != SectionEndToken);

				Configurations[CurrentSection][str] = ct.c_str();
			}

			break;
		}

		case SectionNameStartToken:
		{
			string str;
			next = content[index++];
			do{
				str.push_back(next);
				next = content[index++];
			} while (next != SectionNameEndToken);
			CurrentSection = str.c_str();
			Configurations[str] = std::map<std::string, cstring>();
			break;
		}
			break;
		default:
			break;
		}
	}
}

bool Config::Save(cstring filename, cstring content) {
	auto file = IFile::MakeFile(filename);
	auto success = file->Write(content);
	if (success)
	{
		Parse(content);
	}
	return success;
}