#include "JsonTestObject.h"

class JSONTestObjectContainer : public JSONTestObject
{
public:
	PRODUCTABLE
	REFLECTABLE
		SERIALIZEABLE(JSONTestObject)

		JSONTestObjectContainer();

		JSONTestObject lonely;
	vector<JSONTestObject> not_so_lonely;
	queue<JSONTestObject> q_of_obj;
};

DECL_OBJECT_VARIANT(JSONTestObjectContainer)