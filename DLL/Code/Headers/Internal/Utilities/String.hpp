/**
 * @file String.hpp
 * @author Pablo Rodriguez (przuro@gmail.com)
 * @brief 
 * @version 0.1
 * @date 05-06-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef LOCALIZATION_TOOL_INTERNAL_UTILITIES_STRING_H_
#define LOCALIZATION_TOOL_INTERNAL_UTILITIES_STRING_H_

#include <Declarations.hpp>

namespace prz
{

	static bool free_char_array(char* charArray)
	{
		if (charArray)
		{
			delete[] charArray;
			return true;
		}

		return false;
	}

	static string split_string_by_separator(const string& str, const char* separator)
	{
		return str.substr(str.find_last_of(separator) + 1);
	}

	static string get_string_from(const char* charArray)
	{
		return string(charArray);
	}
	
	static char* get_copy_of(const char* charArray, size_t size, bool lastNullCharIncluded = false)
	{
		if (size != 0)
		{
			if (!lastNullCharIncluded)
			{
				++size; // Include the trailing '\0' character
			}

			char* arrayToReturn = new char[size]; // Create a char array with the input array size
			strcpy_s(arrayToReturn, size, charArray); // Copy the elemets from the input array to the new array
			return arrayToReturn;
		}

		return nullptr;
	}

	static char* get_copy_of(const char* charArray)
	{
		if (charArray)
		{
			size_t size = char_traits<char>::length(charArray);

			if (size != 0)
			{
				return get_copy_of(charArray, size);
			}
		}

		return nullptr;
	}

	static char* to_char_array(const string& str)
	{
		return get_copy_of(str.c_str(), str.length());
	}

	static void copy(const char* from, char* to)
	{
		free_char_array(to); // Delete the previous memory block 
		to = get_copy_of(from);
	}

	static void copy(const string& from, char* to)
	{
		free_char_array(to);// Delete the previous memory block
		to = to_char_array(from);
	}

}

#endif // !LOCALIZATION_TOOL_INTERNAL_UTILITIES_STRING_H_
