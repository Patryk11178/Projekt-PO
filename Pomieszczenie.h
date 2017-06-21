#ifndef CENTRALKAALARMOWA_POMIESZCZENIE_H
#define CENTRALKAALARMOWA_POMIESZCZENIE_H


#include <string>
#include <vector>
#include "Czujnik.h"

class Pomieszczenie {
    std::string nazwa;
    bool czujnikiWlaczone = true;
    std::vector<Czujnik*> czujniki;

public:
    Pomieszczenie(const std::string& nazwa);
    Pomieszczenie();

    void ustawNazwe(const std::string& n);
    const std::string& pobierzNazwe();

    void sprawdzStanCzujnikow() const;
    bool czyCzujnikWykryl() const;
    void zapiszInformacjeDoPliku(std::ostream& out);
    void dodajCzujnik(Czujnik* czujnik);


    void wlaczCzujniki();
    void wylaczCzujniki();
    bool czyCzujnikiWlaczone();

    std::vector<Czujnik*> pobierzCzujniki();

    virtual ~Pomieszczenie();
};


#endif //CENTRALKAALARMOWA_POMIESZCZENIE_H
