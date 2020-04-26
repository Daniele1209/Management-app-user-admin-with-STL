#pragma once
#include "repository.h"
#include "turret.h"

class Watchman {
private:
	Repository& repo;
	std::vector<Turret> mylist;
	int index = 0;

public:

	Watchman(Repository& r, std::vector<Turret> l): repo{ r }, mylist{ l } {}

	Turret next();
	std::vector<Turret>& turret_list(std::string size, int parts);
	void add_turret_mylist(std::string elements);
	std::vector<Turret>& get_turret_list();
};