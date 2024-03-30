#ifndef HARMONOGRAM_H
#define HARMONOGRAM_H

#include "czas.h"

class Harmonogram {
private:
    Czas* czasy; // dynamiczna tablica czas�w
    int rozmiar; // aktualny rozmiar tablicy
    int pojemnosc; // maksymalna pojemno�� tablicy

public:
    Harmonogram(int pojemnosc_poczatkowa = 10);// Konstruktor

    ~Harmonogram();// Destruktor

    void dodajCzas(const Czas& czas);// Metoda dodaj�ca czas do zestawienia

    int iloscCzasow() const;// Metoda zwracaj�ca ilo�� czas�w w zestawieniu

    Czas& operator[](int index);// Metoda zwracaj�ca referencj� do konkretnego czasu w zestawieniu

    Czas sumaCzasow() const;// Metoda zsumowuj�ca wszystkie czasy w zestawieniu

    void wypiszZestawienie() const;// Metoda wypisuj�ca ca�e zestawienie

private:
    void powiekszTablice();//prywatna metoda pomocnicza do zwi�kszania rozmiaru tablicy
};

#endif
