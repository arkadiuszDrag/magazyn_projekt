#include <iostream>
#include "Produkt.h"


#ifndef UNTITLED4_TOWAR_H
#define UNTITLED4_TOWAR_H


class Towar: public Produkt{
    char* nazwa;
    int liczba_sztuk;

public:
    explicit Towar(const Towar &t);
    explicit Towar(const std::string &nazwa);
    explicit Towar(const char* nazwa = nullptr);

    Produkt& operator+= (int ilosc) override {
        this->liczba_sztuk += ilosc;
        return *this;
    }

    Produkt& operator-= (int ilosc) override {
        this->liczba_sztuk -= ilosc;
        return *this;
    }

    friend std::ostream & operator << (std::ostream &wyjscie, const Towar &t);

    int pobierzIloscInt() override { return liczba_sztuk; }//zwraca liczbe sztuk towaru
    void wypiszProdukt() override {
        std::cout << "ID:"<< ID << " || Nazwa produktu: " << nazwa <<" || liczba sztuk: "<< liczba_sztuk << std::endl;
    }

    void wypiszIlosc() override { std::cout << liczba_sztuk << " sztuk" << std::endl; }
    Produkt* podziel(int ilosc) override;
    void scal(Produkt *p) override;
    int getID() override {return ID;}

    Produkt &operator-=(float ilosc) override {
        this->liczba_sztuk -= ilosc;
        return *this;
    }
    Produkt &operator+=(float ilosc) override {
        this->liczba_sztuk += ilosc;
        return *this;
    }
    float pobierzIloscFloat() override { return liczba_sztuk; }
    Produkt* podziel(float ilosc) override;

};


#endif //UNTITLED4_TOWAR_H
