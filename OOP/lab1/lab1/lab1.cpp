#include <iostream>
#include "Image.h"

void main()
{
    Image s1(3,3);

    s1.ucitaj();
    s1.prikazi();
    s1.dimenzija();
    s1.crop(2, 2);
    s1.prikazi();
    s1.dimenzija();
    s1.invert();
}
