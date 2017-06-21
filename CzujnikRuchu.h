#ifndef CENTRALKAALARMOWA_CZUJNIKRUCHU_H
#define CENTRALKAALARMOWA_CZUJNIKRUCHU_H


#include "Czujnik.h"

class CzujnikRuchu : public Czujnik {

public:
    CzujnikRuchu();
    CzujnikRuchu(const std::string& nazwa);

    void wypiszInformacje(std::ostream &out) const;
};


#endif