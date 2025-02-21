#pragma once

#include <string>
#include <regex>
#include "MetaData.h"

static UriType detectUriType(const std::string& uri)
{
	const std::regex localFile(R"(^/([^/ ]+/)*([^/ ]+)$)");
	const std::regex url(R"(^https?://.+)");
	const std::regex bundle(R"(^bundle://.+)");

	if (std::regex_search(uri, url)) return UriType::Url;
	if (std::regex_search(uri, bundle)) return UriType::Bundle;
	if (std::regex_search(uri, localFile)) return UriType::File;

	return UriType::Unknown;
}

static DataType detectDataType(const std::string& path)
{
	const std::regex zipRegex(".*\\.zip$", std::regex_constants::icase);
	const std::regex imageRegex(".*\\.(jpg|jpeg|png|gif|bmp)$", std::regex_constants::icase);
	const std::regex jsonRegex(".*\\.json$", std::regex_constants::icase);

	if (std::regex_search(path, zipRegex))
	{
		return DataType::Zip;
	}
	else if (std::regex_search(path, imageRegex))
	{
		return DataType::Image;
	}
	else if (std::regex_search(path, jsonRegex))
	{
		return DataType::JSON;
	}

	return DataType::Unknown;
}
