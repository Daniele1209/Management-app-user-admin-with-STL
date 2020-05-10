#include <crtdbg.h>
#include "UI.h"
#include "test.h"
#include "watchman.h"
#include <iostream>
using namespace std;

int main()
{
	int option;
	//run_all_tests();
	
	while (true) {
		cout << "Choose the file format for watchman: \n";
		cout << "1 - csv file\n";
		cout << "2 - html file\n";
		cout << ">>> ";
		cin >> option;
		if(option == 1 || option == 2){
			break;
		}
		else {
			cout << "\nNot a valid option !\n";
		}
	}
	if (option == 1) {
		watchman_CSV repo2{"Mylist.csv"};
		Repository repo{};
		Watchman watch{ repo, repo2 };
		Service service{ repo };
		UI ui{ service , watch };

		ui.ui_console();

	}
	else {
		watchman_HTML repo2{"mylist.html"};
		Repository repo{};
		Watchman watch{ repo, repo2 };
		Service service{ repo };
		UI ui{ service , watch };

		ui.ui_console();
	}

	return 0;
}