#ifndef STRING_H
#define STRING_H

#include "Types.h"
#include "../astares.core.h"

namespace astares
{
	class String
	{
	public:
		class ASTARESCORE_API CharIterator
		{
		public:
			typedef Detail<char> CharInteratorDetails;
			CharIterator(CharInteratorDetails::PointerType ValuePtr);

			typedef CharIterator self_type;
			typedef CharInteratorDetails::ValueType value_type;
			typedef CharInteratorDetails::ReferenceType reference;
			typedef CharInteratorDetails::PointerType pointer;
			typedef std::forward_iterator_tag iterator_category;
			typedef int difference_type;
			CharIterator(pointer ValuePtr) : ValuePtr(ValuePtr) { }
			self_type operator++() { self_type i = *this;  ValuePtr++; return i; }
			self_type operator++(int junk) { ValuePtr++; return *this; }
			reference operator*() { return *ValuePtr; }
			pointer operator->() { return ValuePtr; }
			bool operator==(const self_type& rhs) const { return ValuePtr == rhs.ValuePtr; }
			bool operator!=(const self_type& rhs) const { return ValuePtr != rhs.ValuePtr; }

		private:
			CharInteratorDetails::PointerType ValuePtr;
		};

		class ASTARESCORE_API ConstCharIterator
		{
		public:
			typedef Detail<const char> ConstCharInteratorDetails;
			ConstCharIterator(ConstCharInteratorDetails::PointerType ValuePtr);

			typedef ConstCharIterator self_type;
			typedef ConstCharInteratorDetails::ValueType value_type;
			typedef ConstCharInteratorDetails::ReferenceType reference;
			typedef ConstCharInteratorDetails::PointerType pointer;
			typedef std::forward_iterator_tag iterator_category;
			typedef int difference_type;
			ConstCharIterator(pointer ValuePtr) : ValuePtr(ValuePtr) { }
			self_type operator++() { self_type i = *this;  ValuePtr++; return i; }
			self_type operator++(int junk) { ValuePtr++; return *this; }
			reference operator*() { return *ValuePtr; }
			pointer operator->() { return ValuePtr; }
			bool operator==(const self_type& rhs) const { return ValuePtr == rhs.ValuePtr; }
			bool operator!=(const self_type& rhs) const { return ValuePtr != rhs.ValuePtr; }

		private:
			ConstCharInteratorDetails::PointerType ValuePtr;
		};

		ASTARESCORE_API String();
		ASTARESCORE_API String(cstring Source);
		ASTARESCORE_API String(cstring Source, uint64 size);
		ASTARESCORE_API	String(const String& other);
		ASTARESCORE_API	String(String&& other);
		ASTARESCORE_API	String(ConstCharIterator First, ConstCharIterator Last);
		ASTARESCORE_API ~String();

		ASTARESCORE_API String SubString(uint64 StartIndex, uint64 Length) const;
		ASTARESCORE_API int32 Compare(const String& other) const;

		ASTARESCORE_API String ToLower() const;
		ASTARESCORE_API String ToUpper() const;

		ASTARESCORE_API void MakeLower();
		ASTARESCORE_API void MakeUpper();

		ASTARESCORE_API bool IsNumeric() const;
		ASTARESCORE_API bool IsDecimal() const;
		ASTARESCORE_API bool IsEmpty() const;
		ASTARESCORE_API bool IsWhitespace() const;
		ASTARESCORE_API bool Contains(const String& Value) const;

		ASTARESCORE_API int8 ToInt8() const;
		ASTARESCORE_API int16 ToInt16() const;
		ASTARESCORE_API int32 ToInt32() const;
		ASTARESCORE_API int64 ToInt64() const;
		ASTARESCORE_API uint8 ToUint8() const;
		ASTARESCORE_API uint16 ToUint16() const;
		ASTARESCORE_API uint32 ToUint32() const;
		ASTARESCORE_API uint64 ToUint64() const;
		ASTARESCORE_API f32 ToF32() const;
		ASTARESCORE_API f64 ToF64() const;

		ASTARESCORE_API static String FromInt8(int8 Value);
		ASTARESCORE_API static String FromInt16(int16 Value);
		ASTARESCORE_API static String FromInt32(int32 Value);
		ASTARESCORE_API static String FromInt64(int64 Value);
		ASTARESCORE_API static String FromUint8(uint8 Value);
		ASTARESCORE_API static String FromUint16(uint16 Value);
		ASTARESCORE_API static String FromUint32(uint32 Value);
		ASTARESCORE_API static String FromUint64(uint64 Value);
		ASTARESCORE_API static String FromF32(f32 Value);
		ASTARESCORE_API static String FromF64(f64 Value);

		ASTARESCORE_API uint64 Length() const;

		ASTARESCORE_API char* Data();

		ASTARESCORE_API CharIterator begin();
		ASTARESCORE_API CharIterator end();

		ASTARESCORE_API ConstCharIterator cbegin() const;
		ASTARESCORE_API ConstCharIterator cend() const;

		ASTARESCORE_API cstring ToCString() const;

		ASTARESCORE_API String& operator=(const String& rhs);
		ASTARESCORE_API String& operator=(cstring rhs);
		ASTARESCORE_API String& operator=(String&& rhs);
		ASTARESCORE_API char& operator[](uint64 Index);
		ASTARESCORE_API const char& operator[](uint64 Index) const;


	private:
		std::string InternalString;
	};
}

#endif