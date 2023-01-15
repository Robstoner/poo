/*
    Schmidt Robert-Eduard
    Grupa 264
    Octavian Comanescu
    gcc 8.1.0 x86_64-w64-mingw32
*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <random>
#include <cmath>
#include <exception>

class IDGenerator
{
private:
    static std::mt19937 rng;
    static std::uniform_int_distribution<std::mt19937::result_type> dist;

public:
    static std::string generateID()
    {
        return std::to_string(dist(rng));
    }
};

std::mt19937 IDGenerator::rng;
std::uniform_int_distribution<std::mt19937::result_type> IDGenerator::dist = std::uniform_int_distribution<std::mt19937::result_type>(0, 1000000);

class IOStream
{
protected:
    virtual void Print(std::ostream &) const = 0;

    friend std::ostream &operator<<(std::ostream &, const IOStream &);
    friend std::ostream &operator<<(std::ostream &, const IOStream *);

    virtual ~IOStream();
};

class TipNuExistaException : public std::exception
{
public:
    [[nodiscard]] const char *what() const noexcept override;
};

const char *TipNuExistaException::what() const noexcept
{
    return "Tipul introdus nu exista!";
}

class InvalidOptionException : public std::exception
{
public:
    [[nodiscard]] const char *what() const noexcept override;
};

const char *InvalidOptionException::what() const noexcept
{
    return "Optiune invalida!";
}

std::ostream &operator<<(std::ostream &os, const IOStream &obj)
{
    obj.Print(os);
    return os;
}

std::ostream &operator<<(std::ostream &os, const IOStream *obj)
{
    obj->Print(os);
    return os;
}

IOStream::~IOStream() = default;

class Masina : public IOStream
{
protected:
    int anulInceperiiProd = 0;
    std::string nume;
    std::string model;
    float vitezaMaxima = 0;
    float greutate = 0;

public:
    Masina() = default;

    Masina(int anulInceperiiProd, const std::string &nume, const std::string &model, float vitezaMaxima, float greutate);

    virtual ~Masina() = default;

    // const int getAnulInceperiiProd() const;
    // const std::string getNume() const;
    // const std::string getModel() const;
    // const float getVitezaMaxima() const;
    // const float getGreutate() const;

    // void setAnulInceperiiProd(int anulInceperiiProd_);
    // void setNume(std::string nume_);
    // void setModel(std::string model_);
    // void setVitezaMaxima(float vitezaMaxima_);
    // void setGreutate(float greutate_);

    virtual float calculeazaAutonomia() const = 0;

    friend std::istream &operator>>(std::istream &in, Masina &masina);
};

Masina::Masina(int anulInceperiiProd, const std::string &nume, const std::string &model, float vitezaMaxima, float greutate) : anulInceperiiProd(anulInceperiiProd), nume(nume), model(model), vitezaMaxima(vitezaMaxima), greutate(greutate) {}

// const int Masina::getAnulInceperiiProd() const
// {
//     return this->anulInceperiiProd;
// }

// void Masina::setAnulInceperiiProd(int anulInceperiiProd_)
// {
//     this->anulInceperiiProd = anulInceperiiProd_;
// }

std::istream &operator>>(std::istream &in, Masina &masina)
{
    std::cout << "Introdu anul inceperii productiei: ";
    in >> masina.anulInceperiiProd;
    std::cout << "Introdu numele: ";
    in >> masina.nume;
    std::cout << "Introdu modelul: ";
    in >> masina.model;
    std::cout << "Introdu viteza maxima: ";
    in >> masina.vitezaMaxima;
    std::cout << "Introdu greutatea: ";
    in >> masina.greutate;
    return in;
}

class MasinaFosil : public Masina
{
    std::string tipCombustibil;
    int capacitateRezervor = 0;

public:
    MasinaFosil() = default;

    MasinaFosil(int anulInceperiiProd, const std::string &nume, const std::string &model, float vitezaMaxima,
                float greutate, const std::string &tipCombustibil, int capacitateRezervor);

    ~MasinaFosil() = default;

    // const std::string getTipCombustibil() const;
    // const int getcapacitateRezervor() const;

    // void setTipCombustibil(std::string tipCombustibil_);
    // void setCapacitateRezervor(int capacitateRezervor_);

    void Print(std::ostream &) const override;

    float calculeazaAutonomia() const override;

    friend std::istream &operator>>(std::istream &in, MasinaFosil &masinaFosil);
};

MasinaFosil::MasinaFosil(int anulInceperiiProd, const std::string &nume, const std::string &model, float vitezaMaxima,
                         float greutate, const std::string &tipCombustibil, int capacitateRezervor) : Masina(anulInceperiiProd, nume, model, vitezaMaxima, greutate),
                                                                                                      tipCombustibil(tipCombustibil), capacitateRezervor(capacitateRezervor) {}

void MasinaFosil::Print(std::ostream &os) const
{
    os << "Masina pe combustibili fosili" << std::endl;
    os << "Anul Inceperii Productiei: " << this->anulInceperiiProd << std::endl;
    os << "Numele masinii: " << this->nume << std::endl;
    os << "Modelul: " << this->model << std::endl;
    os << "Viteza maxima: " << this->vitezaMaxima << std::endl;
    os << "Greutate: " << this->greutate << std::endl;
    os << "Tip combustibil: " << this->tipCombustibil << std::endl;
    os << "Capacitate Rezervor: " << this->capacitateRezervor << std::endl;
}

float MasinaFosil::calculeazaAutonomia() const
{
    return capacitateRezervor / sqrt(greutate);
}

std::istream &operator>>(std::istream &in, MasinaFosil &masinaFosil)
{
    in >> dynamic_cast<Masina &>(masinaFosil);
    std::cout << "Introdu tipul combustibilului: ";
    in >> masinaFosil.tipCombustibil;
    std::cout << "Introdu capacitatea rezervorului: ";
    in >> masinaFosil.capacitateRezervor;
    return in;
}

class MasinaElectrica : public Masina
{
    int capacitateBaterie = 0;

public:
    MasinaElectrica() = default;

    MasinaElectrica(int anulInceperiiProd, const std::string &nume, const std::string &model, float vitezaMaxima,
                    float greutate, int capacitateBaterie);

    ~MasinaElectrica() = default;

    // const int getCapacitateBaterie() const;

    // void setCapacitateBaterie(int capacitateBaterie_);

    void Print(std::ostream &) const override;

    float calculeazaAutonomia() const override;

    friend std::istream &operator>>(std::istream &in, MasinaElectrica &masinaElectrica);
};

MasinaElectrica::MasinaElectrica(int anulInceperiiProd, const std::string &nume, const std::string &model, float vitezaMaxima,
                                 float greutate, int capacitateBaterie) : Masina(anulInceperiiProd, nume, model, vitezaMaxima, greutate),
                                                                          capacitateBaterie(capacitateBaterie) {}

void MasinaElectrica::Print(std::ostream &os) const
{
    os << "Masina electrica" << std::endl;
    os << "Anul Inceperii Productiei: " << this->anulInceperiiProd << std::endl;
    os << "Numele masinii: " << this->nume << std::endl;
    os << "Modelul: " << this->model << std::endl;
    os << "Viteza maxima: " << this->vitezaMaxima << std::endl;
    os << "Greutate: " << this->greutate << std::endl;
    os << "Capacitate baterie: " << this->capacitateBaterie << std::endl;
}

float MasinaElectrica::calculeazaAutonomia() const
{
    return capacitateBaterie / (greutate * greutate);
}

std::istream &operator>>(std::istream &in, MasinaElectrica &masinaElectrica)
{
    in >> dynamic_cast<Masina &>(masinaElectrica);
    std::cout << "Introdu capacitatea bateriei: ";
    in >> masinaElectrica.capacitateBaterie;
    return in;
}

class Tranzactie : public IOStream
{
    std::string numeClient;
    std::string dataTranzactie;
    std::vector<std::shared_ptr<Masina>> modeleAchizitionate;

public:
    Tranzactie() = default;

    Tranzactie(const std::string &numeClient, const std::string &dataTranzactie, const std::vector<std::shared_ptr<Masina>> modeleAchizitionate);

    ~Tranzactie() = default;

    void setModeleAchizitionate(std::vector<std::shared_ptr<Masina>> modeleAchizitionate_);

    void Print(std::ostream &) const override;

    friend std::istream &operator>>(std::istream &in, Tranzactie &tranzactie);
};

Tranzactie::Tranzactie(const std::string &numeClient, const std::string &dataTranzactie, const std::vector<std::shared_ptr<Masina>> modeleAchizitionate)
    : numeClient(numeClient), dataTranzactie(dataTranzactie), modeleAchizitionate(modeleAchizitionate) {}

void Tranzactie::setModeleAchizitionate(std::vector<std::shared_ptr<Masina>> modeleAchizitionate_)
{
    this->modeleAchizitionate = modeleAchizitionate_;
}

void Tranzactie::Print(std::ostream &os) const
{
    os << "Tranzactie" << std::endl;
    os << "Numele clientului: " << numeClient << std::endl;
    os << "Data tranzactiei: " << dataTranzactie << std::endl;
    os << "Modelele achizitionate: " << std::endl;
    for (auto model : modeleAchizitionate)
    {
        os << model << std::endl;
    }
}

std::istream &operator>>(std::istream &in, Tranzactie &tranzactie)
{
    std::cout << "Introdu numele clientului: ";
    in >> tranzactie.numeClient;
    std::cout << "Introdu data tranzactiei (yyyy-mm-dd): ";
    in >> tranzactie.dataTranzactie;
    std::cout << "Introdu numarul de modele din tranzactie: ";
    int nrModele;
    in >> nrModele;
    std::vector<std::shared_ptr<Masina>> modele;
    std::cout << "Introdu modelele unul cate unul: ";

    for (int i = 0; i < nrModele; ++i)
    {
        std::cout << "Introdu tipul de masina dorit (1 - Fosil, 2 - Electrica, 3 - Hibrid): ";
        int tip;

        std::cin >> tip;

        if (tip == 1)
        {
            auto masinaFosil = new MasinaFosil();
            std::cin >> *masinaFosil;

            modele.push_back(std::shared_ptr<Masina>(masinaFosil));
        }
        else if (tip == 2)
        {
            auto masinaElectrica = new MasinaElectrica();
            std::cin >> *masinaElectrica;

            modele.push_back(std::shared_ptr<Masina>(masinaElectrica));
        }
        else if (tip == 3)
        {
            std::cout << "tipul nu a fost implementat" << std::endl;
        }
        else
        {
            throw TipNuExistaException();
        }
    }
    tranzactie.setModeleAchizitionate(modele);

    return in;
}

// Singleton design pattern
class InteractiveMenu
{
private:
    std::vector<Tranzactie> tranzactii;
    std::vector<std::shared_ptr<Masina>> masini;
    int option = 0;
    static InteractiveMenu *singleton;

    InteractiveMenu();
    InteractiveMenu(InteractiveMenu &menu) = delete;
    InteractiveMenu &operator=(InteractiveMenu &obj) = delete;

public:
    void showStartMenu();
    void showMenu();
    void showMainMenu();
    ~InteractiveMenu();
    static InteractiveMenu *getInstance();
};

InteractiveMenu::InteractiveMenu() {}
InteractiveMenu::~InteractiveMenu() {}

InteractiveMenu *InteractiveMenu::singleton = nullptr;
InteractiveMenu *InteractiveMenu::getInstance()
{
    if (singleton == nullptr)
        singleton = new InteractiveMenu();
    return singleton;
}

void InteractiveMenu::showStartMenu()
{
    std::cout << "Colocviu - POO - Schmidt Robert-Eduard" << std::endl
              << std::endl;

    showMenu();
}

void InteractiveMenu::showMenu()
{
    std::cout << "1. Adauga masina" << std::endl
              << "2. Adauga tranzactie" << std::endl
              << "3. Afiseaza cel mai vandut model" << std::endl
              << "4. Afiseaza modelul cu autonomia cea mai mare" << std::endl
              << "5. Optimieaza modelul" << std::endl
              << "0. Inchide meniul" << std::endl;

    std::cout << "Introduceti optiunea: ";

    std::cin >> option;

    showMainMenu();
}

void InteractiveMenu::showMainMenu()
{
    try
    {
        switch (option)
        {
        case 1:
        { // adauga masina
            std::cout << "Introdu tipul de masina dorit (1 - Fosil, 2 - Electrica, 3 - Hibrid): ";
            int tip;

            std::cin >> tip;

            if (tip == 1)
            {
                auto masinaFosil = new MasinaFosil();
                std::cin >> *masinaFosil;

                masini.push_back(std::shared_ptr<Masina>(masinaFosil));
            }
            else if (tip == 2)
            {
                auto masinaElectrica = new MasinaElectrica();
                std::cin >> *masinaElectrica;

                masini.push_back(std::shared_ptr<Masina>(masinaElectrica));
            }
            else if (tip == 3)
            {
                std::cout << "tipul nu a fost implementat" << std::endl;
            }
            else
            {
                throw TipNuExistaException();
            }

            showMenu();
            break;
        }
        case 2:
        { // adauga tranzactie
            auto tranzactie = Tranzactie();

            std::cin >> tranzactie;

            tranzactii.push_back(tranzactie);

            showMenu();
            break;
        }
        case 0:
        {
            std::cout << "La revedere!";

            break;
        }
        default:
        { // Invalid option
            std::cin.ignore(255, '\n');
            // std::cin.ignore(255, '\n');
            throw InvalidOptionException();
            break;
        }
        }
    }
    catch (const InvalidOptionException &e)
    {
        std::cout << std::endl
                  << e.what() << std::endl
                  << std::endl;
        showMenu();
    }
    catch (const TipNuExistaException &e)
    {
        std::cout << std::endl
                  << e.what() << std::endl
                  << std::endl;
        showMenu();
    }
    catch (...)
    {
        std::cout << "Unknown exception!" << std::endl;
    }
}

int main()
{
    // auto m1 = new MasinaFosil();

    // std::cout << *m1 << std::endl;

    // auto m2 = new MasinaElectrica();

    // std::cout << *m2 << std::endl;

    // std::vector<std::shared_ptr<Masina>> vect;

    // vect.push_back(std::shared_ptr<Masina>(m1));
    // vect.push_back(std::shared_ptr<Masina>(m2));

    // Tranzactie t1("Schmidt Robert", "10-01-2023", vect);

    // std::cout << t1;

    InteractiveMenu *menu = InteractiveMenu::getInstance();

    menu->showStartMenu();
}