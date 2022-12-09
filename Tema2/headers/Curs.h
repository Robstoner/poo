#ifndef TEMA2_CURS_H
#define TEMA2_CURS_H

#include <string>
#include <vector>
#include <memory>

#include "Amfiteatru.h"
#include "Laborator.h"
#include "Seminar.h"

class Curs
{
    std::string nume;
    std::vector<std::shared_ptr<Sala>> sali;
    std::vector<std::string> studenti;

public:
    Curs(std::string nume, std::vector<std::shared_ptr<Sala>> sali, std::vector<std::string> studenti);
    Curs(const Curs& curs);
    Curs& operator=(const Curs& curs);
    ~Curs();

    std::string get_nume() const;
    std::vector<std::shared_ptr<Sala>> get_sali() const;
    std::vector<std::string> get_studenti() const;

    void set_nume(std::string nume);
    void set_sali(std::vector<std::shared_ptr<Sala>> sali);
    void set_studenti(std::vector<std::string> studenti);

    friend std::ostream& operator<<(std::ostream& out, const Curs& curs);
};

#endif // TEMA2_CURS_H