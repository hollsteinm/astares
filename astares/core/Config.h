#ifndef CONFIG_H
#define CONFIG_H

#include "String.h"
#include <map>

#ifndef VIDEO_SECTION
#define VIDEO_SECTION "Video"
#endif

class Config {
public:
	Config(const String& filepath);
	~Config();

	Config& MoveSection(String section);

	bool HasSetting(String setting) const;
	bool HasSection(String section) const;

	bool AsBool(String setting) const;
	String AsString(String setting) const;
	float AsFloat(String setting) const;
	int AsInt(String setting) const;

	void Parse(String content);

private:
	std::map<String, std::map<String, String>> Configurations;

	String CurrentSection;

	static const char SectionStartToken;
	static const char SectionEndToken;
	static const char SettingSplitToken;
	static const char SectionNameStartToken;
	static const char SectionNameEndToken;

protected:
	bool Load(String filename, String& outContent);
	bool Save(String filename, String content);

};

#endif