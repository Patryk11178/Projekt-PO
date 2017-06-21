#include "Czujnik.h"

Czujnik::Czujnik(const std::string &nazwa) : nazwa(nazwa), wlaczony(true) {

}

void Czujnik::wlacz() {
    wlaczony = true;
}

void Czujnik::wylacz() {
    wlaczony = false;
}

void Czujnik::ustawStan(bool wartosc) {
    stan = wartosc;
}

bool Czujnik::odczytajStan() const {
    return stan;
}

const std::string& Czujnik::odczytajNazwe() const {
    return nazwa;
}

bool Czujnik::czyWlaczony() const {
    return wlaczony;
}

Czujnik::Czujnik() {

}

Czujnik::~Czujnik() {

}
