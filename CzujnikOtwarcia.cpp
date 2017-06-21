#include "CzujnikOtwarcia.h"
#include <iostream>

CzujnikOtwarcia::CzujnikOtwarcia(const std::string &nazwa) : Czujnik(nazwa) {

}


void CzujnikOtwarcia::wypiszInformacje(std::ostream &out) const {
    out << "\nCZUJNIK OTWARCIA\n";
    out << nazwa << std::endl;
    if(!wlaczony) {
        out << "Czujnik jest wylaczony.\n";
        return;
    }

    out << "Stan czujnika = " << stan << std::endl;
    if(stan) {
        out << "Zamek otwarty\n";
    } else {
        out << "Zamek zamkniety\n";
    }
}
