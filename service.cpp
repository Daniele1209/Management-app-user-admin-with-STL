#include "service.h"
#include <iostream>


int Service::add_turret_repo(const std::string& location, const std::string& size, const int aura_level, const int parts, const std::string& vision) {
	Turret tur{ location, size, aura_level,parts, vision };

	return this->repo.add_turret(tur);

}

int Service::delete_turret_list(std::string command) {
	return this->repo.delete_turret(command);
}

Turret Service::get_turret(int pos) {
	return this->repo.get_all_turrets(pos);
}

int Service::get_repo_size() {
	return this->repo.get_the_size();
}

int Service::update_list(const std::string& location, const std::string& size, const int aura_level, const int parts, const std::string& vision) {
	Turret tur{ location, size, aura_level,parts, vision };
	return this->repo.update_turret(tur, location);
}