#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Action.h"
#include "../DataObject.h"
#include "../Utility.h"


class ExtractZipAction : public Action<std::string>
{
public:
	std::unique_ptr<DataObject<std::string>> process(std::unique_ptr<DataObject<std::string>> input) override
	{
		if (input->getMeta().type == DataType::Zip)
		{
			std::cout << "Extracting zip: " << input->getMeta().filePath << "\n";

			// TODO: extract archive here

			// Mock data for testing
			constexpr int mock_num_entries = 1;

			for (int i = 0; i < mock_num_entries; ++i)
			{
				std::string filename = "Mock Image";
				std::cout << "Found file inside zip: " << filename << "\n";

				const DataType fileType = DataType::Image; // TODO: substitute to detectDataType(filename);

				if constexpr (fileType == DataType::JSON)
				{
					MetaData _meta = input->getMeta();
					_meta.type = DataType::JSON;
					_meta.filePath = "new_json_path_after_extraction";

					return std::make_unique<DataObject<std::string>>(filename, _meta);
				}
				else if constexpr (fileType == DataType::Image)
				{
					MetaData _meta = input->getMeta();
					_meta.type = DataType::Image;
					_meta.filePath = "new_img_path_after_extraction";

					return std::make_unique<DataObject<std::string>>(filename, _meta);
				}
			}
		}
		
		std::string filename = "Empty archive";
		MetaData _meta = input->getMeta();
		_meta.type = DataType::Unknown;

		return std::make_unique<DataObject<std::string>>(filename, _meta);
	}

	
	bool canProcess(DataType type) const override
	{
		return type == DataType::Zip;
	}
};