#include <matlib/matrix_1d.h>
#include <string>
#include <stdexcept>


Matrix1D::Matrix1D()
	: Matrix1D(0)
{

}

Matrix1D::Matrix1D(size_t size, double value)
	: m_data(size, value)
{
	
}

Matrix1D::Matrix1D(const std::vector<double> data)
	: m_data(data)
{

}


void Matrix1D::resize(size_t new_size)
{
	m_data.resize(new_size);
}

size_t Matrix1D::get_size() const
{
	return m_data.size();
}

void Matrix1D::set_element(size_t index, double value)
{
	// check if index is valid
	if (index >= get_size())
	{
		throw std::runtime_error("Index (" + std::to_string(index) + ") out of bound");
	}

	m_data[index] = value;
}

double Matrix1D::get_element(size_t index) const
{
	// check if index is valid
	if (index >= get_size())
	{
		throw std::runtime_error("Index (" + std::to_string(index) + ") out of bound");
	}

	return m_data[index];
}


double& Matrix1D::operator() (size_t index)
{
	// check if index is valid
	if (index >= get_size())
	{
		throw std::runtime_error("Index (" + std::to_string(index) + ") out of bound");
	}

	return m_data[index];
}

const double& Matrix1D::operator() (size_t index) const
{
	// check if index is valid
	if (index >= get_size())
	{
		throw std::runtime_error("Index (" + std::to_string(index) + ") out of bound");
	}

	return m_data[index];
}
