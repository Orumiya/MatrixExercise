#include <iostream>

using namespace std;

class Matrix
{
public:
	Matrix(int, int = 0);
	Matrix(const Matrix&);
	~Matrix();

	void randomFill(const int);
	friend ostream& operator<<(ostream&, const Matrix&);
	//�rt�kad�s
	void operator=(const Matrix&);
	//m�trixok �sszead�sa
	Matrix operator+(const Matrix&);
	//m�trixok szorz�sa
	Matrix operator*(const Matrix&);
	//m�trix �sszead�sa
	void operator+=(const Matrix&);

	//minden elem�hez hozz�ad x-et
	Matrix operator+(int);
	
	//minden elem�t megszorozza x-el
	Matrix operator*(int);

private:
	int _nRows;
	int _nCols;
	double** _matrix;
};

