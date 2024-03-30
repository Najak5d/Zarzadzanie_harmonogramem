#ifndef HARMONOGRAM_H
#define HARMONOGRAM_H

#include "czas.h"

class Harmonogram {
private:
    Czas* czasy; // dynamiczna tablica czasów
    int rozmiar; // aktualny rozmiar tablicy
    int pojemnosc; // maksymalna pojemnoœæ tablicy

public:
    Harmonogram(int pojemnosc_poczatkowa = 10);// Konstruktor

    ~Harmonogram();// Destruktor

    void dodajCzas(const Czas& czas);// Metoda dodaj¹ca czas do zestawienia

    int iloscCzasow() const;// Metoda zwracaj¹ca iloœæ czasów w zestawieniu

    Czas& operator[](int index);// Metoda zwracaj¹ca referencjê do konkretnego czasu w zestawieniu

    Czas sumaCzasow() const;// Metoda zsumowuj¹ca wszystkie czasy w zestawieniu

    void wypiszZestawienie() const;// Metoda wypisuj¹ca ca³e zestawienie

private:
    void powiekszTablice();//prywatna metoda pomocnicza do zwiêkszania rozmiaru tablicy
};

#endif
