
/**
 * @file PString.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief Class to handle a string with "smart" allocated memory
 * @version 0.1
 * @date 09-06-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef LOCALIZATION_TOOL_INTERNAL_UTILITIES_PSTRING_H_ 
#define LOCALIZATION_TOOL_INTERNAL_UTILITIES_PSTRING_H_

#include "Internal/Declarations/Standard_Library.hpp"
#include <Utilities.hpp>

namespace prz
{
	class PString
	{
	public:

		/**
		 * @brief Construct a new PString
		 * 
		 */
		PString() : 
			m_stringAsCharArray(nullptr)
		{
			set_string("");
		}

		/**
		 * @brief Construct a new PString
		 * 
		 * @param str 
		 */
		PString(const string& str) :
			m_stringAsCharArray(nullptr)
		{
			set_string(str);
		}

		/**
		 * @brief Construct a new PString
		 * 
		 * @param other 
		 */
		PString(const PString& other) :
			m_stringAsCharArray(nullptr)
		{
			set_string(other.m_string);
		}

		/**
		 * @brief Destroy the PString
		 * 
		 */
		~PString()
		{
			free_char_array(m_stringAsCharArray);
		}

	public:

		/**
		 * @brief Set the string 
		 * 
		 * @param str 
		 */
		void set_string(const string& str)
		{
			m_string = str;

			free_char_array(m_stringAsCharArray);

			m_stringAsCharArray = to_char_array(str);
		}

	public:
		
		/**
		 * @brief Operator = 
		 * 
		 * @param other 
		 */
		void operator= (const PString& other)
		{
			set_string(other.m_string);
		}

		/**
		 * @brief Operator = 
		 * 
		 * @param s 
		 */
		void operator= (const string& s)
		{
			set_string(s);
		}

		/**
		 * @brief Operator = 
		 * 
		 * @param charArray 
		 */
		void operator= (const char* charArray)
		{
			set_string(charArray);
		}

		/**
		 * @brief Return the PString as a string
		 * 
		 * @return const string& 
		 */
		operator const string& () const
		{
			return m_string;
		}
		
		/**
		 * @brief Return the PString as a char array 
		 * 
		 * @return const char* 
		 */
		operator const char* () const
		{
			return m_stringAsCharArray;
		}

	public:

		/**
		 * @brief Get the string 
		 * 
		 * @return const string& 
		 */
		const string& get_string() const
		{
			return m_string;
		}

		/**
		 * @brief Get the char array 
		 * 
		 * @return const char* 
		 */
		const char* get_char_array() const
		{
			return m_stringAsCharArray;
		}

	private:

		string m_string;
		char* m_stringAsCharArray;

	};

	#pragma region PStringExport
	extern "C"
	{

		/**
		 * @brief Get the pstring size 
		 * 
		 * @param pString 
		 * @return int 
		 */
		LOCALIZATION_TOOL_API int get_pstring_size(PString* pString);

		/**
		 * @brief Get the pstring char array 
		 * 
		 * @param pString 
		 * @return const char* 
		 */
		LOCALIZATION_TOOL_API const char* get_pstring_char_array(PString* pString);

	}
	#pragma endregion PStringExport
	
}

#endif // !LOCALIZATION_TOOL_INTERNAL_UTILITIES_PSTRING_H_