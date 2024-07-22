#pragma once
#include <vector>
#include <iostream>
#include <random>
#include <string>
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
		std::vector<std::string> strs;
		strs.resize(size, "");
		std::srand(10);//std::time(nullptr));
		for(size_t n = 0; n < size; n++)
		{

			ValRow<T> a(rand()%10, n);
			if (a.val)
			{
				VR.push_back(a);
			}
			strs[n] += std::to_string(a.val) + " ";


			for (size_t m = 1+n; m < size; m++)
			{

				if(rand()%101 <= sparseness)
				{
					ValRow<T> b(rand()%10, m);
					strs[m] += std::to_string(b.val) + " ";
					if (b.val)
					{
						VR.push_back(b);
					}
				}
				else
				{
					strs[m] += std::to_string(0) + " ";
				}
			}
			col.push_back(VR.size());
		}


		for(int i = 0; i < VR.size();i++)
		{
			std::cout << VR[i].val << ' ';
		}
		std::cout << std::endl;
		for (int i = 0; i < VR.size(); i++)
		{
			std::cout << VR[i].row << ' ';
		}
		std::cout << std::endl;
		for (int i = 0; i < col.size(); i++)
		{
			std::cout << col[i] << ' ';
		}
		std::cout << std::endl;
		for(auto a : strs)
		{
			std::cout << a << std::endl;
		
		}
		std::cout << std::endl;

	}

	void print()
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


		for(size_t n = 0; n < triangle.size(); n++)
		{
			for (size_t m = 0; m < triangle.size(); m++)
			{
				if (n < m)
				{
					std::cout << (triangle[n][m - n] != 0 ? triangle[n][m - n] : 0) << ' ';
				}
				if (n > m) 
				{
					std::cout << (triangle[m][n-m] != 0 ? triangle[m][n-m] : 0) << ' ';
				}
				if(n == m)
				{
					std::cout << (triangle[n][0] != 0 ? triangle[n][0] : 0) << ' ';
				}
			}
			std::cout << std::endl;
		}
	
	
	}



};