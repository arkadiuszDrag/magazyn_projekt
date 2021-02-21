// Created by Arkadiusz Drąg on 15/12/2020.
#include <iostream>
#include "Exceptions.h"

#ifndef DRAGARKADIUSZ_ETAP1_PRODUKT_H
#define DRAGARKADIUSZ_ETAP1_PRODUKT_H

//template<typename T>
class Produkt {
protected:
    int ID;
    static int idGenerator;
    void copyString(const char *src, char **dst);


public:
    Produkt(const Produkt &p) : ID(p.ID) {}
    Produkt();
    virtual ~Produkt() = 0;

    virtual Produkt &operator-=(int ilosc) = 0;
    virtual Produkt &operator+=(int ilosc) = 0;
    virtual Produkt &operator-=(float ilosc) = 0;
    virtual Produkt &operator+=(float ilosc) = 0;

    virtual int getID() = 0;// const {return ID;}
    virtual float pobierzIloscFloat() = 0;
    virtual int pobierzIloscInt() = 0;


    virtual void wypiszProdukt() = 0;
    virtual void wypiszIlosc() = 0;
    virtual Produkt* podziel (int ilosc) = 0;
    virtual Produkt* podziel(float ilosc) = 0;

    virtual void scal(Produkt *p) = 0;




};


#endif //DRAGARKADIUSZ_ETAP1_PRODUKT_H
