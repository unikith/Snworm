#include "GameSettings.h"



GameSettings::GameSettings(const char * LoadFile) : Settings(LoadFile)
{
	load();
}


GameSettings::~GameSettings()
{
}

void GameSettings::load()
{
	mInputFile.open(mFileName);
	std::string garbage;
	int garbageInt = 0;

	mInputFile >> garbage >> mNodeRadius;
	mInputFile >> garbage >> mSpeed;
	mInputFile >> garbage >> mTurnSpeed;
	mInputFile >> garbage >> mConsumableRadius;
	mInputFile >> garbage >> garbageInt;
	this->mConsumableColor.r = garbageInt;
	mInputFile >> garbageInt;
	mConsumableColor.g = garbageInt;
	mInputFile >> garbageInt;
	mConsumableColor.b = garbageInt;

	mInputFile >> garbage >> garbageInt;
	this->mP1SnakeColor.r = garbageInt;
	mInputFile >> garbageInt;
	mP1SnakeColor.g = garbageInt;
	mInputFile >> garbageInt;
	mP1SnakeColor.b = garbageInt;

	mInputFile >> garbage >> garbageInt;
	this->mP2SnakeColor.r = garbageInt;
	mInputFile >> garbageInt;
	mP2SnakeColor.g = garbageInt;
	mInputFile >> garbageInt;
	mP2SnakeColor.b = garbageInt;

	mInputFile.close();
}

void GameSettings::save()
{
	mInputFile.open(mFileName);
	mInputFile << "NodeRadius\t" << mNodeRadius << "\n";
	mInputFile << "Speed\t" << mSpeed << "\n";
	mInputFile << "TurnSpeed\t" << mTurnSpeed << "\n";
	mInputFile << "ConsumableRad\t" << mConsumableRadius << "\n";
	mInputFile << "ConsumableClr\t" << mConsumableColor.r << " " << mConsumableColor.g
		<< " " << mConsumableColor.b << "\n";
	mInputFile << "P1Color\t" << mP1SnakeColor.r << " " << mP1SnakeColor.g << " " 
		<< mP1SnakeColor.g << "\n";
	mInputFile << "P2Color\t" << mP2SnakeColor.r << " " << mP2SnakeColor.g << " "
		<< mP2SnakeColor.g << "\n";
	mInputFile.close();
}
