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
    std::vector<std::string> profesori;

public:
    Curs(const std::string &nume, const std::vector<std::shared_ptr<Sala>> &sali = {}, const std::vector<std::string> &profesori = {});
    Curs(const Curs& curs);
    Curs& operator=(const Curs& curs);
    ~Curs();

    void adauga_sala(std::shared_ptr<Sala> sala);
    void adauga_profesor(const std::string &profesor);

    [[maybe_unused]] std::string get_nume() const;
    [[maybe_unused]] std::vector<std::shared_ptr<Sala>> get_sali() const;
    [[maybe_unused]] std::vector<std::string> get_profesori() const;

    [[maybe_unused]] void set_nume(const std::string &nume_);
    [[maybe_unused]] void set_sali(const std::vector<std::shared_ptr<Sala>> &sali_);
    [[maybe_unused]] void set_profesori(const std::vector<std::string> &profesori_);

    friend std::ostream& operator<<(std::ostream& out, const Curs& curs);
};

#endif // TEMA2_CURS_H