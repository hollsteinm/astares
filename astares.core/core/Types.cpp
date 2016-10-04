#include "Types.h"

using namespace astares;

const char* TypeQuery::GetName() const 
{ 
	return name; 
}

int64 TypeQuery::GetTypeId() const 
{ 
	return typeId; 
}

int64 TypeQuery::GetSize() const 
{ 
	return size; 
}

bool TypeQuery::GetIsCollection() const 
{ 
	return isCollection; 
}

bool TypeQuery::GetIsPointer() const 
{ 
	return isPointer; 
}

bool TypeQuery::GetIsPrimitive() const 
{ 
	return isPrimitive; 
}