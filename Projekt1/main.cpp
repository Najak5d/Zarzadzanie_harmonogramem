#include "headline.h"

int main() {
    Czas czas1(12, 30, 45);// utworzenie obiektu czasu
    Czas czas2(1, 15, 10);

    czas1.wyswietlCzas();// wyswietlenie czasu
    czas2.wyswietlCzas();

    Czas suma_czasow = czas1 + czas2;// testowanie dodanych funkcji
    suma_czasow.wyswietlCzas();

    czas1 += 10;
    czas1.wyswietlCzas();

    if (czas1 == czas2)
        std::cout << "Czasy s¹ rowne. :)\n";
    else if (czas1 < czas2)
        std::cout << "Czas 1 jest mniejszy od czasu 2.\n";
    else
        std::cout << "Czas 1 jest wiekszy od czasu 2.\n";

    return 0;
}