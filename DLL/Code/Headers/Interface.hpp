#ifndef LOCALIZATION_TOOL_LOCALIZATION_TOOL_H_
#define LOCALIZATION_TOOL_LOCALIZATION_TOOL_H_

#ifdef LOCALIZATIONTOOL_EXPORTS
#define LOCALIZATIONTOOL_API __declspec(dllexport)
#else
#define LOCALIZATIONTOOL_API __declspec(dllimport)
#endif

#include <Declarations.hpp>

namespace prz
{

	extern "C"
	{

	#pragma region Utilities

		#pragma region Memory Release

		LOCALIZATIONTOOL_API int free_char_array(char* charArray);
		LOCALIZATIONTOOL_API int free_pointer(void* ptr);

		#pragma endregion

		#pragma region Testing

		LOCALIZATIONTOOL_API const char* get_byte_array();

		#pragma endregion

	#pragma endregion
		
	}

} // !namespace prz


#endif // !LOCALIZATION_TOOL_LOCALIZATION_TOOL_H_
