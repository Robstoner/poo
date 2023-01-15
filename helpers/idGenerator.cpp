class IDGenerator
{
private:
    static uint64_t nextID;
    static std::unordered_map<uint64_t, bool> usedIDs;

public:
    static std::string generateID()
    {
        std::string s;
        while (usedIDs.find(nextID) != usedIDs.end())
        {
            nextID++;
        }

        s = "ID-" + std::to_string(nextID++);

        return s;
    }
};

uint64_t IDGenerator::nextID = 0;
std::unordered_map<uint64_t, bool> IDGenerator::usedIDs;