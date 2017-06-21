#include "Fabryka.h"
#include "CzujnikRuchu.h"
#include "CzujnikOtwarcia.h"


Czujnik* Fabryka::stworzCzujnik(RodzajCzujnika rodzaj, const std::string &nazwa) {
    switch(rodzaj) {
        case CZUJNIK_RUCHU:
            return new CzujnikRuchu(nazwa);
        case CZUJNIK_OTWARCIA:
            return new CzujnikOtwarcia(nazwa);
    }
}