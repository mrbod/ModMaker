#include "modbuilder.h"
#include <direct.h>
#define MakeDir _mkdir

modbuilder::modbuilder(CStringA modPath, CStringA modName) {
	path = modPath + "\\";
	name = modName;
}

int modbuilder::makeFirstLevelFolders()
{
	try
	{
		MakeDir(path + name + maps);
		MakeDir(path + name + materials);
		MakeDir(path + name + resource);
		MakeDir(path + name + scripts);
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
		MakeDir(path + name + materials + overviews);
		MakeDir(path + name + resource + overviews);
		MakeDir(path + name + resource + flash3);
		MakeDir(path + name + scripts + npc);
		MakeDir(path + name + scripts + shops);
		MakeDir(path + name + scripts + vscripts);
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
	MakeDir(path + name);

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