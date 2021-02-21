#include <iostream>
#include "Produkt.h"

#ifndef DRAGARKADIUSZ_ETAP1_TOWARSYPKI_H
#define DRAGARKADIUSZ_ETAP1_TOWARSYPKI_H

class TowarSypki: public Produkt {
    char *nazwa;
    float ilosc_kg;

public:
    explicit TowarSypki(const TowarSypki &t);

    explicit TowarSypki(const std::string &nazwa);

    explicit TowarSypki(const char *nazwa = nullptr);


    Produkt& operator+= (float ilosc) override {
        this->ilosc_kg += ilosc;
        return *this;
    }

    Produkt& operator-= (float ilosc) override {
        this->ilosc_kg -= ilosc;
        return *this;
    }

    float pobierzIloscFloat() override {return ilosc_kg;}
    void wypiszProdukt() override {
        std::cout << "ID:"<< ID << " || Nazwa produktu: " << nazwa <<" || ilosc w kilogramach: "<< ilosc_kg << std::endl;
    }
    void wypiszIlosc() override { std::cout << ilosc_kg << " kg" << std::endl; }
    Produkt* podziel(float ilosc) override; //wydziela dana ilosc towaru do nowego zwracanego towaru
    void scal(Produkt *p) override; //dodaje ilosc towaru do danego z podanego towaru
    int getID() override {return ID;}

    Produkt &operator-=(int ilosc) override {
        this->ilosc_kg -= ilosc;
        return *this;
    }
    Produkt &operator+=(int ilosc) override {
        this->ilosc_kg += ilosc;
        return *this;
    }
    int pobierzIloscInt() override {return ilosc_kg;}
    Produkt* podziel (int ilosc) override;





};

#endif //DRAGARKADIUSZ_ETAP1_TOWARSYPKI_H
