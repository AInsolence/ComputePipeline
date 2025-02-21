// ComputePipeline.cpp : Defines the entry point for the application.
//

#include "ComputePipeline.h"
#include "Public/Pipeline.h"

#include "Public/Actions/LoadFileAction.h"
#include "Public/Actions/ExtractZipAction.h"
#include "Public/Actions/ImgDecodeAction.h"
#include "Public/Actions/JSONParseAction.h"

using namespace std;

int main()
{
	Pipeline pipeline;

	pipeline.addAction(std::make_unique<LoadFileAction<std::string>>());
	pipeline.addAction(std::make_unique<ExtractZipAction>());
	pipeline.addAction(std::make_unique<ImgDecodeAction>());
	pipeline.addAction(std::make_unique<JSONParseAction>());

	std::cout << "Starting Pipeline\n\n";

	pipeline.addInput("/path/to/archive.zip");
	pipeline.addInput("/path/to/file.json");
	pipeline.addInput("/path/to/image.jpg");
	pipeline.addInput("https://path/to/image.jpg");
	pipeline.addInput("bundle://path/to/image.jpg");

	pipeline.process();

	return 0;
}
