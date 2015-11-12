#ifndef CONFIG_H
#define CONFIG_H

#include <map>

#ifndef VIDEO_SECTION
#define VIDEO_SECTION "Video"
#endif

class Config {
public:
	Config(std::string filepath);
	~Config();

	Config& MoveSection(std::string section);

	bool HasSetting(std::string setting) const;
	bool HasSection(std::string section) const;

	bool Bool(std::string setting) const;
	std::string String(std::string setting) const;
	float Float(std::string setting) const;
	int Int(std::string setting) const;

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