#include <pch.h>
#include "Internal/Utilities/PString.hpp"

namespace prz
{

	#pragma region PStringExport
	extern "C"
	{

		int get_pstring_size(PString* pString)
		{
			if (pString)
			{
				return (int)pString->get_string().size();
			}

			return int::MinValue;
		}

		const char* get_pstring_char_array(PString* pString)
		{
			if (pString)
			{
				return pString->get_char_array();
			}

			return nullptr;
		}

	}
	#pragma endregion PStringExport

}