#include "pch.h"
#include "Matrix.h"
#include <string>
#include "MatrixError.h"


Matrix::Matrix(int nRows_, int nCols_):_nRows(nRows_),_nCols(nCols_)
{
	if (nCols_ == 0) {
		_nCols = _nRows;
	}
	_matrix = new double*[_nRows];
	for (size_t i = 0; i < _nRows; i++)
	{
		_matrix[i] = new double[_nCols];
	}

}

Matrix::~Matrix()
{
	for (size_t i = 0; i < _nRows; i++)
	{
		delete[] _matrix[i];
	}
	
	delete[] _matrix;
}

void Matrix::randomFill(const int number_) {
	for (size_t i = 0; i < _nRows; i++)
	{
		for (size_t j = 0; j < _nCols; j++)
		{
			_matrix[i][j] = number_;
		}
	}		
}

Matrix::Matrix(const Matrix& m_):
	_nRows(m_._nRows), _nCols(m_._nCols) {

	_matrix = new double*[_nRows];
	for (size_t i = 0; i < _nRows; i++)
	{
		_matrix[i] = new double[_nCols];
		for (size_t j = 0; j < _nCols; j++)
		{
			_matrix[i][j] = m_._matrix[i][j];
		}
	}
}

ostream& operator<<(ostream& os_, const Matrix& m_) {
	string sep;
	for (size_t i = 0; i < m_._nRows; i++)
	{
		sep = "";
		for (size_t j = 0; j < m_._nCols; j++)
		{
			os_ << sep << m_._matrix[i][j];
			sep = " , ";
		}
		os_ << "\n";
	}
	return os_;
}

Matrix Matrix::operator+(const Matrix& m_) {
	if (_nRows != m_._nRows || _nCols != m_._nCols) {
		MatrixError("addition is not possible");
	}
	Matrix m(_nRows, _nCols);
	for (size_t i = 0; i < _nRows; i++)
	{
		for (size_t j = 0; j < _nCols; j++)
		{
			m._matrix[i][j] = _matrix[i][j] + m_._matrix[i][j];
		}
	}
	return m;
}

void Matrix::operator=(const Matrix& m_) {
	if (_nRows != m_._nRows || _nCols != m_._nCols) {
		for (size_t i = 0; i < _nRows; i++)
		{
			delete[] _matrix[i];
		}
		delete[] _matrix;

		_nRows = m_._nRows;
		_nCols = m_._nCols;
		_matrix = new double*[_nRows];
		for (size_t i = 0; i < _nRows; i++)
		{
			for (size_t j = 0; j < _nCols; j++)
			{
				_matrix[i] = new double[_nCols];
			}
		}
	
	}
	for (size_t i = 0; i < m_._nRows; i++)
	{
		for (size_t j = 0; j < m_._nCols; j++)
		{
			_matrix[i][j] = m_._matrix[i][j];
		}
	}
}

//C = A * B, ha A (this) k*L méretû, B (m_) L*m méretû, a C (m) az k * m méretû lesz
Matrix Matrix::operator*(const Matrix& m_) {
	if (this->_nCols != m_._nRows) {
		throw MatrixError("matrix multiplication error");
	}

	Matrix m(this->_nRows, m_._nCols);
	for (size_t i = 0; i < m._nRows; i++)
	{
		for (size_t j = 0; j < m._nCols; j++)
		{
			double sum = 0;
			for (size_t k = 0; k < this->_nCols; k++)
			{
				sum += this->_matrix[i][k] * m_._matrix[k][j];
			}
			m._matrix[i][j] = sum;
		}
	}
	return m;
}

void Matrix::operator+=(const Matrix& m_) {
	if (_nRows != m_._nRows || _nCols != m_._nCols) {
		MatrixError("matrix addition error");
	}

	for (size_t i = 0; i < _nRows; i++)
	{
		for (size_t j = 0; j < _nCols; j++)
		{
			_matrix[i][j] += m_._matrix[i][j];

		}
	}
}

Matrix Matrix::operator+(int number) {
	Matrix m(_nRows, _nCols);
	m._matrix = new double*[_nRows];
	for (size_t i = 0; i < _nRows; i++)
	{
		m._matrix[i] = new double[_nCols];
		for (size_t j = 0; j < _nCols; j++)
		{
			m._matrix[i][j] = _matrix[i][j] + number;
		}
	}
	return m;
}

Matrix Matrix::operator*(int number) {
	Matrix m(_nRows, _nCols);
	m._matrix = new double*[_nRows];
	for (size_t i = 0; i < m._nRows; i++)
	{
		m._matrix[i] = new double[_nCols];
		for (size_t j = 0; j < m._nCols; j++)
		{
			m._matrix[i][j] = _matrix[i][j] * number;
		}
	}
	return m;
}