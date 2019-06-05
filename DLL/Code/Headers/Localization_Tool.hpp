#ifndef LOCALIZATION_TOOL_LOCALIZATION_TOOL_H_
#define LOCALIZATION_TOOL_LOCALIZATION_TOOL_H_

#ifdef LOCALIZATIONTOOL_EXPORTS
#define LOCALIZATIONTOOL_API __declspec(dllexport)
#else
#define LOCALIZATIONTOOL_API __declspec(dllimport)
#endif

namespace prz
{

	extern "C"
	{
		LOCALIZATIONTOOL_API int add(int a, int b);

		LOCALIZATIONTOOL_API const char* get_byte_array();
		
		LOCALIZATIONTOOL_API int free_memory(char* arrayPtr);
	}

} // !namespace prz


#endif // !LOCALIZATION_TOOL_LOCALIZATION_TOOL_H_
