#include <iostream>
using namespace std;
int f(int y)
{ if (y<0) throw y;
return y/2;
}
int main()
{ int x;
try
{
cout<<"Da-mi un numar par: ";
cin>>x;
if (x%2) x=f(x);
else throw x;
cout<<"Numarul "<<x<<" e bun!"<<endl;
}
catch (int i)
{ cout<<"Numarul "<<i<<" nu e bun!"<<endl;
}
return 0;
}