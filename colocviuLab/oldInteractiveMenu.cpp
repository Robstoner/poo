class InteractiveMenu
{
    static int option;
    static std::vector<Tranzactie> tranzactii;
    static std::vector<std::shared_ptr<Masina>> masini;

public:
    InteractiveMenu();
    ~InteractiveMenu();
    static void showStartMenu();
    static void showMenu();
    static void showMainMenu();
    static void setOption(int option_);
};

int InteractiveMenu::option;
std::vector<Tranzactie> InteractiveMenu::tranzactii;
std::vector<std::shared_ptr<Masina>> InteractiveMenu::masini

void InteractiveMenu::setOption(int option_)
{
    option = option_;
}

void InteractiveMenu::showStartMenu()
{
    std::cout << "Colocviu - POO - Schmidt Robert-Eduard" << std::endl
              << std::endl;

    InteractiveMenu::showMenu();
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

    int option_;
    std::cin >> option_;

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

            InteractiveMenu::showMenu();
            break;
        }
        case 2:
        { // adauga tranzactie
            auto tranzactie = Tranzactie();

            std::cin >> tranzactie;

            tranzactii.push_back(tranzactie);

            InteractiveMenu::showMenu();
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
        std::cout << e.what() << std::endl;
        InteractiveMenu::showMenu();
    }
    catch (const TipNuExistaException &e)
    {
        std::cout << e.what() << std::endl;
        InteractiveMenu::showMenu();
    }
    catch (...)
    {
        std::cout << "Unknown exception!" << std::endl;
    }
}