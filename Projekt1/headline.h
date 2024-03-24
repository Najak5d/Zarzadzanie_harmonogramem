#include <iostream>

class Czas {
private:
    int sekunda;
    int minuta;
    int godzina;

public:
    Czas(); // konstruktor domy�lny
    Czas(int h, int m, int s); // konstruktor z parametrami

    int pobierzSekunde() const;// akcesor
    int pobierzMinute() const;// akcesor
    int pobierzGodzine() const;// akcesor

    void ustawSekunde(int s);
    void ustawMinute(int m);
    void ustawGodzine(int h);
    void wyswietlCzas() const;    // metoda do wy�wietlania czasu
};