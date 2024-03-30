#ifndef CZAS_H
#define CZAS_H

#include <iostream>

class Czas {
private:
    int sekunda;
    int minuta;
    int godzina;

    // prywatne akcesory do ustawiania wartosci atrybutow
    void ustawCzas(int h, int m, int s);
    void ustawCzas(int m, int s);
    void ustawCzas(int s);

public:
    Czas(); // konstruktor domyslny
    Czas(int h, int m, int s); // konstruktor z parametrami
    // destruktor nie jest wymagany?? bo nie alokuje dynamicznych zasobow pamieci?
    // akcesory do pobierania wartosci atrybutow
    int pobierzSekunde() const; // akcesor
    int pobierzMinute() const; // akcesor
    int pobierzGodzine() const; // akcesor

    // Operatory
    Czas operator+(const Czas& czas) const; // operator dodawania czasow
    Czas& operator+=(int sekundy); // operator zwi�kszania czasu o sekundy
    Czas& operator+=(const Czas& czas);
    bool operator==(const Czas& czas) const; // operator rowno�ci
    bool operator<(const Czas& czas) const; // operator mniejszo�ci

    void wyswietlCzas() const;    // metoda do wy�wietlania czasu
};

#endif
