#ifndef CONFIG_H
#define CONFIG_H

#include "../core/Types.h"

#ifndef VIDEO_SECTION
#define VIDEO_SECTION "Video"
#endif

class Config {
public:
	Config(const std::string& filepath);
	~Config();

	Config& MoveSection(std::string section);

	bool HasSetting(std::string setting) const;
	bool HasSection(std::string section) const;

	bool AsBool(std::string setting) const;
	std::string AsString(std::string setting) const;
	f32 AsFloat(std::string setting) const;
	int32 AsInt(std::string setting) const;

	void Parse(std::string content);

private:
	std::map<std::string, std::map<std::string, std::string>> Configurations;

	std::string CurrentSection;

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