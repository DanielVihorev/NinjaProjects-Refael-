#include "NinjasSchool.h"
/*
The function is a constractor to the function
INPUT: NULL
OUTPUT: NULL
*/
NinjasSchool::NinjasSchool()
{
}
/*
The function is a destractor to the function
INPUT: NULL
OUTPUT: NULL
*/
NinjasSchool::~NinjasSchool()
{
}
/*
The function adds a trainer to the vector of trainers
INPUT: *DS - the pointer to the NinjasSchool class
OUTPUT: retStatus - the status of the function if succesed or failed and why
*/
string NinjasSchool::AddTrainer(void * DS, int trainerID)
{
	string retStatus;
	if (DS == NULL || trainerID <= 0)
	{
		retStatus = INPUT_ERORR;
		return retStatus;
	}

	try
	{
		if (find(trainers.begin(), trainers.end(), trainerID) != trainers.end())
		{
			retStatus = FAIL;
		}
		else
		{
			trainers.push_back(trainerID);
			retStatus = SUCCESS;
		}
	}
	catch (...)
	{
		retStatus = AL_ERORR;
	}

	return retStatus;
}
/*
The function adds a ninja to the vector of ninjas
INPUT: *DS - the pointer to the NinjasSchool class
		ninjaID - the id of the ninja
		trainerID - the id of the trainer to add the ninja
		level - the level of the ninja to add
OUTPUT: retStatus - the status of the function if succesed or failed and why
*/
string NinjasSchool::AddNinja(void * DS, int ninjaID, int trainerID, int level)
{
	string retStatus;
	if (DS == NULL || ninjaID <= 0 || trainerID <= 0 || level <= 0)
	{
		retStatus = INPUT_ERORR;
		return retStatus;
	}
	try
	{
		for (auto n = ninjas.begin(); n != ninjas.end(); n++)
		{
			if (n->getNinjaID() == ninjaID)
			{
				retStatus = FAIL;
				return retStatus;
			}
		}
		if (find(trainers.begin(), trainers.end(), trainerID) == trainers.end())
		{
			for (auto n = ninjas.begin(); n != ninjas.end(); n++)
			{
				if(n->getNinjaID() == ninjaID)
				{
					retStatus = FAIL;
					break;
				}
			}
			retStatus = FAIL;
		}
		else
		{
			Ninja ninja(ninjaID, trainerID, level);
			ninjas.push_back(ninja);
			retStatus = SUCCESS;
		}
		
	}
	catch (...)
	{
		retStatus = AL_ERORR;
	}
	return retStatus;
}

/*
The function removes the ninja from the vector of ninjas 
INPUT: *DS - the pointer to the NinjasSchool class
		ninjaID - the id of the ninja to remove
OUTPUT: retStatus - the status of the function if succesed or failed and why
*/
string NinjasSchool::dismissNinja(void * DS, int ninjaID)
{
	string retStatus;
	if (DS == NULL || ninjaID <= 0)
	{
		retStatus = INPUT_ERORR;
		return retStatus;
	}
	try
	{
		for (auto n = ninjas.begin(); n != ninjas.end(); n++)
		{
			if (n->getNinjaID() == ninjaID)
			{
				ninjas.erase(n);
				retStatus = SUCCESS;
				break;
			}
			else
			{
				retStatus = FAIL;
			}
		}
	}
	catch (...)
	{
		retStatus = AL_ERORR;
	}
	return retStatus;
}
/*
The function levels up the ninja's level
INPUT: *DS - the pointer to the NinjasSchool class
		ninjaID - the id of the ninja to increase
		levelIncrease - the amount of levels to increase
OUTPUT: retStatus - the status of the function if succesed or failed and why
*/
string NinjasSchool::LevelUp(void * DS, int ninjaID, int levelIncrease)
{
	string retStatus;
	int newLevel;
	if (DS == NULL || ninjaID <= 0 || levelIncrease == 0)
	{
		retStatus = INPUT_ERORR;
		return retStatus;
	}
	try
	{
		for (auto n = ninjas.begin(); n != ninjas.end(); n++)
		{
			if (n->getNinjaID() == ninjaID)
			{
				newLevel = n->getNinjaLevel() + levelIncrease;
				n->setsNewLevel(newLevel);
				retStatus = SUCCESS;
			}
			else
			{
				retStatus = FAIL;
			}
		}
	}
	catch (...)
	{
		retStatus = AL_ERORR;
	}
	return retStatus;
}
/*
The function gets all of the top ninjas by trainers id 
INPUT: *DS - the pointer to the NinjasSchool class
		trainerID - the id of the ninja's trainer
		* ninjaID - the array of the top ninjas
OUTPUT: retStatus - the status of the function if succesed or failed and why
*/
string NinjasSchool::GetTopNinjas(void * DS, int trainerID, int * ninjaID)
{
	string retStatus;
	int ninjaCurrLev; 
	int ninjaSavedLev;

	if (DS == NULL || ninjaID == 0 || trainerID == 0 )
	{
		retStatus = INPUT_ERORR;
		return retStatus;
	}
	try
	{
		if (trainerID > 0)
		{
			if (ninjas.begin() == ninjas.end())
			{
				*ninjaID = NO_TRAINER;
				retStatus = FAIL;
			}
			for (auto n = ninjas.begin(); n != ninjas.end(); n++)
			{
				if (n->getNinjaTrainer() != trainerID && n == ninjas.end() - 1)
				{
					*ninjaID = NO_TRAINER;
				}
				else if (n->getNinjaTrainer() == trainerID)
				{
					ninjaCurrLev = n->getNinjaLevel();
					if (*ninjaID == NULL || ninjaSavedLev < ninjaCurrLev)
					{
						ninjaSavedLev = n->getNinjaLevel();
						*ninjaID = n->getNinjaID();
					}
					else if (ninjaCurrLev == n->getNinjaLevel())
					{
						if (*ninjaID < n->getNinjaID())
						{
							*ninjaID = n->getNinjaID();
						}
					}
				}
				retStatus = SUCCESS;
			}
		}
		else
		{
			retStatus = FAIL;
		}
	}
	catch (...)
	{
		retStatus = AL_ERORR;
	}
	return retStatus;
}
/*
The function upgrades the ninja's ID and gives him a new upgraded id 
INPUT: *DS - the pointer to the NinjasSchool class
		ninjaID - the id of the ninja
		upgradedID - the upgraded id of the ninja 
OUTPUT: retStatus - the status of the function if succesed or failed and why
*/
string NinjasSchool::UpgradeNinja(void * DS, int ninjaID, int upgradedID)
{
	string retStatus;
	if (DS == NULL || ninjaID <= 0 || upgradedID <= 0)
	{
		retStatus = INPUT_ERORR;
		return retStatus;
	}
	try
	{
		for (auto n = ninjas.begin(); n != ninjas.end(); n++)
		{
			if (n->getNinjaID() == ninjaID)
			{
				n->setsUpgradedID(upgradedID);
			}
			else
			{
				retStatus = FAIL;
			}
		}
		retStatus = SUCCESS;
	}
	catch (...)
	{
		retStatus = AL_ERORR;
	}
	return retStatus;
}
/*
The function updates the levels of the ninjas 
INPUT : *DS - the pointer to the NinjasSchool class
		prayerCode - the checker to the ninja ID 
		prayerFactor - by how much the level is increased 
OUTPUT : retStatus - the status of the function if succesed or failed and why
*/
string NinjasSchool::UpdateLevels(void * DS, int prayerCode, int prayerFactor)
{
	string retStatus;
	int prayerLevel;
	if (DS == NULL || prayerCode < 1 || prayerFactor < 1)
	{
		retStatus = INPUT_ERORR;
		return retStatus;
	}
	for (auto n = ninjas.begin(); n != ninjas.end(); n++)
	{
		if (n->getNinjaID() % prayerCode == 0)
		{
			prayerLevel = n->getNinjaLevel() * prayerFactor;
			n->setsNewLevel(prayerLevel);
		}
		else
		{
			retStatus = AL_ERORR;
		}
	}
	retStatus = SUCCESS;
	return retStatus;
}
/*
The function delete the NinjasSchool class
INPUT: *DS - the pointer to the NinjasSchool class
OUTPUT: NULL
*/
void NinjasSchool::Quit(void ** DS)
{
	delete *DS;
}
/*
The function is a getter to trainer 
INPUT: NULL 
OUTPUT: trainers - the vector of trainers 
*/
vector<int> NinjasSchool::getsTrainers()
{
	return trainers;
}
/*
The function is a getter to ninjas
INPUT: NULL
OUTPUT: trainers - the vector of ninjas
*/
vector<Ninja> NinjasSchool::getsNinjas()
{
	return ninjas;
}
