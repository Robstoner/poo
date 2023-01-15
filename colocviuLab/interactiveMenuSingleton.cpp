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
    std::cout << "1. ----" << std::endl
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
        {

            showMenu();
            break;
        }
        case 2:
        {

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