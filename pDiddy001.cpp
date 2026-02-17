#include <iostream>
#include <string>
#include <cctype>
#define PI 3.1416

using namespace std;

// Variable global
int epstein = 0;

// Prototipo de funciones
void funcion(int tmp);

int main()
{
    string hawking;
    int trump;
    // printf
    cout << "Hola Pedrito, ingresa numero: "<< endl;
    // scanf
    //cin >> hawking;
    getline(cin, hawking);
    cout << "Ingresastesss: "<< hawking << endl;

    cout << isdigit('c') << endl;

    /*
    for(int i = 0; i < hawking.length(); i++)
        cout << hawking[i] << " - " << isdigit(hawking[i]) << endl;
    */
    for(char c : hawking)
        cout << c << " - " << isdigit(c) << endl;
    //funcion(trump);
    return 0;
}

void funcion(int tmp)
{
    cout << "Valor recibido: " << tmp << endl;
}


