/**
 * @file Interface.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief 
 * @version 0.1
 * @date 02-06-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef LOCALIZATION_TOOL_INTERFACE_H_
#define LOCALIZATION_TOOL_INTERFACE_H_

#include <Declarations.hpp>

namespace prz
{

	extern "C"
	{

	#pragma region Utilities

		#pragma region Testing

		LOCALIZATION_TOOL_API float test_get_seconds_from_string(const char* str);

		#pragma endregion

	#pragma endregion
		
	}

} // !namespace prz


#endif // !LOCALIZATION_TOOL_INTERFACE_H_
