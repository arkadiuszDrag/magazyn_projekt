//
// Created by Arkadiusz Drąg on 15/12/2020.
//
#include <iostream>
#include "Produkt.h"

#ifndef DRAGARKADIUSZ_ETAP1_TOWARCIEKLY_H
#define DRAGARKADIUSZ_ETAP1_TOWARCIEKLY_H

class TowarCiekly: public Produkt {
    char *nazwa;
    float ilosc_L;

public:
    explicit TowarCiekly(const TowarCiekly &t);

    explicit TowarCiekly(const std::string &nazwa);

    explicit TowarCiekly(const char *nazwa = nullptr);

    Produkt& operator+= (float ilosc) override {
        this->ilosc_L += ilosc;
        return *this;
    }

    Produkt& operator-= (float ilosc) override {
        this->ilosc_L -= ilosc;
        return *this;
    }

    float pobierzIloscFloat() override {return ilosc_L;}

    void wypiszProdukt() override {
        std::cout << "ID:"<< ID << " || Nazwa produktu: " << nazwa <<" || ilosc w Litrach: "<< ilosc_L << std::endl;
    }
    void wypiszIlosc() override { std::cout << ilosc_L << " litrów" << std::endl; }
    Produkt* podziel(float ilosc) override;
    void scal(Produkt *p) override;
    int getID() override {return ID;}

    Produkt &operator-=(int ilosc) override {
        this->ilosc_L -= ilosc;
        return *this;
    }
    Produkt &operator+=(int ilosc) override {
        this->ilosc_L += ilosc;
        return *this;
    }
    int pobierzIloscInt() override {return ilosc_L;}
    Produkt* podziel (int ilosc) override;


};

#endif //DRAGARKADIUSZ_ETAP1_TOWARCIEKLY_H
