#pragma once
#include "turret.h"
#include "service.h"
#include "watchman.h"
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