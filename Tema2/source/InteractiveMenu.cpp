#include "../headers/InteractiveMenu.h"
#include "../headers/Curs.h"
#include "../errors/exceptions.h"

int InteractiveMenu::option = 0;
std::vector<std::shared_ptr<Curs>> InteractiveMenu::cursuri;

InteractiveMenu::InteractiveMenu() {}
InteractiveMenu::~InteractiveMenu() {}

void InteractiveMenu::setOption(int option_)
{
    option = option_;
}

void InteractiveMenu::showStartMenu()
{
    std::cout << "Tema 2 - POO - Schmidt Robert-Eduard" << std::endl
              << "In aceasta tema vom lucra cu un sistem de management al unui curs cu salile asociate lui." << std::endl
              << "Salile pot fi de tipul: Amfiteatru, Laborator, Seminar." << std::endl
              << "Amfiteatrul are in plus un numar de randuri si un nume propriu." << std::endl
              << "Seminarul are in plus un tip de tabla." << std::endl
              << "Laboratorul are in plus un tip de tabla si un numar de calculatoare" << std::endl
              << "Cursul are un nume, o lista de sali si o lista de profesori." << std::endl;

    InteractiveMenu::showMenu();
}

void InteractiveMenu::showMenu(bool invalid)
{
    std::cout << "1. Creaza curs" << std::endl
              << "2. Afiseaza curs" << std::endl
              << "3. Afiseaza toate cursurile" << std::endl
              << "4. Sterge curs" << std::endl
              << "5. Adauga amfiteatru" << std::endl
              << "6. Adauga laborator" << std::endl
              << "7. Adauga seminar" << std::endl
              << "8. Adauga profesor" << std::endl
              << "9. Clear console" << std::endl
              << "10. Iesire" << std::endl;

    std::cout << "Introduceti optiunea: ";
    if (invalid)
        std::cin.ignore(255, '\n');

    int option;
    std::cin >> option;
    InteractiveMenu::setOption(option);
    InteractiveMenu::showMainMenu();
}

void InteractiveMenu::showMainMenu()
{
    try
    {
        switch (option)
        {
        case 1:
        { // Creeaza curs
            std::cout << std::endl
                      << "Introduceti numele cursului: ";
            std::string nume_curs;
            std::cin >> nume_curs;

            Curs curs(nume_curs);

            cursuri.push_back(std::make_unique<Curs>(curs));
            std::cout << "Ati introdus cursul " << cursuri.size() - 1 << " cu success!" << std::endl;

            throw ResetMenuException();
            break;
        }
        case 2:
        { // Afiseaza curs
            int i;
            std::cout << std::endl
                      << "Introduceti numarul cursului: ";
            std::cin >> i;
            std::cout << *cursuri[i - 1];

            throw ResetMenuException();
            break;
        }
        case 3:
        { // Afiseaza toate cursurile
            for (size_t i = 0; i < cursuri.size(); i++)
            {
                std::cout << std::endl
                          << "Cursul " << i + 1 << ": " << std::endl;
                std::cout << std::endl
                          << *cursuri[i];
            }

            throw ResetMenuException();
            break;
        }
        case 4:
        { // Sterge un curs
            std::cout << std::endl
                      << "Introduceti numarul cursului: ";
            size_t i;
            std::cin >> i;
            if (i > cursuri.size())
                throw InvalidIndexException();
            cursuri.erase(cursuri.begin() + i - 1);

            throw ResetMenuException();
            break;
        }
        case 5:
        { // Adauga amfiteatru
            std::cout << std::endl
                      << "Introduceti numarul cursului: ";
            int i;
            std::cin >> i;
            try
            {
                std::cout << "Introduceti numele amfiteatrului(salii): ";
                std::string nume;
                std::cin >> nume;
                std::cout << "Introduceti numarul de locuri: ";
                int nr_locuri;
                std::cin >> nr_locuri;
                std::cout << "Introduceti etajul: ";
                int etaj;
                std::cin >> etaj;
                std::cout << "Introduceti numarul salii: ";
                int nr_sala;
                std::cin >> nr_sala;
                std::cout << "Introduceti numarul de echipamente: ";
                int nr_echipamente;
                std::cin >> nr_echipamente;
                std::vector<std::string> echipamente;
                for (int j = 0; j < nr_echipamente; ++j)
                {
                    std::cout << "Introduceti numele echipamentului: ";
                    std::string echipament;
                    std::cin >> echipament;
                    echipamente.push_back(echipament);
                }
                std::cout << "Introduceti numele propriu al amfiteatrului: ";
                std::string nume_amfiteatru;
                std::cin >> nume_amfiteatru;
                std::cout << "Introduceti numarul de randuri: ";
                int nr_randuri;
                std::cin >> nr_randuri;

                Amfiteatru *amf = new Amfiteatru(nume, etaj, nr_sala, nr_locuri, echipamente, nr_randuri, nume_amfiteatru);

                cursuri[i - 1]->adauga_sala(std::shared_ptr<Sala>(amf));
            }
            catch (const SalaExistaException &e)
            {
                std::cout << e.what() << std::endl << std::endl;
            }

            throw ResetMenuException();
            break;
        }
        case 6:
        { // Adauga laborator
            std::cout << std::endl
                      << "Introduceti numarul cursului: ";
            int i;
            std::cin >> i;
            try
            {
                std::cout << "Introduceti numele laboratorului(salii): ";
                std::string nume;
                std::cin >> nume;
                std::cout << "Introduceti numarul de locuri: ";
                int nr_locuri;
                std::cin >> nr_locuri;
                std::cout << "Introduceti etajul: ";
                int etaj;
                std::cin >> etaj;
                std::cout << "Introduceti numarul salii: ";
                int nr_sala;
                std::cin >> nr_sala;
                std::cout << "Introduceti numarul de echipamente: ";
                int nr_echipamente;
                std::cin >> nr_echipamente;
                std::vector<std::string> echipamente;
                for (int j = 0; j < nr_echipamente; ++j)
                {
                    std::cout << "Introduceti numele echipamentului: ";
                    std::string echipament;
                    std::cin >> echipament;
                    echipamente.push_back(echipament);
                }
                std::cout << "Introduceti tipul de tabla din laborator (alba, neagra, smart): ";
                Tip_tabla tip_tabla;
                while (true)
                {
                    std::string tip_tabla_string;
                    std::cin >> tip_tabla_string;
                    if (tip_tabla_string == "alba")
                    {
                        tip_tabla = Tip_tabla::alba;
                        break;
                    }
                    else if (tip_tabla_string == "neagra")
                    {
                        tip_tabla = Tip_tabla::neagra;
                        break;
                    }
                    else if (tip_tabla_string == "smart")
                    {
                        tip_tabla = Tip_tabla::smart;
                        break;
                    }
                    else
                    {
                        std::cout << "Tipul de tabla nu este valid!" << std::endl;
                        std::cout << "Alegeti unul dintre urmatoarele: alba, neagra, smart" << std::endl;
                    }
                }
                std::cout << "Introduceti numarul de calculatoare: ";
                int nr_calculatoare;
                std::cin >> nr_calculatoare;

                Laborator *lab = new Laborator(nume, etaj, nr_sala, nr_locuri, echipamente, tip_tabla, nr_calculatoare);

                cursuri[i - 1]->adauga_sala(std::shared_ptr<Sala>(lab));
            }
            catch (const SalaExistaException &e)
            {
                std::cout << e.what() << std::endl << std::endl;
            }

            throw ResetMenuException();
            break;
        }
        case 7:
        { // Adauga seminar
            std::cout << std::endl
                      << "Introduceti numarul cursului: ";
            int i;
            std::cin >> i;
            try
            {
                std::cout << "Introduceti numele seminarului(salii): ";
                std::string nume;
                std::cin >> nume;
                std::cout << "Introduceti numarul de locuri: ";
                int nr_locuri;
                std::cin >> nr_locuri;
                std::cout << "Introduceti etajul: ";
                int etaj;
                std::cin >> etaj;
                std::cout << "Introduceti numarul salii: ";
                int nr_sala;
                std::cin >> nr_sala;
                std::cout << "Introduceti numarul de echipamente: ";
                int nr_echipamente;
                std::cin >> nr_echipamente;
                std::vector<std::string> echipamente;
                for (int j = 0; j < nr_echipamente; ++j)
                {
                    std::cout << "Introduceti numele echipamentului: ";
                    std::string echipament;
                    std::cin >> echipament;
                    echipamente.push_back(echipament);
                }
                std::cout << "Introduceti tipul de tabla din seminar (alba, neagra, smart): ";
                Tip_tabla tip_tabla;
                while (true)
                {
                    std::string tip_tabla_string;
                    std::cin >> tip_tabla_string;
                    if (tip_tabla_string == "alba")
                    {
                        tip_tabla = Tip_tabla::alba;
                        break;
                    }
                    else if (tip_tabla_string == "neagra")
                    {
                        tip_tabla = Tip_tabla::neagra;
                        break;
                    }
                    else if (tip_tabla_string == "smart")
                    {
                        tip_tabla = Tip_tabla::smart;
                        break;
                    }
                    else
                    {
                        std::cout << "Tipul de tabla nu este valid!" << std::endl;
                        std::cout << "Alegeti unul dintre urmatoarele: alba, neagra, smart" << std::endl;
                    }
                }

                Seminar *sem = new Seminar(nume, etaj, nr_sala, nr_locuri, echipamente, tip_tabla);

                cursuri[i - 1]->adauga_sala(std::shared_ptr<Sala>(sem));
            }
            catch (const SalaExistaException &e)
            {
                std::cout << e.what() << std::endl << std::endl;
            }

            throw ResetMenuException();
            break;
        }
        case 8:
        { // Adauga profesor
            std::cout << std::endl
                      << "Introduceti numarul cursului: ";
            int i;
            std::cin >> i;
            try
            {
                std::cout << "Introduceti numele profesorului: ";
                std::string nume;
                std::cin >> nume;

                cursuri[i - 1]->adauga_profesor(nume);
            }
            catch (const ProfesorExistaException &e)
            {
                std::cout << e.what() << std::endl << std::endl;
            }

            throw ResetMenuException();
            break;
        }
        case 9:
        { // Clear console
            system("cls");
            throw ResetMenuException();
            break;
        }
        case 10:
        { // Iesire
            std::cout << "La revedere!" << std::endl;
            break;
        }
        default:
        { // Invalid option
            std::cout << "Optiune invalida!" << std::endl;
            std::cin.ignore(255, '\n');
            std::cin.ignore(255, '\n');
            throw ResetMenuException();
            break;
        }
        }
    }
    catch (const ResetMenuException &e)
    {
        InteractiveMenu::showMenu();
    }
    catch (const InvalidIndexException &e)
    {
        std::cout << e.what() << std::endl;
        InteractiveMenu::showMainMenu();
    }
    catch (...)
    {
        std::cout << "Unknown exception!" << std::endl;
    }
}