#include "test.h"

void run_service_tests() {
	Repository repo{};
	Service service{ repo };
	service.new_path("file.txt");
	service.add_turret_repo("east", "huge", 400, 4000, "tower");
	service.add_turret_repo("west", "medium", 250, 3400, "tower");
	service.add_turret_repo("north", "small", 120, 1000, "mountains");
	service.add_turret_repo("south", "medium", 230, 2700, "tower");
	assert(service.get_repo_size() == 4);
	service.delete_turret_list("east");
	assert(service.get_repo_size() == 3);
	service.update_list("west", "mid", 0, 0, "tower");
	service.delete_turrets();
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
	Turret tur3 = repo.get_turrets()[1];
	assert(tur2 == tur3);
	repo.delete_all();
	std::cout << "repo tests passes !\n";
}

void run_turret_test() {
	Turret tur{ "south", "medium", 230, 2700, "tower" };
	assert(tur.get_location() == "south");
	assert(tur.get_size() == "medium");
	assert(tur.get_aura_level() == 230);
	assert(tur.get_parts() == 2700);
	assert(tur.get_vision() == "tower");
	Turret tur2{ "east", "huge", 400, 4000, "tower" };
	assert((tur == tur2) == false);
	Turret tur3{ "east", "huge", 400, 4000, "tower" };
	assert((tur2 == tur3) == true);
	std::cout << "turret tests passes !\n";

}

void run_watchman_test() {
	Repository repo{};
	std::vector<Turret> list{};
	Watchman watchman{ repo, list };
	Service service{ repo };
	service.add_turret_repo("east", "huge", 400, 4000, "tower");
	Turret tur2{ "east", "huge", 400, 4000, "tower" };
	Turret tur3 = watchman.next();
	assert(tur2 == tur3);
	watchman.add_turret_mylist("east");
	std::vector<Turret> t_list = watchman.turret_list("medium", 4000);
	std::vector<Turret> tt_list = watchman.get_turret_list();
	assert(tt_list.size() == 1);
	std::cout << "watchman tests passes !\n\n";
}

void run_all_tests() {
	run_service_tests();
	run_repo_services();
	run_turret_test();
	run_watchman_test();
}