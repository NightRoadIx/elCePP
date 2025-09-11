/*
    Programa tal
    Elaborado por mi
    Fecha: 6/6/666
*/
#include <iostream>

using namespace std;

/* FUNCIONES */
/**
 * @brief Calcula el factorial de un número n (n!)
 * @param n Número entero positivo para calcular factorial
 * @return El valor del factorial de n
*/
long hacerFactorial(int n)
{
    int i;
    long fatorial;
    // O(n)  tiempo lineal


    for(fatorial = 1, i = 0; i < n; fatorial *= n - i, i+=1);
    return  fatorial;
}

int main()
{
    // Declar variables
    int n;
    // Pedir n al usuario
    cout << "Ingresa n: ";  // O(1), tiempo "costante"
    // Guardar en memoria
    cin >> n;  // scanf("%d", &n);
    // Ejecutar función y mostrar
    cout << n << "! = " << hacerFactorial(n);

    return 0;
}
