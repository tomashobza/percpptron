#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>

class Percpptron
{
private:
	std::vector<float> weights;

public:
	Percpptron(int inputs)
	{
		// initialize the weights randomly
		for (int i = 0; i < inputs; ++i)
		{
			weights.push_back(std::rand());
		}

		std::cout << "Weights: (";
		for (int i = 0; i < weights.size(); ++i)
		{
			std::cout << weights.at(i);
			if (i + 1 < weights.size())
			{
				std::cout << ", ";
			}
		}
		std::cout << ")" << std::endl;
	}
};
