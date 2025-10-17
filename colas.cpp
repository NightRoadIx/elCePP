/************************************************************
 * std::queue (cola) - FIFO
 * -----------------------------------
 * - push(): encola al final
 * - front(): consulta el primero
 * - pop(): desencola el primero
 * - empty(): verifica si hay elementos
 * Complejidad: push/pop/front en O(1).
 ************************************************************/

#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<string> clientes;
    clientes.push("Cliente A");
    clientes.push("Cliente B");
    clientes.push("Cliente C");

    while (!clientes.empty()) {
        cout << "Atendiendo: " << clientes.front() << endl; // primero en entrar, primero en salir
        clientes.pop();
    }
    return 0;
}
