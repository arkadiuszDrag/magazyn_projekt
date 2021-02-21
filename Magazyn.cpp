//
// Created by Arkadiusz Drąg on 19/11/2020.
//
#include "Magazyn.h"
#include "Exceptions.h"

Magazyn::Magazyn(const std::string &nazwa): nazwaMagazynu{nazwa} {}

void Magazyn::dodajTowar(Produkt* t) {
    t_vec.insert(t_vec.begin(), t);
}

void Magazyn::print() {
    for (int i = 0; i < t_vec.size(); i++) {
        t_vec[i]->wypiszProdukt();
    }
}

void Magazyn::usunTowar(int id) {
    int index;
    try {
        index = getIndexOfID(id); //wyciagamy indeks elementu o podanym id
    }
    catch(IDError &ex) {
        std::cerr << "ID Error: " + ex.message  << std::endl;
    }
    t_vec.erase(t_vec.begin() + index); //usuwamy element o znalezionym indeksie
}

int Magazyn::getIndexOfID(int id) {
    for ( int i = 0; i < t_vec.size(); i++ ) {
        if (id == t_vec[i]->getID())
            return i; //jesli element trafil na podane id elementu to zwracam index tego elementu
    }
    throw IDError();
}

template<typename T> void Magazyn::wydaj(int id, T ilosc, Paleciak &p) {
    int index;
    try {
        index = getIndexOfID(id);
    }
    catch(IDError &ex) {
        std::cerr << "ID Error: " + ex.message  << std::endl;
    }

    p.dodajProdukt(t_vec[index]->podziel(ilosc));
    *t_vec[index] -= ilosc;

}

template void Magazyn::wydaj<int>(int id, int ilosc, Paleciak &p);
template void Magazyn::wydaj<float>(int id, float ilosc, Paleciak &p);


//void Magazyn::wydaj(int id, float ilosc, Paleciak &p) {
//    int index = getIndexOfID(id);
//    p.dodajProdukt(t_vec[index]->podziel(ilosc));
//    *t_vec[index] -= ilosc;
//}
//
//void Magazyn::wydaj(int id, int ilosc, Paleciak &p) {
//    int index = getIndexOfID(id);
//    Produkt *produkt = t_vec[index]->podziel(ilosc);
//    p.dodajProdukt(produkt);
//    *t_vec[index] -= ilosc;
//}

Produkt* Magazyn::getEle(int id) {
    int index;
    try {
        index = getIndexOfID(id);
    }
    catch(IDError &ex) {
        std::cerr << "ID Error: " + ex.message  << std::endl;
    }
    return t_vec[index];
}

bool Magazyn::idExists(int id) {
    for(int i = 0; i < t_vec.size(); i++) {
        if (id == t_vec[i]->getID()) {
            return true;
        }
    }
    throw IDError();
}

void Magazyn::przyjmij(Paleciak &p) {
    for(int i = 0; i < p.getSize(); i++) {
            if (idExists(p[i]->getID())) {
                try {
                    t_vec[getIndexOfID(p[i]->getID())]->scal(p[i]);
                }
                catch (IDError &ex) {
                    std::cerr << "ID Error: " + ex.message << std::endl;
                }

        } else {
            dodajTowar(p[i]);
            try {
                t_vec[getIndexOfID(p[i]->getID())]->scal(p[i]);
            }
            catch(IDError &ex) {
                std::cerr << "ID Error: " + ex.message  << std::endl;
            }
        }
        p.usunProdukt(i);
    }
}
