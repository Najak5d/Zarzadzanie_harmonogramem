#include "headline.h"

Czas::Czas() {
    godzina = 0;
    minuta = 0;
    sekunda = 0;
}

Czas::Czas(int h, int m, int s) {
    ustawCzas(h, m, s);
}

int Czas::pobierzSekunde() const {
    return sekunda;
}

int Czas::pobierzMinute() const {
    return minuta;
}

int Czas::pobierzGodzine() const {
    return godzina;
}

void Czas::ustawCzas(int h, int m, int s) {
    if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60) {
        godzina = h;
        minuta = m;
        sekunda = s;
    }
    else {
        std::cerr << "Niepoprawne wartosci czasu\n";
    }
}

void Czas::ustawCzas(int m, int s) {
    if (m >= 0 && m < 60 && s >= 0 && s < 60) {
        minuta = m;
        sekunda = s;
    }
    else {
        std::cerr << "Niepoprawne wartosci czasu\n";//zabezpieczenie
    }
}

void Czas::ustawCzas(int s) {
    if (s >= 0 && s < 60) {
        sekunda = s;
    }
    else {
        std::cerr << "Niepoprawne wartosci czasu\n";//zabezpieczenie
    }
}

Czas Czas::operator+(const Czas& czas) const {
    int suma_godzin = godzina + czas.godzina;
    int suma_minut = minuta + czas.minuta;
    int suma_sekund = sekunda + czas.sekunda;

    if (suma_sekund >= 60) {
        suma_minut++;
        suma_sekund -= 60;
    }
    if (suma_minut >= 60) {
        suma_godzin++;
        suma_minut -= 60;
    }
    if (suma_godzin >= 24) {
        suma_godzin -= 24;
    }

    return Czas(suma_godzin, suma_minut, suma_sekund);
}

Czas& Czas::operator+=(int sekundy) {
    int dodane_godziny = sekundy / 3600;
    sekundy %= 3600;
    int dodane_minuty = sekundy / 60;
    sekundy %= 60;

    godzina = (godzina + dodane_godziny) % 24;
    minuta = (minuta + dodane_minuty) % 60;
    sekunda = (sekunda + sekundy) % 60;

    return *this;
}

bool Czas::operator==(const Czas& czas) const {
    return (godzina == czas.godzina && minuta == czas.minuta && sekunda == czas.sekunda);
}

bool Czas::operator<(const Czas& czas) const {
    if (godzina < czas.godzina)
        return true;
    else if (godzina == czas.godzina && minuta < czas.minuta)
        return true;
    else if (godzina == czas.godzina && minuta == czas.minuta && sekunda < czas.sekunda)
        return true;
    else
        return false;
}

void Czas::wyswietlCzas() const {
    std::cout << "Czas: " << godzina << ":" << minuta << ":" << sekunda << std::endl;
}