#include <string>
#include <stdio.h>
#include <afx.h>

using namespace std;

class modbuilder
{
	char name[30];
	char path[FILENAME_MAX];
	char fullname[FILENAME_MAX];
	//level 1 folders
	char* maps = "\\maps";
	char* materials = "\\materials";
	char* resource = "\\resource";
	char* scripts = "\\scripts";
	//level 2 folders
	char* overviews = "\\overviews";
	char* flash3 = "\\flash3";
	char* npc = "\\npc";
	char* shops = "\\shops";
	char* vscripts = "\\vscripts";



	public:
		modbuilder(char* modPath, char* modName);
		int buildMod();
		int makeFirstLevelFolders();
		int makeSecondLevelFolders();
		void makeDirFirst(char* inDir);
		void makeDirSecond(char* inDir, char* inDirSec);
		void createFileFirst(char* inDir, char*fileName);
		void createFileSecond(char* inDir, char* inDirSec, char*fileName);
		void getPathFirst(char* inBuff, char* indDir);
		void getBasePath(char* inBuff);
		int copyFiles();

};