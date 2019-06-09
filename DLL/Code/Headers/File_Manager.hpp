/**
 * @file File_Manager.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief Create, load, store and manage sequences and files
 * @version 0.1
 * @date 07-06-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef LOCALIZATION_TOOL_SEQUENCES_LOADER_H_
#define LOCALIZATION_TOOL_SEQUENCES_LOADER_H_

#include <Declarations.hpp>

namespace prz
{
	class Sequence;

	/**
	 * @brief Create, load, store and manage sequences and files
	 * 
	 */
	class File_Manager
	{
	public:

		/**
		 * @brief Return the instance to the file manager
		 * 
		 * @return File_Manager& 
		 */
		static File_Manager& instance()
		{
			static File_Manager instance;
			return instance;
		}

	public:

		/**
		 * @brief Load a file in path.
		 * 
		 * @param filePath 
		 * @param forceReimport 
		 * @return int. The number of sequences loaded by file
		 */
		int load_file(const string& filePath, bool forceReimport = false);

		/**
		 * @brief Load all file sequences
		 * 
		 * @param filePath 
		 * @return int. The number of sequences loaded by file
		 */
		int load_file_sequences(const string& filePath);

	public:

		/**
		 * @brief Copy the audio files by path (that audio clips store) to the destination folder
		 * 
		 * @param fileName 
		 * @param destination 
		 * @return true 
		 * @return false 
		 */
		bool copy_all_audio_clip_files_of_file(const string& fileName, const string& destination);

	public:

		/**
		 * @brief Get the file sequences by name array
		 * 
		 * @param fileName 
		 * @return Sequence** 
		 */
		Sequence** get_file_sequences_by_name(const string& fileName);

		/**
		 * @brief Get the file sequences by path array
		 * 
		 * @param filePath 
		 * @return Sequence** 
		 */
		Sequence** get_file_sequences_by_path(const string& filePath);

	public:

		/**
		 * @brief Return if a file is loaded by name
		 * 
		 * @param fileName 
		 * @return true 
		 * @return false 
		 */
		bool is_file_loaded_by_name(const string& fileName);	

		/**
		 * @brief Return if a file is loaded by path
		 * 
		 * @param filePath 
		 * @return true 
		 * @return false 
		 */
		bool is_file_loaded_by_path(const string& filePath);

	public:

		/**
		 * @brief Get the file number of sequences by name 
		 * 
		 * @param fileName 
		 * @return int 
		 */
		int get_file_number_of_sequences_by_name(const string& fileName);

		/**
		 * @brief Get the file number of sequences by path 
		 * 
		 * @param filePath 
		 * @return int 
		 */
		int get_file_number_of_sequences_by_path(const string& filePath);

	private:

		/**
		 * @brief Construct a new File_Manager. PRIVATE
		 * 
		 */
		File_Manager(){}

		/**
		 * @brief Destroy the File_Manager. PRIVATE
		 * 
		 */
		~File_Manager();

	private:

		/**
		 * @brief Create a sequence
		 * 
		 * @param sequenceItem 
		 * @return Sequence* 
		 */
		Sequence* create_sequence(const value_json& sequenceItem);

	private:

		/**
		 * @brief Delete all sequences from a file name
		 * 
		 * @param fileName 
		 */
		void clear_file_sequences(const string& fileName);

	private:

		unordered_map <string, vector<Sequence*>> m_sequencesByFile;
			
	};

	#pragma region SequencesLoaderExport

	extern "C"
	{	
		/**
		 * @brief load file
		 * 
		 * @param jsonFilePath 
		 * @param forceReimport 
		 * @return int. Number of sequences loaded
		 */
		LOCALIZATION_TOOL_API int load_file(const char* jsonFilePath, bool forceReimport);

		/**
		 * @brief load file and return the sequences array
		 * 
		 * @param jsonFilePath 
		 * @param forceReimport 
		 * @return Sequence** 
		 */
		LOCALIZATION_TOOL_API Sequence** load_file_and_get_sequences(const char* jsonFilePath, bool forceReimport);

		/**
		 * @brief Get the file sequences by name 
		 * 
		 * @param fileName 
		 * @return Sequence** 
		 */
		LOCALIZATION_TOOL_API Sequence** get_file_sequences_by_name(const char* fileName);

		/**
		 * @brief Get the file sequences by path 
		 * 
		 * @param filePath 
		 * @return Sequence** 
		 */
		LOCALIZATION_TOOL_API Sequence** get_file_sequences_by_path(const char* filePath);

		/**
		 * @brief Return if a file is loaded by name
		 * 
		 * @param fileName 
		 * @return true 
		 * @return false 
		 */
		LOCALIZATION_TOOL_API bool is_file_loaded_by_name(const char* fileName);

		/**
		 * @brief Return if a file is loaded by path
		 * 
		 * @param filePath 
		 * @return true 
		 * @return false 
		 */
		LOCALIZATION_TOOL_API bool is_file_loaded_by_path(const char* filePath);

		/**
		 * @brief Get the file number of sequences by name 
		 * 
		 * @param fileName 
		 * @return int 
		 */
		LOCALIZATION_TOOL_API int get_file_number_of_sequences_by_name(const char* fileName);

		/**
		 * @brief Get the file number of sequences by path 
		 * 
		 * @param filePath 
		 * @return int 
		 */
		LOCALIZATION_TOOL_API int get_file_number_of_sequences_by_path(const char* filePath);
	}

	#pragma endregion SequencesLoaderExport
	
} // !namespace prz

#endif // !LOCALIZATION_TOOL_SEQUENCES_LOADER_H_
