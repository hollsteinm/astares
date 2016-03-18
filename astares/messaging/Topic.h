#ifndef TOPIC_H
#define TOPIC_H

#include "../core/Types.h"

class Topic {
public:
	Topic();
	Topic(const string& name);
	Topic(const string& name, const std::vector<Topic>& children);
	Topic(const Topic& rhs);
	void operator = (const Topic& rhs);
	~Topic();
	string GetName() const;
	const std::vector<Topic>& GetChildren() const;

	friend std::ostream& operator << (std::ostream& out, const Topic& message);
	friend std::istream& operator >> (std::istream& in, Topic& message);

private:
	string name;
	std::vector<Topic> children;
};

#endif