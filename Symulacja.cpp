#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>


#include "Symulacja.h"
#include "Fabryka.h"

void Symulacja::menu() {
    srand(time(0));

    kreator();


    do {
        int wybor = 0;
        std::cout << "1) Uruchom symulacje.\n2) Wyjdz z programu.\n";
        std::cin >> wybor;

        switch (wybor) {
            case 1:
                symuluj();
                break;
            case 2:
                exit(0);
                break;
            default:
            std::cout << "Nie ma takiej w opcji menu.\n";
        }
    }while (true);

}

void Symulacja::kreator() {
    int liczbaPomieszczen = 0;
    std::cout << "Podaj ile chcesz utworzyc pomieszczen: ";
    std::cin >> liczbaPomieszczen;

    Pomieszczenie** pomieszczenia = new Pomieszczenie*[liczbaPomieszczen];

    std::string nazwa;
    for(int i = 0; i < liczbaPomieszczen; i++) {
        std::cout << "Podaj nazwe pomieszczenia " << i + 1 <<": ";
        std::cin >> nazwa;

        pomieszczenia[i] = new Pomieszczenie;
        pomieszczenia[i]->ustawNazwe(nazwa);
        centrala.dodajPomieszczenie(pomieszczenia[i]);
    }

    int liczbaCzujnikow = 0;
    for(int i = 0; i < liczbaPomieszczen; i++) {
        std::cout << "Podaj ile dodac czujnikow do pomieszczenia " << i + 1 <<": ";
        std::cin >> liczbaCzujnikow;

        std::string nazwaCzujnika, typ;
        for(int j = 0; j < liczbaCzujnikow; j++) {
            std::cin.ignore(1000000, '\n');
            std::cout << "Podaj nazwe czujnika: ";
            std::getline(std::cin, nazwaCzujnika);

            std::cout << "Podaj typ czujnika [otwarcia/ruchu]: ";
            std::cin >> typ;

            if(typ == "otwarcia") {
                pomieszczenia[i]->dodajCzujnik(Fabryka::stworzCzujnik(CZUJNIK_OTWARCIA, nazwaCzujnika));
            } else {
                pomieszczenia[i]->dodajCzujnik(Fabryka::stworzCzujnik(CZUJNIK_RUCHU, nazwaCzujnika));
            }
        }

    }

    int liczbaNumerow = 0;
    std::cout << "Ile chcesz dodac numerow do centrali: ";
    std::cin >> liczbaNumerow;

    std::string numer;
    for(int i = 0; i < liczbaNumerow; i++) {
        std::cout << "Podaj numer " << i + 1 << ": ";
        std::cin >> numer;
        centrala.dodajNumer(numer);
    }


}

void Symulacja::symuluj() {
    while(true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        losoweDzialanie();
        centrala.sprawdzPomieszczenia();

    }
}

void Symulacja::losoweDzialanie() {

    static int liczbaPomieszczen = 0;
    static int losowyNumerPomieszczenia = 0;
    static int liczbaCzujnikow = 0;
    static int losowyNumerCzujnika = 0;

    centrala.pobierzPomieszczenia()[losowyNumerPomieszczenia]->pobierzCzujniki()[losowyNumerCzujnika]->ustawStan(false);

    int szansa = rand() % 100 + 1;
    if(szansa > 20) return;

    liczbaPomieszczen = centrala.pobierzPomieszczenia().size();
    losowyNumerPomieszczenia = rand() % (liczbaPomieszczen);
    std::cout << "Losowy numer pomieszczenia: " << losowyNumerPomieszczenia << std::endl;
    liczbaCzujnikow = centrala.pobierzPomieszczenia()[losowyNumerPomieszczenia]->pobierzCzujniki().size();
    losowyNumerCzujnika = rand() % (liczbaCzujnikow);
    std::cout << "Losowy numer czujnika: " << liczbaCzujnikow << std::endl;
    centrala.pobierzPomieszczenia()[losowyNumerPomieszczenia]->pobierzCzujniki()[losowyNumerCzujnika]->ustawStan(true);

}
