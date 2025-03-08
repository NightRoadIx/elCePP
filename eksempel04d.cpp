#include <iostream>  // Para entrada y salida estándar
#include <cstdlib>   // Para exit()
using namespace std;

/*
  🔹 Arreglos de punteros:
  - Se pueden usar arreglos de punteros para almacenar direcciones de diferentes valores.
  - Un ejemplo común es un arreglo de **cadenas de caracteres**, donde cada elemento es un puntero a un `char*`.
*/

// Arreglo de punteros a cadenas de caracteres
const char *meses[12] = {
    "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
    "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"
};

int main()
{
    /*
    🔹 Accediendo a un arreglo de punteros:
    - `meses[i]` apunta a una cadena de caracteres.
    - Como `meses` es un **arreglo de punteros**, cada `meses[i]` es un puntero `char*` que apunta a una cadena.
    */

    cout << "Los meses del año:\n";
    for (int i = 0; i < 12; i++)
    {
        cout << "Mes " << i + 1 << " es " << meses[i] << "\n";
    }

    /*
    🔹 Uso de punteros en arreglos:
    - Se puede recorrer un **arreglo de caracteres** (`char[]`) con un puntero.
    */

    char alfabeto[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Cadena con las letras del alfabeto
    char *p = alfabeto; // p apunta al primer elemento (equivalente a `&alfabeto[0]`)

    cout << "\nElemento al que apunta p: " << *p << "\n";
    cout << "Recorriendo el alfabeto con un puntero:\n";

    // Se recorre el alfabeto con un puntero hasta encontrar el carácter nulo (`\0`)
    while (*p)  // Es lo mismo que `while(*p != '\0')`
    {
        cout << *p << " ";
        p++; // Se mueve el puntero al siguiente carácter
    }

    /*
    🔹 Reglas sobre operaciones con punteros:
    - Se puede **sumar o restar** un entero a un puntero (`p + n` o `p - n`).
    - Se puede **comparar** dos punteros (`p1 == p2`, `p1 < p2`).
    - No se pueden **sumar dos punteros** (`p1 + p2` no está permitido).
    - No se pueden **multiplicar o dividir** punteros (`p1 * p2`, `p1 / p2` no tiene sentido).
    */

    return 0;
}
