#pragma once
#include "Image.h"

class Kolekcija
{
    int maxSlika;
    int brojSlika;
    Image* slike;

public:
    Kolekcija(int maxSlika);
    ~Kolekcija();

    Kolekcija(const Kolekcija&) = delete;
    Kolekcija& operator=(const Kolekcija&) = delete;

    bool dodaj(const Image& slika);
    void stampaj(std::ostream& out = std::cout) const;
};
