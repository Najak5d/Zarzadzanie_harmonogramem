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

Harmonogram::Harmonogram(const Harmonogram& other) : rozmiar(other.rozmiar), pojemnosc(other.pojemnosc) {
    czasy = new Czas[pojemnosc];
    for (int i = 0; i < rozmiar; ++i) {
        czasy[i] = other.czasy[i];
    }
}

// Funkcja do tworzenia kopii zawieraj�cej tylko pierwsze n czas�w
Harmonogram Harmonogram::kopijNczasow(int n) const {
    Harmonogram kopija;
    for (int i = 0; i < n && i < rozmiar; ++i) {
        kopija.dodajCzas(czasy[i]);
    }
    return kopija;
}
// Funkcja do tworzenia kopii zawieraj�cej tylko te czasy, kt�rych suma mie�ci si� w podanym zakresie
Harmonogram Harmonogram::kopijCzasyDoZakresu(const Czas& zakres) const {
    Harmonogram kopija;
    Czas suma;
    for (int i = 0; i < rozmiar; ++i) {
        if ((suma + czasy[i]) < zakres) {
            kopija.dodajCzas(czasy[i]);
            suma += czasy[i];
        }
        else {
            break;
        }
    }
    return kopija;
}