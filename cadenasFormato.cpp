/************************************************************
 * stringstream para formatear cadenas
 * ----------------------------------------------
 * - stringstream permite construir texto como si fuera un cout
 *   en memoria (útil para logs, serialización simple, etc.).
 * - .str() devuelve la cadena resultante.
 * - Puedes usar manipuladores (fixed, setprecision, etc.).
 ************************************************************/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    stringstream registro;

    string nombre = "Juan Nepomuceno";
    int id = 1042;
    double saldo = 2050.75;

    // Componemos un mensaje formateado:
    registro << "Usuario: " << nombre
             << " | ID: " << id
             << " | Saldo: $" << saldo;

    string salida = registro.str(); // extraemos el contenido como string

    cout << salida << endl;

    return 0;
}
