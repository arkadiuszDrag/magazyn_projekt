//
// Created by Arkadiusz Drąg on 15/12/2020.
//

#include <iostream>
#include "TowarCiekly.h"
#include <string>
#include <cstring>


TowarCiekly::TowarCiekly(const TowarCiekly &t): Produkt(t) { //konstruktor kopiujacy
    copyString(t.nazwa, &this->nazwa);
    this->ilosc_L = t.ilosc_L;
}

TowarCiekly::TowarCiekly(const std::string &nazwa): TowarCiekly::TowarCiekly(nazwa.c_str()) {}

TowarCiekly::TowarCiekly(const char* nazwa): nazwa{nullptr}, ilosc_L{0}, Produkt() {
    if (nazwa != nullptr) {
        this->nazwa = new char[strlen(nazwa)+1];
        copyString(nazwa, &this->nazwa);
    }
}

Produkt* TowarCiekly::podziel(float ilosc) {
    TowarCiekly* t = new TowarCiekly (*this);
    t->ilosc_L = ilosc;
    return t;
}

Produkt* TowarCiekly::podziel(int ilosc) {
    TowarCiekly* t = new TowarCiekly (*this);
    t->ilosc_L = static_cast<float>(ilosc);
    return t;
}

void TowarCiekly::scal(Produkt *p) {
    this->ilosc_L += p->pobierzIloscFloat();
    delete p;
}

