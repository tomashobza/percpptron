#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>

class Percpptron
{
private:
	int features;
	std::vector<float> weights;
	float bias;

public:
	Percpptron(int features)
	{
		this->features = features;

		// initialize the weights randomly
		for (int i = 0; i < features; ++i)
		{
			// weights.push_back(0);
			weights.push_back(std::rand() % 100);
		}

		// initialize bias randomly
		// bias = 0;
		bias = std::rand() % 100;
	}

	float predict(std::vector<float> input)
	{
		if (input.size() != features)
		{
			std::cerr << "Input feature count does not match the perceptron weight count." << std::endl;
			return 0;
		}

		float sum = 0;
		// multiply weights with inputs
		for (int i = 0; i < features; ++i)
		{
			sum += input.at(i) * weights.at(i);
		}

		// add bias
		sum += bias;

		// pass through the activation function and return
		return activation(sum);
	}

	// activation function is just a signum function - 0->1 step function
	float activation(float x)
	{
		if (x >= 0)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}

	void train(std::vector<std::vector<float>> train_data, std::vector<float> y, int epochs)
	{
		for (int epoch_i = 0; epoch_i < epochs; ++epoch_i)
		{
			int incorrect_cnt = 0;

			for (int sample_idx = 0; sample_idx < train_data.size(); ++sample_idx)
			{
				// check if the sample is incorrectly classified
				// that's cases where y=1 & pred=-1 OR y=-1 & pred=1 -> their product is negative
				// zero product is also an incorrect prediction
				float y_loc = y.at(sample_idx);
				std::vector<float> sample = train_data.at(sample_idx);
				int product = y_loc * predict(sample);
				if (product <= 0)
				{
					++incorrect_cnt;
					// update the weights with the most basic rule
					for (int i = 0; i < features; ++i)
					{
						weights[i] += (y_loc * sample.at(i));
					}

					// update the bias
					bias += y.at(sample_idx);
				}
			}

			float accuracy = 1.0 - (incorrect_cnt * 1.0 / train_data.size());
			std::cout << "Epoch[" << epoch_i << "] Acc: " << accuracy << " Miss: " << incorrect_cnt << std::endl;

			print();
		}
	}

	void print()
	{
		std::cout << "Weights: (";
		for (int i = 0; i < features; ++i)
		{
			std::cout << weights.at(i);
			if (i + 1 < weights.size())
			{
				std::cout << ", ";
			}
		}
		std::cout << ")" << std::endl;

		std::cout << "Bias: " << bias << std::endl;
	}
};
