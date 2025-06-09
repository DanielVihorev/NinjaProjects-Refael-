🥷 NinjaProjects-Refael

A C++ project simulating a dojo-style ninja training center, where trainers and ninjas are managed, matched, and scored. Built for learning and practicing object-oriented programming, error handling, and standard template libraries (STL).

📦 Project Overview

This system allows managing a dynamic set of trainers and ninja trainees, with support for:
	•	Creating and destroying the dojo system
	•	Adding trainers and ninjas
	•	Matching and training logic
	•	Querying top-performing ninjas
	•	Full error handling with descriptive messages

⸻

🧠 Core Concepts

The project simulates a training environment where trainers manage groups of ninjas, and the system can:
	•	Allocate resources dynamically
	•	Throw appropriate error messages on invalid input
	•	Retrieve and manipulate collections of data using STL containers

⸻

🔧 Libraries and Header Usage

#pragma once

	•	Ensures that header files like Ninja.h are only included once per translation unit, preventing duplicate symbol errors.

C++ Standard Libraries

#include <iostream>

	•	Handles input/output operations such as debugging messages or user interaction.

#include <vector>

	•	Implements dynamic arrays (vectors), used to manage lists of ninjas and trainers efficiently.

#include <map>

	•	Implements associative arrays or dictionaries (key-value pairs). This is essential for mapping trainers to ninja groups.

#include <string>

	•	Provides the std::string class for handling text and character arrays in a memory-safe way.

Custom Includes

#include "Ninja.h"

	•	This is the main object representing a Ninja. It contains attributes like skill, ID, and methods related to training and scoring.

⸻

📑 Macros Defined

#define AL_ERORR "ALLOCATION_ERROR"
#define INPUT_ERORR "INVALID_INPUT"
#define FAIL "FAILURE"
#define SUCCESS "SUCCESS"
#define NO_TRAINER -1

These are used for error messaging and controlling flow throughout the program, making the code more readable and maintainable.

⸻

🔤 Namespace Usage

using std::vector;
using std::pair;
using std::string;
using std::map;
using std::find;

Instead of polluting the global namespace with using namespace std;, this project takes a more refined approach by including only the needed components from the STL, improving clarity and avoiding name collisions.

⸻

🚀 How to Compile and Run
	1.	Clone the repository:

git clone https://github.com/DanielVihorev/NinjaProjects-Refael-.git
cd NinjaProjects-Refael-


	2.	Use g++ to compile:

g++ -std=c++11 -o dojo main.cpp Ninja.cpp


	3.	Run the executable:

./dojo



⸻

✅ Example Features
	•	Add a trainer:

AddTrainer(int trainerID);


	•	Add a ninja to a trainer:

AddNinja(int ninjaID, int power, int trainerID);


	•	Get strongest ninja:

GetStrongestNinja();


	•	Match ninjas between trainers:

TrainerFight(int trainerID1, int trainerID2, int numOfNinjas);



⸻

🧪 Testing and Validation

All error conditions are handled via return codes and macro-defined messages. You can extend the test cases by simulating dojo scenarios and asserting results against expected outputs.

⸻

🤝 Contributing

If you’d like to contribute improvements or extensions (like GUI support, leaderboard export, or additional gameplay logic), feel free to open a pull request or issue.

⸻

📜 License

This project is open source and available under the MIT License.

⸻

Let me know if you’d like a diagram or test file structure added next!
