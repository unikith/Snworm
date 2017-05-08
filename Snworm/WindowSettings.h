#pragma once
#include "Settings.h"

class WindowSettings :
	public Settings
{
public:
	WindowSettings(const char * SaveFile);
	~WindowSettings();
	int getHeight() const { return mHeight; }
	int getWidth() const { return mWidth; }
	int getFrameRate() const { return mFrameRate; }
	void load();
	void save();

private:
	int mHeight;
	int mWidth;
	int mFrameRate;
};

