/*
    Schmidt Robert-Eduard 264
    GCC 8.1.0 x86_64-w64-mingw32
    Octavian Comanescu
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <random>
#include <memory>

class InvalidOptionException : public std::exception
{
public:
    [[nodiscard]] const char *what() const noexcept override;
};

const char *InvalidOptionException::what() const noexcept
{
    return "Optiune invalida!";
}

// preluata de la laborator, pentru usurinta afisarii
class IOStream
{
protected:
    virtual void Print(std::ostream &) const = 0;

    friend std::ostream &operator<<(std::ostream &, const IOStream &);
    friend std::ostream &operator<<(std::ostream &, const IOStream *);

    virtual ~IOStream();
};

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

// preluata din cod propriu, pentru usurinta generarii id urilor
class IDGenerator
{
private:
    static unsigned int nextIDInt;
    static uint64_t nextID;
    static std::unordered_map<uint64_t, bool> usedIDs;

public:
    static std::string generateID()
    {
        std::string s;
        while (usedIDs.find(nextID) != usedIDs.end())
        {
            nextID++;
        }

        s = "ID-" + std::to_string(nextID++);

        return s;
    }

    static unsigned int generateIDInt()
    {
        return nextIDInt++;
    }
};

unsigned int IDGenerator::nextIDInt = 1;
uint64_t IDGenerator::nextID = 0;
std::unordered_map<uint64_t, bool> IDGenerator::usedIDs;

enum culori
{
    rosu,
    albastru,
    galben,
    alb,
    negru
};

class Unealta : public IOStream
{
protected:
    const std::string serie;
    const unsigned int numarSerie;
    culori culoare;

public:
    Unealta();
    Unealta(culori culoare);
    virtual ~Unealta();

    virtual float calculeazaTimpDezapezire(float suprafataCuratata) const = 0;
    virtual float calculeazaConsumEnergie(float suprafataCuratata) const = 0;

    friend std::istream &operator>>(std::istream &in, Unealta &unealta);
};

Unealta::Unealta() : serie(IDGenerator::generateID()),
                     numarSerie(IDGenerator::generateIDInt())
{
    culoare = alb;
}

Unealta::Unealta(culori culoare) : serie(IDGenerator::generateID()),
                                   numarSerie(IDGenerator::generateIDInt()), culoare(culoare) {}

Unealta::~Unealta() {}

std::istream &operator>>(std::istream &in, Unealta &unealta)
{
    std::cout << "Introduceti culoarea uneltii" << std::endl
              << "0 - rosu, 1 - albastru,  2 - galben,  3 - alb,  4 - negru" << std::endl;
    int x;
    in >> x;
    if (x < 0 || x > 4)
        throw InvalidOptionException();
    switch (x)
    {
    case 0:
        unealta.culoare = rosu;
        break;
    case 1:
        unealta.culoare = albastru;
        break;
    case 2:
        unealta.culoare = galben;
        break;
    case 3:
        unealta.culoare = alb;
        break;
    case 4:
        unealta.culoare = negru;
        break;
    }

    return in;
}

class LopataElectrica : public Unealta
{
    float suprafataFaras;
    float capacitateBaterie;

public:
    LopataElectrica();
    LopataElectrica(culori culoare, float suprafataFaras, float capacitateBaterie);
    ~LopataElectrica();

    float calculeazaTimpDezapezire(float suprafataCuratata) const;
    float calculeazaConsumEnergie(float suprafataCuratata) const;
    void Print(std::ostream &) const;

    friend std::istream &operator>>(std::istream &in, LopataElectrica &lopataElectrica);
};

LopataElectrica::LopataElectrica() : Unealta(), suprafataFaras(0), capacitateBaterie(0) {}

LopataElectrica::LopataElectrica(culori culoare, float suprafataFaras, float capacitateBaterie)
    : Unealta(culoare), suprafataFaras(suprafataFaras), capacitateBaterie(capacitateBaterie) {}

LopataElectrica::~LopataElectrica() {}

float LopataElectrica::calculeazaTimpDezapezire(float suprafataCuratata) const
{
    return suprafataCuratata / std::sqrt(suprafataFaras);
}

float LopataElectrica::calculeazaConsumEnergie(float suprafataCuratata) const
{
    return std::pow(suprafataCuratata, 2) * capacitateBaterie;
}

void LopataElectrica::Print(std::ostream &os) const
{
    os << "Lopata electrica" << std::endl;
    os << "Serie: " << serie << std::endl;
    os << "Numar: " << numarSerie << std::endl;
    os << "Culoare: ";

    os << "Suprafata faras: " << suprafataFaras << std::endl;
    os << "Capacitate baterie: " << capacitateBaterie << std::endl;
    os << "Timp dezapezire pe suprafata de 100: " << calculeazaTimpDezapezire(100) << std::endl;
    os << "Consum energie pe suprafata de 100: " << calculeazaConsumEnergie(100) << std::endl;
}

std::istream &operator>>(std::istream &in, LopataElectrica &lopataElectrica)
{
    in >> dynamic_cast<Unealta &>(lopataElectrica);
    std::cout << "Introduceti suprafata farasului: " << std::endl;
    in >> lopataElectrica.suprafataFaras;
    std::cout << "Introduceti capacitatea bateriei: " << std::endl;
    in >> lopataElectrica.capacitateBaterie;

    return in;
}

class Drona : public Unealta
{
    int altitudineMaxima;
    int nrMotoare;

public:
    Drona();
    Drona(culori culoare, int altitudineMaxima, int nrMotoare);
    ~Drona();

    bool curatatTurturi() const;
    float calculeazaTimpDezapezire(float suprafataCuratata) const;
    float calculeazaConsumEnergie(float suprafataCuratata) const;
    void Print(std::ostream &) const;

    friend std::istream &operator>>(std::istream &in, Drona &drona);
};

Drona::Drona() : Unealta(), altitudineMaxima(0), nrMotoare(0) {}

Drona::Drona(culori culoare, int altitudineMaxima, int nrMotoare)
    : Unealta(culoare), altitudineMaxima(altitudineMaxima), nrMotoare(nrMotoare) {}

Drona::~Drona() {}

bool Drona::curatatTurturi() const
{
    srand(0);
    return rand() % 2;
}

float Drona::calculeazaTimpDezapezire(float suprafataCuratata) const
{
    return std::log(suprafataCuratata) * std::tanh(altitudineMaxima);
}

float Drona::calculeazaConsumEnergie(float suprafataCuratata) const
{
    return suprafataCuratata * std::pow(nrMotoare, 3);
}

void Drona::Print(std::ostream &os) const
{
    os << "Drona" << std::endl;
    os << "Serie: " << serie << std::endl;
    os << "Numar: " << numarSerie << std::endl;
    os << "Culoare: ";

    os << "Altitudine maxima: " << altitudineMaxima << std::endl;
    os << "Numar motoare: " << nrMotoare << std::endl;
    os << "Timp dezapezire pe suprafata de 100: " << calculeazaTimpDezapezire(100) << std::endl;
    os << "Consum energie pe suprafata de 100: " << calculeazaConsumEnergie(100) << std::endl;
}

std::istream &operator>>(std::istream &in, Drona &drona)
{
    in >> dynamic_cast<Unealta &>(drona);
    std::cout << "Introduceti altitudinea maxima: " << std::endl;
    in >> drona.altitudineMaxima;
    std::cout << "Introduceti numarul de motoare: " << std::endl;
    in >> drona.nrMotoare;

    return in;
}

class UnealtaPrototip : public Unealta
{
    int ceva1;
    int ceva2;

public:
    UnealtaPrototip();
    UnealtaPrototip(culori culoare, int ceva1, int ceva2);
    ~UnealtaPrototip();

    float calculeazaTimpDezapezire(float suprafataCuratata) const;
    float calculeazaConsumEnergie(float suprafataCuratata) const;
    void Print(std::ostream &) const;

    friend std::istream &operator>>(std::istream &in, UnealtaPrototip &unealtaPrototip);
};

UnealtaPrototip::UnealtaPrototip() : Unealta(), ceva1(0), ceva2(0) {}

UnealtaPrototip::UnealtaPrototip(culori culoare, int ceva1, int ceva2)
    : Unealta(culoare), ceva1(ceva1), ceva2(ceva2) {}

UnealtaPrototip::~UnealtaPrototip() {}

float UnealtaPrototip::calculeazaTimpDezapezire(float suprafataCuratata) const
{
    return suprafataCuratata * 2 / std::pow(ceva1, 2) / ceva2;
}

float UnealtaPrototip::calculeazaConsumEnergie(float suprafataCuratata) const
{
    return suprafataCuratata * std::sqrt(ceva1) + ceva2;
}

void UnealtaPrototip::Print(std::ostream &os) const
{
    os << "Unealta Prototip" << std::endl;
}

class Echipa : public IOStream
{
    std::string nume;
    std::string motto;
    std::vector<std::shared_ptr<Unealta>> unelte;

public:
    Echipa();
    Echipa(const std::string &nume, const std::string &motto, std::vector<std::shared_ptr<Unealta>> unelte);
    ~Echipa();

    void setUnelte(std::vector<std::shared_ptr<Unealta>> unelte);
    void addUnealta(std::shared_ptr<Unealta> unealta);
    void Print(std::ostream &) const;

    friend std::istream &operator>>(std::istream &in, Echipa &echipa);
};

Echipa::Echipa() {}

Echipa::Echipa(const std::string &nume, const std::string &motto, std::vector<std::shared_ptr<Unealta>> unelte)
    : nume(nume), motto(motto), unelte(unelte) {}

Echipa::~Echipa() {}

void Echipa::setUnelte(std::vector<std::shared_ptr<Unealta>> unelte_)
{
    unelte = unelte_;
}

void Echipa::addUnealta(std::shared_ptr<Unealta> unealta)
{
    unelte.push_back(unealta);
}

void Echipa::Print(std::ostream &os) const
{
    os << "Echipa" << std::endl;
    os << "Nume: " << nume << std::endl;
    os << "Motto: " << motto << std::endl;
    os << "Unelte: " << std::endl;

    for (auto unealta: unelte)
    {
        os << *unealta;
    }
}

std::istream &operator>>(std::istream &in, Echipa &echipa)
{
    std::cout << "Introduceti numele echipei: " << std::endl;
    in.ignore(255, '\n');
    std::getline(in, echipa.nume);
    std::cout << "Introdu motto-ul echipei: " << std::endl;
    in.ignore(255, '\n');
    std::getline(in, echipa.motto);
    std::cout << " Introdu numarul de unelte ale echipei: " << std::endl;
    int nr;
    in >> nr;
    for (int i = 0; i < nr; ++i)
    {
        std::cout << "Introdu tipul de unealta (1 - Lopata electrica, 2 - Drona, 3 - Unealta Prototip): " << std::endl;
        int x;
        in >> x;
        if (x == 1)
        {
            auto l = new LopataElectrica();

            in >> *l;

            echipa.addUnealta(std::shared_ptr<Unealta>(l));
        }
        else if (x == 2)
        {
            auto l = new Drona();

            in >> *l;

            echipa.addUnealta(std::shared_ptr<Unealta>(l));
        }
        else if (x == 3)
        {
            std::cout << "Nu am implementat a treia unealta";
        }
        else
            throw InvalidOptionException();
    }

    return in;
}

class Competitie : public IOStream
{
    std::string id;
    std::vector<Echipa> echipe;

public:
    Competitie();
    Competitie(std::vector<Echipa> echipe);
    ~Competitie();

    void addEchipa(Echipa echipa);
    void Print(std::ostream &) const;

    friend std::istream &operator>>(std::istream &in, Competitie &competitie);
};

Competitie::Competitie() : id(IDGenerator::generateID()) {}

Competitie::Competitie(std::vector<Echipa> echipe)
    : id(IDGenerator::generateID()), echipe(echipe) {}

Competitie::~Competitie() {}

void Competitie::addEchipa(Echipa echipa)
{
    echipe.push_back(echipa);
}

void Competitie::Print(std::ostream &os) const
{
    os << "Competitie" << std::endl;
    os << "ID: " << id << std::endl;
    os << "Echipe: " << std::endl;
    for (auto echipa : echipe)
    {
        os << echipa << std::endl;
    }
}

std::istream &operator>>(std::istream &in, Competitie &competitie)
{
    std::cout << "Introdu numarul de echipe: " << std::endl;
    int x;
    in >> x;

    for (int i = 0; i < x; ++i)
    {
        Echipa e;

        in >> e;

        competitie.addEchipa(e);
    }

    return in;
}

// preluat din cod propriu, pentru scriere de cod mai rapid
// sablon de proiectare Singleton
class InteractiveMenu
{
private:
    std::vector<Competitie> competitii;
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
    std::cout << "1. Adauga Competitie" << std::endl
              << "2. Adauga Echipa la competitie" << std::endl
              << "3. Afiseaza competitia x" << std::endl
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
        { // adauga competitie

            Competitie a;
            std::cin >> a;

            competitii.push_back(a);

            showMenu();
            break;
        }
        case 2:
        { // adauga echipa la competitie
            std::cout << "La ce competitie vrei sa adaugi? Intre 0 si " << competitii.size() << std::endl;
            size_t x;
            std::cin >> x;
            if (x > competitii.size())
                throw InvalidOptionException();

            Echipa e;
            std::cin >> e;

            competitii[x].addEchipa(e);

            showMenu();
            break;
        }
        case 3:
        { // Afiseaza competitia x
            std::cout << "Ce competitie vrei sa afisezi? Intre 0 si " << competitii.size() << std::endl;
            size_t x;
            std::cin >> x;
            if (x > competitii.size())
                throw InvalidOptionException();
            
            std::cout << competitii[x];

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
    catch (...)
    {
        std::cout << "Unknown exception!" << std::endl;
    }
}

int main()
{
    InteractiveMenu *menu = InteractiveMenu::getInstance();

    menu->showStartMenu();

    return 0;
}