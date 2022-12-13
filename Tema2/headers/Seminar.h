#ifndef TEMA2_SEMINAR_H
#define TEMA2_SEMINAR_H

#include "Sala.h"

class Seminar : public Sala
{
    Tip_tabla tip_tabla;

public:
    Seminar();
    Seminar(const std::string &nume, int etaj, int nr_sala, int nr_locuri, Tip_tabla tip_tabla = Tip_tabla::alba);
    Seminar(const Seminar& seminar);
    Seminar& operator=(const Seminar& seminar);
    ~Seminar();

    [[maybe_unused]] Tip_tabla get_tip_tabla() const;

    [[maybe_unused]] void set_tip_tabla(Tip_tabla tip_tabla_);

    int get_nr_echipamente() const override;

    friend std::ostream& operator<<(std::ostream& out, const Seminar& seminar);
    friend std::istream& operator>>(std::istream& in, Seminar& seminar);
};

#endif // TEMA2_SEMINAR_H