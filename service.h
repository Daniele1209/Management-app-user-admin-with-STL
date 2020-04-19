#pragma once
#include "repository.h";

class Service {
private:
	Repository& repo;

public:
	Service(Repository& r) :repo{ r } {}
	Repository& get_repo() const {
		return repo;
	}
	int add_turret_repo(const std::string& location, const std::string& size, const int aura_level, const int parts, const std::string& vision);
	Turret get_turret(int pos);
	int get_repo_size();
	int delete_turret_list(std::string command);
	int update_list(const std::string& location, const std::string& size, const int aura_level, const int parts, const std::string& vision);
};