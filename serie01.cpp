/*
 * Programa que calcula la serie:
 * Suma(n=0, N) (1/n!)
*/
#include <iostream>
#include <iomanip>

using namespace std;

/* FUNCIONES */
/**
 * @brief Calcula el factorial de un número n (n!)
 * @param n Número entero positivo para calcular factorial
 * @return El valor del factorial de n
*/
long hacerFactorial(int n)
{
    int i; long fatorial;
    // O(n)  tiempo lineal
    for(fatorial = 1, i = 0; i < n; fatorial *= n - i, i+=1);
    return  fatorial;
}

/**
 * @brief Calcula la serie Suma(n=0, N) (1/n!)
 * @param N Número entero positivo
 * @return El valor de la serie
*/
double serie01(int N)
{
    int n; double suma;
    // O(n)  tiempo lineal
    for(suma=0, n=0; n <= N; suma += 1.0/hacerFactorial(n), n++);
    return suma;
}

int main()
{
    // Declar variables
    int N;
    // Pedir n al usuario
    cout << "Ingresa N: ";  // O(1), tiempo "costante"
    // Guardar en memoria
    cin >> N;
    cout << fixed << setprecision(10);
    // Ejecutar función y mostrar
    cout << "Valor: " << serie01(N);

    return 0;
}
