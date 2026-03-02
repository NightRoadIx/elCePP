/*
 *  Generador de números pseudoaleatorios congruencial
 *  Recibe los valores a, b, m para el cálculo
 *  de N números aleatorios
 *  Se inicia con un número semilla X0
*/
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    // Valores para el cálculo del método
    int a, b, m;
    // Cantidad de números a calcular
    int N;
    // Valor semilla
    int X0;
    int i;

    // Vector X
    vector <int> X;
    // Vector para los números pseudoaleatorios
    vector <float> U;

    cout << "Ingresa los valores: " <<endl;
    cout << "a: ";
    cin >> a;

    cout << "b: ";
    cin >> b;

    cout << "m: ";
    cin >> m;

    cout << "Numeros a generar" << endl;
    cout << "N: ";
    cin >> N;

    cout << "Semilla: ";
    cin >> X0;

    // Reservar la cantidad de memoria solicitada
    X.reserve(N);
    U.reserve(N);

    // Almacenar el primer valor (semilla)
    X.push_back(X0);
    U.push_back(float(X0)/m);

    // Generar los valores
    for(i=1; i < N; i++)
    {
        cout << i << "\t" << X[i - 1] << "\t";
        // Calcular el siguiente número Xn+1
        int Xn = (a * X[i - 1] + b) % m;
        // Obtener el número pseudoaleatorio
        float Un = float(Xn) / m;
        cout << Xn << "\t";
        // Esto permite mostrar 4 dígitos de precisión
        cout << fixed << setprecision(4);
        cout << Un << endl;
        // Guardar en el vector
        X.push_back(Xn);
        U.push_back(Un);
    }
}
