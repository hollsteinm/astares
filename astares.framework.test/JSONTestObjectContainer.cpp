#include "JSONTestObjectContainer.h"
#include <reflection\IReflector.h>

JSONTestObjectContainer::JSONTestObjectContainer()
	: lonely(),
	not_so_lonely({
		JSONTestObject(),
		JSONTestObject(),
		JSONTestObject(),
		JSONTestObject()
	}),
	q_of_obj({ JSONTestObject(), JSONTestObject() })
{

}

PRODUCE(JSONTestObjectContainer)

START_SERIAL(JSONTestObjectContainer)
PARENT_SERIAL(JSONTestObject)
WRITE(lonely)
WRITE(not_so_lonely)
WRITE(q_of_obj)
END_SERIAL

START_DESERIAL(JSONTestObjectContainer)
PARENT_DESERIAL(JSONTestObject)
READ(lonely)
READ(not_so_lonely)
READ(q_of_obj)
END_DESERIAL

START_PROPERTIES(JSONTestObjectContainer)
PARENT(JSONTestObject)
PROPERTY(lonely)
PROPERTY(not_so_lonely)
PROPERTY(q_of_obj)
END_PROPERTIES