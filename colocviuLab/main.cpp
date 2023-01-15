#include <iostream>
#include <string>
#include <vector>
#include <random>

class IDGenerator {
private:
   static std::mt19937 rng;
   static std::uniform_int_distribution<std::mt19937::result_type> dist;

public:
   static std::string generateID() {
       return std::to_string(dist(rng));
   }
};

std::mt19937 IDGenerator::rng;
std::uniform_int_distribution<std::mt19937::result_type> IDGenerator::dist = std::uniform_int_distribution<std::mt19937::result_type>(0, 1000000);


class IOStream {
protected:
    virtual void Print(std::ostream &) const = 0;

    friend std::ostream& operator<<(std::ostream &, const IOStream&);
    friend std::ostream& operator<<(std::ostream &, const IOStream*);

    virtual ~IOStream();
};

std::ostream& operator<<(std::ostream &os, const IOStream &obj) {
    obj.Print(os);
    return os;
}

std::ostream& operator<<(std::ostream &os, const IOStream *obj) {
    obj->Print(os);
    return os;
}

IOStream::~IOStream() = default;



int main()
{

}