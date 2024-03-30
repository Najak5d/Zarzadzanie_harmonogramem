#include "czas.h"
#include "harmonogram.h"
#include <iostream>

int main() {
    // Tworzenie poczatkowych czasow
    Czas czas1(12, 30, 45);
    Czas czas2(1, 15, 10);

    // Tworzenie harmonogramu i dodawanie czasow
    Harmonogram harmonogram;
    harmonogram.dodajCzas(czas1);
    harmonogram.dodajCzas(czas2);

    // Menu opcji
    int wybor;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Wyswietl czas 1\n";
        std::cout << "2. Wyswietl czas 2\n";
        std::cout << "3. Sumuj czasy\n";
        std::cout << "4. Zwiekasz czas 1 o 10 sekund\n";
        std::cout << "5. Porownaj czasy\n";
        std::cout << "6. Wyswietl zestawienie\n";
        std::cout << "7. Utworz kopie pierwszych n czasow\n";
        std::cout << "8. Utworz kopie czasow, ktorych suma miesci sie w podanym zakresie\n";
        std::cout << "9. Zwiekasz wybrany czas o okreslona liczbe sekund\n";
        std::cout << "10. Wyjscie\n";
        std::cout << "Wybierz: ";
        std::cin >> wybor;

        switch (wybor) {
        case 1:
            czas1.wyswietlCzas();
            break;
        case 2:
            czas2.wyswietlCzas();
            break;
        case 3: {
            Czas suma_czasow = czas1 + czas2;
            std::cout << "Suma czasow: ";
            suma_czasow.wyswietlCzas();
            break;
        }
        case 4:
            czas1 += 10;
            std::cout << "Czas 1 po zwiekszeniu o 10 sekund: ";
            czas1.wyswietlCzas();
            break;
        case 5:
            if (czas1 == czas2)
                std::cout << "Czasy sa rowne. :)\n";
            else if (czas1 < czas2)
                std::cout << "Czas 1 jest mniejszy od czasu 2.\n";
            else
                std::cout << "Czas 1 jest wiekszy od czasu 2.\n";
            break;
        case 6:
            harmonogram.wypiszZestawienie();
            break;
        case 7: {
            int n;
            std::cout << "Podaj liczbe czasow do skopiowania: ";
            std::cin >> n;
            Harmonogram kopia = harmonogram.kopijNczasow(n);
            kopia.wypiszZestawienie();
            break;
        }
        case 8: {
            int h, m, s;
            std::cout << "Podaj maksymalny zakres sumy w formacie GG MM SS: ";
            std::cin >> h >> m >> s;
            Czas zakres(h, m, s);
            Harmonogram kopia = harmonogram.kopijCzasyDoZakresu(zakres);
            kopia.wypiszZestawienie();
            break;
        }
        case 9: {
            int indeks, sekundy;
            std::cout << "Podaj indeks czasu do zwiekszenia: ";
            std::cin >> indeks;
            std::cout << "Podaj liczbe sekund do dodania: ";
            std::cin >> sekundy;
            harmonogram[indeks] += sekundy;
            harmonogram.wypiszZestawienie();
            break;
        }
        case 10:
            std::cout << "Zamykanie...\n";
            break;
        default:
            std::cout << "Niepoprawny wybor\n";
        }
    } while (wybor != 10);

    return 0;
}
