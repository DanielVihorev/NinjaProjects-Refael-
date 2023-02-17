class Ninja
-------------
Ninja(ninjaID,trainerID,level)
~Ninja()
getNinjaTrainer() : ninjaTrainerID
getNinjaID() : ninjaIdNumber
getNinjaLevel() : ninjaLevel
getUpgradedID() : upgradedID
setsNewLevel(newLevel):
setsUpgradedID(newUpID)
ninjaTrainerID : int
ninjaIdNumber : int
ninjaLevel : int
upgradedID : int

NinjasSchool
+ NinjasSchool()
+ ~NinjasSchool()
+ AddTrainer(*DS,trainerID) : retStatus
+ AddNinja(*DS,ninjaID,trainerID,level) : retStatus
+ dismissNinja(*DS,ninjaID)
+ LevelUp(*DS,ninjaID,*levelIncrease) : retStatus
+ GetTopNinjas(*DS,trainerID,ninjaID) : retStatus
+ UpgradeNinja(*DS,ninjaID,upgradedID) : retStatus
+ UpdateLevels(*DS,prayerCode,prayerFactor) : retStatus
+ Quit(**DS)
+ getsTrainers() : trainers
+ getsNinjas() : ninjas
----------------------------------------------------------------------------------------------
- retStatus : string
- trainers : vector<int>
- ninjas : vector<Ninja>