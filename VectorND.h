#pragma once
#include <ostream>
#include <vector>

class VectorND
{
public:
	int num_elements;
	std::vector<int> elements;

	VectorND()
	{
		std::vector<int> temp(num_elements, 0);
		this->elements = temp;
	}

	VectorND(std::vector<int> input)
	{
		this->num_elements = input.size();
		this->elements = input;
	}

	// overloading plus (addition) operator
	
	VectorND operator+(const VectorND& input)
	{
		std::vector<int> vec;
		//vec.size = this->num_elements; 
		for (int i = 0; i < this->num_elements; i++)
		{
			vec.push_back(this->elements.at(i) + input.elements.at(i));
		}
		VectorND result;
		result.num_elements = vec.size();
		result.elements = vec;
		return result;
	}

	// dot product
	int operator*(const VectorND& input)
	{
		int dot_product = 0;
		//dot_product = this->x_*b.x_ + this->y_*b.y_ + this->z_*b.z_;
		for (int i = 0; i < this->num_elements; i++)
		{
			dot_product += this->elements.at(i)*input.elements.at(i);
		}
		return dot_product;
	}
	
};

std::ostream& operator<<(std::ostream& os, const VectorND &input)
{
	for (int i = 0; i < input.num_elements; i++)
	{
		os << input.elements.at(i) << " ";
	}
	os << std::endl;
	return os;
}
