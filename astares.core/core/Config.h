#ifndef CONFIG_H
#define CONFIG_H

#include "../astares.core.h"
#include "../core/Types.h"

#ifndef VIDEO_SECTION
#define VIDEO_SECTION "Video"
#endif

DEF_CORE_STL_MAP(string, string)
typedef std::map<string, string> stringmap;
DEF_CORE_STL_MAP(string, stringmap)

class ASTARESCORE_API Config {
public:
	Config(const string& filepath);
	~Config();

	Config& MoveSection(string section);

	bool HasSetting(string setting) const;
	bool HasSection(string section) const;

	gate AsBool(string setting) const;
	string AsString(string setting) const;
	f32 AsFloat(string setting) const;
	int32 AsInt(string setting) const;

	void Parse(string content);

private:
	map<string, map<string, string>> Configurations;

	string CurrentSection;

	static const char SectionStartToken;
	static const char SectionEndToken;
	static const char SettingSplitToken;
	static const char SectionNameStartToken;
	static const char SectionNameEndToken;

protected:
	bool Load(std::string filename, std::string& outContent);
	bool Save(std::string filename, std::string content);

};

#endif