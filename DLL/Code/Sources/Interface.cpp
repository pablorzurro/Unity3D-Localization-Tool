#include <pch.h>
#include <Interface.hpp>

#include <Utilities.hpp>

namespace prz
{
	extern "C"
	{

		const char* get_byte_array()
		{
			string s = "This is a boring test";

			size_t stringLength = s.length() + 1; // + "/0"

			char* charArray = new char[stringLength];
			const char* charArrayToReturn = new char[stringLength];

			strcpy_s(charArray, stringLength, s.c_str());
			charArrayToReturn = charArray;

			return charArrayToReturn;
		}

		int free_char_array(char* charArray)
		{
			delete[] charArray;
			return 0;
		}

		int free_pointer(void* ptr)
		{
			delete ptr;
			return 0;
		}

		int free_memory(void* memory)
		{
			if()
			delete memory;
		}

	}
}
