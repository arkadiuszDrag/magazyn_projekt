#include "Towar.h"
#include "Magazyn.h"
#include "interfejs.h"
#include "Produkt.h"
#include <iostream>

#include "iosfwd"
#include <fstream>

std::basic_istream<char> *input;

int main(int argc, char** argv) {

    input = &std::cin;

    if (argc == 2) {
        auto file = new std::ifstream(argv[1], std::ios_base::in);
        input = file;
    } else {
        std::cerr << "Blad! Nie ma pliku wesciowego.";
    }
    interfejs system;
    system.interfejsStart(input);
}
