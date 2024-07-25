#pragma once
#include <vector>
#include <iostream>
#include <random>


#define MAXVALUE 9


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
	void generate(const size_t &size, const unsigned short &sparseness)
	{
		float count = size * (size - 1) / 2;
		float left = count * sparseness/100;
		float chance = sparseness;

		float tan = (100 - chance) ? (100 - chance) / ((100 / chance) - 1) : 1;
		
		std::srand(std::time(nullptr));
		for(size_t n = 0; n < size; n++)
		{

			ValRow<T> block(rand() % (MAXVALUE + 1), n);
			if (block.val)
			{
				VR.push_back(block);
			}

			for (size_t m = 1+n; m < size && left > 0 ; m++)
			{

				if(rand()%100 < chance)
				{
					block.val = rand() % (MAXVALUE) + 1;
					
					if (block.val)
					{
						block.row = m;
						VR.push_back(block);
					}

					left--;
					count--;
					chance = left / count*100;
					tan = (100.f - chance) ? (100.f - chance) / ((100.f / chance)-1) : 1;
				}
				else
				{
					count--;
					chance += tan;
				}
			}
			col.push_back(VR.size());
		}

		return;
	}

	void out(std::string& fileName) 
	{
		std::ofstream file(fileName);
		for(auto &a : VR)
		{
			file << a.val << " ";
		}
		file << std::endl;
		for (auto& a : VR)
		{
			file << a.row << " ";
		}
		file << std::endl;
		for (auto& a : col)
		{
			file << a << " ";
		}
		file << std::endl;
		file.close();
	}
	
};