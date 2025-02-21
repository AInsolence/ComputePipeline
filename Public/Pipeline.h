#pragma once

#include <memory>
#include <queue>
#include <string>
#include <vector>

#include "DataObject.h"
#include "Actions/Action.h"


class Pipeline
{
public:
	void process();

	void addInput(const std::string& data);
	void addAction(std::unique_ptr<Action<std::string>> action);

private:
	std::queue<std::unique_ptr<DataObject<std::string>>> queue;
	std::vector<std::unique_ptr<Action<std::string>>> PipelineActions;

	MetaData getMetaDataFromFile(const std::string& filePath) const;
};
