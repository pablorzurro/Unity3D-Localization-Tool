/**
 * @file IO.hpp
 * @author Pablo Rodriguez (przuro@gmail.com)
 * @brief 
 * @version 0.1
 * @date 05-06-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef LOCALIZATION_TOOL_INTERNAL_UTILITIES_IO_H_
#define LOCALIZATION_TOOL_INTERNAL_UTILITIES_IO_H_

#include <Declarations.hpp>

namespace prz
{

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
				// Read the content of the file and save it
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

}


#endif // !LOCALIZATION_TOOL_INTERNAL_UTILITIES_IO_H_
