#include <pch.h>
#include <Interface.hpp>

#include <Utilities.hpp>

namespace prz
{
	extern "C"
	{

		char* test_communication(const char* charArray)
		{
			string myString = get_string_from(charArray) + " Mode";
			
			return get_copy_of(to_char_array(myString));
		}

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

		int free_pointer(void* ptr)
		{
			delete ptr;
			return 0;
		}
	}
}
