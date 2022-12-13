#ifndef TEMA2_AMFITEATRU_H
#define TEMA2_AMFITEATRU_H

#include "Sala.h"

class Amfiteatru : public Sala
{
    int nr_randuri;
    std::string nume_amf;

public:
    Amfiteatru();
    Amfiteatru(const std::string &nume, int etaj, int nr_sala, int nr_locuri, int nr_randuri, const std::string &nume_amf);
    Amfiteatru(const Amfiteatru& amfiteatru);
    Amfiteatru& operator=(const Amfiteatru& amfiteatru);
    ~Amfiteatru();

    [[maybe_unused]] int get_nr_randuri() const;
    [[maybe_unused]] std::string get_nume_amf() const;

    [[maybe_unused]] void set_nr_randuri(int nr_randuri_);
    [[maybe_unused]] void set_nume_amf(const std::string &nume_);

    int get_nr_echipamente() const override;

    friend std::ostream& operator<<(std::ostream& out, const Amfiteatru& amfiteatru);
    friend std::istream& operator>>(std::istream& in, Amfiteatru& amfiteatru);
};

#endif // TEMA2_AMFITEATRU_H