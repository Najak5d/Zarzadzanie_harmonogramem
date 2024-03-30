#include "harmonogram.h"

Harmonogram::Harmonogram(int pojemnosc_poczatkowa) : rozmiar(0), pojemnosc(pojemnosc_poczatkowa) {// knstruktor
    czasy = new Czas[pojemnosc];
}

Harmonogram::~Harmonogram() {// destruktor
    delete[] czasy;
}

void Harmonogram::dodajCzas(const Czas& czas) {// metoda dodaj�ca czas do zestawienia
    if (rozmiar >= pojemnosc) {
        // jesli tablica jest pe�na, zwi�ksz jej rozmiar
        powiekszTablice();
    }
    czasy[rozmiar++] = czas;
}

int Harmonogram::iloscCzasow() const {// metoda zwracaj�ca ilo�� czas�w w zestawieniu
    return rozmiar;
}

Czas& Harmonogram::operator[](int index) {// metoda zwracaj�ca referencj� do konkretnego czasu w zestawieniu
    if (index < 0 || index >= rozmiar) {
        throw std::out_of_range("Indeks poza zakresem");
    }
    return czasy[index];
}

Czas Harmonogram::sumaCzasow() const {// metoda zsumowuj�ca wszystkie czasy w zestawieniu
    Czas suma;
    for (int i = 0; i < rozmiar; ++i) {
        suma += czasy[i];
    }
    return suma;
}

void Harmonogram::wypiszZestawienie() const {// Metoda wypisuj�ca ca�e zestawienie
    for (int i = 0; i < rozmiar; ++i) {
        czasy[i].wyswietlCzas();
    }
}

void Harmonogram::powiekszTablice() {// prywatna metoda pomocnicza do zwi�kszania rozmiaru tablicy
    pojemnosc *= 2;
    Czas* nowa_tablica = new Czas[pojemnosc];
    for (int i = 0; i < rozmiar; ++i) {
        nowa_tablica[i] = czasy[i];
    }
    delete[] czasy;
    czasy = nowa_tablica;
}