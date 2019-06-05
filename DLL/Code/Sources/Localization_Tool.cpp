#include "pch.h"
#include <Localization_Tool.hpp>

#include <string>

namespace prz
{
	int add(int a, int b)
	{
		return a + b;
	}

	const char* get_byte_array()
	{
		std::string s = "This is a boring test";

		int stringLength = s.length() + 1; // + "/0"

		char* charArray = new char[stringLength];
		const char* charArrayToReturn = new char[stringLength];

		strcpy_s(charArray, stringLength, s.c_str());
		charArrayToReturn = charArray;

		return charArrayToReturn;
	}
	
	int free_memory(char* arrayPtr)
	{
		delete[] arrayPtr;
		return 0;
	}
}