#include <iostream>
#include <random>
#include "CSC.h"

typedef double REAL;


int main()
{
	size_t size = 0;
	unsigned sparseness = 0;

	//std::cout << "Enter size of matrix and sparseness in 0-100\n";
	//std::cin >> size >> sparseness;
	
	CSC<int> c;
	c.generate(10, 10);
	c.print();







}