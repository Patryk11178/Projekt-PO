#include <iostream>
#include "Pomieszczenie.h"

Pomieszczenie::Pomieszczenie(const std::string &nazwa) : nazwa(nazwa) {
}

void Pomieszczenie::zapiszInformacjeDoPliku(std::ostream &out) {
    out << nazwa << std::endl;
    for(auto czujnik : czujniki) {
        if(czujnik->odczytajStan() && czujnik->czyWlaczony())
            czujnik->wypiszInformacje(out);
    }
}
void Pomieszczenie::sprawdzStanCzujnikow() const {

    for(auto czujnik : czujniki) {
        czujnik->wypiszInformacje(std::cout);
    }
}


bool Pomieszczenie::czyCzujnikWykryl() const {
    for(auto czujnik : czujniki) {
        if(czujnik->odczytajStan() && czujnik->czyWlaczony()) {
            return true;
        }
    }

    return false;
}

void Pomieszczenie::dodajCzujnik(Czujnik *czujnik) {
    czujniki.push_back(czujnik);
}

const std::string &Pomieszczenie::pobierzNazwe() {
    return nazwa;
}

void Pomieszczenie::wlaczCzujniki() {
    czujnikiWlaczone = true;
}

void Pomieszczenie::wylaczCzujniki() {
    czujnikiWlaczone = false;
}

bool Pomieszczenie::czyCzujnikiWlaczone() {
    return czujnikiWlaczone;
}

Pomieszczenie::Pomieszczenie() {

}

void Pomieszczenie::ustawNazwe(const std::string &n) {
    nazwa = n;
}

std::vector<Czujnik *> Pomieszczenie::pobierzCzujniki() {
    return czujniki;
}

Pomieszczenie::~Pomieszczenie() {
    for(auto czujnik : czujniki) {
        delete czujnik;
    }
}
