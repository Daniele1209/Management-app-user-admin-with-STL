#pragma once
#include "repository.h"
#include "turret.h"

class Watchman {
private:
	Repository& repo;
	Repository& mylist;
	int index = 0;

public:

	Watchman(Repository& r, Repository& l): repo{ r }, mylist{ l } {}

	Turret next();
	Turret current_turret();
	std::string turret_list(std::string elements);
	void add_turret_mylist(std::string elements);
	Dynamic_vector<Turret> get_turret_list();
};