#include "Produkt.h"
#include <iostream>
#include <vector>
#include "Towar.h"
#include "TowarSypki.h"
#include "TowarCiekly.h"


#ifndef DRAGARKADIUSZ_ETAP1_PALECIAK_H
#define DRAGARKADIUSZ_ETAP1_PALECIAK_H

class Paleciak {
    std::vector<Produkt*> p_vec;
    std::vector<Produkt*>::iterator it;

    float udzwig;
    static float aktualnyUdzwig;

public:
    explicit Paleciak(float udzwig): udzwig{udzwig} {}

    bool isEmpty() {return p_vec.empty();}
    int getIndexOfID(int id);
    Produkt* getEleWithID(int id);
    void dodajProdukt(Produkt *p);
    void usunProdukt(int index);
    void print();
    bool zwiekszAktualnyUdzwig(float waga);
    int getSize() {return p_vec.size();}
    int getUdzwig() {return udzwig;}
    float getAktualnyUdzwig() { return aktualnyUdzwig; }
    Produkt* operator[](int el) { return p_vec[el]; }
    bool idExists(int id);
    void cleanAktualnyUdzwig() {aktualnyUdzwig = 0;}

};

#endif //DRAGARKADIUSZ_ETAP1_PALECIAK_H
