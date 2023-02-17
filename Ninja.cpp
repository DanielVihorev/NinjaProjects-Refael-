#include "Ninja.h"

Ninja::Ninja(int ninjaID, int trainerID, int level) : ninjaIdNumber(ninjaID),ninjaTrainerID(trainerID),ninjaLevel(level)
{
}

Ninja::~Ninja()
{

}

int Ninja::getNinjaTrainer()
{
	return ninjaTrainerID;
}

int Ninja::getNinjaID()
{
	return ninjaIdNumber;
}

int Ninja::getNinjaLevel()
{
	return ninjaLevel;
}

int Ninja::getUpgradedID()
{
	return upgradedID;
}

void Ninja::setsNewLevel(int newLevel)
{
	ninjaLevel = newLevel;
}

void Ninja::setsUpgradedID(int newUpID)
{
	upgradedID = newUpID;
}
