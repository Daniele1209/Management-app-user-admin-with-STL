#include "turret.h"
#include <string>

Turret::Turret() : location(""), size(""), aura_level(0), parts(0), vision(""){}

Turret::Turret(const std::string& location, const std::string& size, const int aura_level, const int parts, const std::string& vision) {
	this->location = location;
	this->size = size;
	this->aura_level = aura_level;
	this->parts = parts;
	this->vision = vision;
}

bool Turret::operator==(const Turret& t)
{
	return (this->location == t.location && this->size == t.size && this->aura_level == t.aura_level && this->parts == t.parts && this->vision == t.vision);
}

std::string Turret::message() {
	return "Location: " + this->get_location() + "  Size: " + this->get_size() + "  Aura level: " + std::to_string(this->get_aura_level()) + "  Parts: " + std::to_string(this->get_parts()) + "  Vision: " + this->get_vision();
}
