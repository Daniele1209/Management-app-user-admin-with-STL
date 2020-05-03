#pragma once
#include "file_handle.h"
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

vector<string> tokenize(const string& str, char delimiter)
{
	vector <string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}

std::vector<Turret> load_data(std::string filename)
{
	ifstream file{ filename };
	vector<Turret> dataset;

	Turret turr{};

	while (file >> turr)
		dataset.push_back(turr);
	file.close();

	return dataset;
}

void split_data(std::vector<Turret> dataset, double factor, std::vector<Turret>& train, std::vector<Turret>& test)
{
	int number_for_testing = static_cast<int>(factor * dataset.size());
	size_t number_for_training = dataset.size() - number_for_testing;

	int i = 0;
	for (i = 0; i < number_for_training; i++)
		train.push_back(dataset[i]);
	while (i < dataset.size())
	{
		test.push_back(dataset[i]);
		i++;
	}
}