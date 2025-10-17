/************************************************************
 * Ejemplo 7: std::vector (arreglo dinámico)
 * -----------------------------------------
 * - push_back(): agrega al final, amortizadamente O(1).
 * - size(): número de elementos almacenados.
 * - capacity(): capacidad reservada (puede ser >= size()).
 * - Iteración con for-each (const ref para evitar copias).
 ************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> nombres;

    nombres.push_back("Tron");
    nombres.push_back("Ares");
    nombres.push_back("Legacy");

    cout << "Lista de nombres:\n";
    for (const string &n : nombres)
        cout << " - " << n << endl;

    cout << "Total: " << nombres.size() << " elementos.\n";
    // cout << "Capacidad interna: " << nombres.capacity() << endl; // opcional, para ver reserva

    return 0;
}
