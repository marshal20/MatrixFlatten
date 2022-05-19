#pragma once
#include "vector_1d.h"


struct Size3D
{
	size_t rows;
	size_t columns;
	size_t pages;
};

class Matrix3D
{
public:
	Matrix3D();
	Matrix3D(const Size3D& size, double value = 0);

	void resize(const Size3D& size);
	Size3D get_size() const;
	void set_element(size_t i, size_t j, size_t k, double value);
	double get_element(size_t i, size_t j, size_t k) const;

	// operator() access
	double& operator() (size_t i, size_t j, size_t k);
	const double& operator() (size_t i, size_t j, size_t k) const;

private:
	size_t flatten_3d_index(size_t i, size_t j, size_t k) const;

private:
	Vector1D m_contents_vector;
	Size3D m_size;

};
