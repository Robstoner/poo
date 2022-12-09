#ifndef TEMA2_SEMINAR_H
#define TEMA2_SEMINAR_H

#include "Sala.h"

enum Tip_tabla {alba, neagra, smart};

class Seminar : public Sala
{
    Tip_tabla tip_tabla;

public:
    Seminar();
    Seminar(std::string nume, int etaj, int nr_sala, int nr_locuri, std::vector<std::string> echipamente, Tip_tabla tip_tabla = Tip_tabla::alba);
    Seminar(const Seminar& seminar);
    Seminar& operator=(const Seminar& seminar);
    ~Seminar();

    std::string get_nume() const;
    int get_etaj() const;
    int get_nr_sala() const;
    int get_nr_locuri() const;
    std::vector<std::string> get_echipamente() const;
    Tip_tabla get_tip_tabla() const;

    void set_nume(std::string nume);
    void set_etaj(int etaj);
    void set_nr_sala(int nr_sala);
    void set_nr_locuri(int nr_locuri);
    void set_echipamente(std::vector<std::string> echipamente);
    void set_tip_tabla(Tip_tabla tip_tabla);

    friend std::ostream& operator<<(std::ostream& out, const Seminar& seminar);
};

#endif // TEMA2_SEMINAR_H