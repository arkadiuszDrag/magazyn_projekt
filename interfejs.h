//
// Created by Arkadiusz Drąg on 23/11/2020.
//

#ifndef UNTITLED4_INTERFEJS_H
#define UNTITLED4_INTERFEJS_H
#include "Magazyn.h"
#include "Towar.h"
#include "TowarSypki.h"
#include "TowarCiekly.h"
#include "Produkt.h"
#include "Paleciak.h"





class interfejs {
    void interfejsGlowny(Magazyn &m, std::vector<Magazyn*> &vec, Paleciak *p, std::basic_istream<char> *input);
    void interfejsMagazyn(Magazyn &m,std::vector<Magazyn*> &vec, Paleciak &p, std::basic_istream<char> *input);
    std::string readString( std::basic_istream<char> *input);
    void dodajRodzajTowaru(Magazyn &m, std::basic_istream<char> *input); //dodaje rodzaj towaru do magazynu
    void usunRodzajTowaru(Magazyn &m, std::basic_istream<char> *input); //usuwa rodzaj towaru do magazynu
    void odbierzTowar(Magazyn &m, std::basic_istream<char> *input); //usuwa dana ilosc danego towaru z magazynu
    void przyjecieTowaru(Magazyn &m, std::basic_istream<char> *input); //dodaje dana ilosc danego towaru do magazynu
    void wyswietl(Magazyn &m); //wyswietla zawartosc towaru w magazynie
    void stworzMagazyn(std::vector<Magazyn*> &vec, std::basic_istream<char> *input); //tworzy magazyn
    void wejscieMagazynu(Magazyn *m, std::vector<Magazyn*> &vec, Paleciak *p, std::basic_istream<char> *input); //wejscie do magazynu na ktorym ustawiony jest wskaznik
    void odbierzZPaleciaka(Magazyn &m, Paleciak &p); //przenosi wszystkie towary z paleciaka do magazynu
    void zaladujNaPaleciaka(Magazyn &m, Paleciak &p, std::basic_istream<char> *input); //przenosi dany towar z magazynu do paleciaka
    void wyswietlPaleciaka(Paleciak &p); //wyswietla twowary znajdujace sie w paleciaku
    void wyswietlListeMagazynow(std::vector<Magazyn*> &vec); // wyswietla liste magazynow
    template<typename T> T readNumber(std::basic_istream<char> *input);

public:
    interfejs() {}
    void interfejsStart(std::basic_istream<char> *input); //uruchamia caly interfejs

};


#endif //UNTITLED4_INTERFEJS_H
