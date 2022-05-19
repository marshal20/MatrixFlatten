#include <matlib/matrix_3d.h>
#include <string>
#include <stdexcept>


// the 3D matrix consists of rows, columns and pages
// a page is a 2D matrix consisting of rows and colums
// a row is a 1D vector consisting of elements
// 
// Here is how a row (V) is stored in memory
//  -----------------------------
//  | V1 | V2 | V3 | ..... | Vn |
//  -----------------------------
// 
// Here is how a page is stored in memeory
//  -------------------------------------
//  | ROW1 | ROW2 | ROW3 | ..... | ROWn |
//  -------------------------------------
//
// Here is how the 3D matrix is stored in memory
//  -----------------------------------------
//  | PAGE1 | PAGE2 | PAGE3 | ..... | PAGEn |
//  -----------------------------------------
//
// all this is stored sequentially in a 1D vector, page by page, row by row, element by element
// 
// flattening equation: 
//  q = k*page_size + i*columns_count + j
//
// indexing:
//  i : row number
//  j : column number
//  k : page number


Matrix3D::Matrix3D()
{

}

Matrix3D::Matrix3D(const Size3D& size, double value)
	: m_size(size), m_contents_vector(size.rows*size.columns*size.pages, value)
{

}


void Matrix3D::resize(const Size3D& size)
{
	m_size = size;
	m_contents_vector.resize(size.rows*size.columns*size.pages);
}

Size3D Matrix3D::get_size() const
{
	return m_size;
}

void Matrix3D::set_element(size_t i, size_t j, size_t k, double value)
{
	m_contents_vector(flatten_3d_index(i, j, k)) = value;
}

double Matrix3D::get_element(size_t i, size_t j, size_t k) const
{
	return m_contents_vector(flatten_3d_index(i, j, k));
}


double& Matrix3D::operator() (size_t i, size_t j, size_t k)
{
	return m_contents_vector(flatten_3d_index(i, j, k));
}

const double& Matrix3D::operator() (size_t i, size_t j, size_t k) const
{
	return m_contents_vector(flatten_3d_index(i, j, k));
}


size_t Matrix3D::flatten_3d_index(size_t i, size_t j, size_t k) const
{
	// check for out of bound index
	if (i >= m_size.rows || j >= m_size.columns || k >= m_size.pages)
	{
		throw std::runtime_error(std::string("Index ") +
			"(" + std::to_string(i) + std::to_string(j) + std::to_string(k) + ")" +
			" out of bound for 3D matrix of size " + 
			"(" + std::to_string(m_size.rows) + std::to_string(m_size.columns) + std::to_string(m_size.pages) + ")"
		);
	}

	// q = k*page_size + i*columns_count + j
	return k*(m_size.rows*m_size.columns) + i*m_size.columns + j;
}
