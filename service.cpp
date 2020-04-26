#include "service.h"
#include <iostream>

int Service::add_turret_repo(const std::string& location, const std::string& size, const int aura_level, const int parts, const std::string& vision) {
	Turret tur{ location, size, aura_level,parts, vision };

	return this->repo.add_turret(tur);

}

void Service::new_path(std::string set_path) {
	this->repo.path_set(set_path);
}

int Service::delete_turret_list(std::string command) {
	Turret remove{ command, "", 0, 0, "" };
	return this->repo.delete_turret(remove);
}

std::vector<Turret> Service::get_turret() {
	return this->repo.get_turrets();
}

int Service::get_repo_size() {
	return this->repo.get_the_size();
}

int Service::update_list(const std::string& location, const std::string& size, const int aura_level, const int parts, const std::string& vision) {
	Turret tur = Turret(location, size, aura_level,parts, vision);
	this->repo.delete_turret(tur);
	return this->repo.add_turret(tur);

}

void Service::delete_turrets() {
	this->repo.delete_all();
}