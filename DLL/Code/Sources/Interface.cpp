#include <pch.h>
#include <Interface.hpp>

#include <Utilities.hpp>
#include <File_Manager.hpp>

namespace prz
{
	extern "C"
	{

		float test_get_seconds_from_string(const char* str)
		{
			return get_seconds_from_string(str);
		}

		const char* test_me(const char* str)
		{
			string s(str);

			char* m_ = nullptr;
			copy(s, m_);
			return m_;
		}

	}
	
}
