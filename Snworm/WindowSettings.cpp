#include "WindowSettings.h"

WindowSettings::WindowSettings(const char * LoadFile) : Settings(LoadFile)
{
	load();
}

WindowSettings::~WindowSettings(){/*Empty*/}

void WindowSettings::load()
{
	this->mInputFile.open(mFileName);
	std::string garbage;
	mInputFile >> garbage >> mWidth;
	mInputFile >> garbage >> mHeight;
	mInputFile >> garbage>> mFrameRate;
	this->mInputFile.close();
}

void WindowSettings::save()
{
	this->mInputFile.open(mFileName);
	mInputFile << "Width\t" << mWidth << "\n";
	mInputFile << "Height\t" << mHeight << "\n";
	mInputFile << "FrameRate\t" << mFrameRate << "\n";
	this->mInputFile.close();
}
