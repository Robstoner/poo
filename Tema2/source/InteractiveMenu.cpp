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
    // if (invalid){
    //     std::cin.ignore(255, '\n');
    //     std::cin.ignore(255, ' ');
    // }
    std::cout << "Introduceti optiunea: ";
    /// Am incercat sa rezolv problema cand cineva introduce un string in loc de un int, sau prea multe cuvinte la vreun input, dar nu am reusit :/
    if (invalid)
    {
        //work
    }
    // if (invalid){
    //     std::cin.ignore(255, '\n');
    //     std::cin.ignore(255, ' ');
    // }

    int option_;
    std::cin >> option_;

    // if (invalid){
    //     std::cin.ignore(255, '\n');
    //     std::cin.ignore(255, '\n');
    // }
    
    InteractiveMenu::setOption(option_);
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
            size_t i;
            std::cout << std::endl
                      << "Introduceti numarul cursului (>0): ";
            std::cin >> i;
            if (i > cursuri.size() || i == 0)
                throw InvalidIndexException();
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
                      << "Introduceti numarul cursului (>0): ";
            size_t i;
            std::cin >> i;
            if (i > cursuri.size() || i == 0)
                throw InvalidIndexException();
            try
            {
                Amfiteatru *amf = new Amfiteatru();

                std::cin >> *amf;

                cursuri[i - 1]->adauga_sala(std::shared_ptr<Sala>(amf));
            }
            catch (const SalaExistaException &e)
            {
                std::cout << e.what() << std::endl
                          << std::endl;
            }

            throw ResetMenuException();
            break;
        }
        case 6:
        { // Adauga laborator
            std::cout << std::endl
                      << "Introduceti numarul cursului (>0): ";
            size_t i;
            std::cin >> i;
            if (i > cursuri.size() || i == 0)
                throw InvalidIndexException();
            try
            {
                Laborator *lab = new Laborator();

                std::cin >> *lab;

                cursuri[i - 1]->adauga_sala(std::shared_ptr<Sala>(lab));
            }
            catch (const SalaExistaException &e)
            {
                std::cout << e.what() << std::endl
                          << std::endl;
            }

            throw ResetMenuException();
            break;
        }
        case 7:
        { // Adauga seminar
            std::cout << std::endl
                      << "Introduceti numarul cursului (>0): ";
            size_t i;
            std::cin >> i;
            if (i > cursuri.size() || i == 0)
                throw InvalidIndexException();
            try
            {
                Seminar *sem = new Seminar();

                std::cin >> *sem;

                cursuri[i - 1]->adauga_sala(std::shared_ptr<Sala>(sem));
            }
            catch (const SalaExistaException &e)
            {
                std::cout << e.what() << std::endl
                          << std::endl;
            }

            throw ResetMenuException();
            break;
        }
        case 8:
        { // Adauga profesor
            std::cout << std::endl
                      << "Introduceti numarul cursului (>0): ";
            size_t i;
            std::cin >> i;
            if (i > cursuri.size() || i == 0)
                throw InvalidIndexException();
            try
            {
                std::cout << "Introduceti numele profesorului: ";
                std::string nume;
                std::cin >> nume;

                cursuri[i - 1]->adauga_profesor(nume);
            }
            catch (const ProfesorExistaException &e)
            {
                std::cout << e.what() << std::endl
                          << std::endl;
            }

            throw ResetMenuException();
            break;
        }
        case 9:
        { // Clear console
            system("cls");
            throw ClearConsoleException();
            break;
        }
        case 10:
        { // Iesire
            std::cout << "La revedere!" << std::endl;
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
    catch (const ClearConsoleException &e)
    {
        std::cout << e.what() << std::endl;
        InteractiveMenu::showMenu();
    }
    catch (const InvalidOptionException &e)
    {
        std::cout << e.what() << std::endl;
        InteractiveMenu::showMenu(true);
    }
    catch (const ResetMenuException &e)
    {
        std::cout << e.what() << std::endl;
        InteractiveMenu::showMenu();
    }
    catch (const InvalidIndexException &e)
    {
        std::cout << e.what() << std::endl;
        InteractiveMenu::showMenu();
    }
    catch (...)
    {
        std::cout << "Unknown exception!" << std::endl;
    }
}