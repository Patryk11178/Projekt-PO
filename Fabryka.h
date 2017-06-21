#ifndef CENTRALKAALARMOWA_FABRYKA_H
#define CENTRALKAALARMOWA_FABRYKA_H


#include "Czujnik.h"

enum RodzajCzujnika {
    CZUJNIK_RUCHU,
    CZUJNIK_OTWARCIA
};

class Fabryka {
public:
    static Czujnik* stworzCzujnik(RodzajCzujnika rodzaj, const std::string& nazwa);
};


#endif //CENTRALKAALARMOWA_FABRYKA_H
