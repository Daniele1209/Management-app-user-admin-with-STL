#pragma once
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

class Turret {
private:
	std::string location;
	std::string size;
	int aura_level;
	int parts;
	std::string vision;

public:
	Turret();

	Turret(const std::string& location, const std::string& size, const int aura_level, const int parts, const std::string& vision);

	std::string get_location() const { 
		return location; 
	}
	std::string get_size() const { 
		return size; 
	}
	int get_aura_level() const { 
		return aura_level; 
	}
	int get_parts() const {
		return parts;
	}
	std::string get_vision() const { 
		return vision; 
	}

	bool operator==(const Turret& t);

	std::string message();
};