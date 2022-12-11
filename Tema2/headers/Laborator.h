#ifndef TEMA2_LABORATOR_H
#define TEMA2_LABORATOR_H

#include "Sala.h"

class Laborator : public Sala
{
    Tip_tabla tip_tabla;
    int nr_calculatoare;

public:
    Laborator();
    Laborator(const std::string &nume, int etaj, int nr_sala, int nr_locuri, const std::vector<std::string> &echipamente, Tip_tabla tip_tabla, int nr_calculatoare);
    Laborator(const Laborator& laborator);
    Laborator& operator=(const Laborator& laborator);
    ~Laborator();

    [[maybe_unused]] std::string get_nume() const override;
    [[maybe_unused]] int get_etaj() const override;
    [[maybe_unused]] int get_nr_sala() const override;
    [[maybe_unused]] int get_nr_locuri() const override;
    [[maybe_unused]] std::vector<std::string> get_echipamente() const override;
    [[maybe_unused]] Tip_tabla get_tip_tabla() const;
    [[maybe_unused]] int get_nr_calculatoare() const;

    [[maybe_unused]] void set_nume(const std::string &nume_) override;
    [[maybe_unused]] void set_etaj(int etaj_) override;
    [[maybe_unused]] void set_nr_sala(int nr_sala_) override;
    [[maybe_unused]] void set_nr_locuri(int nr_locuri_) override;
    [[maybe_unused]] void set_echipamente(const std::vector<std::string> &echipamente_) override;
    [[maybe_unused]] void set_tip_tabla(Tip_tabla tip_tabla_);
    [[maybe_unused]] void set_nr_calculatoare(int nr_calculatoare_);

    friend std::ostream& operator<<(std::ostream& out, const Laborator& laborator);
    friend std::istream& operator>>(std::istream& in, Laborator& laborator);
};

#endif // TEMA2_LABORATOR_H