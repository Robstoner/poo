#include <unordered_map>
#include <string>

class IDGenerator
{
private:
    static uint64_t nextID;
    static std::unordered_map<uint64_t, bool> usedIDs;

public:
    static std::string generateID()
    {
        if (!usedIDs.contains(nextID))
        {
            std::string s = "ID" + std::to_string(IDGenerator::nextID++);
        }
        else
        {
            IDGenerator::nextID++;
        }
    }
};

uint64_t IDGenerator::nextID = 0;
std::unordered_map<uint64_t, bool> IDGenerator::usedIDs;
