#pragma once
#include "turret.h"
#include "dynamic_array.h"
#include <vector>
#define _CRT_SECURE_NO_WARNINGS

class Repository {
private:
	Dynamic_vector<Turret> turrets;
	std::string file_path;

public:
	//initialise the repo
	Repository() : file_path{"file.txt"} {}
	//fct for files
	void path_set(std::string path_of_file);
	bool vector_search(std::vector<Turret>, Turret);

	int get_the_size();
	int add_turret(Turret tur);
	std::vector<Turret> get_turrets();
	Turret find_turret(std::string location);
	int delete_turret(Turret tur);
	void delete_all();
};