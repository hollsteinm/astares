#ifndef MetaGraph_H
#define MetaGraph_H

#include <map>
#include "../core/Array.h"
#include "../core/String.h"

class MetaGraph
{
public:
	static MetaGraph& Get();
	~MetaGraph();

	void Add(struct Meta* Class);

	struct Meta* Get(unsigned long typeId) const;
	struct Meta* Get(String name) const;

	Array<long> AllTypeIds() const;

private:
	static MetaGraph* __instance;
	MetaGraph();

	std::map<long, struct Meta*> Classes;
};

#endif