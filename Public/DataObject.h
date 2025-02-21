#pragma once

#include "MetaData.h"

template <typename T>
class DataObject
{
public:
	DataObject(T _data, MetaData _meta) : data(std::move(_data)), meta(std::move(_meta)) {}

	T& getData()
	{
		return data;
	}

	const T& getData() const
	{
		return data;
	}

	MetaData& getMeta()
	{
		return meta;
	}

	const MetaData& getMeta() const
	{
		return meta;
	}

	void setMeta(MetaData _meta)
	{
		meta = std::move(_meta);
	}

private:
	T data;
	MetaData meta;
};
