#pragma once

#include <memory>

#include "../DataObject.h"

template <typename T>
class Action
{
public:
	virtual ~Action() = default;

	virtual bool canProcess(DataType type) const = 0;
	virtual std::unique_ptr<DataObject<T>> process(std::unique_ptr<DataObject<T>> input) = 0;
};
