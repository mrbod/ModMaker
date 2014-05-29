#include <iostream>
#include <string>
#include <direct.h>
#include <stdio.h>
#include <afx.h>
#include "modbuilder.h"


using namespace std;


DWORD getCurrentDirName(TCHAR* currentDir)
{
	//Fill array with current dir
	return GetCurrentDirectory(FILENAME_MAX, currentDir);
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

CStringA ConvertCurrDir(TCHAR* cPath)
{
	CString csCurrentDir = CString(cPath);
	CStringA result = csCurrentDir;
	return result;
}

int main()
{
	//Input selections
	string sChoice;
	char cModName[30];
	//Current directory
	TCHAR cCurrentPath[FILENAME_MAX];
	CStringA casCurrentDir;

	if (getCurrentDirName(cCurrentPath) == 0)
	{
		//Something is dreadfully wrong i fear.
		exit(0);
	}
	
	sChoice = printWelcomeMessage();
	
	if (sChoice == "makemod")
	{
		printModNameQuestion(cModName);
		
		casCurrentDir = ConvertCurrDir(cCurrentPath);

		//Modbuilder instance
		modbuilder mbuilder = modbuilder::modbuilder(casCurrentDir, cModName);
		mbuilder.buildMod();
	}
}
