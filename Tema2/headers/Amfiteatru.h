#ifndef TEMA2_AMFITEATRU_H
#define TEMA2_AMFITEATRU_H

#include "Sala.h"

class Amfiteatru : public Sala
{
    int nr_randuri;
    std::string nume_amf;

public:
    Amfiteatru();
    Amfiteatru(const std::string &nume, int etaj, int nr_sala, int nr_locuri, const std::vector<std::string> &echipamente, int nr_randuri, const std::string &nume_amf);
    Amfiteatru(const Amfiteatru& amfiteatru);
    Amfiteatru& operator=(const Amfiteatru& amfiteatru);
    ~Amfiteatru();

    std::string get_nume() const override;
    int get_etaj() const override;
    int get_nr_sala() const override;
    int get_nr_locuri() const override;
    std::vector<std::string> get_echipamente() const override;
    int get_nr_randuri() const;
    std::string get_nume_amf() const;

    void set_nume(const std::string &nume_) override;
    void set_etaj(int etaj_) override;
    void set_nr_sala(int nr_sala_) override;
    void set_nr_locuri(int nr_locuri_) override;
    void set_echipamente(const std::vector<std::string> &echipamente_) override;
    void set_nr_randuri(int nr_randuri_);
    void set_nume_amf(const std::string &nume_);

    friend std::ostream& operator<<(std::ostream& out,  Amfiteatru& amfiteatru);
};

#endif // TEMA2_AMFITEATRU_H