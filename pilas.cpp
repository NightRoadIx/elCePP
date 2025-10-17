/************************************************************
 * std::stack (pila) - LIFO
 * -----------------------------------
 * - push(): apila al tope
 * - top(): consulta el tope
 * - pop(): desapila el tope
 * - empty(): verifica si hay elementos
 * Complejidad: push/pop/top en O(1).
 ************************************************************/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> paginas;
    paginas.push("Inicio");
    paginas.push("Productos");
    paginas.push("Contacto");

    while (!paginas.empty()) {
        cout << "Página actual: " << paginas.top() << endl; // último en entrar, primero en salir
        paginas.pop();
    }
    return 0;
}
