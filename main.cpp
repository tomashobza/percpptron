#include <iostream>
#include <cstdlib>
#include <vector>

#include "percpptron.h"

int main()
{
	// set the seed
	std::srand(42);

	Percpptron pctn(2);
	pctn.print();

	// training data
	std::vector<std::vector<float>> train_x = {
		// class A
		{0, 1},
		{0, 2},
		{1, 2},
		{1, 3},
		// class B
		{1, 0},
		{2, 0},
		{2, 1},
		{3, 1},
	};

	// labels
	std::vector<float> y = {
		1,
		1,
		1,
		1,
		-1,
		-1,
		-1,
		-1};

	std::cout << "Predictions:" << std::endl;
	for (int i = 0; i < train_x.size(); ++i)
	{
		std::cout << pctn.predict(train_x.at(i)) << " : " << y.at(i) << std::endl;
	}

	pctn.train(train_x, y, 30);

	std::cout << "Predictions:" << std::endl;
	for (int i = 0; i < train_x.size(); ++i)
	{
		std::cout << pctn.predict(train_x.at(i)) << " : " << y.at(i) << std::endl;
	}

	return 0;
}
