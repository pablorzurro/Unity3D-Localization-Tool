
#ifndef LOCALIZATION_TOOL_SEQUENCES_LOADER_H_
#define LOCALIZATION_TOOL_SEQUENCES_LOADER_H_

#include <Declarations.hpp>

namespace prz
{
	class Sequence;

	class Sequences_Loader
	{
	public:

		static Sequences_Loader& instance()
		{
			static Sequences_Loader instance;
			return instance;
		}

	public:

		void load_file_sequences(const string& filePath);
		Sequence* create_sequence(const json::value_type& sequenceItem);

	public:

		bool is_file_loaded(const string& fileName);

	private:

		Sequences_Loader(){}
		~Sequences_Loader();

	private:

		unordered_map <string, list<Sequence*>> m_sequencesByFile;
			
	};
	
} // !namespace prz

#endif // !LOCALIZATION_TOOL_SEQUENCES_LOADER_H_
