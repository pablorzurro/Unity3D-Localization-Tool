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
#include "Internal/Utilities/String.hpp"

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

	// Must have the next format: "Minutes:Seconds:Milliseconds"
	static float get_seconds_from_string(const string& str)
	{
		if (std::count(str.begin(), str.end(), ':') == 2)
		{
			string minutesStr = str; // "Minutes:Seconds:Milliseconds"
			string secondsStr = split_string_by_separator(str, ":"); // "Seconds:Milliseconds"
			string millisecondsStr = split_string_by_separator(secondsStr, ":");  // "Milliseconds"

			string strToRemoveForMinutes = ":" + secondsStr;  // ":Seconds:Milliseconds"
			string strToRemoveForSeconds = ":" + millisecondsStr; // ":Milliseconds"


			std::string::size_type i1 = minutesStr.find(":" + secondsStr);
			std::string::size_type i2 = secondsStr.find(":" + strToRemoveForSeconds);

			if (i1 != std::string::npos)
			{
				minutesStr.erase(i1, strToRemoveForMinutes.length());
			}
			if (i2 != std::string::npos)
			{
				secondsStr.erase(i2, strToRemoveForSeconds.length());
			}

			float minutes = stof(minutesStr);
			float seconds = stof(secondsStr);
			float milliseconds = stof(millisecondsStr);


			return (minutes * 60.f) + seconds + (milliseconds / 1000.f);
		}

		return float::MinValue;
	}

}

#endif //LOCALIZATION_TOOL_INTERNAL_UTILITIES_MATH_H_