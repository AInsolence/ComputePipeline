#pragma once

#include <iostream>

#include "Action.h"
#include "../DataObject.h"

class ImgDecodeAction : public Action<std::string>
{
public:
	std::unique_ptr<DataObject<std::string>> process(std::unique_ptr<DataObject<std::string>> input) override
	{
		std::cout << "Decoding image: " << input->getMeta().filePath << "\n";

		if (input->getMeta().type == DataType::Image)
		{
			// TODO: Decode image here
			input->getMeta().type = DataType::Final; // Assuming this is a final object
		}

		return input;
	}

	bool canProcess(DataType type) const override
	{
		return type == DataType::Image;
	}
};
