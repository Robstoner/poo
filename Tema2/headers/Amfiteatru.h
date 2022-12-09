#ifndef TEMA2_AMFITEATRU_H
#define TEMA2_AMFITEATRU_H

#include "Sala.h"

class Amfiteatru : public Sala
{
    int nr_randuri;
    std::string nume_amf;

public:
    Amfiteatru();
    Amfiteatru(std::string nume, int etaj, int nr_sala, int nr_locuri, std::vector<std::string> echipamente, int nr_randuri, std::string nume_amf);
    Amfiteatru(const Amfiteatru& amfiteatru);
    Amfiteatru& operator=(const Amfiteatru& amfiteatru);
    ~Amfiteatru();

    std::string get_nume() const;
    int get_etaj() const;
    int get_nr_sala() const;
    int get_nr_locuri() const;
    std::vector<std::string> get_echipamente() const;
    int get_nr_randuri() const;
    std::string get_nume_amf() const;

    void set_nume(std::string nume);
    void set_etaj(int etaj);
    void set_nr_sala(int nr_sala);
    void set_nr_locuri(int nr_locuri);
    void set_echipamente(std::vector<std::string> echipamente);
    void set_nr_randuri(int nr_randuri);
    void set_nume_amf(std::string nume);

    friend std::ostream& operator<<(std::ostream& out,  Amfiteatru& amfiteatru);
};

#endif // TEMA2_AMFITEATRU_H