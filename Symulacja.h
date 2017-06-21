#ifndef CENTRALKAALARMOWA_SYMULACJA_H
#define CENTRALKAALARMOWA_SYMULACJA_H


#include "Centrala.h"

class Symulacja {
    Centrala centrala;
    void kreator();
    void symuluj();
    void losoweDzialanie();
public:
    void menu();
};


#endif //CENTRALKAALARMOWA_SYMULACJA_H
