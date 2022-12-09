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
    std::vector<std::string> echipamente;

public:
    Sala();
    Sala(std::string nume, int etaj, int nr_sala, int nr_locuri, std::vector<std::string> echipamente);
    Sala(const Sala &sala);
    virtual Sala &operator=(const Sala &sala);
    virtual ~Sala();

    virtual std::string get_nume() const = 0;
    virtual int get_etaj() const = 0;
    virtual int get_nr_sala() const = 0;
    virtual int get_nr_locuri() const = 0;
    virtual std::vector<std::string> get_echipamente() const = 0;

    virtual void set_nume(std::string nume) = 0;
    virtual void set_etaj(int etaj) = 0;
    virtual void set_nr_sala(int nr_sala) = 0;
    virtual void set_nr_locuri(int nr_locuri) = 0;
    virtual void set_echipamente(std::vector<std::string> echipamente) = 0;

    friend std::ostream &operator<<(std::ostream &out, const Sala &sala);
};

#endif // TEMA2_SALA_H