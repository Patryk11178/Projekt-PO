#ifndef CENTRALKAALARMOWA_CZUJNIKOTWARCIA_H
#define CENTRALKAALARMOWA_CZUJNIKOTWARCIA_H


#include "Czujnik.h"

class CzujnikOtwarcia : public Czujnik {
public:
    CzujnikOtwarcia();
    CzujnikOtwarcia(const std::string& nazwa);

    void wypiszInformacje(std::ostream& out) const;
};


#endif
