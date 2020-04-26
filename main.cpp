#include <crtdbg.h>
#include "UI.h"
#include "test.h"

int main()
{

	//run_all_tests();
	Repository repo{};
	std::vector<Turret> list{};
	Watchman watch{ repo, list };
	Service service{ repo };
	UI ui{ service , watch};

	ui.ui_console();

	return 0;
}