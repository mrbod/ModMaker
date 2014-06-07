#include "modbuilder.h"
#include <direct.h>
#include <iostream>
#include <fstream>
#define MakeDir _mkdir

modbuilder::modbuilder(char* modPath, char* modName) {
	strcpy(path, modPath);
	strcat(path, "\\");
	strcpy(name, modName);
}


void modbuilder::makeDirFirst(char* inDir)
{
	char result[FILENAME_MAX];

	strcpy(result, path);
	strcat(result, name);
	strcat(result, inDir);

	MakeDir(result);
}
void modbuilder::makeDirSecond(char* inDir, char* inDirSec)
{
	char result[FILENAME_MAX];
	strcpy(result, path);
	strcat(result, name);
	strcat(result, inDir);
	strcat(result, inDirSec);

	MakeDir(result);
}

void modbuilder::getPathFirst(char* inBuff, char* indDir)
{
	memset(inBuff, 0, FILENAME_MAX);
	strcpy(inBuff, path);
	strcat(inBuff, name);
	strcat(inBuff, indDir);
}

void modbuilder::getBasePath(char* inBuff)
{
	memset(inBuff, 0, FILENAME_MAX);
	strcpy(inBuff, path);
	strcat(inBuff, name);
}

void modbuilder::createAddonInfo()
{
	char file_path[FILENAME_MAX];

	getBasePath(file_path);
	strcat(file_path, "\\addoninfo.txt");
	ofstream  dst(file_path, std::ios::binary);
	dst << "//This file is mostly used for giving tooltip texts to your custom items, spells, etc." << endl;
	dst << "lang" << endl;
	dst << "{" << endl;
	dst << "\t\"Language\"\t\t\"English\"" << endl;
	dst << "\t\"Tokens\"" << endl;
	dst << "\t{" << endl;
	dst << "" << endl;
	dst << "\t}" << endl;
	dst << "}" << endl;
	dst.close();
}

void modbuilder::createAddonEnglish()
{
	char file_path[FILENAME_MAX];

	getPathFirst(file_path, resource);
	strcat(file_path, "\\addon_english.txt");
	ofstream  dst(file_path, std::ios::binary);
	
	dst << "// The addoninfo.txt file is a metadata file that is required by all Source Engine Add-ons." << endl;
	dst << "\"AddonInfo\"" << endl;
	dst << "{" << endl;
	dst << "\taddonSteamAppID\t\t816" << endl;
	dst << "\taddontitle\t\t\"My Addon\"" << endl;
	dst << "\taddonversion\t\t0.001" << endl;
	dst << "\taddontagline\t\t\"Tagline for My Addon\"" << endl;
	dst << "\taddonauthor\t\t\"My Nick\"" << endl;
	dst << "\taddonSteamGroupName\t\t\"Steamgroup name for My Addon\"" << endl;
	dst << "\taddonauthorSteamID\t\t\"\"" << endl;
	dst << "\taddonContent_Campaign\t\t0" << endl;
	dst << "\taddonURL0\t\t\"\"" << endl;
	dst << "\taddonSteamGroupName\t\t\"Description of my addon, its a lot of fun and you will not be able to stop playing it.\"" << endl;
	dst << "}" << endl;
	dst.close();
}

int modbuilder::createFiles()
{
	try
	{
		
		createAddonInfo();
		createAddonEnglish();

		return 0;
	}
	catch (int e)
	{
		return -1;
	}
}


int modbuilder::makeFirstLevelFolders()
{
	try
	{
		makeDirFirst(maps);
		makeDirFirst(materials);
		makeDirFirst(resource);
		makeDirFirst(scripts);
		return 0;
	}
	catch (int e)
	{
		return -1;
	}
	
}
int modbuilder::makeSecondLevelFolders()
{
	try
	{
		makeDirSecond(materials, overviews);
		makeDirSecond(resource, overviews);
		makeDirSecond(resource, flash3);
		makeDirSecond(scripts, npc);
		makeDirSecond(scripts, shops);
		makeDirSecond(scripts, vscripts);
		return 0;
	}
	catch (int e)
	{
		return -1;
	}
}

int modbuilder::buildMod()
{
	//Make all directories and files needed for a bare repo
	//Create mod folder
	char modDir[FILENAME_MAX];
	strcpy(modDir, path);
	strcat(modDir, name);
	MakeDir(modDir);

	if (makeFirstLevelFolders() != 0)
	{
		return -1;
	}
	if (makeSecondLevelFolders() != 0)
	{
		return -1;
	}
	if (createFiles() != 0)
	{
		return -1;
	}

	return 0;
}