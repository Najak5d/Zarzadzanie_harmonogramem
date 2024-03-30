#include "harmonogram.h"

Harmonogram::Harmonogram(int pojemnosc_poczatkowa) : rozmiar(0), pojemnosc(pojemnosc_poczatkowa) {// knstruktor
    czasy = new Czas[pojemnosc];
}

Harmonogram::~Harmonogram() {// destruktor
    delete[] czasy;
}

void Harmonogram::dodajCzas(const Czas& czas) {// metoda dodaj¹ca czas do zestawienia
    if (rozmiar >= pojemnosc) {
        // jesli tablica jest pe³na, zwiêksz jej rozmiar
        powiekszTablice();
    }
    czasy[rozmiar++] = czas;
}

int Harmonogram::iloscCzasow() const {// metoda zwracaj¹ca iloœæ czasów w zestawieniu
    return rozmiar;
}

Czas& Harmonogram::operator[](int index) {// metoda zwracaj¹ca referencjê do konkretnego czasu w zestawieniu
    if (index < 0 || index >= rozmiar) {
        throw std::out_of_range("Indeks poza zakresem");
    }
    return czasy[index];
}

Czas Harmonogram::sumaCzasow() const {// metoda zsumowuj¹ca wszystkie czasy w zestawieniu
    Czas suma;
    for (int i = 0; i < rozmiar; ++i) {
        suma += czasy[i];
    }
    return suma;
}

void Harmonogram::wypiszZestawienie() const {// Metoda wypisuj¹ca ca³e zestawienie
    for (int i = 0; i < rozmiar; ++i) {
        czasy[i].wyswietlCzas();
    }
}

void Harmonogram::powiekszTablice() {// prywatna metoda pomocnicza do zwiêkszania rozmiaru tablicy
    pojemnosc *= 2;
    Czas* nowa_tablica = new Czas[pojemnosc];
    for (int i = 0; i < rozmiar; ++i) {
        nowa_tablica[i] = czasy[i];
    }
    delete[] czasy;
    czasy = nowa_tablica;
}