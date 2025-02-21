#include "../Public/Pipeline.h"

#include <iostream>

#include "../Public/Actions/ExtractZipAction.h"

void Pipeline::addAction(std::unique_ptr<Action<std::string>> action)
{
	PipelineActions.push_back(std::move(action));
}

void Pipeline::addInput(const std::string& data)
{
	MetaData meta = getMetaDataFromFile(data);
	queue.push(std::make_unique<DataObject<std::string>>(data, meta));
}

void Pipeline::process()
{
	while (!queue.empty())
	{
		auto ProcessedObj = std::move(queue.front());
		queue.pop();

		std::cout << "Processing: " << ProcessedObj->getMeta().filePath << "\n";

		bool actionApplied = false;

		for (const auto& action : PipelineActions)
		{
			if (action->canProcess(ProcessedObj->getMeta().type))
			{
				ProcessedObj = action->process(std::move(ProcessedObj));
				actionApplied = true;
			}
		}

		if (actionApplied)
		{
			std::cout << "Processed: " << ProcessedObj->getData() << "\n";
		}
		else
		{
			std::cout << "Skipping, no applicable processing for: " << ProcessedObj->getMeta().filePath << "\n";
		}

		std::cout << "URI Type: " << static_cast<int>(ProcessedObj->getMeta().uriType) << "\n";
		std::cout << "Data Type: " << static_cast<int>(ProcessedObj->getMeta().type) << "\n\n";

		if (ProcessedObj->getMeta().type == DataType::Zip)
		{
			queue.push(std::move(ProcessedObj));
		}
	}
}

MetaData Pipeline::getMetaDataFromFile(const std::string& filePath) const
{
	const DataType type = detectDataType(filePath);

	MetaData metaData;
	metaData.filePath = filePath;
	metaData.type = type;

	metaData.uriType = UriType::File;

	return metaData;
}
