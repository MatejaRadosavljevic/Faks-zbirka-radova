#include "Kolekcija.h"
#include <iostream>
#include <stdexcept>

Kolekcija::Kolekcija(int maxSlika)
{
    if (maxSlika < 0)
        throw std::invalid_argument("Neispravan kapacitet!");

    this->maxSlika = maxSlika;
    brojSlika = 0;

    slike = nullptr;

    if (maxSlika > 0)
    {
        slike = new Image[maxSlika];
    }
}


Kolekcija::~Kolekcija()
{
    delete[] slike;
    slike = nullptr;
}


bool Kolekcija::dodaj(const Image& slika)
{
    if (brojSlika >= maxSlika)
    {
        std::cout << "Kolekcija je puna!\n";
        return false;
    }

    slike[brojSlika] = slika;

    brojSlika++;

    return true;
}


void Kolekcija::stampaj(std::ostream& out) const
{
    out << "\n========== KOLEKCIJA ==========\n";

    for (int i = 0; i < brojSlika; i++)
    {
        out << "\nSlika broj " << i + 1 << ":\n";
        out << slike[i];
    }

    out << "\n===============================\n";
}
