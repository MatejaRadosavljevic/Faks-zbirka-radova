#include "Image.h"
#include <iostream>
#include <cstring>
#include <stdexcept>

void Image::ucitaj()
 {
     int buffer;
     for (int i = 0; i < row; i++)
     {
         for (int j = 0; j < column; j++)
         {

             std::cout << "Unesi element na poziciji " << i + 1 << " , " << j + 1 << ": ";
             std::cin >> buffer;
             if (buffer == 0 || buffer == 1)
                 m[i][j] = buffer;
             else
             {
                 std::cout << "Netacan unos, vrednost mora biti 0 ili 1\n";
             j--;
             }
         }
     }
 }

 void Image::prikazi()
 {
     std::cout << "\n----------------------------------------\n";

     for (int i = 0; i < row; i++)
     {
         for (int j = 0; j < column; j++)
         {
             std::cout << m[i][j] << " ";
         }
         std::cout << "\n";
     }
 }


 void Image::invert()
{
     std::cout << "\n-----------------Invert-----------------\n";

    /* for (int i = 0; i < row; i++)
     {
         for (int j = 0; j < column; j++)
         {
             if(m[i][j]==1)
             std::cout << 0 << " ";
             if (m[i][j] == 0)
                 std::cout << 1 << " ";
         }
         std::cout << "\n";
     }*/
      for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            m[i][j] = 1 - m[i][j];
        }
    }
    
}
 void Image::crop(int row_cropped, int column_cropped)
 {
     if (row_cropped <= this->row && row_cropped > 0 && column_cropped <= this->column && column_cropped > 0) 
     {
         /*Image kopija = *this;

         this->row = row_cropped;
         this->column = column_cropped;
         // ili preko this->setter(rc,cc)

         for (int i = 0; i < this->row; i++)
         {
             for (int j = 0; j < this->column; j++)
             {
                 this->m[i][j] = kopija.m[i][j];
                 
             }
         }*/
         
         int** nova_m = new int* [row_cropped];

         for (int i = 0; i < row_cropped; i++)
         {
             nova_m[i] = new int[column_cropped];
             for (int j = 0; j < column_cropped; j++)
             {
                 nova_m[i][j] = this->m[i][j];
             }
         }
         for (int i = 0; i < this->row; i++)
         {
             delete[] this->m[i];
         }
         delete[] this->m;

         this->row = row_cropped;
         this->column = column_cropped;
         this->m = nova_m;
         
        
     }
     else { 
         std::cout << "Cropovane dimenzije vece od pocetnih"; 
     return; };
 }

 void Image::preklop(Image* s1, Image* s2)
 {
     for (int i = 0; i < row; i++)
     {
         for (int j = 0; j < column; j++)
         {
             if (s1->m[i][j] == 1 || s2->m[i][j] == 1)
             {
                 std::cout << " 1";
             }
             else std::cout << " 0";
         }
         std::cout << "\n";
     }
 }
 
 void Image::rotiraj90()
 {
     if (m == nullptr)
         return;

     int** novaM = new int* [column];

     for (int i = 0; i < column; i++)
     {
         novaM[i] = new int[row];
     }


     for (int i = 0; i < row; i++)
     {
         for (int j = 0; j < column; j++)
         {
             novaM[j][row - 1 - i] = m[i][j];
         }
     }

     for (int i = 0; i < row; i++)
     {
         delete[] m[i];
     }

     delete[] m;
     m = novaM;

     int temp = row;
     row = column;
     column = temp;
 }


 Image& Image::operator=(const Image& druga)
 {
    
     if (this == &druga)
         return *this;

     int** novaM = nullptr;

     if (druga.row > 0)
     {
         novaM = new int* [druga.row];

         for (int i = 0; i < druga.row; i++)
         {
             novaM[i] = new int[druga.column];

             for (int j = 0; j < druga.column; j++)
             {
                 novaM[i][j] = druga.m[i][j];
             }
         }
     }

     
     char* noviNaziv = nullptr;

     if (druga.naziv != nullptr)
     {
         size_t duzina = strlen(druga.naziv) + 1;
         noviNaziv = new char[duzina];
         strcpy_s(noviNaziv, duzina, druga.naziv);
     }

   
    // prebaci destruktor u f-ju this->~Image();

     if (m != nullptr)
     {
         for (int i = 0; i < row; i++)
             delete[] m[i];

         delete[] m;
     }

     delete[] naziv;

     m = novaM;
     naziv = noviNaziv;
     row = druga.row;
     column = druga.column;

     return *this;
 }

 std::istream& operator>>(std::istream& in, Image& slika)
 {
     int vrednost;

     for (int i = 0; i < slika.row; i++)
     {
         for (int j = 0; j < slika.column; j++)
         {
             in >> vrednost;

             if (!in)
                 return in;

             if (vrednost != 0 && vrednost != 1)
             {
                 in.setstate(std::ios::failbit);
                 return in;
             }

             slika.m[i][j] = vrednost;
         }
     }

     return in;
 }


 std::ostream& operator<<(std::ostream& out, const Image& slika)
 {
     out << "Dimenzije: "
         << slika.row << " x " << slika.column << "\n";

     for (int i = 0; i < slika.row; i++)
     {
         for (int j = 0; j < slika.column; j++)
         {
             out << slika.m[i][j] << " ";
         }

         out << "\n";
     }

     return out;
 }
