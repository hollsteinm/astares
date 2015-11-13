#include "IField.h"
#include "Meta.h"


IField::IField(std::string name, unsigned long typeId, int flags) :
	Meta(name, typeId),
	Flags(flags)
{}

IField::~IField() {

}

bool IField::HasFlag(FieldFlags flag) const {
	return (Flags & (int)flag) > 0;
}