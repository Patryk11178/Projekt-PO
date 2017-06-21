#include <iostream>
#include <iomanip>

#include <ctime>

#include "Centrala.h"

Centrala::Centrala() {
    log.open(NAZWA_PLIKU, std::ios::app);
}

void Centrala::dodajNumer(const std::string &numer) {
    numery.push_back(numer);
}

void Centrala::dodajPomieszczenie(Pomieszczenie *pomieszczenie) {
    pomieszczenia.push_back(pomieszczenie);
}

/*void Centrala::wlaczPomieszczenie(const std::string &nazwa) {
    for(auto pomieszczenie : pomieszczenia) {
        if(pomieszczenie->pobierzNazwe() == nazwa) {
            pomieszczenie->wlaczCzujniki();
        }
    }
}

void Centrala::wylaczPomieszczenie(const std::string &nazwa) {
    for(auto pomieszczenie : pomieszczenia) {
        if(pomieszczenie->pobierzNazwe() == nazwa) {
            pomieszczenie->wylaczCzujniki();
        }
    }
}*/


void Centrala::zapiszCzas(std::ostream &out) {
    time_t rawtime;
    struct tm * timeinfo;

    time (&rawtime);
    timeinfo = localtime (&rawtime);

    std::string przetworzonyCzas(asctime(timeinfo));

    out << przetworzonyCzas << std::endl;

}

void Centrala::sprawdzPomieszczenia() {
    for(auto pomieszczenie: pomieszczenia) {
        std::cout << std::endl << pomieszczenie->pobierzNazwe() << std::endl;

        if(pomieszczenie->czyCzujnikiWlaczone()) {
            bool stan = pomieszczenie->czyCzujnikWykryl();

            if(stan) {
                std::cout << "Wykryto zdarzenie. Zapisuje informacje do logu.\n";
                std::cout << "Wyslano informacje na podane numery: \n";
                wypiszNumery(std::cout);

                log << "\n";
                log << std::setw(50) << std::setfill('#') << " ";
                log << "\n";
                zapiszCzas(log);
                log << "Wyslano informacje na podane numery: \n";
                wypiszNumery(log);
                pomieszczenie->zapiszInformacjeDoPliku(log);

            }
            else {
                std::cout << "Nie wykryto zdarzenia w tym pomieszczeniu.\n";
            }

        } else {
            std::cout << "W tym pomieszczeniu czujniki sa wylaczone.\n";
        }
    }
}

Centrala::~Centrala() {
    log.close();

    for(auto pomieszczenie : pomieszczenia) {
        delete pomieszczenie;
    }
}

void Centrala::wypiszNumery(std::ostream &out) {
    for(auto numer : numery) {
        out << numer << std::endl;
    }
}

std::vector<Pomieszczenie *> &Centrala::pobierzPomieszczenia() {

    return pomieszczenia;
}
