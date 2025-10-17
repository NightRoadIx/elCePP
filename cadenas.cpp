/************************************************************
 * Operaciones con std::string
 * --------------------------------------
 * - length(): longitud de la cadena.
 * - append(): concatena al final (equivalente a +=).
 * - find(): devuelve la posición de la subcadena o string::npos.
 * - replace(pos, len, nueva): reemplaza [pos, pos+len) por "nueva".
 * - stoi(cadena, ..., base): convierte texto a entero en la base indicada.
 *   Lanza std::invalid_argument si no hay número válido, o
 *   std::out_of_range si el valor se desborda.
 ************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string nombre = "Tron";

    // Longitud inicial
    cout << nombre.length() << endl;

    // Agregamos " Ares" (incluye espacio inicial)
    nombre.append(" Ares");
    cout << nombre.length() << endl;

    cout << "Nombre completo: " << nombre << endl;

    // Búsqueda de subcadenas: compara contra "Legacy"
    if (nombre.find("Legacy") != string::npos)
        cout << "Es Tron Legacy\n";
    else
        cout << "Es Tron Ares\n";

    // Reemplazo: desde índice 4 (el espacio), 5 caracteres (" Ares") por "."
    // Resultado: "Tron."
    nombre.replace(4, 5, ".");
    cout << nombre << endl;

    // Conversión de texto a entero con diferentes bases
    string binario = "101";
    cout << "Convertir en base 10: " << stoi(binario, nullptr, 10) << endl; // 101 decimal
    cout << "Convertir en base 2: "  << stoi(binario, nullptr, 2)  << endl; // 5 decimal

    return 0;
}
