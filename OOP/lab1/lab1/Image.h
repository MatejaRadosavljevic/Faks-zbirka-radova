#pragma once
#include <iostream>
class Image
{
	int** m;
	char* naziv;
	int row = 0;
	int column = 0;

public:
	Image()
	{
		m = nullptr;
		naziv = nullptr;
		row = 0;
		column = 0;
	};

	Image(int row, int column)
	{
		this->row = row;
		this->column = column;
		naziv = nullptr;

		m = new int* [row];

		for (int i = 0; i < row; i++)
		{
			m[i] = new int[column] {};
		}
	};

	Image(const Image& s) //kopi konst.
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
		/*  ili
	m = nullptr;
    naziv = nullptr;
    row = 0;
    column = 0;

    *this = druga;*/
	};

	~Image()
	{
		//for (int i = 0; i < row; i++)
		//{
		//	delete[] m[i];
		//}
		//delete[] m;
		//m = nullptr;
		//delete[] naziv;
		//naziv = nullptr;
		////isto za char*

		if (m != nullptr)
		{
			for (int i = 0; i < row; i++)
			{
				delete[] m[i];
			}
			delete[] m;
		}
		m = nullptr;
		delete[] naziv;
		naziv = nullptr;
		row = 0;
		column = 0;
	};
	inline void dimenzija()
	{
		std::cout << "Matrica je dimenzija: " << row << " * " << column;
	};
	void invert();
	void ucitaj();
	void prikazi();
	void rotiraj90();
	void preklop(Image* s1, Image* s2);
	void crop(int row_cropped, int column_cropped);
	inline void setter(int row, int column)
	{
		this->row = row;
		this->column = column;
	};
	Image& operator=(const Image& druga);
	friend std::istream& operator>>(std::istream& in, Image& slika);
	friend std::ostream& operator<<(std::ostream& out, const Image& slika);
};