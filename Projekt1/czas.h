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

    // Akcesory do pobierania wartosci atrybutów
    int pobierzSekunde() const; // akcesor
    int pobierzMinute() const; // akcesor
    int pobierzGodzine() const; // akcesor

    // Operatory
    Czas operator+(const Czas& czas) const; // operator dodawania czasow
    Czas& operator+=(int sekundy); // operator zwiêkszania czasu o sekundy
    bool operator==(const Czas& czas) const; // operator rownoœci
    bool operator<(const Czas& czas) const; // operator mniejszoœci
   //mozna dodac wiecej operatorow metoda podobnie jak u gory

    void wyswietlCzas() const;    // metoda do wyœwietlania czasu
};
