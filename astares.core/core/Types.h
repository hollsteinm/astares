#ifndef TYPES_H
#define TYPES_H

#include "../astares.core.h"

#include <string>
#include <memory>
#include <vector>
#include <map>
#include <queue>
#include <iosfwd>

//TEMPLATE_EXTERN template class ASTARESCORE_API std::basic_string < char, std::char_traits<char>, std::allocator<char> > ;

typedef char			int8;
typedef short			int16;
typedef int				int32;
typedef long			int64;
typedef unsigned char	uint8;
typedef unsigned short	uint16;
typedef unsigned int	uint32;
typedef unsigned long	uint64;
typedef float			f32;
typedef double			f64;
typedef std::string		string;
typedef bool			gate;

typedef std::iostream	Stream;
typedef std::istream	ReadStream;
typedef std::ostream	WriteStream;

#ifndef DEF_CORE_STL
#define DEF_CORE_STL(type) TEMPLATE_EXTERN template class ASTARESCORE_API std::vector<type>;	\
 TEMPLATE_EXTERN template class ASTARESCORE_API std::deque<type>;	\
 TEMPLATE_EXTERN template class ASTARESCORE_API std::queue<type>;
#endif

#ifndef DEF_CORE_STL_MAP
#define DEF_CORE_STL_MAP(key, value) TEMPLATE_EXTERN template class ASTARESCORE_API std::map<key, value>;
#endif

#ifndef DEF_CORE_STL_PTR
#define DEF_CORE_STL_PTR(type) TEMPLATE_EXTERN template class ASTARESCORE_API std::shared_ptr<type>; TEMPLATE_EXTERN template class ASTARESCORE_API std::weak_ptr<type>; TEMPLATE_EXTERN template class ASTARESCORE_API std::unique_ptr<type>;
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
	arr.resize(size);
	for (size_t i = 0; i < size; ++i) {
		in >> arr[i];
	}
	return in;
}

template<> ASTARESCORE_API
WriteStream& operator << (WriteStream& out, const std::vector<int8>& arr);
template<> ASTARESCORE_API
ReadStream& operator >> (ReadStream& in, std::vector<int8>& arr);

template<> ASTARESCORE_API
WriteStream& operator << (WriteStream& out, const std::vector<uint8>& arr);
template<> ASTARESCORE_API
ReadStream& operator >> (ReadStream& in, std::vector<uint8>& arr);

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
	out << q.size() << ' ';
	for (auto elem : q) {
		out << elem << ' ';
	}
	return out;
}

template<typename T>
ReadStream& operator >> (ReadStream& in, queue<T>& q) {
	size_t size;
	in >> size;
	q.resize(size);
	for (size_t i = 0; i < size; ++i) {
		T t;
		in >> t;
		q.push(t);
	}
	return in;
}

#include "Enum.h"

#endif