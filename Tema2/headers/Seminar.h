#ifndef TEMA2_SEMINAR_H
#define TEMA2_SEMINAR_H

#include "Sala.h"

class Seminar : public Sala
{
    Tip_tabla tip_tabla;

public:
    Seminar();
    Seminar(const std::string &nume, int etaj, int nr_sala, int nr_locuri, const std::vector<std::string> &echipamente, Tip_tabla tip_tabla = Tip_tabla::alba);
    Seminar(const Seminar& seminar);
    Seminar& operator=(const Seminar& seminar);
    ~Seminar();

    std::string get_nume() const override;
    int get_etaj() const override;
    int get_nr_sala() const override;
    int get_nr_locuri() const override;
    std::vector<std::string> get_echipamente() const override;
    Tip_tabla get_tip_tabla() const;

    void set_nume(const std::string &nume_) override;
    void set_etaj(int etaj_) override;
    void set_nr_sala(int nr_sala_) override;
    void set_nr_locuri(int nr_locuri_) override;
    void set_echipamente(const std::vector<std::string> &echipamente_) override;
    void set_tip_tabla(Tip_tabla tip_tabla_);

    friend std::ostream& operator<<(std::ostream& out, const Seminar& seminar);
};

#endif // TEMA2_SEMINAR_H