#include <iostream>
using namespace std;
class B{
public: virtual B*  fv(){return this;}
        virtual int adun(int p){return p+1;}
};
class D:public B{
public: virtual B*  fv(){return this;}
        virtual int adun (int p){return p+2;}
};
int main(){
B *p =new D;
int x=p->fv()->adun(1);
return 0;
}
