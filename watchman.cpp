#include "watchman.h"

Turret Watchman::next() {
	++index;
	if (index == repo.get_the_size())
		index = 0;
	if (repo.get_the_size() > index)
		return repo.find_turret_location(index);
}

Turret Watchman::current_turret() {
	if (repo.get_the_size() > index)
		return repo.find_turret_location(index);
}

void Watchman::add_turret_mylist(std::string elements) {
	Turret turret = repo.find_turret(elements);
	mylist.add_turret(turret);
}

std::string Watchman::turret_list(std::string elements) {
	std::string str;
	std::string str_to_components[2];

	int j = 0;
	for (unsigned int i = 0; i < elements.length(); ++i) {
		if (elements[i] == ',')
			j++;
		else if (elements[i] == ' ' and i == 0)
			continue;
		else if (elements[i] == ' ' and elements[i - 1] == ' ')
			continue;
		else if (elements[i] == ' ' and elements[i - 1] == ',')
			continue;
		else str_to_components[j] += elements[i];
	}

	int parts;
	std::string size = "";

	if (j == 0) {
		parts = std::stoi(str_to_components[1]);
	}
	else if (j == 1) {
		size = str_to_components[0];
		parts = std::stoi(str_to_components[1]);
	}


	for (int i = 0; i < repo.get_the_size(); ++i) {
		if (repo.find_turret_location(i).get_parts() < parts)
			if (size != "") {
				if (repo.find_turret_location(i).get_size() == size)
					str += repo.find_turret_location(i).message() + "\n";
			}
			else str += repo.find_turret_location(i).message() + "\n";
	}

	return str;

}

Dynamic_vector<Turret> Watchman::get_turret_list() {
	return this->mylist.get_turrets();

}
