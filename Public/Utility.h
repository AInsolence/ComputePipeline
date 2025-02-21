#pragma once

#include <string>
#include <regex>
#include "MetaData.h"

static UriType detectUriType(const std::string& uri)
{
	const std::regex localFile(R"(^/([^/ ]+/)*([^/ ]+)$)");
	const std::regex url(R"(^https?://.+)");
	const std::regex bundle(R"(^bundle://.+)");

	if (std::regex_match(uri, url)) return UriType::Url;
	if (std::regex_match(uri, bundle)) return UriType::Bundle;
	if (std::regex_match(uri, localFile)) return UriType::File;

	return UriType::Unknown;
}

static DataType detectDataType(const std::string& path)
{
	const std::regex zipRegex(".*\\.zip$", std::regex_constants::icase);
	const std::regex imageRegex(".*\\.(jpg|jpeg|png|gif|bmp)$", std::regex_constants::icase);
	const std::regex jsonRegex(".*\\.json$", std::regex_constants::icase);

	if (std::regex_match(path, zipRegex))
	{
		return DataType::Zip;
	}
	else if (std::regex_match(path, imageRegex))
	{
		return DataType::Image;
	}
	else if (std::regex_match(path, jsonRegex))
	{
		return DataType::JSON;
	}

	return DataType::Unknown;
}
