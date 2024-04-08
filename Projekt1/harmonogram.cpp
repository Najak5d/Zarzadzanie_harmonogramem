#include "harmonogram.h"

Harmonogram::Harmonogram(int pojemnosc_poczatkowa) : rozmiar(0), pojemnosc(pojemnosc_poczatkowa) {// knstruktor
    czasy = new Czas[pojemnosc];
}

Harmonogram::~Harmonogram() {// destruktor
    delete[] czasy;
}

void Harmonogram::dodajCzas(const Czas& czas) {// metoda dodajaca czas do zestawienia
    if (rozmiar >= pojemnosc) {
        powiekszTablice();// jesli tablica jest pe³na to zwieksz jej rozmiar
    }
    czasy[rozmiar++] = czas;
}

int Harmonogram::iloscCzasow() const {
    return rozmiar;
}

Czas& Harmonogram::operator[](int indeks) {// metoda zwracajaca referencje do konkretnego czasu w zestawieniu
    if (indeks < 0 || indeks >= rozmiar) {
        throw std::out_of_range("Indeks poza zakresem");//Jesli indeks jest mniejszy ni¿ zero lub wiêkszy lub równy rozmiarowi zestawienia, zg³aszany jest wyj¹tek std::out_of_range z odpowiednim komunikatem.
    }
    return czasy[indeks];
}

Czas Harmonogram::sumaCzasow() const {// metoda sumujaca wszystkie czasy w zestawieniu
    Czas suma;
    for (int i = 0; i < rozmiar; ++i) {
        suma += czasy[i];
    }
    return suma;
}

void Harmonogram::wypiszZestawienie() const {// metoda wwypisuje nam wszystko
    for (int i = 0; i < rozmiar; ++i) {
        czasy[i].wyswietlCzas();
    }
}

void Harmonogram::powiekszTablice() {// prywatna metoda pomocnicza do zwiêkszania rozmiaru tablicy
    pojemnosc *= 2;//zwiekszam dwukrotnie
    Czas* nowa_tablica = new Czas[pojemnosc];
    for (int i = 0; i < rozmiar; ++i) {
        nowa_tablica[i] = czasy[i];//kopiuje wszystkie do nowej tablicy
    }
    delete[] czasy;
    czasy = nowa_tablica;
}

Harmonogram::Harmonogram(const Harmonogram& kopia) : rozmiar(kopia.rozmiar), pojemnosc(kopia.pojemnosc) {//konstrukotr kopiujacy
    czasy = new Czas[pojemnosc];
    for (int i = 0; i < rozmiar; ++i) {
        czasy[i] = kopia.czasy[i];
    }
}

Harmonogram& Harmonogram::operator=(const Harmonogram& kopia) {//operator przypisania
    if (this == &kopia) // sprawdzenie czy nie jest to samo
        return *this;
    delete[] czasy;// usun poprzednie czasy

    rozmiar = kopia.rozmiar;//skopiuj rozmiar
    pojemnosc = kopia.pojemnosc;//kopiuj pojemnosc
    czasy = new Czas[pojemnosc];//alokacja nowej talicy i kopia zawartosci
    for (int i = 0; i < rozmiar; ++i) {
        czasy[i] = kopia.czasy[i];
    }
    return *this; // zwracam referencje
}

Harmonogram Harmonogram::kopiujNczasow(int n) const {
    Harmonogram kopija;
    for (int i = 0; i < n && i < rozmiar; ++i) {
        kopija.dodajCzas(czasy[i]);
    }
    return kopija;
}

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