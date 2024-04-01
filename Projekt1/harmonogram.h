#ifndef HARMONOGRAM_H //tak samo jak w czas.h
#define HARMONOGRAM_H

#include "czas.h"

class Harmonogram {
private:
    Czas* czasy; // dynamiczna tablica czasów
    int rozmiar; // aktualny rozmiar tablicy
    int pojemnosc; // maksymalna pojemnoœæ tablicy

    void powiekszTablice(); // Prywatna metoda pomocnicza do zwiêkszania rozmiaru tablicy

public:
    Harmonogram(int pojemnosc_poczatkowa = 10); // Konstruktor
    Harmonogram(const Harmonogram& other); // Konstruktor kopiuj¹cy
    Harmonogram& operator=(const Harmonogram& other); // Operator przypisania
    ~Harmonogram(); // Destruktor

    void dodajCzas(const Czas& czas); // Metoda dodaj¹ca czas do zestawienia
    int iloscCzasow() const; // Metoda zwracaj¹ca iloœæ czasów w zestawieniu
    Czas& operator[](int index); // Metoda zwracaj¹ca referencjê do konkretnego czasu w zestawieniu
    Czas sumaCzasow() const; // Metoda zsumowuj¹ca wszystkie czasy w zestawieniu
    void wypiszZestawienie() const; // Metoda wypisuj¹ca ca³e zestawienie

    Harmonogram kopijNczasow(int n) const; // Metoda tworz¹ca kopiê zawieraj¹c¹ tylko pierwsze n czasów
    Harmonogram kopijCzasyDoZakresu(const Czas& zakres) const; // Metoda tworz¹ca kopiê zawieraj¹c¹ tylko czasy, których suma mieœci siê w podanym zakresie

};

#endif
