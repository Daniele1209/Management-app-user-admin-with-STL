#pragma once
#include "repository.h";
#include <vector>

class Service {
private:
	Repository& repo;

public:
	Service(Repository& r) :repo{ r } {}
	Repository& get_repo() const {
		return repo;
	}
	void new_path(std::string path);
	int add_turret_repo(const std::string& location, const std::string& size, const int aura_level, const int parts, const std::string& vision);
	std::vector<Turret> get_turret();
	int get_repo_size();
	int delete_turret_list(std::string command);
	int update_list(const std::string& location, const std::string& size, const int aura_level, const int parts, const std::string& vision);
	void delete_turrets();
};