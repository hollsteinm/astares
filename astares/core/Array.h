#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <vector>

template <typename T>
struct Array : public std::vector<T> {
	typedef _Alloc allocator_type;
	typedef typename _Mybase::value_type value_type;
	typedef typename _Mybase::size_type size_type;


	explicit Array(const allocator_type& alloc = allocator_type()) :
		std::vector<T>(alloc)
	{

	}

	explicit Array(size_type n) : 
		std::vector<T>(n)
	{

	}
	
	Array(size_type n, const value_type& val, const allocator_type& alloc = allocator_type()) : 
		std::vector<T>(n, val, alloc)
	{

	}

	template <class InputIterator>
	Array(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) :
		std::vector<T>(first, last, alloc)
	{

	}

	Array(const Array& x) : 
		std::vector<T>(x)
	{

	}

	Array(const Array& x, const allocator_type& alloc) : 
		std::vector<T>(x, alloc)
	{

	}

	Array(Array&& x) : 
		std::vector<T>(x)
	{

	}

	Array(Array&& x, const allocator_type& alloc) :
		std::vector<T>(x, alloc)
	{

	}

	friend std::ostream& operator<<(std::ostream& out, Array<T>& self) {
		out << self.size() << ' ';
		for (auto elem : self) {
			out << elem;
		}
		return out;
	}

	friend std::istream& operator>>(std::istream& in, Array<T>& self) {
		unsigned int size = 0;
		in >> size;
		self.resize(size);
		for (unsigned int i = 0; i < size; ++i) {
			T obj;
			in >> obj;
			self[i] = obj;
		}

		return in;
	}
};

#endif