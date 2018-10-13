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
	//értékadás
	void operator=(const Matrix&);
	//mátrixok összeadása
	Matrix operator+(const Matrix&);
	//mátrixok szorzása
	Matrix operator*(const Matrix&);
	//mátrix összeadása
	void operator+=(const Matrix&);

	//minden eleméhez hozzáad x-et
	Matrix operator+(int);
	
	//minden elemét megszorozza x-el
	Matrix operator*(int);

private:
	int _nRows;
	int _nCols;
	double** _matrix;
};

