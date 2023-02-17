#pragma once
//includes
#include "Ninja.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
// defines
#define AL_ERORR "ALLOCATION_ERROR"
#define INPUT_ERORR "INVALID_INPUT"
#define FAIL "FAILURE"
#define SUCCESS "SUCCESS"
#define NO_TRAINER -1

//using std library
using std::vector;
using std::pair;
using std::string;
using std::map;
using std::find;



class NinjasSchool
{
public:
	NinjasSchool();
	~NinjasSchool();
	string AddTrainer(void *DS, int trainerID);
	string AddNinja(void *DS, int ninjaID, int trainerID, int level);
	string dismissNinja(void *DS, int ninjaID);
	string LevelUp(void *DS, int ninjaID, int levelIncrease);
	string GetTopNinjas(void *DS, int trainerID, int * ninjaID); 
	string UpgradeNinja(void *DS, int ninjaID, int upgradedID);
	string UpdateLevels(void *DS, int prayerCode, int prayerFactor);
	void Quit(void **DS); //RECHECK
	//getters and setter 
	vector<int> getsTrainers();
	vector<Ninja> getsNinjas();

private:
	vector<int> trainers;
	vector<Ninja> ninjas;
};