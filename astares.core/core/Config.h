#ifndef CONFIG_H
#define CONFIG_H

#include "../astares.core.h"
#include "../core/Types.h"

#ifndef VIDEO_SECTION
#define VIDEO_SECTION "Video"
#endif

DECL_CORE_STL_MAP(string, string)
typedef std::map<string, string> stringmap;
DECL_CORE_STL_MAP(string, stringmap)

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
	map<string, stringmap> Configurations;

	string CurrentSection;

	static const char SectionStartToken;
	static const char SectionEndToken;
	static const char SettingSplitToken;
	static const char SectionNameStartToken;
	static const char SectionNameEndToken;

protected:
	bool Load(const string& filename, string& outContent);
	bool Save(const string& filename, const string& content);

};

#endif