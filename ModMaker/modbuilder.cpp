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

int modbuilder::copyFiles()
{
	try
	{
		char file_path[FILENAME_MAX];

		getBasePath(file_path);
		strcat(file_path, "\\addoninfo.txt");
		ifstream  src("data\\addoninfo.txt", std::ios::binary);
		ofstream  dst(file_path, std::ios::binary);
		dst << src.rdbuf();
		src.close();
		dst.close();

		getPathFirst(file_path, resource);
		strcat(file_path, "\\addon_english.txt");
		src = ifstream("data\\addon_english.txt", std::ios::binary);
		dst = ofstream(file_path, std::ios::binary);
		dst << src.rdbuf();
		src.close();
		dst.close();

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
	if (copyFiles() != 0)
	{
		return -1;
	}

	return 0;
}