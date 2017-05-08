#pragma once
#include <fstream>
#include <string>

using std::fstream;

class Settings
{
public:
	Settings(const char * SaveFile);
	virtual ~Settings();
	//virtual bool load() = 0;
	virtual void load() = 0;
	virtual void save() = 0;
protected:
	fstream mInputFile;
	std::string mFileName;
};

