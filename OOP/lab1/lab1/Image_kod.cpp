#include "Image.h"
#include <iostream>

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

     for (int i = 0; i < row; i++)
     {
         for (int j = 0; j < column; j++)
         {
             if(m[i][j]==1)
             std::cout << 0 << " ";
             if (m[i][j] == 0)
                 std::cout << 1 << " ";
         }
         std::cout << "\n";
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


 