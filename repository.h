#pragma once
#include "turret.h"
#include "dynamic_array.h"
#define _CRT_SECURE_NO_WARNINGS

class Repository {
private:
	Dynamic_vector<Turret> turrets;
	std::string file_path;

public:
	//initialise the repo
	Repository() : file_path{"file.txt"} {}

	void path_set(std::string path_of_file);
	int get_the_size();
	int add_turret(const Turret& tur);
	Turret find_turret_location(int location);
	Turret get_all_turrets(int pos);
	Dynamic_vector<Turret> get_turrets();
	Turret find_turret(std::string location);
	int delete_turret(std::string str);
	int update_turret(const Turret tur, std::string str);
};