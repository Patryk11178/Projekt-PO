
#include "CzujnikRuchu.h"
#include <iostream>

CzujnikRuchu::CzujnikRuchu(const std::string &nazwa) : Czujnik(nazwa) {

}

void CzujnikRuchu::wypiszInformacje(std::ostream &out) const {
    out << "\nCZUJNIK RUCHU\n";
    out << nazwa << std::endl;
    if(!wlaczony) {
        out << "Czujnik jest wylaczony.\n";
        return;
    }

    out << "Stan czujnika = " << stan << std::endl;
    if(stan) {
        out << "Wykryto ruch\n";
    } else {
        out << "Nie wykryto ruchu\n";
    }
}

CzujnikRuchu::CzujnikRuchu() {

}
