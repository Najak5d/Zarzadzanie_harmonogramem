#ifndef HARMONOGRAM_H //tak samo zabezpieczenie jak w czas.h
#define HARMONOGRAM_H

#include "czas.h"

class Harmonogram {
private:
    Czas* czasy; // dynamiczna tablica czasow
    int rozmiar; // aktualny rozmiar tablicy
    int pojemnosc; // maksymalna pojemnossc tablicy

    void powiekszTablice(); // prywatna metoda pomocnicza do zwiêkszania rozmiaru tablicy

public:
    Harmonogram(int pojemnosc_poczatkowa = 10); // Konstruktor
    Harmonogram(const Harmonogram& kopia); // Konstruktor kopiuj¹cy
    Harmonogram& operator=(const Harmonogram& kopia); // Operator przypisania
    ~Harmonogram(); // Destruktor

    void dodajCzas(const Czas& czas); // Metoda ktora dodaje czas do zestawienia
    int iloscCzasow() const; // Metoda ktora zwraca ilosc czasow w zestawieniu
    Czas& operator[](int indeks); // Metoda zwracaj¹ca referencjê do konkretnego czasu w zestawieniu
    Czas sumaCzasow() const; // Metoda sumowuj¹ca wszystkie czasy w zestawieniu
    void wypiszZestawienie() const; // Metoda wypisuje nam cale zestawienie

    Harmonogram kopiujNczasow(int n) const; // Metoda tworzaca kopie zawierajaca tylko pierwsze n czasow
    Harmonogram kopijCzasyDoZakresu(const Czas& zakres) const; // Metoda tworz¹ca kopiê zawieraj¹c¹ tylko czasy, których suma mieœci siê w podanym zakresie

};

#endif
