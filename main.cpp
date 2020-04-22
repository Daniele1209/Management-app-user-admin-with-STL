#include <crtdbg.h>
#include "UI.h"
#include "test.h"

int main()
{
	//Tests::testAll();
	//run_all_tests();
	Repository repo{};
	Repository list{};
	Watchman watch{ repo, list };
	Service service{ repo };
	UI ui{ service , watch};

	ui.ui_console();

	return 0;
}