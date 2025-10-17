/************************************************************
 * std::map para relacionar IDs con nombres
 * ---------------------------------------------------------
 * - Un std::map mantiene pares (clave, valor) ORDENADOS por
 *   clave (aquí: int -> string).
 * - Búsqueda: O(log N). Inserción/actualización: O(log N).
 * - operator[]:
 *     • Si la clave existe, retorna una referencia al valor.
 *     • Si NO existe, INSERTA un valor por defecto (¡ojo!).
 *   Para evitar inserciones accidentales, usa find() o at().
 ************************************************************/

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    // Mapa de alumnos: clave = matrícula (int), valor = nombre (string).
    map<int, string> alumnos;

    // Inserciones: si la clave no existe, se agrega; si existe, se actualiza.
    alumnos[101] = "Cucaracho";
    alumnos[102] = "YoMero";
    alumnos[103] = "Gus";

    // Búsqueda segura: find() NO inserta nada si la clave no existe.
    // Devuelve un iterador al elemento o end() si no lo encontró.
    auto it = alumnos.find(103);
    if (it != alumnos.end())
        cout << "Alumno hallado: " << it->second << endl; // it->first es la clave, it->second el valor

    // Recorremos el mapa (quedará ordenado ascendentemente por la clave).
    cout << "Lista de alumnos:\n";
    for (const auto &par : alumnos)
        cout << par.first << " - " << par.second << endl;

    return 0;
}
