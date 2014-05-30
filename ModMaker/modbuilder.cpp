#include "modbuilder.h"
#include <direct.h>
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


int modbuilder::makeFirstLevelFolders()
{
	try
	{
		modbuilder::makeDirFirst(maps);
		modbuilder::makeDirFirst(materials);
		modbuilder::makeDirFirst(resource);
		modbuilder::makeDirFirst(scripts);
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
		modbuilder::makeDirSecond(materials, overviews);
		modbuilder::makeDirSecond(resource, overviews);
		modbuilder::makeDirSecond(resource, flash3);
		modbuilder::makeDirSecond(scripts, npc);
		modbuilder::makeDirSecond(scripts, shops);
		modbuilder::makeDirSecond(scripts, vscripts);
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

	return 0;
}