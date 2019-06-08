
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

		void load_file(const string& filePath, bool forceReimport = false);
		void load_file_sequences(const string& filePath);

	public:

		Sequence* create_sequence(const value_json& sequenceItem);

	public:

		Sequence** get_file_sequences_by_name(const string& fileName);
		Sequence** get_file_sequences_by_path(const string& filePath);

	public:

		bool is_file_loaded_by_name(const string& fileName);
		bool is_file_loaded_by_path(const string& filePath);

	public:

		int get_file_number_of_sequences_by_name(const string& fileName);
		int get_file_number_of_sequences_by_path(const string& filePath);

	private:

		Sequences_Loader(){}
		~Sequences_Loader();

	private:

		void clear_file_sequences(const string& fileName);

	private:

		unordered_map <string, vector<Sequence*>> m_sequencesByFile;
			
	};

	#pragma region SequencesLoaderExport

	extern "C"
	{
		LOCALIZATION_TOOL_API Sequence** load_file(const char* jsonFilePath, bool forceReimport);
		LOCALIZATION_TOOL_API Sequence** get_file_sequences_by_name(const string& fileName);
		LOCALIZATION_TOOL_API Sequence** get_file_sequences_by_path(const string& filePath);
		LOCALIZATION_TOOL_API bool is_file_loaded_by_name(const string& fileName);
		LOCALIZATION_TOOL_API bool is_file_loaded_by_path(const string& filePath);
		LOCALIZATION_TOOL_API int get_file_number_of_sequences_by_name(const string& fileName);
		LOCALIZATION_TOOL_API int get_file_number_of_sequences_by_path(const string& filePath);
	}

	#pragma endregion SequencesLoaderExport
	
} // !namespace prz

#endif // !LOCALIZATION_TOOL_SEQUENCES_LOADER_H_
