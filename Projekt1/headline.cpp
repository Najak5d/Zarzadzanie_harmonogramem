#include "headline.h"

Czas::Czas() {
    godzina = 0;
    minuta = 0;
    sekunda = 0;
}

Czas::Czas(int h, int m, int s) {
    ustawGodzine(h);
    ustawMinute(m);
    ustawSekunde(s);
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

void Czas::ustawSekunde(int s) {
    if (s >= 0 && s < 60) {
        sekunda = s;
    }
    else {
        std::cerr << "Niepoprawna wartoœæ sekundy\n";
    }
}

void Czas::ustawMinute(int m) {
    if (m >= 0 && m < 60) {
        minuta = m;
    }
    else {
        std::cerr << "Niepoprawna wartoœæ minuty\n";
    }
}

void Czas::ustawGodzine(int h) {
    if (h >= 0 && h < 24) {
        godzina = h;
    }
    else {
        std::cerr << "Niepoprawna wartoœæ godziny\n";
    }
}

void Czas::wyswietlCzas() const {
    std::cout << "Czas: " << godzina << ":" << minuta << ":" << sekunda << std::endl;
}