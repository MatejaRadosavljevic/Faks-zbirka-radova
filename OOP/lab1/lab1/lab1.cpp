#include <iostream>
#include "Image.h"

int main()
{
    Image* s1 = new Image(3, 3);
    Image* s2 = new Image(3, 3);

    std::cout << "Unesi prvu sliku:\n";

    if (!(std::cin >> *s1))
    {
        delete s1;
        delete s2;
        return 1;
    }

    std::cout << "Unesi drugu sliku:\n";

    if (!(std::cin >> *s2))
    {
        delete s1;
        delete s2;
        return 1;
    }

    s1->invert();
    s2->invert();

    std::cout << *s1 << *s2;

    s2->preklop(s1, s2);

    delete s1;
    delete s2;

    return 0;
}