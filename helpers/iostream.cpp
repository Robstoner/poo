#include <iostream>

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