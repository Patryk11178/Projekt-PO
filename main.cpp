#include <iostream>
#include <fstream>
#include "Czujnik.h"
#include "CzujnikRuchu.h"
#include "CzujnikOtwarcia.h"
#include "Fabryka.h"
#include "Pomieszczenie.h"
#include "Centrala.h"
#include "Symulacja.h"

int main() {
    /*
    Pomieszczenie a("Salon");
    Czujnik* czujnik1 = Fabryka::stworzCzujnik(CZUJNIK_OTWARCIA, "1# Salon");
    czujnik1->ustawStan(true);
    Czujnik* czujnik2 = Fabryka::stworzCzujnik(CZUJNIK_RUCHU, "2# Salon");
    czujnik2->ustawStan(true);

    a.dodajCzujnik(czujnik1);
    a.dodajCzujnik(czujnik2);


    Pomieszczenie b("Kuchnia");
    Czujnik* czujnik3 = Fabryka::stworzCzujnik(CZUJNIK_OTWARCIA, "1# Kuchnia");
    Czujnik* czujnik4 = Fabryka::stworzCzujnik(CZUJNIK_RUCHU, "2# Kuchni");


    b.dodajCzujnik(czujnik3);
    b.dodajCzujnik(czujnik4);

    Centrala centrala;
    centrala.dodajNumer("+48 555 333 222");
    centrala.dodajNumer("+48 727 333 111");

    centrala.dodajPomieszczenie(&a);
    centrala.dodajPomieszczenie(&b);

    centrala.sprawdzPomieszczenia();
     */

    Symulacja symulacja;
    symulacja.menu();
    return 0;
}