#ifndef ARRAY_H
#define ARRAY_H

#include "../astares.framework.h"
#include <iosfwd>
#include <vector>
#include <functional>
#include <memory>

struct ASTARESFRAMEWORK_API ArrayHelper {
	template <typename T>
	static void Serialize(const std::vector<T>& source, std::ostream& out)
	{
		out << source.size();
		for (auto elem : source)
		{
			out << elem;
		}
	}

	template <typename T>
	static void Deserialize(std::vector<T>& destiniation, std::istream& in)
	{
		std::vector<T>::size_type size = 0;
		in >> size;
		destiniation.reserve(size);
		for (std::vector<T>::size_type i = 0; i < size; ++i)
		{
			T data;
			in >> data;
			destiniation.push_back(data);
		}
	}

	template <typename T>
	static void Serialize(const std::vector<T>& source, std::ostream& out, std::function<void(const T&, std::ostream&)> sourceElementSerialize)
	{
		out << source.size();
		for (auto elem : source)
		{
			sourceElementSerialize(elem, out);
		}
	}

	template <typename T>
	static void Deserialize(std::vector<T>& destiniation, std::istream& in, std::function<void(T&, std::istream&)> destinationElementDeserialize)
	{
		std::vector<T>::size_type size = 0;
		in >> size;
		destiniation.reserve(size);
		for (std::vector<T>::size_type i = 0; i < size; ++i)
		{
			T data;
			destinationElementDeserialize(data, in);
			destiniation.push_back(data);
		}
	}

	template <typename T>
	static void Serialize(const std::vector<std::shared_ptr<T>>& source, std::ostream& out, void (T::*SerializeFunc)(std::ostream&, int32))
	{
		out << source.size();
		for (auto elem : source)
		{
			elem->*SerializeFunc(out, 0);
		}
	}

	template <typename T>
	static void Deserialize(std::vector<std::shared_ptr<T>>& destiniation, std::istream& in, void (T::*DeserializeFunc)(std::istream&, int32))
	{
		std::vector<std::shared_ptr<T>>::size_type size = 0;
		in >> size;
		destiniation.reserve(size);
		for (std::vector<T>::size_type i = 0; i < size; ++i)
		{
			std::shared_ptr<T> data(new T());
			data->*DeserializeFunc(in, 0);
			destiniation.push_back(data);
		}
	}
};

#endif