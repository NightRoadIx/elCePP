/************************************************************
 * std::set para colecciones SIN duplicados
 * ---------------------------------------------------
 * - std::set mantiene elementos ÚNICOS y ORDENADOS.
 * - Insertar un elemento ya existente no cambia el set.
 * - Búsqueda/Inserción/Eliminación: O(log N).
 ************************************************************/

#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    set<string> materias = {"Matemáticas", "Física", "Programación"};

    materias.insert("Electrónica"); // se agrega
    materias.insert("Física");      // duplicado, NO se agrega

    cout << "Materias inscritas:\n";
    for (const auto &m : materias)
        cout << " - " << m << endl; // salen ordenadas alfabéticamente

    return 0;
}
