#ifndef LOCALIZATION_TOOL_INTERNAL_UTILITIES_PSTRING_H_ 
#define LOCALIZATION_TOOL_INTERNAL_UTILITIES_PSTRING_H_

#include "Internal/Declarations/Standard_Library.hpp"
#include <Utilities.hpp>

namespace prz
{
	class PString
	{
	public:

		PString() : 
			m_stringAsCharArray(nullptr)
		{
			set_string("");
		}

		PString(const string& str) :
			m_stringAsCharArray(nullptr)
		{
			set_string(str);
		}

		PString(const PString& other) :
			m_stringAsCharArray(nullptr)
		{
			set_string(other.m_string);
		}

		~PString()
		{
			delete[] m_stringAsCharArray;
		}

	public:

		void set_string(const string& str)
		{
			m_string = str;

			copy(m_string, m_stringAsCharArray);
		}

	public:

		void operator= (const PString& other)
		{
			set_string(other.m_string);
		}

		void operator= (const string& s)
		{
			set_string(m_string);
		}

		void operator= (const char* charArray)
		{
			set_string(get_string_from(charArray));
		}

		operator const string& () const
		{
			return m_string;
		}

		operator const char* () const
		{
			return m_stringAsCharArray;
		}

	public:

		const string& get_string() const
		{
			return m_string;
		}

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

		LOCALIZATION_TOOL_API int get_pstring_size(PString* pString);
		LOCALIZATION_TOOL_API const char* get_pstring_char_array(PString* pString);

	}
	#pragma endregion PStringExport
	
}

#endif // !LOCALIZATION_TOOL_INTERNAL_UTILITIES_PSTRING_H_