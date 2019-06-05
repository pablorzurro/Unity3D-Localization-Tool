#include "pch.h"
#include "Audio_Clip.hpp"

prz::Audio_Clip::~Audio_Clip()

{
	delete[] m_filePath;
	delete[] m_fileName;
	delete[] m_completeFilePath;
}
