/*
    Nume Prenume: Schmidt Robert-Eduard
    Grupa: 264
    Tutore Laborator: Octavian Comanescu
    IDE: CLion
    Compilator: Mingw
*/

#ifndef SIMULARE_IOSTREAM_H
#define SIMULARE_IOSTREAM_H

#include <iostream>

class IOStream {
protected:
    virtual void Print(std::ostream &) const = 0;

    friend std::ostream& operator<<(std::ostream &, const IOStream&);
    friend std::ostream& operator<<(std::ostream &, const IOStream*);

    virtual ~IOStream();
};


#endif //SIMULARE_IOSTREAM_H
