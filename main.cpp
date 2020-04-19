#include <crtdbg.h>
#include "UI.h"
#include "test.h"

int main()
{
	run_all_tests();
	Repository repo{};
	Repository list{};
	Watchman watch{ repo, list };
	Service service{ repo };
	UI ui{ service , watch};

	service.add_turret_repo("east", "huge", 400, 4000, "tower");
	service.add_turret_repo("west", "medium", 250, 3400, "tower");
	service.add_turret_repo("north", "small", 120, 1000, "mountains");
	service.add_turret_repo("south", "medium", 230, 2700, "tower");

	ui.ui_console();

	return 0;
}