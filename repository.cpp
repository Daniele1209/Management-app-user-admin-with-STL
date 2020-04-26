#include "repository.h"
#include "turret.h"
#include <string>
#include <Windows.h>
#include <fstream>
#include <vector>

using namespace std;

int Repository::add_turret(Turret tur) {
	vector<Turret> turrets;
	Turret current{};
	ifstream input(this->file_path);
	while (input >> current) {
		turrets.push_back(current);
	}
	input.close();
	if (vector_search(turrets, tur))
		return 0;

	ofstream output(this->file_path, ios::app);
	output << tur;
	output.close();
	return 1;
}

bool Repository::vector_search(vector<Turret> turrets, Turret tur) {
	for (auto it : turrets) {
		if (it == tur)
			return true;
	}
	return false;
}

void Repository::delete_all() {
	ofstream os;
	os.open(this->file_path, ofstream::out | ofstream::trunc);
	os.close();
}

int Repository::get_the_size() {
	vector<Turret> turrets;
	Turret current;
	ifstream input(this->file_path);

	while (input >> current) {
		turrets.push_back(current);
	}

	input.close();

	return turrets.size();
}

Turret Repository::find_turret(std::string location) {
	vector<Turret> turrets;
	Turret current;
	ifstream input(this->file_path);

	while (input >> current) {
		turrets.push_back(current);
		if (current.get_location() == location)
			return current;
	}

	input.close();


}

int Repository::delete_turret(Turret tur) {
	vector<Turret> turrets;
	Turret current{};

	ifstream input(this->file_path);
	while (input >> current) {
		turrets.push_back(current);
	}
	input.close();

	auto it = turrets.begin();
	while (it != turrets.end()) {
		if (*it == tur) 
			break;
		it++;
	}

	if (it == turrets.end())
		return -2;
	else (turrets.erase(it));

	ofstream output(this->file_path);
	for (auto it : turrets) {
		output << it;
	}
	output.close();

	return 1;

}

vector<Turret> Repository::get_turrets() {
	vector<Turret> turrets;
	Turret current;
	ifstream input(this->file_path);

	while (input >> current) {
		turrets.push_back(current);
	}

	input.close();

	return turrets;
}

//for files

void Repository::path_set(std::string path_of_file) {
	this->file_path = path_of_file;
}

