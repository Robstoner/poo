

#include "headers/Curs.h"

int main()
{
    std::vector<std::string> echipamente;
    echipamente.push_back("Proiector");
    echipamente.push_back("Microfon");
    Amfiteatru *amfiteatru = new Amfiteatru("Amfiteatru", 1, 1, 100, echipamente, 10, "Amfiteatrul 1");
    
    std::vector<std::string> echipamente2;
    echipamente2.push_back("Proiector");
    echipamente2.push_back("Microfon");
    echipamente2.push_back("Laptop");
    Laborator *laborator = new Laborator("Laborator", 1, 2, 30, echipamente2, Tip_tabla::alba, 10);

    Laborator *laborator2 = new Laborator("Laborator 2", 1, 4, 30, echipamente2, Tip_tabla::alba, 10);

    std::vector<std::string> echipamente3;
    echipamente3.push_back("Proiector");
    Seminar *seminar = new Seminar("Seminar", 1, 3, 20, echipamente3, Tip_tabla::neagra);

    std::vector<std::shared_ptr<Sala>> sali;
    sali.push_back(std::shared_ptr<Sala>(amfiteatru));
    sali.push_back(std::shared_ptr<Sala>(laborator));
    sali.push_back(std::shared_ptr<Sala>(seminar));
    sali.push_back(std::shared_ptr<Sala>(laborator2));

    Curs curs("POO", sali, {"Andrei", "Ion"});

    std::cout << curs;
}