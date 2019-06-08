/**
 * @file Utilities.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief 
 * @version 0.1
 * @date 05-06-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef LOCALIZATION_TOOL_UTILITIES_H_
#define LOCALIZATION_TOOL_UTILITIES_H_

#include "Internal/Utilities/Math.hpp"
#include "Internal/Utilities/String.hpp"
#include "Internal/Utilities/IO.hpp"
#include "Internal/Utilities/Nlohmann_JSON_Converter.hpp"

namespace prz
{

	template< typename T >
	static size_t byte_sizeof(const vector<T>& vec)
	{
		return vec.size() * sizeof(T);
	}
}

#endif // !LOCALIZATION_TOOL_UTILITIES_H_
