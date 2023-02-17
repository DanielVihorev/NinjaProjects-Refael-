#include "library1.h"
#include "NinjasSchool.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;

void main()
{
	Init();
	system("pause");
}

void Quit(void **DS)
{
	return ((NinjasSchool*)DS)->Quit(&*DS);
}

string UpdateLevels(void *DS, int prayerCode, int prayerFactor)
{
	return ((NinjasSchool*)DS)->UpdateLevels(DS,prayerCode,prayerFactor);
}

string UpgradeNinja(void *DS, int ninjaID, int upgradedID)
{
	return ((NinjasSchool*)DS)->UpgradeNinja(DS,ninjaID,upgradedID);
}

string GetTopNinjas(void * DS, int trainerID, int * ninjaID)
{
	return ((NinjasSchool*)DS)->GetTopNinjas(DS, trainerID, ninjaID);
}

string LevelUp(void *DS, int ninjaID, int levelIncrease)
{
	return ((NinjasSchool*)DS)->LevelUp(DS,ninjaID,levelIncrease);
}

string dismissNinja(void * DS, int ninjaID)
{
	return ((NinjasSchool*)DS)->dismissNinja(DS,ninjaID);
}

string AddNinja(void * DS, int ninjaID, int trainerID, int level)
{
	return ((NinjasSchool*)DS)->AddNinja(DS,ninjaID,trainerID,level);
}

string AddTrainer(void *DS, int trainerID)
{
	return ((NinjasSchool*)DS)->AddTrainer(DS,trainerID);
}

void* Init() {
	NinjasSchool * DS = new NinjasSchool();
	return (void*)DS;
}


