#ifndef TEMA2_INTERACTIVEMENU_H
#define TEMA2_INTERACTIVEMENU_H
#include <iostream>

#include "Curs.h"

class InteractiveMenu {
    static int option;
    static std::vector<std::shared_ptr<Curs>> cursuri;

public:
    InteractiveMenu();
    ~InteractiveMenu();
    static void showStartMenu();
    static void showMenu(bool invalid = false);
    static void showMainMenu();
    static void setOption(int option_);
    
};

#endif // TEMA2_INTERACTIVEMENU_H