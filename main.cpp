#include <crtdbg.h>
#include "UI.h"
#include "test.h"
using namespace std;

int main()
{

	//run_all_tests();
	Repository repo{};
	watchman_repo list{};
	Watchman watch{ repo, list };
	Service service{ repo };
	UI ui{ service , watch};

	ui.ui_console();

	return 0;
}