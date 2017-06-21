#ifndef CENTRALKAALARMOWA_CZUJNIK_H
#define CENTRALKAALARMOWA_CZUJNIK_H


#include <string>



class Czujnik {
protected:
    bool stan       = false;
    bool wlaczony   = false;

    std::string nazwa;
public:
    Czujnik(const std::string& nazwa);
    Czujnik();

    void ustawStan(bool wartosc);
    bool odczytajStan() const;

    void wlacz();
    void wylacz();

    bool czyWlaczony() const;
    const std::string& odczytajNazwe() const;

    virtual void wypiszInformacje(std::ostream &out) const = 0;

    virtual ~Czujnik();
};


#endif
