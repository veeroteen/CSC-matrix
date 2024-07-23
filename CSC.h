#pragma once
#include <vector>
#include <iostream>
#include <random>
#include <string>
#include <fstream>

template <typename T>
struct ValRow
{
	T val;
	size_t row;

	ValRow(T _val, size_t _row)
		: val(_val), row(_row) { }
};

template <typename T>
class CSC
{
	std::vector<ValRow<T>> VR;
	std::vector<size_t> col;

public:
	void generate(const size_t &size, const unsigned &sparseness)
	{

		std::srand(std::time(nullptr));
		for(size_t n = 0; n < size; n++)
		{

			ValRow<T> block(rand()%10, n);
			if (block.val)
			{
				VR.push_back(block);
			}

			for (size_t m = 1+n; m < size; m++)
			{

				if(rand()%100 <= sparseness)
				{
					block.val = rand()%10;
					
					if (block.val)
					{
						block.row = m;
						VR.push_back(block);
					}
				}
			}
			col.push_back(VR.size());
		}

		return;
	}

	void out(std::string &fileName)
	{
		std::vector<std::vector<T>> triangle;
		size_t colIter = 0;
		std::vector<T> column;
		column.resize(col.size(),0);

		size_t i = 0;
		while(i < VR.size())
		{
			if (i != col[colIter]) 
			{
				column[VR[i].row - colIter] = VR[i].val;
				i++;
			}
			if(i == col[colIter])
			{
				colIter++;
				triangle.push_back(column);
				column.clear();
				column.resize(col.size()-colIter, 0);
			}

		}

		std::ofstream file(fileName);
		for(size_t n = 0; n < triangle.size(); n++)
		{
			for (size_t m = 0; m < triangle.size(); m++)
			{

				if (n > m)
				{
					file << triangle[m][n - m] << ' ';
				}
				if (n == m)
				{
					file <<  triangle[n][0] << ' ';
				}
			}
			file << std::endl;
		}
		file.close();

		return;
	}

};