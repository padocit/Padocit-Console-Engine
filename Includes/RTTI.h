#pragma once

#include "Core.h"

class ENGINE_API RTTI
{
public:
	virtual const size_t& TypeIdInstance() const = 0;

	virtual bool Is(const size_t id) const
	{
		return false;
	}

	template<typename T>
	T* As()
	{
		if (Is(T::TypeIdClass()))
		{
			return (T*)this;
		}

		return nullptr;
	}

	template<typename T>
	const T* As() const
	{
		if (Is(T::TypeIdClass()))
		{
			return (T*)this;
		}

		return nullptr;
	}
};

#define GENERATED_BODY(Type, ParentType)\
public:\
	using Super = ParentType;\
	virtual const size_t& TypeIdInstance() const { return Type::TypeIdClass(); }\
	static const size_t TypeIdClass()\
	{\
		static int runTimeTypeId = 0;\
		return reinterpret_cast<size_t>(&runTimeTypeId);\
	}\
	virtual bool Is(const size_t id) const\
	{\
		if (id == TypeIdClass())\
		{\
			return true;\
		}\
		else\
		{\
 			return Super::Is(id);\
		}\
	}\

// TODO: 성능개선 - typeId 저장 Hashtable 사용