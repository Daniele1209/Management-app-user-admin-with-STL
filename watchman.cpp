#include "watchman.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

Turret Watchman::next() {
	vector<Turret> list = repo.get_turrets();
	if (list.size() == 0) {
		throw exception();
	}
	Turret& tur = list[index];
	this->index++;
	return tur;
}

void Watchman::add_turret_mylist(std::string elements) {
	Turret turret = repo.find_turret(elements);

	vector<Turret> list = repo.get_turrets();
	if (repo.vector_search(this->mylist, turret))
		throw exception();
	if (!repo.vector_search(list, turret))
		throw exception();

	for (auto it : list) {
		if (it == turret) {
			this->mylist.push_back(it);
			break;
		}
	}
}

vector<Turret>& Watchman::turret_list(string size, int parts) {
	vector<Turret> list = repo.get_turrets();

	this->mylist = vector<Turret>(list.size());

	auto it = copy_if(list.begin(), list.end(), mylist.begin(), [parts, size](Turret& t) {
		return (t.get_parts() <= parts);
		});
	this->mylist.resize(distance(this->mylist.begin(), it));

	return this->mylist;
}

std::vector<Turret>& Watchman::get_turret_list() {
	return this->mylist;
}

