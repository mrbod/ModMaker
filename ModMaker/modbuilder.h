#include <string>
#include <stdio.h>
#include <afx.h>

using namespace std;

class modbuilder
{
	CStringA name;
	CStringA path;
	public:
		modbuilder(CStringA modPath, CStringA modName);
		int buildMod();
};