//
// Created by Arkadiusz Drąg on 19/11/2020.
//
#include <iostream>
#include <vector>
#include "Towar.h"
#include "TowarSypki.h"
#include "TowarCiekly.h"
#include "Produkt.h"
#include "Paleciak.h"
#include <string>
#include <cstdio>

#ifndef UNTITLED4_MAGAZYN_H
#define UNTITLED4_MAGAZYN_H


class Magazyn {
    std::vector<Produkt*> t_vec;
    std::string nazwaMagazynu;

public:
//    struct IDError: public ChooseError {



    explicit Magazyn(const std::string &nazwa);

    Magazyn() = default;
    template<typename T> void wydaj(int id, T ilosc, Paleciak &p);

    int getIndexOfID(int id); //wyciaga nam element wektora o podanym id
    bool idExists(int id);
    void print(); //wyswietla zawartosc wektora
    void dodajTowar(Produkt *t); //dodaje element Towar do magazynu
    void usunTowar(int id); //usuwa eleent Towar z magazynu
    int getSize() {return t_vec.size();} //zwraca wielkosc wektora
    bool isEmpty() {return t_vec.empty();} //sprawdza czy wektor jest pusty
    std::string getName() {return nazwaMagazynu;}
    Produkt* getEle(int id);
//    void wydaj(int id, float ilosc, Paleciak &p); // oddaje dany towar do paleciaka i usuwa go z magazynu
//    void wydaj(int id, int ilosc, Paleciak &p);
    void wyswietlInfo() {
        std::cout  <<nazwaMagazynu<< " || liczba rodzajow towaru w magazynie: " << t_vec.size() << std::endl;
    }
    void przyjmij(Paleciak &p);

    Produkt* operator[](int el) { return t_vec[el]; }
};




#endif //UNTITLED4_MAGAZYN_H
