#ifndef CENTRALKAALARMOWA_CENTRALA_H
#define CENTRALKAALARMOWA_CENTRALA_H


#include <string>
#include <vector>
#include <fstream>
#include "Pomieszczenie.h"

class Centrala {
    const std::string NAZWA_PLIKU = "log.txt";
    std::ofstream log;

    std::vector<std::string> numery;
    std::vector<Pomieszczenie*> pomieszczenia;

    bool wyslanoInformacje  = false;
    bool wlaczonoAlarm      = false;
    //bool centralaWlaczona   = true;


    void zapiszCzas(std::ostream& out);
public:
    Centrala();
    ~Centrala();

    void dodajNumer(const std::string& numer);
    void wypiszNumery(std::ostream& out);
    void dodajPomieszczenie(Pomieszczenie* pomieszczenie);
    //void wlaczPomieszczenie(const std::string &nazwa);
    //void wylaczPomieszczenie(const std::string& nazwa);

    std::vector<Pomieszczenie*>& pobierzPomieszczenia();

    void sprawdzPomieszczenia();


};


#endif
