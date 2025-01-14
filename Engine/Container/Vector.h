#pragma once

#include "Core.h"
#include <iostream>

template<typename T>
class ENGINE_API Vector
{
public:
	Vector()
		: capacity(4)
	{
		size = 0;
		data = new T[capacity];
	}

	~Vector()
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}

	void PushBack(const T& value)
	{
		if (size >= capacity)
		{
			Resize(capacity * 2);
		}

		data[size] = value;
		++size;
	}

	void PushBack(const T&& value) // R-value reference
	{
		if (size >= capacity)
		{
			Resize(capacity * 2);
		}

		data[size] = std::move(value);
		++size;
	}

	void Erase(size_t idx)
	{
		if (idx < 0 || idx >= size)
		{
			__debugbreak();
		}

		// shifting
		for (int i = 0; i < size - 1; ++i)
		{
			data[i] = std::move(data[i + 1]);
		}
		
		--size;
	}

	// operator[] overloading
	const T& operator[](size_t idx) const
	{
		if (idx < 0 || idx >= size)
		{
			__debugbreak();
		}

		return data[idx];
	}

	T& operator[](size_t idx)
	{
		if (idx < 0 || idx >= size)
		{
			__debugbreak();
		}

		return data[idx];
	}

	// Simple iterator (for range-based loop)
	T* begin() const
	{
		return data;
	}

	T* end() const
	{
		return data + size;
	}

private:
	void Resize(const size_t newCapacity)
	{
		T* newBlock = new T[newCapacity];
		memset(newBlock, 0, sizeof(T) * newCapacity);

		if (newCapacity < size)
		{
			size = newCapacity;
		}

		memcpy(newBlock, data, sizeof(T) * newCapacity); // data != nullptr

		delete[] data;
		data = newBlock;
		capacity = newCapacity;
	}

public:
	// getter
	__forceinline size_t Size() const { return size; }
	__forceinline size_t Capacity() const { return capacity; }

private:
	T* data = nullptr;
	size_t capacity = 0;
	size_t size = 0;
};