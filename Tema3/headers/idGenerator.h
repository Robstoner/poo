#ifndef IDGENERATOR_H
#define IDGENERATOR_H
#include <string>

class IDGenerator {
private:
   static int nextID;

public:
   static std::string generateID() {
       return "ID-" + std::to_string(++nextID);
   }
};

#endif // IDGENERATOR_H