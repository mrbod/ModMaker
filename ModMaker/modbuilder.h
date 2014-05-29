#include <string>
#include <stdio.h>
#include <afx.h>

using namespace std;

class modbuilder
{
	CStringA name;
	CStringA path;
	//level 1 folders
	CStringA maps = "\\maps";
	CStringA materials = "\\materials";
	CStringA resource = "\\resource";
	CStringA scripts = "\\scripts";
	//level 2 folders
	CStringA overviews = "\\overviews";
	CStringA flash3 = "\\flash3";
	CStringA npc = "\\npc";
	CStringA shops = "\\shops";
	CStringA vscripts = "\\vscripts";



	public:
		modbuilder(CStringA modPath, CStringA modName);
		int buildMod();
		int makeFirstLevelFolders();
		int makeSecondLevelFolders();
};