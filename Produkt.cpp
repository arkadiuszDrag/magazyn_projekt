#include "Produkt.h"
#include <string>
#include <iostream>
#include <cstring>

int Produkt::idGenerator = 0;

void Produkt::copyString(const char *src, char **dst) {
    *dst = new char[ strlen(src) +1 ];
    strcpy(*dst, src);
}

Produkt::Produkt(): ID{idGenerator++} {
    std::cout<<"Konstruktor Produkt"<<std::endl;
}

Produkt::~Produkt() {}