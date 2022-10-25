#include <iostream>
#include <fstream>

using namespace std;

class obiect {
    int x;
    bool merge;

    public:
    void get_x() {
        cin >> x;
        merge = true;
    }
    void output() {
        if (merge)
            cout << "a citit x : " << x;
    }
};

int main()
{
    obiect A;
    A.get_x();
    A.output();
}