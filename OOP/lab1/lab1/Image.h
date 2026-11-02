#pragma once
#include <iostream>
class Image
{
	int** m;
	char* naziv;
	int row=0;
	int column=0;

public:
	Image()
	{
		m = new int* [0];
		m = nullptr;
		naziv = nullptr;
	};

	Image(int row, int column)
	{
		
		this->row=row;
		this->column=column;
		naziv = nullptr;

		m = new int* [row];
		for (int i = 0; i < row; i++)
		{
			m[i] = new int[column];
		}
	};
	
	/*Image(const Image& s)
	{
		this->row = s.row;
		this->column = s.column;
		naziv = nullptr;

		this->m = new int* [this->row];
		for (int i = 0; i < this->row; i++)
		{
			this->m[i] = new int[this->column];
		}

		for (int i = 0; i < this->row; i++)
		{
			for (int j = 0; j < this->column; j++)
			{
				this->m[i][j] = s.m[i][j];
			}
		}
	};*/

~Image()
	{
		for (int i = 0; i < row; i++)
		{
			delete[] m[i];
		}
		delete[] m;
		m = nullptr;
		delete[] naziv;
		naziv = nullptr;
		//isto za char*
	};
	inline void dimenzija()
	{
		std::cout<<"Matrica je dimenzija: " << row << " * " << column;
	};
	void invert();
	void ucitaj();
	void prikazi();
	void crop(int row_cropped, int column_cropped);
	inline void setter(int row, int column)
	{
		this->row = row;
		this->column = column;
	};
};