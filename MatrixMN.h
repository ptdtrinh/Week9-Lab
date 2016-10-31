#pragma once
#include "VectorND.h"


class MatrixMN
{
public:
	int num_rows, num_cols;
	std::vector<VectorND> matrix_elements;

	MatrixMN(std::vector<VectorND> input)
	{
		this->num_rows = input.size(); 
		this->num_cols = input.at(0).num_elements;
		this->matrix_elements = input;
		//for (int i = 0; i < input.size(); i++)
		//{
		//	matrix_elements.at(i) = input.at(i);
		//}
	}
		
	// Multiplication of MatrixMN and VectorND
	VectorND operator*(const VectorND& rhs)
	{
		std::vector<int> vec;
		for (int i = 0; i < this->num_rows; i++)
		{
			vec.push_back(this->matrix_elements.at(i)*rhs);
		}
		VectorND result;
		result.num_elements = vec.size();
		result.elements = vec;
		return result;
	}
};

std::ostream& operator<<(std::ostream& os, const MatrixMN &input)
{
	for (int i = 0; i < input.num_rows; i++)
	{
		os << input.matrix_elements.at(i) << std::endl;
	}
	os << std::endl;
	return os;
}