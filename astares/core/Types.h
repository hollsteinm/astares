#ifndef TYPES_H
#define TYPES_H

#include <string>
#include <memory>
#include <vector>
#include <map>
#include <queue>
#include <iosfwd>
typedef char int8;
typedef short int16;
typedef int int32;
typedef long int64;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long uint64;
typedef float f32;
typedef double f64;
typedef std::string string;
typedef bool gate;

template<typename T>
using vector = std::vector<T>;

template<typename T>
std::ostream& operator << (std::ostream& out, const vector<T>& arr) {
	out << arr.size() << ' ';
	for (auto elem : arr) {
		out << elem << ' ';
	}
	return out;
}

template<typename T>
std::istream& operator >> (std::istream& in, vector<T>& arr) {
	size_t size;
	in >> size;
	arr.resize(size);
	for (size_t i = 0; i < size; ++i) {
		in >> arr[i];
	}
	return in;
}

template<>
std::ostream& operator << (std::ostream& out, const vector<int8>& arr);
template<>
std::istream& operator >> (std::istream& in, vector<int8>& arr);

template<>
std::ostream& operator << (std::ostream& out, const vector<uint8>& arr);
template<>
std::istream& operator >> (std::istream& in, vector<uint8>& arr);

template<typename K, typename V>
using map = std::map<K, V>;

template<typename T, typename V>
std::ostream& operator << (std::ostream& out, const map<T, V>& m) {
	out << m.size() << ' ';
	for (auto kvp : m) {
		out << kvp.first << ' ' << kvp.second << ' ';
	}
	return out;
}

template<typename T, typename V>
std::istream& operator >> (std::istream& in, map<T, V>& m) {
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
std::ostream& operator << (std::ostream& out, const queue<T>& q) {
	out << q.size() << ' ';
	for (auto elem : q) {
		out << elem << ' ';
	}
	return out;
}

template<typename T>
std::istream& operator >> (std::istream& in, queue<T>& q) {
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