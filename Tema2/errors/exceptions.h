#include <exception>

class InvalidSalaException : public std::exception
{
public:
    [[nodiscard]] const char *what() const noexcept override;
};

class SalaExistaException : public std::exception
{
public:
    [[nodiscard]] const char *what() const noexcept override;
};

class ProfesorExistaException : public std::exception
{
public:
    [[nodiscard]] const char *what() const noexcept override;
};

class ResetMenuException : public std::exception
{
public:
    [[nodiscard]] const char *what() const noexcept override;
};

class ClearConsoleException : public std::exception
{
public:
    [[nodiscard]] const char *what() const noexcept override;
};

class InvalidOptionException : public std::exception
{
public:
    [[nodiscard]] const char *what() const noexcept override;
};

class InvalidIndexException : public std::exception
{
public:
    [[nodiscard]] const char *what() const noexcept override;
};