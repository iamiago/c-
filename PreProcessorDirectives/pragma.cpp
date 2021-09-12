
#include "functions.h"

// void __attribute__((constructor)) init();
// void __attribute__((destructor)) end();
// #pragma startup init
// #pragma exit
// #pragma warn - rvl /* No Return Value */
// #pragma warn - par /* Parameter Not Used */
// #pragma warn - rch /* Unused Code */

void total();
void end(int x);

int main()
{
    cout << "we're inside main methode" << endl;
    Player player("player1");
    cout << player.name << endl;
    Print();
    return 0;
}

void total()
{
    cout << "sum of a and b is c" << endl;
}

void init()
{

    cout << "we're inside init methode" << endl;
}

void end()
{

    cout << "we're inside end methode" << endl;
}