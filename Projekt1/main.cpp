#include "czas.h"
#include "harmonogram.h"

int main() {
    Czas czas1(12, 30, 45);
    Czas czas2(1, 15, 10);

    czas1.wyswietlCzas();
    czas2.wyswietlCzas();

    Czas suma_czasow = czas1 + czas2;
    suma_czasow.wyswietlCzas();

    czas1 += 10;
    czas1.wyswietlCzas();

    if (czas1 == czas2)
        std::cout << "Czasy s¹ rowne. :)\n";
    else if (czas1 < czas2)
        std::cout << "Czas 1 jest mniejszy od czasu 2.\n";
    else
        std::cout << "Czas 1 jest wiekszy od czasu 2.\n";

    Harmonogram harmonogram;
    harmonogram.dodajCzas(czas1);
    harmonogram.dodajCzas(czas2);
    harmonogram.wypiszZestawienie();

    return 0;
} 