#include "test.h"

void run_service_tests() {
	Repository repo{};
	Service service{ repo };
	service.add_turret_repo("east", "huge", 400, 4000, "tower");
	service.add_turret_repo("west", "medium", 250, 3400, "tower");
	service.add_turret_repo("north", "small", 120, 1000, "mountains");
	service.add_turret_repo("south", "medium", 230, 2700, "tower");
	assert(repo.get_the_size() == 4);
	service.delete_turret_list("east");
	assert(repo.get_the_size() == 3);
	service.update_list("south", "huge", 2230, 27, "castle");
	assert(repo.get_the_size() == 3);
	std::cout << "service tests passes !\n";
}

void run_repo_services() {
	Repository repo{};
	Service service{ repo };
	Turret tur{ "south", "medium", 230, 2700, "tower" };
	Turret tur2{ "east", "huge", 400, 4000, "tower" };
	repo.add_turret(tur);
	assert(repo.get_the_size() == 1);
	repo.add_turret(tur2);
	assert(repo.get_the_size() == 2);
	Turret tur3 = repo.get_all_turrets(1);
	assert(tur2 == tur3);
	Turret tur4 = repo.find_turret("south");
	assert(tur4 == tur);
	repo.delete_turret("east");
	assert(repo.get_the_size() == 1);
	Turret tur5{ "south", "meh", 200, 5000, "lake" };
	repo.update_turret(tur5, "south");
	assert(repo.get_the_size() == 1);
	std::cout << "repo tests passes !\n";
}

void run_turret_test() {
	Turret tur{ "south", "medium", 230, 2700, "tower" };
	Turret tur2{ "east", "huge", 400, 4000, "tower" };
	assert((tur == tur2) == false);
	Turret tur3{ "east", "huge", 400, 4000, "tower" };
	assert((tur2 == tur3) == true);
	std::cout << "turret tests passes !\n";

}

void run_watchman_test() {
	Repository repo{};
	Repository list{};
	Watchman watchman{ repo, list };
	Service service{ repo };
	service.add_turret_repo("east", "huge", 400, 4000, "tower");
	Turret tur2{ "east", "huge", 400, 4000, "tower" };
	Turret tur3 = watchman.next();
	assert(tur2 == tur3);
	Turret tur4 = watchman.current_turret();
	assert(tur2 == tur4);
	watchman.add_turret_mylist("east");
	assert(list.get_the_size() == 1);
	std::cout << "watchman tests passes !\n\n";
}

void run_all_tests() {
	run_service_tests();
	run_repo_services();
	run_turret_test();
	run_watchman_test();
}