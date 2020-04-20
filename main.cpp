#include <iostream>
#include "Complex.h"
const int deg = 4;
using namespace std;
int main()
{
    Complex a{0,1};
    auto roots = a.roots(deg);
    for(auto root: roots)
        cout<<root<<"\n";
    cout<<endl;
    for(auto root: roots)
        cout<<Pow(root,deg)<<"\n";
    return 0;
}
