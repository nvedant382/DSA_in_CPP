#include <iostream>
using namespace std;
/*
Stack space holds non completed functions

Recursion Tree :->
            f() 0
           /
        f() 1
       /
    f() 2
    /
f() 3

*/
int cnt = 0;

void f()
{
    if (cnt == 4) // A specified Stop Condition called Base Condition
        return;
    cout << cnt << endl;
    cnt++;

    f();
}

int main()
{
    f();
    return 0;
}