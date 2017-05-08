#include "Settings.h"



Settings::Settings(const char * SaveFile) : mFileName(SaveFile) {/*Empty*/}


Settings::~Settings()
{
	if (mInputFile.is_open())
	{
		mInputFile.close();
	}
}
