#include <regex>
#include "interfejs.h"
#include "Exceptions.h"


void interfejs::interfejsStart(std::basic_istream<char> *input) {

    std::vector<Magazyn*> m_vec;
    std::cout << "Podaj udzwig paleciaka w kg: ";
    float udzwig = readNumber<float>(input);
    Paleciak* p = new Paleciak(udzwig); //tworzy paleciaka o podanym udzwigu
    Magazyn* m = nullptr;
    interfejsGlowny(*m, m_vec, p, input);
}


void interfejs::interfejsGlowny(Magazyn &m, std::vector<Magazyn*> &vec, Paleciak *p, std::basic_istream<char> *input) {

    int choice;

    do {
        std::cout <<   "______________________________________\n"
                       "|---------====== MENU ======---------|\n"
                       "|                                    |\n"
                       "|0: Wyjscie z systemu                |\n"
                       "|1: Stworz magazyn                   |\n"
                       "|2: Wejscie do systemu magazynu      |\n"
                       "|3: Wyswietl liste magazynow         |\n"
                       "|                                    |\n"
                       "--------------------------------------\n"
                       " Wybierz akcje: ";

        try {
            choice = readNumber<int>(input);
        }
        catch(ChooseError &ex) {
            std::cerr << "Choose Error: " + ex.message  << std::endl;
            exit(0); //exit jest uzyty z uwagi na to, że odpalamy program z pliku wejsciowego i nie może na bierząco wychodzić z programu kiedy pojawi sie blad
        }

        switch (choice) {
            case 0:
                break;
            case 1:
                stworzMagazyn(vec, input );
                break;
            case 2:
                wejscieMagazynu(&m, vec, p, input);
                break;
            case 3:
                wyswietlListeMagazynow(vec);
                break;
            default:
                std::cout << "Niepoprawny wybór" << std::endl;
        }

    } while (choice != 0);
}

void interfejs::interfejsMagazyn(Magazyn &m, std::vector<Magazyn*> &vec, Paleciak &p, std::basic_istream<char> *input) {

    int choice;
    do {
        std::cout <<   "______________________________________\n"
                       "|-----====== MENU MAGAZYNU ======----|\n"
                       "|"; std::cout <<"NAZWA MAGAZYNU: " << m.getName() << std::endl;
        std::cout <<   "|                                    |\n"
                       "|0: Wroc do menu glownego            |\n"
                       "|1: Dodaj rodzaj towaru do magazynu  |\n" // dodaje książkę na wybraną półkę
                       "|2: Usuń rodzaj towaru z magazynu    |\n" // usuwa książkę ze wskazanej półki
                       "|3: Przyjęcie towaru do magazynu     |\n" // przenosi książkę pomiędzy dwoma półkami
                       "|4: Odbiór towaru z magazynu         |\n" // pokazuje zawartość wybranej półki
                       "|5: Wyświetl zawartość towaru        |\n"
                       "|6: Obierz towar z paleciaka         |\n"
                       "|7: Przenieś dany towar do paleciaka |\n"
                       "|8: Wyswietl zawartosc paleciaka     |\n"
                       "|                                    |\n"
                       "--------------------------------------\n"
                       " Wybierz akcje: ";

        try {
            choice = readNumber<int>(input);
        }
        catch(ChooseError &ex) {
            std::cerr << "Choose Error: " + ex.message  << std::endl;
            exit(0); //exit jest uzyty z uwagi na to, że odpalamy program z pliku wejsciowego i nie może na bierząco wychodzić z programu kiedy pojawi sie blad
        }

        switch (choice) {
            case 0:
                interfejsGlowny(m, vec, &p, input);
                break;
            case 1:
                dodajRodzajTowaru(m, input);
                break;
            case 2:
                usunRodzajTowaru(m, input);
                break;
            case 3:
                przyjecieTowaru(m, input);
                break;
            case 4:
                odbierzTowar(m, input);
                break;
            case 5:
                wyswietl(m);
                break;
            case 6:
                odbierzZPaleciaka(m, p );
                break;
            case 7:
                zaladujNaPaleciaka(m, p, input);
                break;
            case 8:
                wyswietlPaleciaka(p);
                break;
            default:
                std::cout << "Niepoprawny wybór" << std::endl;
        }
    } while (choice != 0);
}


void interfejs::wyswietlPaleciaka(Paleciak &p) {
    p.print();
}


void interfejs::odbierzZPaleciaka(Magazyn &m, Paleciak &p) {

    if(p.isEmpty()) {
        std::cout << "--------------------------------------\n"
                     "Paleciak jest pusty \n";
        return;
    }

    m.przyjmij(p);
    p.cleanAktualnyUdzwig();
    std::cout << "Odebrano produkty z paleciaka\n";
}



void interfejs::zaladujNaPaleciaka(Magazyn &m, Paleciak &p, std::basic_istream<char> *input) {


    if(m.isEmpty()) { // jesli magazyn jest pusty informujemy uzytkownika o braku mozliwosci odebrania towaru z pustego magazynu ktory nie obsluguje jeszcze zadnego rodzaju
        std::cout << "--------------------------------------\n"
                     "Nie można zaladowac towaru na paleciaka, ponieważ magazyn nie obsługuje jeszcze żadnego rodzaju towaru.\n";
        return;
    }

    std::cout << "--------------------------------------\n"
                 "Podaj id towaru do zaladowania: ";
    int id;
    try {
        id = readNumber<int>(input);
        m.idExists(id);
    }
    catch(ChooseError &ex) {
        std::cerr << "Choose Error: "<< ex.message << std::endl;
        exit(0);
    }

    float waga;

    if ( dynamic_cast<Towar*>(m.getEle(id)) ) { //sprawwdzanie typu elementu w magazunie o podanym id
        if(m.getEle(id)->pobierzIloscInt() == 0) {
            std::cout << "--------------------------------------\n"
                         "Nie mmozna zaladowac towaru. Ilosc podanego twaru w magazynie jest rowna 0.\n";
            return;
        }
        std::cout << "--------------------------------------\n"
                     "Zważ pojedynczy towar i podaj jego wagę w kilogramach: ";
        int liczba_sztuk;
        try {
            waga = readNumber<float>(input);

            std::cout << "--------------------------------------\n"
                         "Podaj liczbe sztuk towaru do zaladowania: ";
            liczba_sztuk = readNumber<int>(input);


            while (liczba_sztuk > m.getEle(
                    id)->pobierzIloscInt()) { // jesli podana ilosc towarow do usuniecia jest wieksza niz ta znajdujaca sie w magazynie to prosimy uzytkownika o podanie jej ponownie
                std::cout << "--------------------------------------\n"
                             "Nie ma wystarczającej ilości sztuk podanego towaru w magazynie.\n"
                             "Dostępna ilość sztuk to: ";
                m.getEle(id)->wypiszIlosc();
                std::cout << " Podaj liczbę sztuk ponownie: ";
                liczba_sztuk = readNumber<int>(input);
            }
        }
        catch (ChooseError &ex) {
            std::cerr << "Choose Error: "<< ex.message << std::endl;
            exit(0);
        }


        waga *= liczba_sztuk; // wyliczna jest waga ogolna


        if (!p.zwiekszAktualnyUdzwig(waga)) {
            std::cout << "--------------------------------------\n"
                         "Towar waży za dużo aby go załadować na paleciaka.\n"
                         "Aktualny udźwig paleciaka: ";
            std::cout << p.getAktualnyUdzwig() << std::endl;
            std::cout << "Maksymalny udzwig paleciaka: ";
            std::cout << p.getUdzwig() << std::endl;
            return;
        }


        if(p.idExists(id)) {
            *p.getEleWithID(id) += liczba_sztuk;
            *m.getEle(id) -= liczba_sztuk;
        } else {
            m.wydaj(id, liczba_sztuk, p);
        }
    }
    else if ( dynamic_cast<TowarSypki*>(m.getEle(id)) ) {

        if(m.getEle(id)->pobierzIloscFloat() == 0) {
            std::cout << "--------------------------------------\n"
                         "Nie mmozna zaladowac towaru. Ilosc podanego twaru w magazynie jest rowna 0.";
            return;
        }

        std::cout << "--------------------------------------\n"
                     "Podaj ile kilogramow towaru chcesz zaladowac: ";
        try {
            waga = readNumber<float>(input);
        }
        catch (ChooseError &ex) {
            std::cerr << "Choose Error: "<< ex.message << std::endl;
            exit(0);
        }

        if (!p.zwiekszAktualnyUdzwig(waga)) {
            std::cout << "Towar waży za dużo aby go załadować na paleciaka.\n";
            return;
        }
        if(p.idExists(id)) {
            *p.getEleWithID(id) += waga;
            *m[id] -= waga;
        } else {
            m.wydaj(id, waga, p);
        }
    }
    else {

        if(m.getEle(id)->pobierzIloscFloat() == 0) {
            std::cout << "--------------------------------------\n"
                         "Nie mmozna zaladowac towaru. Ilosc podanego twaru w magazynie jest rowna 0.";
            return;
        }
        std::cout << "--------------------------------------\n"
                     "Podaj ile litrow towaru chcesz zaladowac: ";
        try {
            waga = readNumber<float>(input);
        }
        catch (ChooseError &ex) {
            std::cerr << "Choose Error: "<< ex.message << std::endl;
        }

        if (!p.zwiekszAktualnyUdzwig(waga)) {
            std::cout << "Towar waży za dużo aby go załadować na paleciaka.\n";
            return;
        }
        if(p.idExists(id)) {
            *p.getEleWithID(id) += waga;
            *m[id] -= waga;
        } else {
            m.wydaj(id, waga, p);
        }
    }
}


void interfejs::dodajRodzajTowaru(Magazyn &m, std::basic_istream<char> *input) {

    std::cout << "--------------------------------------\n"
                     "Podaj nazwe towaru: ";

    std::string nazwa = readString(input);

    std::cout << "--------------------------------------\n"
                 "Wybierz formę produktu: \n\n"
                 "0. Wróć do menu\n"
                 "1. Na sztuki\n"
                 "2. W formie ciekłej\n"
                 "3. W formie sypkiej\n"
                 "--------------------------------------\n"
                 "Wybierz akcje: ";
    int c;
    try {
        c = readNumber<int>(input);
    }
    catch(ChooseError &ex) {
        std::cerr << "Choose Error: " + ex.message  << std::endl;
        exit(0);
    }


    switch (c) {
        case 1: {
            Produkt* t = new Towar(nazwa);
            m.dodajTowar(t);
            break;
        }
        case 2: {
            Produkt* t = new TowarCiekly(nazwa);
            m.dodajTowar(t);
            break;
        }
        case 3: {
            Produkt* t = new TowarSypki(nazwa);
            m.dodajTowar(t);
            break;
        }
        default:
            std::cout << "Niepoprawny wybór" << std::endl;
    }
}


void interfejs::usunRodzajTowaru(Magazyn &m, std::basic_istream<char> *input) {
    if(m.isEmpty()) { // jessli magazyn jest pusty to nie mozna usunac zadnego rodzaju towaru
        std::cout << "Nie można usunać rodzaju towaru, ponieważ magazyn nie obsługuje jeszcze żadnego rodzaju towaru." << std::endl;
        return;
    }

    std::cout << "--------------------------------------\n"
                 "Podaj id towaru do usunięcia: ";

    int id;
    try {
        id = readNumber<int>(input);
        m.getIndexOfID(id);
    }
    catch(ChooseError &ex) {
        std::cerr << "Choose Error: " + ex.message  << std::endl;
        exit(0);
    }

    m.usunTowar(id);
}


void interfejs::odbierzTowar(Magazyn &m, std::basic_istream<char> *input) {
    if(m.isEmpty()) { // jesli magazyn jest pusty informujemy uzytkownika o braku mozliwosci odebrania towaru z pustego magazynu ktory nie obsluguje jeszcze zadnego rodzaju
        std::cout << "Nie można odebrać towaru, ponieważ magazyn nie obsługuje jeszcze żadnego rodzaju towaru." << std::endl;
        return;
    }
    std::cout << "--------------------------------------\n"
                 "Podaj ID towaru do odbrania: ";

    int id;
    try {
        id = readNumber<int>(input);
        m.getIndexOfID(id);
    }
    catch(ChooseError &ex) {
        std::cerr << "Choose Error: " + ex.message  << std::endl;
        exit(0);
    }

    if ( dynamic_cast<Towar*>(m.getEle(id)) ) {
        std::cout << "--------------------------------------\n"
                     "Ile sztuk towaru chcesz odebrać: ";
        int ilosc;
        try {
            ilosc = readNumber<int>(input);
        }
        catch(ChooseError &ex) {
            std::cerr << "Choose Error: " + ex.message  << std::endl;
            exit(0);
        }


            while (ilosc > m.getEle(id)->pobierzIloscInt()) { // jesli podana ilosc towarow do usuniecia jest wieksza niz ta znajdujaca sie w magazynie to prosimy uzytkownika o podanie jej ponownie
                std::cout << "--------------------------------------\n"
                             "Nie ma wystarczającej ilości sztuk podanego towaru w magazynie.\n"
                             "Dostępna ilość sztuk to: ";
                m.getEle(id)->wypiszIlosc();
                std::cout << " Podaj liczbę sztuk ponownie: ";
                ilosc = readNumber<int>(input);
            }

            *m.getEle(id) -= ilosc;
        }

    else {
        std::cout << "--------------------------------------\n"
                     "Jaka ilosc towaru chcesz odebrać: ";
        float ilosc;
        try {
            ilosc = readNumber<float>(input);
        }
        catch(ChooseError &ex) {
            std::cerr << "Choose Error: " + ex.message  << std::endl;
            exit(0);
        }

            while (ilosc > m.getEle(id)->pobierzIloscFloat()) { // jesli podana ilosc towarow do usuniecia jest wieksza niz ta znajdujaca sie w magazynie to prosimy uzytkownika o podanie jej ponownie
                std::cout << "--------------------------------------\n"
                             "Nie ma wystarczającej ilości sztuk podanego towaru w magazynie.\n"
                             "Dostępna ilość sztuk to: ";
                m[id]->wypiszIlosc();
                std::cout << " Podaj liczbę sztuk ponownie: ";
                ilosc = readNumber<float>(input);
            }
            *m.getEle(id) -= ilosc;

    }
}



void interfejs::przyjecieTowaru(Magazyn &m, std::basic_istream<char> *input) {
    if(m.isEmpty()) { // jesli magazyn jest pusty informujemy uzytkownika o braku mozliwosci przyjecia towaru do pustego magazynu ktory nie obsluguje jeszcze zadnego rodzaju
        std::cout << "Nie można przyjąć towaru, ponieważ magazyn nie obsługuje jeszcze żadnego rodzaju towaru." << std::endl;
        return;
    }
    std::cout << "--------------------------------------\n"
                 "Podaj id towaru do przyjęcia: ";

    int id;
    try {
        id = readNumber<int>(input);
        m.getIndexOfID(id);
    }
    catch(ChooseError &ex) {
        std::cerr << "Choose Error: " + ex.message  << std::endl;
        exit(0);
    }

    std::cout << "--------------------------------------\n"
                 "Podaj ilość towaru do przyjęcia: ";

    if ( dynamic_cast<Towar*>(m.getEle(id)) ) {
        int ilosc;
        try {
            ilosc = readNumber<int>(input);
                *m.getEle(id) += ilosc;
        }
        catch(ChooseError &ex) {
            std::cerr << "Choose Error: " + ex.message  << std::endl;
            exit(0);
        }
    }
    else {
        float ilosc;
        try {
            ilosc = readNumber<float>(input);
            *m.getEle(id) += ilosc;
        }
        catch(ChooseError &ex) {
            std::cerr << "Choose Error: " + ex.message  << std::endl;
            exit(0);
        }
    }
}


void interfejs::wyswietl(Magazyn &m) {
    if(m.isEmpty()) { // jesli magazyn jest pusty to informujemy o tym uzytkownika
        std::cout << "Magazyn jest pusty." << std::endl;
        return;
    }
    std::cout << "--------------------------------------\n"
                 "Zawartość magazynu: \n";
    m.print();
}



template<typename T>
T interfejs::readNumber(std::basic_istream<char> *input) {
    std::string line;
    std::getline(*input, line);

    if(line == "END") {
        exit(0);
    }

    if( !std::regex_match( line, std::regex( ( "((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?" ) ) ))
        throw NotDigitError();

    std::cout << line << std::endl;

    if(line.find('.') != std::string::npos) {
        return atof(line.c_str()); // najpierw kopiujemy nasz string pobrany od uzytkownika a nastepnie odbyywa sie konwersja kopii do intiger i na koncu zwracamy
    }
    else {
        return atoi(line.c_str());
    }
}

template int interfejs::readNumber<int>(std::basic_istream<char> *input);
template float interfejs::readNumber<float>(std::basic_istream<char> *input);


std::string interfejs::readString( std::basic_istream<char> *input) {
    std::string line;
    std::getline(*input, line);
    if(line == "END") {
        exit(0);
    }
    std::cout << line << std::endl;
    return line;
}



void interfejs::stworzMagazyn(std::vector<Magazyn*> &vec, std::basic_istream<char> *input) {
    std::cout << "--------------------------------------\n"
                 "Podaj nazwe magazynu: \n";
    std::string nazwa = readString(input);
    Magazyn *m = new Magazyn(nazwa);
    vec.insert(vec.begin(), m);
}

void interfejs::wejscieMagazynu(Magazyn *m, std::vector<Magazyn*> &vec, Paleciak *p, std::basic_istream<char> *input) {

    if(vec.empty()) {
        std::cout << "--------------------------------------\n"
                     "Nie stworzono jeszcze zadnego magazynu.\n";
    }
    wyswietlListeMagazynow(vec);
    std::cout << "--------------------------------------\n"
                 "Podaj numer magazynu: ";
    int nr;
    try {
        nr = readNumber<int>(input);
    }
    catch(ChooseError &ex) {
        std::cerr << "Choose Error: " + ex.message  << std::endl;
        exit(0);
    }

    if (nr > vec.size()) {
        std::cout << "--------------------------------------\n"
                     "Niepoprany numer magazynu\n";
        return;
    }

    nr = vec.size() - nr;

    m = vec[nr];

    interfejsMagazyn(*m, vec, *p, input);
}

void interfejs::wyswietlListeMagazynow(std::vector<Magazyn*> &vec) {
    for(int i = vec.size()-1; i >= 0; i--) {
        std::cout << vec.size()-i << ". " ; vec[i]->wyswietlInfo();
    }
}


