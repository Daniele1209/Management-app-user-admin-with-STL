#pragma once
#include "turret.h"
#include "service.h"
#include "watchman.h"
#include <vector>
#include "file_handle.h"
#include "custom_exceptions.h"
#define _CRT_SECURE_NO_WARNINGS

class UI {

private:
	Service service;
	Watchman watcher;

public:
	UI(Service& s, Watchman& w) : service{s}, watcher{ w } {}
	
	void ui_console();

private:
	static void menu();

	std::vector<std::string> split_string(std::string str, const std::string c);
	void path(std::string str);
	void path_mylist(std::string str);
	void add_turret(std::string command);
	void list_turrets();
	void delete_turret(std::string command);
	void update_turret(std::string command);
	void next_turret();
	void list_mylist();
	void save_mylist(std::string command);
	void sort_list(std::string command);
	void list_turret(Turret t);
};