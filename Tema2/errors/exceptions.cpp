#include "exceptions.h"

const char *InvalidSalaException::what() const noexcept {
    return "Sala nu este valida!";
}

const char *SalaExistaException::what() const noexcept {
    return "Sala exista deja!";
}

const char *ProfesorExistaException::what() const noexcept {
    return "Profesorul exista deja!";
}

const char *ResetMenuException::what() const noexcept {
    return "Consola a fost curatata.";
}

const char *InvalidIndexException::what() const noexcept {
    return "Indexul nu este valid!";
}