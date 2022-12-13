#ifndef TEMA2_LABORATOR_H
#define TEMA2_LABORATOR_H

#include "Sala.h"

class Laborator : public Sala
{
    Tip_tabla tip_tabla;
    int nr_calculatoare;

public:
    Laborator();
    Laborator(const std::string &nume, int etaj, int nr_sala, int nr_locuri, Tip_tabla tip_tabla, int nr_calculatoare);
    Laborator(const Laborator& laborator);
    Laborator& operator=(const Laborator& laborator);
    ~Laborator();

    [[maybe_unused]] Tip_tabla get_tip_tabla() const;
    [[maybe_unused]] int get_nr_calculatoare() const;

    [[maybe_unused]] void set_tip_tabla(Tip_tabla tip_tabla_);
    [[maybe_unused]] void set_nr_calculatoare(int nr_calculatoare_);

    int get_nr_echipamente() const override;

    friend std::ostream& operator<<(std::ostream& out, const Laborator& laborator);
    friend std::istream& operator>>(std::istream& in, Laborator& laborator);
};

#endif // TEMA2_LABORATOR_H