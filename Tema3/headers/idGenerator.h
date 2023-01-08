#ifndef IDGENERATOR_H
#define IDGENERATOR_H
#include <random>
#include <string>

class IDGenerator {
private:
   static std::mt19937 rng;
   static std::uniform_int_distribution<std::mt19937::result_type> dist;

public:
   static std::string generateID() {
       return std::to_string(dist(rng));
   }
};

#endif // IDGENERATOR_H