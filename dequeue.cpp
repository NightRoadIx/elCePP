/************************************************************
 * std::deque (double-ended queue)
 * -----------------------------------------
 * - Contenedor dinámico que permite inserciones eficientes
 *   tanto al inicio como al final.
 * - push_back(): agrega un elemento al final.
 * - push_front(): agrega un elemento al inicio.
 * - pop_back(): elimina el último elemento.
 * - pop_front(): elimina el primer elemento.
 * - size(): devuelve el número de elementos.
 * - Permite acceso por índice como un vector (d[i]).
 * - Iteración sencilla con for-each.
 ************************************************************/
#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> d;

    d.push_back(10);
    d.push_front(5);
    d.push_back(20);

    for (int x : d)
        cout << x << " ";

    return 0;
}
