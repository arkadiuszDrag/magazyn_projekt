//
// Created by Arkadiusz Drąg on 15/12/2020.
//

#include <iostream>
#include "TowarSypki.h"
#include <string>
#include "Produkt.h"
#include <cstring>

TowarSypki::TowarSypki(const TowarSypki &t): Produkt(t) { //konstruktor kopiujacy
    copyString(t.nazwa, &this->nazwa);
    this->ilosc_kg = t.ilosc_kg;
}

TowarSypki::TowarSypki(const std::string &nazwa): TowarSypki::TowarSypki(nazwa.c_str()) {}

TowarSypki::TowarSypki(const char* nazwa): nazwa{nullptr}, ilosc_kg{0}, Produkt() {
    if (nazwa != nullptr) {
        this->nazwa = new char[strlen(nazwa)+1];
        copyString(nazwa, &this->nazwa);
    }
}

Produkt* TowarSypki::podziel(float ilosc) {
    TowarSypki* t = new TowarSypki (*this); //tworzony jest nowy wskaznik na dany element do zwrocenia
    t->ilosc_kg = ilosc;
    return t;
}

Produkt* TowarSypki::podziel(int ilosc) {
    TowarSypki* t = new TowarSypki (*this);
    t->ilosc_kg = static_cast<float>(ilosc);
    return t;
}

void TowarSypki::scal(Produkt *p) {
    this->ilosc_kg += p->pobierzIloscFloat(); // dodawana jest ilosc tworau z podanego produktu do danego elementu
    delete p;
}
