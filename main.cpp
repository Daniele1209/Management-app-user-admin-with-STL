#include <crtdbg.h>
#include "UI.h"
#include "test.h"
using namespace std;

void set_default_location(string list_location, string mylist_location) {
	cout<<""
}

int main()
{

	//run_all_tests();
	Repository repo{};
	watchman_repo {};
	Watchman watch{ repo, list };
	Service service{ repo };
	UI ui{ service , watch};

	ui.ui_console();

	return 0;
}