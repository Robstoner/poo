#include <iostream>
#include <cstring>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class masinaCurierat
{
    char *marca;
    char *model;
    char *numarInm;
    char *dataAchizitiei;
    char *ultService;

public:
    masinaCurierat()
    {
        marca = new char[8];
        strcpy(marca, "Default");

        model = new char[8];
        strcpy(model, "Default");

        numarInm = new char[10];
        strcpy(numarInm, "IF 12 ABC");

        dataAchizitiei = new char[11];
        strcpy(dataAchizitiei, "2022-01-01");

        ultService = new char[11];
        strcpy(ultService, "2022-01-01");
    }

    masinaCurierat(char *marca_, char *model_, char *numarInm_, char *dataAchizitiei_, char *ultService_)
    {
        marca = new char[strlen(marca_)];
        strcpy(marca, marca_);

        model = new char[strlen(model_)];
        strcpy(model, model_);

        numarInm = new char[strlen(numarInm_)];
        strcpy(numarInm, numarInm_);

        dataAchizitiei = new char[strlen(dataAchizitiei_)];
        strcpy(dataAchizitiei, dataAchizitiei_);

        ultService = new char[strlen(ultService_)];
        strcpy(ultService, ultService_);
    }

    masinaCurierat(const masinaCurierat &oldMasina)
    {
        marca = new char[strlen(oldMasina.marca) + 1];
        strcpy(marca, oldMasina.marca);

        model = new char[strlen(oldMasina.model) + 1];
        strcpy(model, oldMasina.model);

        numarInm = new char[strlen(oldMasina.numarInm) + 1];
        strcpy(numarInm, oldMasina.numarInm);

        dataAchizitiei = new char[strlen(oldMasina.dataAchizitiei) + 1];
        strcpy(dataAchizitiei, oldMasina.dataAchizitiei);

        ultService = new char[strlen(oldMasina.ultService) + 1];
        strcpy(ultService, oldMasina.ultService);
    }

    void afisare() const
    {
        cout << marca << '\n'
             << model << '\n'
             << numarInm << '\n'
             << dataAchizitiei << '\n'
             << ultService << '\n'
             << '\n';
    }

    masinaCurierat &operator=(const masinaCurierat &m)
    {
        if (&m != this)
        {
            delete[] marca;
            marca = new char[strlen(m.marca) + 1];
            strcpy(marca, m.marca);

            delete[] model;
            model = new char[strlen(m.model) + 1];
            strcpy(model, m.model);

            delete[] numarInm;
            numarInm = new char[strlen(m.numarInm) + 1];
            strcpy(numarInm, m.numarInm);

            delete[] dataAchizitiei;
            dataAchizitiei = new char[strlen(m.dataAchizitiei) + 1];
            strcpy(dataAchizitiei, m.dataAchizitiei);

            delete[] ultService;
            ultService = new char[strlen(m.ultService) + 1];
            strcpy(ultService, m.ultService);
        }
        return *this;
    }

    friend ostream &operator<<(ostream &os, const masinaCurierat &m)
    {
        os << m.marca << '\n'
           << m.model << '\n'
           << m.numarInm << '\n'
           << m.dataAchizitiei << '\n'
           << m.ultService << '\n'
           << '\n';

        return os;
    }

    friend istream &operator>>(istream &is, masinaCurierat &m)
    {
        cout << "Introduceti datele masinii:\n";
        char tmp[500];
        cout << "Marca: ";
        is.ignore(1, '\n');

        is.get(tmp, 500);
        delete[] m.marca;
        m.marca = new char[strlen(tmp) + 1];
        strcpy(m.marca, tmp);

        is.ignore(1, '\n');

        cout << "Modelul: ";
        is.getline(tmp, 256, '\n');
        delete[] m.model;
        m.model = new char[strlen(tmp) + 1];
        strcpy(m.model, tmp);

        cout << "Numarul de inmatriculare: ";
        is.getline(tmp, 256, '\n');
        delete[] m.numarInm;
        m.numarInm = new char[strlen(tmp) + 1];
        strcpy(m.numarInm, tmp);

        cout << "Data achizitiei: ";
        is >> tmp;
        delete[] m.dataAchizitiei;
        m.dataAchizitiei = new char[strlen(tmp) + 1];
        strcpy(m.dataAchizitiei, tmp);

        cout << "Data ultimului service: ";
        is >> tmp;
        delete[] m.ultService;
        m.ultService = new char[strlen(tmp) + 1];
        strcpy(m.ultService, tmp);

        return is;
    }

    bool operator==(const masinaCurierat &b) const
    {
        if (strcmp(marca, b.marca) || strcmp(model, b.model) || strcmp(numarInm, b.numarInm) || strcmp(dataAchizitiei, b.dataAchizitiei) || strcmp(ultService, b.ultService))
            return false;
        return true;
    }

    bool operator!=(const masinaCurierat &b) const
    {
        if (!(strcmp(marca, b.marca) || strcmp(model, b.model) || strcmp(numarInm, b.numarInm) || strcmp(dataAchizitiei, b.dataAchizitiei) || strcmp(ultService, b.ultService)))
            return false;
        return true;
    }

    [[maybe_unused]] char *getMarca() const { return marca; }

    [[maybe_unused]] char *getModel() const { return model; }

    [[maybe_unused]] char *getNumarInm() const { return numarInm; }

    [[maybe_unused]] char *getDataAchizitiei() const { return dataAchizitiei; }

    [[maybe_unused]] char *getUltService() const { return ultService; }

    [[maybe_unused]] void setMarca(char *marca_)
    {
        delete[] marca;
        marca = new char[strlen(marca_) + 1];
        strcpy(marca, marca_);
    }

    [[maybe_unused]] void setModel(char *model_)
    {
        delete[] model;
        model = new char[strlen(model_) + 1];
        strcpy(model, model_);
    }

    [[maybe_unused]] void setNumarInm(char *numarInm_)
    {
        delete[] numarInm;
        numarInm = new char[strlen(numarInm_) + 1];
        strcpy(numarInm, numarInm_);
    }

    [[maybe_unused]] void setDataAchizitiei(char *dataAchizitiei_)
    {
        delete[] dataAchizitiei;
        dataAchizitiei = new char[strlen(dataAchizitiei_) + 1];
        strcpy(dataAchizitiei, dataAchizitiei_);
    }

    [[maybe_unused]] void setUltService(char *ultService_)
    {
        delete[] ultService;
        ultService = new char[strlen(ultService_) + 1];
        strcpy(ultService, ultService_);
    }

    ~masinaCurierat()
    {
        delete[] marca;
        delete[] model;
        delete[] numarInm;
        delete[] dataAchizitiei;
        delete[] ultService;
    }
};

class curier
{
    masinaCurierat masina;
    char *nume;
    int salariu;
    int nrComenzi;

public:
    curier()
    {
        nume = new char[9];
        strcpy(nume, "Default");

        salariu = 0;
        nrComenzi = 0;
    }

    curier(const masinaCurierat &masina_, char *nume_, int salariu_, int nrComenzi_) : masina(masina_)
    {

        nume = new char[strlen(nume_) + 1];
        strcpy(nume, nume_);

        salariu = salariu_;
        nrComenzi = nrComenzi_;
    }

    curier(const curier &oldCurier) : masina(oldCurier.masina)
    {

        nume = new char[strlen(oldCurier.nume) + 1];
        strcpy(nume, oldCurier.nume);

        salariu = oldCurier.salariu;
        nrComenzi = oldCurier.nrComenzi;
    }

    void afisare() const
    {
        cout << "--Curier" << '\n';
        cout << nume << '\n'
             << salariu << '\n'
             << nrComenzi << '\n';
        cout << "--Masina curierului\n";
        masina.afisare();
    }

    curier &operator=(const curier &c)
    {
        if (&c == this)
            return *this;

        masina = c.masina;

        delete[] nume;
        nume = new char[strlen(c.nume) + 1];
        strcpy(nume, c.nume);

        salariu = c.salariu;
        nrComenzi = c.nrComenzi;

        return *this;
    }

    friend ostream &operator<<(ostream &os, const curier &c)
    {
        os << c.nume << '\n'
           << c.salariu << '\n'
           << c.nrComenzi << '\n';
        os << "--- Masina curierului ---\n";
        os << c.masina;

        return os;
    }

    friend istream &operator>>(istream &is, curier &c)
    {
        cout << "Introduceti datele curierului:\n";

        char tmp[100];
        cout << "Numele: ";
        is.ignore(1, '\n');
        is.getline(tmp, 99, '\n');
        delete[] c.nume;
        c.nume = new char[strlen(tmp) + 1];
        strcpy(c.nume, tmp);

        cout << "Salariul: ";
        is >> c.salariu;
        cout << "Numarul de comenzi zilnice: ";
        is >> c.nrComenzi;

        is >> c.masina;

        return is;
    }

    bool operator==(const curier &b) const
    {
        if (masina != b.masina)
            return false;
        if (strcmp(nume, b.nume))
            return false;
        if ((salariu != b.salariu) || (nrComenzi != b.nrComenzi))
            return false;
        return true;
    }

    bool operator!=(const curier &b) const
    {
        if (masina != b.masina)
            return true;
        if (strcmp(nume, b.nume))
            return true;
        if ((salariu != b.salariu) || (nrComenzi != b.nrComenzi))
            return true;
        return false;
    }

    masinaCurierat getMasina() const { return masina; }

    [[maybe_unused]] char *getNume() const { return nume; }

    [[maybe_unused]] int getSalariu() const { return salariu; }

    [[maybe_unused]] int getNrComenzi() const { return nrComenzi; }

    [[maybe_unused]] void setMasina(const masinaCurierat &masina_)
    {
        masina = masina_;
    }

    [[maybe_unused]] void setNume(char *nume_)
    {
        delete[] nume;
        nume = new char[strlen(nume_) + 1];
        strcpy(nume, nume_);
    }

    [[maybe_unused]] void setSalariu(int salariu_)
    {
        salariu = salariu_;
    }

    [[maybe_unused]] void setNrComenzi(int nrComenzi_)
    {
        nrComenzi = nrComenzi_;
    }

    ~curier()
    {
        delete[] nume;
    }
};

class firmaCurierat
{
    curier **curieri;
    char *numeComplet;
    char *locatie;
    int nrCurieri;
    int nrComenzi;

public:
    firmaCurierat()
    {
        curieri = new curier *[1];
        curieri[0] = new curier;

        nrCurieri = 1;

        nrComenzi = 0;

        locatie = new char[8];
        strcpy(locatie, "Default");

        numeComplet = new char[8];
        strcpy(numeComplet, "Default");
    }

    firmaCurierat(int nrComenzi_, char *locatie_, char *numeComplet_)
    {
        curieri = new curier *[1];
        curieri[0] = new curier;
        nrCurieri = 1;

        nrComenzi = nrComenzi_;

        locatie = new char[strlen(locatie_)];
        strcpy(locatie, locatie_);

        locatie = new char[strlen(numeComplet_)];
        strcpy(numeComplet, numeComplet_);
    }

    firmaCurierat(const firmaCurierat &oldFirmaCurierat)
    {
        curieri = new curier *[oldFirmaCurierat.nrCurieri];
        for (int i = 0; i < oldFirmaCurierat.nrCurieri; ++i)
        {
            curieri[i] = new curier;
            curieri[i] = oldFirmaCurierat.curieri[i];
        }

        nrCurieri = oldFirmaCurierat.nrCurieri;
        nrComenzi = oldFirmaCurierat.nrComenzi;

        locatie = new char[strlen(oldFirmaCurierat.locatie) + 1];
        strcpy(locatie, oldFirmaCurierat.locatie);

        numeComplet = new char[strlen(oldFirmaCurierat.numeComplet) + 1];
        strcpy(numeComplet, oldFirmaCurierat.numeComplet);
    }

    void afisare() const
    {
        cout << numeComplet << '\n'
             << locatie << '\n'
             << nrComenzi << '\n';
        for (int i = 0; i < nrCurieri; ++i)
        {
            curieri[i]->afisare();
        }
    }

    firmaCurierat &operator=(const firmaCurierat &f)
    {
        if (&f == this)
            return *this;

        for (int i = 0; i < nrCurieri; ++i)
        {
            delete curieri[i];
        }
        delete[] curieri;

        curieri = new curier *[f.nrCurieri];
        for (int i = 0; i < f.nrCurieri; ++i)
        {
            curieri[i] = new curier;
            *curieri[i] = *f.curieri[i];
        }

        nrCurieri = f.nrCurieri;
        nrComenzi = f.nrComenzi;

        delete[] locatie;
        locatie = new char[strlen(f.locatie) + 1];
        strcpy(locatie, f.locatie);

        delete[] numeComplet;
        numeComplet = new char[strlen(f.numeComplet) + 1];
        strcpy(numeComplet, f.numeComplet);

        return *this;
    }

    friend ostream &operator<<(ostream &os, const firmaCurierat &f)
    {
        os << f.numeComplet << '\n'
           << f.locatie << '\n'
           << f.nrComenzi << '\n';
        for (int i = 0; i < f.nrCurieri; ++i)
        {
            os << "--- Curierul " << i + 1 << " ---\n";
            os << *f.curieri[i];
        }

        return os;
    }

    friend istream &operator>>(istream &is, firmaCurierat &f)
    {
        cout << "Introduceti datele firmei:\n";

        char tmp[100];
        cout << "Numele complet: ";
        is.ignore(1, '\n');
        is.getline(tmp, 99, '\n');
        delete[] f.numeComplet;
        f.numeComplet = new char[strlen(tmp) + 1];
        strcpy(f.numeComplet, tmp);

        cout << "Locatia: ";
        is.getline(tmp, 99, '\n');
        delete[] f.locatie;
        f.locatie = new char[strlen(tmp) + 1];
        strcpy(f.locatie, tmp);

        cout << "Numarul de comenzi zilnice: ";
        is >> f.nrComenzi;

        cout << "Numarul de curieri: ";
        is >> f.nrCurieri;

        f.curieri = new curier *[f.nrCurieri];

        for (int i = 0; i < f.nrCurieri; ++i)
        {
            f.curieri[i] = new curier;
            is >> *f.curieri[i];
        }

        return is;
    }

    bool operator==(const firmaCurierat &b) const
    {
        if ((nrCurieri != b.nrCurieri) || (nrComenzi != b.nrComenzi))
            return false;
        if (strcmp(numeComplet, b.numeComplet) || strcmp(locatie, b.locatie))
            return false;
        for (int i = 0; i < nrCurieri; ++i)
        {
            if (*curieri[i] != *b.curieri[i])
                return false;
        }
        return true;
    }

    bool operator!=(const firmaCurierat &b) const
    {
        if ((nrCurieri != b.nrCurieri) || (nrComenzi != b.nrComenzi))
            return true;
        if (strcmp(numeComplet, b.numeComplet) || strcmp(locatie, b.locatie))
            return true;
        for (int i = 0; i < nrCurieri; ++i)
        {
            if (*curieri[i] != *b.curieri[i])
                return true;
        }
        return false;

        // return !(*this == b);
    }

    firmaCurierat &operator+=(const curier &rhs)
    {
        curier **tmp = new curier *[nrCurieri];
        for (int i = 0; i < nrCurieri; ++i)
        {
            tmp[i] = new curier;
            *tmp[i] = *curieri[i];
        }

        for (int i = 0; i < nrCurieri; ++i)
        {
            delete curieri[i];
        }
        delete[] curieri;

        curieri = new curier *[nrCurieri + 1];
        for (int i = 0; i < nrCurieri; ++i)
        {
            curieri[i] = new curier;
            *curieri[i] = *tmp[i];
        }

        curieri[nrCurieri] = new curier;
        *curieri[nrCurieri] = rhs;
        nrCurieri++;

        return *this;
    }

    [[maybe_unused]] curier **getCurieri() const { return curieri; }

    [[maybe_unused]] curier *getCurier(int x) { return curieri[x]; }

    [[maybe_unused]] const char *getNumeComplet() const { return numeComplet; }

    [[maybe_unused]] const char *getLocatie() const { return locatie; }

    [[maybe_unused]] int getNrComenzi() const { return nrComenzi; }

    [[maybe_unused]] int getNrCurieri() const { return nrCurieri; }

    [[maybe_unused]] void setNrComenzi(int nrComenzi_) { nrComenzi = nrComenzi_; }

    [[maybe_unused]] void setLocatie(char *locatie_)
    {
        delete[] locatie;
        locatie = new char[strlen(locatie_) + 1];
        strcpy(locatie, locatie_);
    }

    [[maybe_unused]] void setNumeComplet(char *numeComplet_)
    {
        delete[] numeComplet;
        numeComplet = new char[strlen(numeComplet_) + 1];
        strcpy(numeComplet, numeComplet_);
    }

    ~firmaCurierat()
    {
        delete[] locatie;
        delete[] numeComplet;
        for (int i = 0; i < nrCurieri; ++i)
        {
            delete curieri[i];
        }
        delete[] curieri;
    }
};

int main()
{
    int x = 1;

    cout << "Introduceti un numar pentru a selecte optiunea dorita:\n"
         << "1. Inserati o masina de curierat\n"
         << "2. Inserati un curier\n"
         << "3. Inserati o firma de curierat\n"
         << "4. Creati o firma de curierat, apoi setati locatia ei\n"
         << "5. Introduceti o masina, apoi creati un curier si setati masina respectiva curierului\n"
         << "6. Adaugati un curier la o firma de curierat.\n"
         << "0. Iesire\n";

    cin >> x;

    while (x)
    {
        switch (x)
        {
        case 1:
        {
            masinaCurierat A;
            cout << A;
            cin >> A;
            cout << A;
            return 0;
        }
        case 2:
        {
            curier A;
            cout << A;
            cin >> A;
            cout << A;
            return 0;
        }
        case 3:
        {
            firmaCurierat A;
            cout << A;
            cin >> A;
            cout << A;
            return 0;
        }
        case 4:
        {
            firmaCurierat A;
            cout << A;

            char tmp[100];

            cout << "Introduceti locatia: ";
            cin >> tmp;
            A.setLocatie(tmp);
            cout << A;

            return 0;
        }
        case 5:
        {
            masinaCurierat A;
            cout << A;
            cin >> A;
            cout << A;

            curier B;
            cout << B;

            B.setMasina(A);
            cout << B;

            return 0;
        }
        case 6:
        {
            firmaCurierat A;
            cout << A;
            cin >> A;
            cout << A;

            curier B;
            cin >> B;

            A += B;
            cout << A;

            return 0;
        }
        default:
            cout << "Optiune invalida, introduceti o valoare corecta dintre urmatoarele: ";
            cout << "Introduceti un numar pentru a selecte optiunea dorita:\n"
                 << "1. Inserati o masina de curierat\n"
                 << "2. Inserati un curier\n"
                 << "3. Inserati o firma de curierat\n"
                 << "4. Creati o firma de curierat, apoi setati locatia ei\n"
                 << "5. Introduceti o masina, apoi creati un curier si setati masina respectiva curierului\n"
                 << "6. Adaugati un curier la o firma de curierat.\n"
                 << "0. Iesire\n";
            cin >> x;
            break;
        }
    }
}

/*int main()
{
    // masinaCurierat A;
    // cout << A;

    // cout << "=============================================\n";

    // curier B;
    // cout << B;

    // cout << "=============================================\n";

    // firmaCurierat C;
    // cout << C;

    // cout << "=============================================\n";

    // cout << A;

    // masinaCurierat G = A;

    // masinaCurierat A;
    // cout << A;

    // cin >> A;

    // cout << A;

    // curier B;
    // cout << B;
    // cin >> B;
    // cout << B;

    // firmaCurierat C;

    // cout << C;

    // cin >> C;

    // cout << C;

    // firmaCurierat C;

    // firmaCurierat D;

    // D = C;

    // firmaCurierat F[3];

    // for (int i = 0; i < 3; ++i)
    // {
    //     cin >> F[i];
    //     cout << F[i];
    // }

    // masinaCurierat A, B;
    // A.setMarca("Audi");
    // cout << (A != B);

    // curier A, B;
    // A.setSalariu(2);
    // cout << (A != B);

    // firmaCurierat A, B;
    // A.setNrComenzi(25);
    // cout << (A != B);
}*/