#include "UI.h"
#include <string>
#include <iostream>
#include <string>
using namespace std;

void UI::menu() {
	cout << "add - to add a turret\n";
	cout << "delete - to delete a turret\n";
	cout << "update - to change the turret\n";
	cout << "list - to print all the turrets\n";
	cout << "exit - to exit the app\n";
	cout << "mode - to change the mode (admin or user)\n";
}

//UI for WATCHMAN user
void UI::next_turret() {
	if (service.get_repo_size() != 0) {
		watcher.next();
		list_turret(watcher.current_turret());
	}
	else
		cout << "The main list is empty !\n";
}

void UI::list_mylist() {
	Dynamic_vector<Turret> turret = this->watcher.get_turret_list();
	for (int i = 0; i < turret.get_size(); i++)
	{
		Turret t = turret.get(i);
		cout << t.message() << "\n";
	}
}

void UI::save_mylist(std::string command) {
	command.erase(0, 5);
	cout << command << "\n";
	watcher.add_turret_mylist(command);
	cout << "Turret added !\n";

}

void UI::sort_list(std::string command) {
	command.erase(0, 4);
	cout << watcher.turret_list(command);
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
		if (this->service.add_turret_repo(location, size, aura_level, parts, vision))
			cout << "Turret already exists !\n";
	}
	else
		cout << "Invalid turret !\n";
}
void UI::list_turrets() {
	for (int i = 0; i < this->service.get_repo_size(); i++) {
		Turret t = this->service.get_turret(i);
		cout << t.message() << "\n";
	}
}
void UI::delete_turret(std::string command) {
	command.erase (0, 7);
	if (service.delete_turret_list(command)==-2)
		cout << "Item does not exist !\n";
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
		if (this->service.update_list(location, size, aura_level, parts, vision)==0)
			cout << "Turret does not exist !\n";
	}
	else
		cout << "Invalid turret !\n";
}

void UI::ui_console() {
	menu();
	int ok = 1;
	string mode = "A";
	while (ok)
	{
		while (mode == "A" && ok == 1) {
			char cmd[100], cmd_aux[100], *command;
			cout << ">>>";
			cin.getline(cmd, 100);


			strcpy(cmd_aux, cmd);
			command = strtok(cmd_aux, " ");

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
			else if (strcmp(command, "exit") == 0) {
				ok = 0;
			}
			else printf("Not a valid command !\n");
		}
	}
}