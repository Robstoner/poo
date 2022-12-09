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
    Curs(const std::string &nume, const std::vector<std::shared_ptr<Sala>> &sali, const std::vector<std::string> &studenti);
    Curs(const Curs& curs);
    Curs& operator=(const Curs& curs);
    ~Curs();

    void adauga_sala(std::shared_ptr<Sala> sala);

    std::string get_nume() const;
    std::vector<std::shared_ptr<Sala>> get_sali() const;
    std::vector<std::string> get_studenti() const;

    void set_nume(const std::string &nume_);
    void set_sali(const std::vector<std::shared_ptr<Sala>> &sali_);
    void set_studenti(const std::vector<std::string> &studenti_);

    friend std::ostream& operator<<(std::ostream& out, const Curs& curs);
};

#endif // TEMA2_CURS_H