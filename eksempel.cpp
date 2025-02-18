/*
	Programa para el cálculo de la potencia de un número dado
	Creado: 18/02/2025
	Última modificación: 18/02/2025
*/
// Librería para entrada/salida
#include <iostream>

/// Utilizar el espacio de nombres estándar
using namespace std;

// IMPORTANTE: Usar comentarios de documentación
// para que el programa sea entendible por otras personas
/**
 * @brief Calcula la potencia de un número.
 *
 * Esta función eleva un número base a un exponente utilizando
 * un ciclo `for` en lugar de la función estándar `pow()`.
 *
 * @param x Base de la potencia.
 * @param y Exponente al que se elevará la base.
 * @return int Resultado de x^y.
 */
int powtencia(int x, int y)
{
    int res, i;
    // Inicializa res en 1 y multiplica por x en cada iteración hasta alcanzar y
    for(i = 0, res = 1; i < y; res *= x, i++);
    return res;
}

int main() {
    int base, exponente;  // Variables para la base y el exponente

    // Solicita al usuario los valores
    cout << "Ingresa base     : ";
    cin >> base;
    cout << "Ingresa exponente: ";
    cin >> exponente;

    // Muestra el resultado llamando a la función powtencia()
    cout << base << "^" << exponente << " = " << powtencia(base, exponente) << endl;

    return 0;
}
