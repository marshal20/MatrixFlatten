#include <matlib/vector_1d.h>
#include <string>
#include <stdexcept>


Vector1D::Vector1D()
	: Vector1D(0)
{

}

Vector1D::Vector1D(size_t size, double value)
	: m_data(size, value)
{
	
}

Vector1D::Vector1D(const std::vector<double> data)
	: m_data(data)
{

}


void Vector1D::resize(size_t new_size)
{
	m_data.resize(new_size);
}

size_t Vector1D::get_size() const
{
	return m_data.size();
}

void Vector1D::set_element(size_t index, double value)
{
	// check if index is valid
	if (index >= get_size())
	{
		throw std::runtime_error("Index (" + std::to_string(index) + ") out of bound for 1D vector of size " + std::to_string(get_size()));
	}

	m_data[index] = value;
}

double Vector1D::get_element(size_t index) const
{
	// check if index is valid
	if (index >= get_size())
	{
		throw std::runtime_error("Index (" + std::to_string(index) + ") out of bound for 1D vector of size " + std::to_string(get_size()));
	}

	return m_data[index];
}


double& Vector1D::operator() (size_t index)
{
	// check if index is valid
	if (index >= get_size())
	{
		throw std::runtime_error("Index (" + std::to_string(index) + ") out of bound for 1D vector of size " + std::to_string(get_size()));
	}

	return m_data[index];
}

const double& Vector1D::operator() (size_t index) const
{
	// check if index is valid
	if (index >= get_size())
	{
		throw std::runtime_error("Index (" + std::to_string(index) + ") out of bound for 1D vector of size " + std::to_string(get_size()));
	}

	return m_data[index];
}
