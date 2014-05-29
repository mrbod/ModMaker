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
	MakeDir(path + name + maps);
	MakeDir(path + name + materials);
	MakeDir(path + name + resource);
	MakeDir(path + name + scripts);
	return 0;
}