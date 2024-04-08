#include "czas.h"

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
        std::cerr << "BLAD, niepoprawne wartosci czasu!!!!!\n";//zabezpieczenie
    }
}

void Czas::ustawCzas(int m, int s) {
    if (m >= 0 && m < 60 && s >= 0 && s < 60) {
        minuta = m;
        sekunda = s;
    }
    else {
        std::cerr << "BLAD, niepoprawne wartosci czasu!!!!!\n";//zabezpieczenie
    }
}

void Czas::ustawCzas(int s) {
    if (s >= 0 && s < 60) {
        sekunda = s;
    }
    else {
        std::cerr << "BLAD, niepoprawne wartosci czasu!!!!!\n";//zabezpieczenie
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

    if (sekunda < 0) {
        sekunda += 60;
        minuta--;
    }
    if (minuta < 0) {
        minuta += 60;
        godzina--;
    }
    if (godzina < 0) {
        godzina += 24;
    }
    if (sekundy >= 60) {
        dodane_minuty += sekundy / 60;// dodaje minutê jesli sekundy s¹ wieksze lub rowne 60
    }

    minuta += dodane_minuty; // Dodaj dodatkowe minuty

    if (minuta >= 60) {
        int dodatkowe_godziny = minuta / 60;
        godzina += dodatkowe_godziny;//je¿li minuty przekraczaj¹ 59, zwieeksz godzinê i zmieniam minute
        minuta %= 60;
    }

    if (godzina >= 24) {
        godzina %= 24;    //jezli godziny przekraczaj¹ 23, zmieniam godzine
    }

    return *this;
}

Czas& Czas::operator+=(const Czas& czas) {
    sekunda += czas.sekunda;
    minuta += czas.minuta;
    godzina += czas.godzina;

    if (sekunda >= 60) {
        sekunda -= 60;
        minuta++;
    }
    if (minuta >= 60) {
        minuta -= 60;
        godzina++;
    }
    if (godzina >= 24) {
        godzina -= 24;
    }
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

bool Czas::operator>(const Czas& czas) const {
    if (godzina < czas.godzina)
        return true;
    else if (godzina == czas.godzina && minuta > czas.minuta)
        return true;
    else if (godzina == czas.godzina && minuta == czas.minuta && sekunda > czas.sekunda)
        return true;
    else
        return false;
}

bool Czas::operator<=(const Czas& czas) const {
    return (*this < czas || *this == czas);
}

bool Czas::operator>=(const Czas& czas) const {
    return (*this > czas || *this == czas);
}

bool Czas::operator!=(const Czas& czas) const {
    return !(*this == czas);
}

void Czas::wyswietlCzas() const {
    std::cout << "Czas: " << godzina << ":" << minuta << ":" << sekunda << std::endl;
}