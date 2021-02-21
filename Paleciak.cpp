#include "Paleciak.h"
#include <cstring>

float Paleciak::aktualnyUdzwig = 0;

void Paleciak::dodajProdukt(Produkt *p) {
    it = p_vec.end();
    p_vec.insert(it, p);
}

void Paleciak::usunProdukt(int index) {
    p_vec.erase(p_vec.begin() + index); //usuwamy element o znalezionym indeksie
}

bool Paleciak::zwiekszAktualnyUdzwig(float waga) {
    if(udzwig >= aktualnyUdzwig + waga) { //jezeli aktualny udzwig po dodaniu nowej wagi jest mniejszy lub rowny niz maksymalny udzwig paleciaka to waga zostaje dodana do aktualnego udzwigu i zwarana jest prawda
        aktualnyUdzwig += waga;
        return true;
    }
    else {
        return false; // jezeli waga jest za duza to zwracany jest falsz
    }
}

void Paleciak::print() {
    if(isEmpty()) {
        std::cout << "Paleciak jest pusty." << std::endl;
        return;
    }
    for(int i = 0; i < p_vec.size(); i++) {
        p_vec[i]->wypiszProdukt();
    }
}

int Paleciak::getIndexOfID(int id) {
    for ( int i = 0; i < p_vec.size(); i++ ) {
        if ( id == p_vec[i]->getID() ) return i; //jesli element trafil na podane id elementu to zwracam index tego elementu
    }
}

Produkt* Paleciak::getEleWithID(int id) {
    int index = getIndexOfID(id);
    return p_vec[index];
}

bool Paleciak::idExists(int id) {
    for(int i = 0; i < p_vec.size(); i++) {
        if(id == p_vec[i]->getID()) {
            return false;
        }
    }
    return false;
}