

#ifndef LOCALIZATION_TOOL_SEQUENCE_H_
#define LOCALIZATION_TOOL_SEQUENCE_H_

#include <Declarations.hpp>

namespace prz
{

	class Audio_Track;
	class Text_Track;

	class Sequence
	{
	public:

		Sequence(){}

	private:

		vector <shared_ptr<Audio_Track>> m_audioTracks;
		vector <shared_ptr<Text_Track>> m_textTracks;
	};

} // !namespace prz


#endif // !LOCALIZATION_TOOL_SEQUENCE_H_
