//
// Created by Arkadiusz Drąg on 19/11/2020.
//
#include <iostream>
#include "Towar.h"
#include <string>
#include <cstring>
//komentarze do funkcji sa w klasie TowarSypki poniewaz funkcje sa prawie takie same

Towar::Towar(const Towar &t): Produkt(t) { //konstruktor kopiujacy
    copyString(t.nazwa, &this->nazwa);
    this->liczba_sztuk = t.liczba_sztuk;
}

Towar::Towar(const std::string &nazwa): Towar::Towar(nazwa.c_str()) {}

Towar::Towar(const char* nazwa): nazwa{nullptr}, liczba_sztuk{0}, Produkt() {
    if (nazwa != nullptr) {
        this->nazwa = new char[strlen(nazwa)+1];
        copyString(nazwa, &this->nazwa);
    }
}

std::ostream & operator << (std::ostream &wyjscie, const Towar &t) {
    return wyjscie << "ID:"<< t.ID << " || Nazwa produktu: " << t.nazwa <<" || Liczba sztuk: "<< t.liczba_sztuk;
}



Produkt* Towar::podziel(int ilosc) {
    Towar* t = new Towar (*this);
    t->liczba_sztuk = ilosc;
    return t;
}

Produkt* Towar::podziel(float ilosc) {
    Towar* t = new Towar (*this);
    t->liczba_sztuk = static_cast<int>(ilosc);
    return t;
}

void Towar::scal(Produkt *p) {
    this->liczba_sztuk += p->pobierzIloscInt();
    delete p;
}
