#pragma once
#include <iostream>

class Ninja
{
public:
	Ninja(int ninjaID, int trainerID, int level);
	~Ninja();
	//setters and getters
	int getNinjaTrainer();
	int getNinjaID();
	int getNinjaLevel();
	int getUpgradedID();
	void setsNewLevel(int newLevel);
	void setsUpgradedID(int newUpID);

private:
	int ninjaTrainerID;
	int ninjaIdNumber;
	int ninjaLevel;
	int upgradedID;
};