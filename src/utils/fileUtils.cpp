#include "fileUtils.h"

#include <iostream>
#include <fstream>

std::string readFileAsString(const char* path)
{
	std::string content;
	std::ifstream fileStream(path, std::ios::in);

	if (!fileStream.is_open())
	{
		std::cout << "File doesn't exist: " << path << std::endl;
		std::exit(-1);
	}

	std::string line = "";
	while (!fileStream.eof())
	{
		std::getline(fileStream, line);
		content.append(line + "\n");
	}

	fileStream.close();
	return content;
}