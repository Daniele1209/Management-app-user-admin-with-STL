#include "repository.h"
#include "turret.h"
#include <string>
using namespace std;

int Repository::add_turret(const Turret& tur) {
	if (this->turrets.find_element(tur.get_location()) >= 0)
		return -1;
	this->turrets.add(tur);
	return 0;
}

Turret Repository::find_turret_location(int location) {
	return this->turrets.get(location);
}

int Repository::get_the_size() {
	return turrets.get_size();
}

Turret Repository::get_all_turrets(int pos) {
	return turrets[pos];

}

Turret Repository::find_turret(std::string location) {
	return turrets.find(location);
}

int Repository::delete_turret(std::string location) {
	int index = turrets.find_element(location);
	if (index != -1)
		return turrets.delete_item(index);
	else {
		return -2;
	}
}

int Repository::update_turret(const Turret tur, std::string str) {
	if (this->delete_turret(str) != -2) {
		this->turrets.add(tur);
		return 1;
	}
	else
		return 0;
}

Dynamic_vector<Turret> Repository::get_turrets() {
	return this->turrets;
}
