/**
 * @file Math.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief 
 * @version 0.1
 * @date 05-06-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef LOCALIZATION_TOOL_INTERNAL_UTILITIES_MATH_H_
#define LOCALIZATION_TOOL_INTERNAL_UTILITIES_MATH_H_

#include <Declarations.hpp>

#include <time.h>
#include <random>

namespace prz
{
    
    template
	<
		typename T, //real type
		typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
	>
	static T random(T min, T max, bool seed = false) //range : [min, max)
	{
		static bool first = true;

		if (first || seed)
		{
			srand((unsigned int)time(NULL));
		}

		return min + T(rand()) / T(RAND_MAX) * (max - min);
	}

}

#endif //LOCALIZATION_TOOL_INTERNAL_UTILITIES_MATH_H_