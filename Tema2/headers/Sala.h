#ifndef TEMA2_SALA_H
#define TEMA2_SALA_H

#include <iostream>
#include <string>
#include <vector>

enum Tip_tabla {alba, neagra, smart};

class Sala
{
protected:
    std::string nume;
    int etaj;
    int nr_sala;
    int nr_locuri;

public:
    Sala();
    Sala(const std::string &nume, int etaj, int nr_sala, int nr_locuri);
    Sala(const Sala &sala);
    virtual Sala &operator=(const Sala &sala);
    virtual ~Sala();

    std::string get_nume() const;
    int get_etaj() const;
    int get_nr_sala() const;
    int get_nr_locuri() const;

    void set_nume(const std::string &nume);
    void set_etaj(int etaj);
    void set_nr_sala(int nr_sala);
    void set_nr_locuri(int nr_locuri);

    virtual int get_nr_echipamente() const = 0;

    friend std::ostream &operator<<(std::ostream &out, const Sala &sala);
    friend std::istream &operator>>(std::istream &in, Sala &sala);
};

#endif // TEMA2_SALA_H