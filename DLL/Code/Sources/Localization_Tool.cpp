#include "pch.h"
#include <Localization_Tool.hpp>

namespace prz
{
	int add(int a, int b)
	{
		return a + b;
	}

	char* test_byte_array()
	{
		//Create your array(Allocate memory)
		char* arrayTest = new char[2];

		//Do something to the Array
		arrayTest[0] = 3;
		arrayTest[1] = 5;

		//Return it
		return arrayTest;
	}
	
	int free_memory(char* arrayPtr)
	{
		delete[] arrayPtr;
		return 0;
	}
}