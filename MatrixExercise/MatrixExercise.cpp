// MatrixExercise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Matrix.h"

int main()
{
	Matrix a(3);
	a.randomFill(3);
	//cout << a;

	Matrix b(3);
	b.randomFill(3);
	Matrix c = a.operator+(b);
	//cout << c;

	Matrix d(4);
	d.randomFill(4);
	d = a;
	//cout << d;

	//Matrix e = a.operator*(b);
	//cout << e;

	Matrix f = a.operator+(4);
	cout << f;
	Matrix g = a.operator*(4);
	cout << g;

}

