#ifndef TEMA2_LABORATOR_H
#define TEMA2_LABORATOR_H

#include "Sala.h"

enum Tip_tabla {alba, neagra, smart};

class Laborator : public Sala
{
    Tip_tabla tip_tabla;
    int nr_calculatoare;

public:
    Laborator();
    Laborator(std::string nume, int etaj, int nr_sala, int nr_locuri, std::vector<std::string> echipamente, Tip_tabla tip_tabla, int nr_calculatoare);
    Laborator(const Laborator& laborator);
    Laborator& operator=(const Laborator& laborator);
    ~Laborator();

    std::string get_nume() const;
    int get_etaj() const;
    int get_nr_sala() const;
    int get_nr_locuri() const;
    std::vector<std::string> get_echipamente() const;
    Tip_tabla get_tip_tabla() const;
    int get_nr_calculatoare() const;

    void set_nume(std::string nume);
    void set_etaj(int etaj);
    void set_nr_sala(int nr_sala);
    void set_nr_locuri(int nr_locuri);
    void set_echipamente(std::vector<std::string> echipamente);
    void set_tip_tabla(Tip_tabla tip_tabla);
    void set_nr_calculatoare(int nr_calculatoare);

    friend std::ostream& operator<<(std::ostream& out, const Laborator& laborator);
};

#endif // TEMA2_LABORATOR_H