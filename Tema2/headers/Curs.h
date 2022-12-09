#ifndef TEMA2_CURS_H
#define TEMA2_CURS_H

#include <string>
#include <vector>

#include "Amfiteatru.h"
#include "Laborator.h"
#include "Seminar.h"

class Curs
{
    std::string nume;
    Amfiteatru Amf;
    std::shared_ptr<Seminar> Sem;
    std::shared_ptr<Laborator> Lab;
    std::vector<std::string> studenti;

public:
    Curs(std::string nume, Amfiteatru Amf, std::shared_ptr<Seminar> Sem, std::shared_ptr<Laborator> Lab, std::vector<std::string> studenti);
    Curs(const Curs& curs);
    Curs& operator=(const Curs& curs);
    ~Curs();

    std::string get_nume() const;
    Amfiteatru get_Amf() const;
    std::shared_ptr<Seminar> get_Sem() const;
    std::shared_ptr<Laborator> get_Lab() const;
    std::vector<std::string> get_studenti() const;

    void set_nume(std::string nume);
    void set_Amf(Amfiteatru Amf);
    void set_Sem(std::shared_ptr<Seminar> Sem);
    void set_Lab(std::shared_ptr<Laborator> Lab);
    void set_studenti(std::vector<std::string> studenti);

    friend std::ostream& operator<<(std::ostream& out, const Curs& curs);
};

#endif // TEMA2_CURS_H