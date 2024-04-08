#ifndef CZAS_H //jesli czas.h nie zostal jeszcze zdefiniowany (jest to zabezpieczenie naglowka)
#define CZAS_H //defininijemy czas.h

#include <iostream>

class Czas {
private:
    int sekunda;
    int minuta;
    int godzina;

    //prywatne akcesory do ustawiania wartosci atrybutow
    void ustawCzas(int h, int m, int s);
    void ustawCzas(int m, int s);
    void ustawCzas(int s);

public:
    Czas(); // konstruktor domyslny
    Czas(int h, int m, int s); // konstruktor z parametrami
    // destruktor nie jest wymagany bo nie alokuje dynamicznych zasobow pamieci
    // akcesory do pobierania wartosci atrybutow
    int pobierzSekunde() const; // akcesor
    int pobierzMinute() const; // akcesor
    int pobierzGodzine() const; // akcesor

    // operatory
    Czas operator+(const Czas& czas) const; // operator dodawania czasow
    Czas& operator+=(int sekundy); // op zwiekszania czasu o sekundy
    Czas& operator+=(const Czas& czas);//op zwiekszania czasow
    bool operator==(const Czas& czas) const; // op rownosci
    bool operator<(const Czas& czas) const; // op mniejszosci
    bool operator>(const Czas& czas) const; // op wiekszosci
    // operatory uzywajace isteniacych operatorow
    bool operator<=(const Czas& czas) const;
    bool operator>=(const Czas& czas) const;
    bool operator!=(const Czas& czas) const; //op nierownosci 

    void wyswietlCzas() const;    // metoda do wyswietlania czasu
};

#endif//konczymy indef