#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER)
#include <afx.h>
#include <direct.h>
#define getcwd _getcwd
#else
#include <unistd.h>
#endif

#include "modbuilder.h"


using namespace std;


int getCurrentDirName(char* currentDir)
{
	//Fill array with current dir
	try
	{
		getcwd(currentDir, FILENAME_MAX);
		return 0;
	}
	catch (int e)
	{
		return -1;
	}
	
}

string printWelcomeMessage()
{
	string sWlcmsg, sDowhat, sChoise;

	sWlcmsg = "Welcome to ModMaker!";
	sDowhat = "What would you like to do?";

	cout << sWlcmsg << endl;
	cout << sDowhat << endl;
	cin >> sChoise;
	return sChoise;
}

void printModNameQuestion(char* cModNameOut)
{
	string sModnamequestion, sMakingmod;
	sModnamequestion = "What should it be called? (max 30 Characters, no space)";
	sMakingmod = "I'm making a mod for you...";

	cout << sModnamequestion << endl;
	cin >> cModNameOut;
	cout << sMakingmod << endl;
}

void printFinishedMessage()
{
	cout << "Your mod was succesfully created!" << endl;
}

void printErrorMessage()
{
	cout << "Something went wrong while creating your mod" << endl;
}

int main()
{
	//Input selections
	string sChoice;
	char cModName[30];
	//Current directory
	char cCurrentPath[FILENAME_MAX];

	//Get current dir
	if (getCurrentDirName(cCurrentPath) != 0)
	{
		//Something is dreadfully wrong i fear.
		exit(-1);
	}
	//Print msg and ask/returns what the user wants to do
	sChoice = printWelcomeMessage();
	
	if (sChoice == "makemod")
	{
		//If user wants to create a mod, ask the name of the mod
		printModNameQuestion(cModName);

		//Create modbuilder class and tell it to build the mod
		modbuilder mbuilder(cCurrentPath, cModName);
		if (mbuilder.buildMod() == 0)
		{
			printFinishedMessage();
		}
		else
		{
			printErrorMessage();
		}
	}
}
