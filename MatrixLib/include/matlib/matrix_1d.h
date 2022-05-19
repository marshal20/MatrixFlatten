#pragma once
#include <vector>


class Matrix1D
{
public:
	Matrix1D();
	Matrix1D(size_t size, double value = 0);
	Matrix1D(const std::vector<double> data);

	void resize(size_t new_size);
	size_t get_size() const;
	void set_element(size_t index, double value);
	double get_element(size_t index) const;

	// operator() access
	double& operator() (size_t index);
	const double& operator() (size_t index) const;

private:
	std::vector<double> m_data;
};
