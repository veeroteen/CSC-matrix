#include <iostream>
#include <random>
#include "CSC.h"




int main()
{
	size_t size = 0;
	unsigned sparseness = 0;
	std::string fileName = "out.txt";
	std::cout << "Enter size of matrix and sparseness in 0-100\n";
	std::cin >> size >> sparseness;
	
	CSC<int> c;
	c.generate(size, sparseness);
	c.out(fileName);







}