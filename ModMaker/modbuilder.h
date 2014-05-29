#include <string>
#include <stdio.h>
#include <afx.h>

using namespace std;

class modbuilder
{
	CStringA name;
	CStringA path;
	CStringA maps = "\\maps";
	CStringA materials = "\\materials";
	CStringA resource = "\\resource";
	CStringA scripts = "\\scripts";
	public:
		modbuilder(CStringA modPath, CStringA modName);
		int buildMod();
};