#ifndef HARMONOGRAM_H //tak samo jak w czas.h
#define HARMONOGRAM_H

#include "czas.h"

class Harmonogram {
private:
    Czas* czasy; // dynamiczna tablica czas�w
    int rozmiar; // aktualny rozmiar tablicy
    int pojemnosc; // maksymalna pojemno�� tablicy

    void powiekszTablice(); // Prywatna metoda pomocnicza do zwi�kszania rozmiaru tablicy

public:
    Harmonogram(int pojemnosc_poczatkowa = 10); // Konstruktor
    Harmonogram(const Harmonogram& other); // Konstruktor kopiuj�cy
    Harmonogram& operator=(const Harmonogram& other); // Operator przypisania
    ~Harmonogram(); // Destruktor

    void dodajCzas(const Czas& czas); // Metoda dodaj�ca czas do zestawienia
    int iloscCzasow() const; // Metoda zwracaj�ca ilo�� czas�w w zestawieniu
    Czas& operator[](int index); // Metoda zwracaj�ca referencj� do konkretnego czasu w zestawieniu
    Czas sumaCzasow() const; // Metoda zsumowuj�ca wszystkie czasy w zestawieniu
    void wypiszZestawienie() const; // Metoda wypisuj�ca ca�e zestawienie

    Harmonogram kopijNczasow(int n) const; // Metoda tworz�ca kopi� zawieraj�c� tylko pierwsze n czas�w
    Harmonogram kopijCzasyDoZakresu(const Czas& zakres) const; // Metoda tworz�ca kopi� zawieraj�c� tylko czasy, kt�rych suma mie�ci si� w podanym zakresie

};

#endif
