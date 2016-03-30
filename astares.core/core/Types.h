#ifndef TYPES_H
#define TYPES_H

#include "../astares.core.h"

#include <string>
#include <memory>
#include <vector>
#include <map>
#include <queue>
#include <iosfwd>
#include <cstdint>

//TEMPLATE_EXTERN template class ASTARESCORE_API std::basic_string < char, std::char_traits<char>, std::allocator<char> > ;

typedef char			int8;
typedef int16_t			int16;
typedef int32_t			int32;
typedef int64_t			int64;
typedef uint8_t			uint8;
typedef uint16_t		uint16;
typedef uint32_t		uint32;
typedef uint64_t		uint64;
typedef float			f32;
typedef double			f64;
typedef std::string		string;
typedef bool			gate;

typedef std::iostream	Stream;
typedef std::istream	ReadStream;
typedef std::ostream	WriteStream;


#ifndef DECL_API_STL
#define DECL_API_STL(api, type) TEMPLATE_EXTERN template class api std::vector<type>;	\
 TEMPLATE_EXTERN template class api std::deque<type>;	\
 TEMPLATE_EXTERN template class api std::queue<type>;
#endif

#ifndef DECL_API_STL_MAP
#define DECL_API_STL_MAP(api, key, value) TEMPLATE_EXTERN template class api std::map<key, value>;
#endif

#ifndef DECL_API_STL_PTR
#define DECL_API_STL_PTR(api, type) TEMPLATE_EXTERN template class api std::shared_ptr<type>; TEMPLATE_EXTERN template class api std::weak_ptr<type>; TEMPLATE_EXTERN template class api std::unique_ptr<type>;
#endif

#ifndef DECL_CORE_STL
#define DECL_CORE_STL(type) DECL_API_STL(ASTARESCORE_API, type)
#endif

#ifndef DECL_CORE_STL_MAP
#define DECL_CORE_STL_MAP(key, value) DECL_API_STL_MAP(ASTARESCORE_API, key, value)
#endif

#ifndef DECL_CORE_STL_PTR
#define DECL_CORE_STL_PTR(type) DECL_API_STL_PTR(ASTARESCORE_API, type)
#endif

template<typename T>
using vector = std::vector<T, std::allocator<T>>;

template<typename T>
WriteStream& operator << (WriteStream& out, const vector<T>& arr) {
	out << arr.size() << ' ';
	for (auto elem : arr) {
		out << elem << ' ';
	}
	return out;
}

template<typename T>
ReadStream& operator >> (ReadStream& in, vector<T>& arr) {
	size_t size;
	in >> size;
	arr.reserve(size);
	for (size_t i = 0; i < size; ++i) {
		T temp;
		in >> temp;
		arr.push_back(temp);
	}
	return in;
}

ASTARESCORE_API
WriteStream& operator << (WriteStream& out, const std::vector<int8>& arr);
ASTARESCORE_API
ReadStream& operator >> (ReadStream& in, std::vector<int8>& arr);

ASTARESCORE_API
WriteStream& operator << (WriteStream& out, const std::vector<uint8>& arr);
ASTARESCORE_API
ReadStream& operator >> (ReadStream& in, std::vector<uint8>& arr);

ASTARESCORE_API
ReadStream& operator >> (ReadStream& in, int8& val);

ASTARESCORE_API
ReadStream& operator >> (ReadStream& in, uint8& val);

template<typename K, typename V>
using map = std::map<K, V>;

template<typename T, typename V>
WriteStream& operator << (WriteStream& out, const map<T, V>& m) {
	out << m.size() << ' ';
	for (auto kvp : m) {
		out << kvp.first << ' ' << kvp.second << ' ';
	}
	return out;
}

template<typename T, typename V>
ReadStream& operator >> (ReadStream& in, map<T, V>& m) {
	size_t size;
	in >> size;
	for (size_t i = 0; i < size; ++i) {
		T t;
		V v;
		in >> t >> v;
		m.emplace(std::make_pair(t, v));
	}
	return in;
}

template<typename T>
using queue = std::queue<T>;

template<typename T>
WriteStream& operator << (WriteStream& out, const queue<T>& q) {
	queue<T> copy(q);
	vector<T> output;
	while (!copy.empty())
	{
		output.push_back(copy.front());
		copy.pop();
	}
	out << output;
	return out;
}

template<typename T>
ReadStream& operator >> (ReadStream& in, queue<T>& q) {
	size_t size;
	in >> size;
	for (size_t i = 0; i < size; ++i) {
		T t;
		in >> t;
		q.push(t);
	}
	return in;
}

#include "Enum.h"

#endif