#include "modbuilder.h"
#include <direct.h>
#define MakeDir _mkdir

modbuilder::modbuilder(CStringA modPath, CStringA modName) {
	path = modPath + "\\";
	name = modName;
}

int modbuilder::buildMod()
{
	//Make all directories and files needed for a bare repo
	MakeDir(path + name);
	return 0;
}