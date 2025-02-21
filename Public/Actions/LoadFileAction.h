#pragma once

#include "Action.h"
#include "../DataObject.h"
#include <iostream>

template <typename T>
class LoadFileAction : public Action<T>
{
public:
	std::unique_ptr<DataObject<T>> process(std::unique_ptr<DataObject<T>> input) override
	{
		// TODO: Load objects here using different logic depending on input type
		std::cout << "Loading: " << input->getMeta().filePath << "\n";
		return input;
	}

	bool canProcess(DataType type) const override
	{
		return type != DataType::Final || type != DataType::Unknown;
	}
};