/*
    Programa tal
    Elaborado por mi
    Fecha: 6/6/666
*/
#include <iostream>
#include <bitset>

using namespace std;


void verBits(unsigned int x, const string& tag)
{
    cout << tag << " = " << x << " -> " <<  bitset<16>(x) << endl;
}

int main()
{
    /*
    Operadores lógicos

    & - AND
    | - OR
    ^ - XOR
    ~ - NOT
    */

    char x = 0b00001101;    // 13
    char y = 0b00000110;    // 6
    //cout << " 0 & 0 = " <<false&&false;

    verBits(x & y, "x & y");
    verBits(x | y, "x | y");
    verBits(x ^ y, "x ^ y");
    verBits(x << 5, "x << 5");
    verBits(x >> 5, "x >> 5");

    return 0;
}
