#pragma once

#include <string>

enum class DataType {
	Image,
	JSON,
	Zip,
	Final,
	Unknown
};

enum class UriType {
	File,
	Url,
	Bundle,
	Unknown
};

struct MetaData {
	std::string filePath;
	DataType type;
	UriType uriType;
};
