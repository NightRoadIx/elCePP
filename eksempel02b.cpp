#include <iostream>

using namespace std;

int main() {
    // Variables
    unsigned int numero, copia;
    unsigned int unidad;
    unsigned int divisor = 1;

    cout << "Ingrese un número entero positivo: ";
    cin >> numero;

    // Encontrar el mayor divisor de 10^n menor o igual a "numero"
    copia = numero;
    while (copia >= 10) {
        copia /= 10;
        divisor *= 10;
    }

    // Extraer y mostrar los dígitos con su peso decimal
    copia = numero;
    while (divisor > 0) {
        unidad = copia / divisor;      // Obtener el dígito más significativo
        cout << divisor << " - " << unidad * divisor << " \n ";
        copia %= divisor;              // Quitar el dígito más significativo
        divisor /= 10;                 // Reducir el divisor
    }

    return 0;
}
