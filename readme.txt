Projekt zawiera siedem klas.
Pierwsze trzy klasu to Towar, TowarSypki i TowarCiekly ktore posiadaja ilosc oraz id dziedzicone z nastepnej klasy.
Czwarta klasa to produkt, która jest klasą abstrakcyjna i bazowa dla pierwszych trzech klas. Posiada id produktu dzieki czemu klasy towarow nie moga miec tego samego id.
Piata klasa to Magazyn, mozna ich utworzyc dowolna ilosc. Przetrzymuje w wektorze wskazniki na produkty dzieki czemu miedzy magazynami nie moze sie potworzyc to samo id, oraz posiada nazwe magazynu.
Szosta klasa to paleciak ktory posiada swoj udzwig. Mozna w nim przetrzymywac produkty z roznych magazynow.
Trzecia klasa to interfejs, Która pozwala wykonywać metody operujące bezpośrednio na naszym magazynie utworzonym w pliku main.cpp.

Każda z tych klas posiada również potrzebne metody do realizacji projektu.

Po utworzeniu obiektu klasy interfejs uruchamiamy i wywolaniu funkcji z klasy interfejs uruchamiamy dzialanie naszego programu.


