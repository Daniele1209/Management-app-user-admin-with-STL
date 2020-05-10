#include "UI.h"
#include <string>
#include <iostream>
#include <string>
#include <sstream>
#include "custom_exceptions.h"
using namespace std;

void UI::menu() {
	cout << "ADMIN COMMANDS :\n\n";
	cout << "add - to add a turret\n";
	cout << "delete - to delete a turret\n";
	cout << "update - to change the turret\n";
	cout << "list - to print all the turrets\n";
	cout << "exit - to exit the app\n";
	cout << "mode - to change the mode (admin or user)\n";
	cout << "fileLocation + path - to set the path where the values are going to be stored\n\n";
	cout << "USER COMMANDS :\n\n";
	cout << "next - to get the next item in the list\n";
	cout << "mylist - to see the list that you saved\n";
	cout << "list + size + parts - to get the items sorted by parts\n";
	cout << "save + location - to save the item in a diffrent list\n\n\n";
}

//UI for storing and files
void UI::path(string str) {
	str.erase(0, 13);
	service.new_path(str);
}

//path for mylist
void UI::path_mylist(string str) {
	string aux_str = str;
	str.erase(0, 15);
	service.new_path(str);
	vector<string> tokens = split_string(str, ".");
	string ending = tokens[tokens.size() - 1];
	if (ending == "html") {
		watchman_repo = new watchman_HTML(aux_str);
	}
	else if (ending == "csv") {
		watchman_repo = new watchman_CSV(aux_str);
	}
	else {
		throw service_exception("Not a valid format, try again !\n");
	}
}

//UI for WATCHMAN user
void UI::next_turret() {
	try {
		Turret t = watcher.next();
		cout << t.message()<<"\n";
	}
	catch (exception&) {
		cout << "List is empty !\n";
	}
}

void UI::list_mylist() {
	vector<Turret> t = watcher.get_turret_list();
	for (auto it = t.begin(); it != t.end(); it++)
		cout << (*it).message() << "\n";
}

void UI::save_mylist(std::string command) {
	command.erase(0, 5);
	cout << command << "\n";
	watcher.add_turret_mylist(command);
	cout << "Turret added !\n";

}

void UI::sort_list(std::string command) {
	vector<string> strr;
	command.erase(0, 4);
	std::string str_to_components[2];
	int j = 0;
	for (unsigned int i = 0; i < command.length(); ++i) {
		if (command[i] == ',')
			j++;
		else if (command[i] == ' ' and i == 0)
			continue;
		else if (command[i] == ' ' and command[i - 1] == ' ')
			continue;
		else if (command[i] == ' ' and command[i - 1] == ',')
			continue;
		else str_to_components[j] += command[i];
	}
	vector<Turret> list = watcher.turret_list(str_to_components[0], stoi(str_to_components[1]));

	for (auto it = list.begin(); it != list.end(); it++)
		cout << (*it).message();
}

void UI::list_turret(Turret t) {
	std::cout << "Current:\n";
	std::cout << t.message() << "\n";
}

//UI for ADMIN user
void UI::add_turret(std::string command) {
	command.erase(0, 3);
	int ok = 1;
	string location, vision, size;
	int parts, aura_level;
	std::string str_to_components[5];
	int j = 0;
	for (unsigned int i = 0; i < command.length(); ++i) {
		if (command[i] == ',')
			j++;
		else if (command[i] == ' ' and i == 0)
			continue;
		else if (command[i] == ' ' and command[i - 1] == ' ')
			continue;
		else if (command[i] == ' ' and command[i - 1] == ',')
			continue;
		else str_to_components[j] += command[i];
	}

	if (j != 4)
		ok = 0;

	if (ok) {
		try
		{
			aura_level = std::stoi(str_to_components[2]);
			parts = std::stoi(str_to_components[3]);
		}
		catch (std::logic_error&)
		{
			ok = 0;
		}
		location = str_to_components[0];
		size = str_to_components[1];
		vision = str_to_components[4];
	}
	if (ok) {
		this->service.add_turret_repo(location, size, aura_level, parts, vision);
	}
	else
		cout << "Invalid turret !\n";
}
void UI::list_turrets() {
	vector<Turret> turrets = this->service.get_turret();
	for (auto it = turrets.begin(); it != turrets.end(); it++) {
		cout << (*it).text();
	}
}
void UI::delete_turret(std::string command) {
	command.erase (0, 7);
	service.delete_turret_list(command);
}
void UI::update_turret(std::string command) {
	command.erase(0, 7);
	int ok = 1;
	string location, vision, size;
	int parts, aura_level;
	std::string str_to_components[5];
	int j = 0;
	for (unsigned int i = 0; i < command.length(); ++i) {
		if (command[i] == ',')
			j++;
		else if (command[i] == ' ' and i == 0)
			continue;
		else if (command[i] == ' ' and command[i - 1] == ' ')
			continue;
		else if (command[i] == ' ' and command[i - 1] == ',')
			continue;
		else str_to_components[j] += command[i];
	}

	if (j != 4)
		ok = 0;

	if (ok) {
		try
		{
			aura_level = std::stoi(str_to_components[2]);
			parts = std::stoi(str_to_components[3]);
		}
		catch (std::logic_error&)
		{
			ok = 0;
		}
		location = str_to_components[0];
		size = str_to_components[1];
		vision = str_to_components[4];
	}
	if (ok) {
		this->service.update_list(location, size, aura_level, parts, vision);
	}
	else
		cout << "Invalid turret !\n";
}

vector<string> UI::split_string(string str, const string c) {
	vector<string> tokens;
	size_t s = str.find(c);
	while (s != string::npos) {
		tokens.push_back(str.substr(0, s));
		str = str.substr(s + 1);
		s = str.find(c);
	}
	tokens.push_back(str);

	return tokens;
}

void UI::ui_console() {
	menu();
	int ok = 1;
	string mode = "A";
	while (ok)
	{
		try {
			while (mode == "A" && ok == 1) {
				char cmd[100], cmd_aux[100], * command;
				cout << ">>> ";
				cin.getline(cmd, 100);


				strcpy(cmd_aux, cmd);
				command = strtok(cmd_aux, " ");
				int sz = strlen(cmd);
				string cmmd;
				cmmd.assign(cmd, sz);

				if (strcmp(command, "add") == 0) {
					add_turret(cmd);
				}
				else if (strcmp(command, "update") == 0) {
					update_turret(cmd);
				}
				else if (strcmp(command, "delete") == 0) {
					delete_turret(cmd);
				}
				else if (strcmp(command, "list") == 0) {
					list_turrets();
				}
				else if (strcmp(command, "fileLocation") == 0) {
					path(cmmd);
				}
				else if (strcmp(command, "mode") == 0) {
					command = strtok(0, " ");
					if (strcmp(command, "B") == 0) {
						mode = "B";
						cout << "You are now in mode: user\n";
					}
					else if (strcmp(command, "A") == 0) {
						cout << "You are now in mode: admin\n";
					}
					else
						cout << "Invalid user type !\n";
				}
				else if (strcmp(command, "exit") == 0) {
					ok = 0;
				}
				else printf("Not a valid command !\n");
			}

			while (mode == "B" && ok == 1) {
				char cmd[100], cmd_aux[100], * command;
				cout << ">>>";
				cin.getline(cmd, 100);


				strcpy(cmd_aux, cmd);
				command = strtok(cmd_aux, " ");
				int sz = strlen(cmd);
				string cmmd;
				cmmd.assign(cmd, sz);

				if (strcmp(command, "mode") == 0) {
					command = strtok(0, " ");
					if (strcmp(command, "A") == 0) {
						mode = "A";
						cout << "You are now in mode: administrator\n";
					}
					else if (strcmp(command, "B") == 0) {
						cout << "You are now in mode: user\n";
					}
					else
						cout << "Invalid user type !\n";
				}
				else if (strcmp(command, "next") == 0) {
					next_turret();
				}
				else if (strcmp(command, "mylist") == 0) {
					list_mylist();
				}
				else if (strcmp(command, "save") == 0) {
					save_mylist(cmd);
				}
				else if (strcmp(command, "list") == 0) {
					if (strlen(cmd) != 4)
						sort_list(cmd);
					else
						cout << "Not a valid command !\n";
				}
				else if (strcmp(command, "mylistLocation") == 0) {
					path_mylist(cmmd);
				}
				else if (strcmp(command, "exit") == 0) {
					ok = 0;
				}
				else printf("Not a valid command !\n");
			}
		}
		catch (exception & exept) {
			cout << "error:  -" << exept.what() << "\n";
		}
	}
}