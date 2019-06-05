#ifndef LOCALIZATION_TOOL_INTERFACE_H_
#define LOCALIZATION_TOOL_INTERFACE_H_

#ifdef LOCALIZATIONTOOL_EXPORTS
#define LOCALIZATION_TOOL_API __declspec(dllexport)
#else
#define LOCALIZATION_TOOL_API __declspec(dllimport)
#endif

#include <Declarations.hpp>

namespace prz
{

	extern "C"
	{

	#pragma region Utilities

		#pragma region Memory Release

		LOCALIZATION_TOOL_API int free_char_array(char* charArray);
		LOCALIZATION_TOOL_API int free_pointer(void* ptr);

		#pragma endregion

		#pragma region Testing

		LOCALIZATION_TOOL_API const char* get_byte_array();

		#pragma endregion

	#pragma endregion
		
	}

} // !namespace prz


#endif // !LOCALIZATION_TOOL_INTERFACE_H_
