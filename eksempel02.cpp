// Importación de bibliotecas estándar
#include <iostream>  // Para entrada y salida estándar (cout, cin)
#include <cmath>     // Para operaciones matemáticas como pow()

// Utilizar el espacio de nombres estándar
using namespace std;

int main() {
    // Declaración de variables
    unsigned int numero, exponente; // Variable para almacenar el número ingresado y su exponente decimal
    int i;                          // Contador para el ciclo for

    // Solicitar al usuario un número entero positivo
    cout << "Ingrese un número entero positivo: ";
    cin >> numero;

    // Determinar el número de dígitos del número ingresado
    exponente = 0;
    while (true) {  
        // Si el número dividido entre 10^exponente es menor que 10, hemos alcanzado el dígito más significativo
        if (numero / pow(10, exponente) < 10) break;
        exponente++;  // Aumentar el exponente para analizar el siguiente orden de magnitud
    }

    // Descomponer el número en sus partes según sus órdenes de magnitud
    for (i = exponente; i >= 0; i--) {
        // Obtener el dígito más significativo en la posición actual y multiplicarlo por su peso decimal
        cout << (int)(numero / pow(10, i)) * pow(10, i) << "\n";
        // TODO: Colocar el texto de la forma 1942 = 1000 + 900 + 40 + 2

        // Eliminar el dígito más significativo del número
        numero %= (int)pow(10, i);
    }

    return 0;  // Indicar que el programa finalizó correctamente
}
