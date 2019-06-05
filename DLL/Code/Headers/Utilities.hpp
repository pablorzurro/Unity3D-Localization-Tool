/**
 * @file Utilities.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief 
 * @version 0.1
 * @date 05-06-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef LOCALIZATION_TOOL_INTERNAL_UTILITIES_H_
#define LOCALIZATION_TOOL_INTERNAL_UTILITIES_H_

#include "Internal/Utilities/Math.hpp"

namespace prz
{

	static string split_string_by_separator(const string& str, const char * separator)
	{
		return str.substr(str.find_last_of(separator) + 1);
	}

	static string load_file_as_string(const string& filePath)
	{
		string str;

		// Open the file

		fstream fileReader(filePath, fstream::in | fstream::binary);

		if (fileReader.is_open())
		{
			// Get the file size

			fileReader.seekg(0, fstream::end);

			size_t fileSize = size_t(fileReader.tellg());

			if (fileReader.good() && fileSize > 0)
			{
				// Read the content of the file and save it in a string
				// It is expected that the file contains one byte for each character with a code smaller than 128 (UTF-8, etc.).

				str.resize(fileSize);

				fileReader.seekg(0, fstream::beg);
				fileReader.read(&str.front(), fileSize);

				assert(fileReader.good());
			}
		}
		else
			assert(false);

		return str;
	}

	template< typename T >
	static size_t byte_sizeof(const std::vector<T>& vector)
	{
		return vector.size() * sizeof(T);
	}
}

#endif // !LOCALIZATION_TOOL_INTERNAL_UTILITIES_H_
