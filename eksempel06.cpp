#include <iostream>
#include <bitset>  // Para mostrar los valores en binario
using namespace std;

// Función para mostrar un entero en binario (8 bits)
void mostrarBinario(int valor, const string &mensaje) {
    cout << mensaje << ": " << bitset<8>(valor) << " (decimal " << valor << ")" << endl;
}

int main() {
    int a = 12;  // 0b00001100
    int b = 5;   // 0b00000101
    bool x = true, y = false;

    cout << "=== OPERACIONES LÓGICAS (booleanas) ===" << endl;
    cout << "x AND y = " << (x && y) << endl;
    cout << "x OR y  = " << (x || y) << endl;
    cout << "NOT x   = " << (!x) << endl;
    cout << "x XOR y (como desigualdad lógica) = " << (x != y) << endl; // XOR lógico
    cout << endl;

    cout << "=== OPERADORES DE COMPARACIÓN ===" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "a == b : " << (a == b) << endl;
    cout << "a != b : " << (a != b) << endl;
    cout << "a < b  : " << (a < b) << endl;
    cout << "a > b  : " << (a > b) << endl;
    cout << "a <= b : " << (a <= b) << endl;
    cout << "a >= b : " << (a >= b) << endl;
    cout << endl;

    cout << "=== OPERACIONES A NIVEL DE BITS ===" << endl;
    mostrarBinario(a, "a");
    mostrarBinario(b, "b");
    mostrarBinario(a & b, "a & b (AND bit a bit)");
    mostrarBinario(a | b, "a | b (OR bit a bit)");
    mostrarBinario(a ^ b, "a ^ b (XOR bit a bit)");
    mostrarBinario(~a, "~a (complemento a 1 de a)");
    cout << endl;

    cout << "=== DESPLAZAMIENTO DE BITS ===" << endl;
    mostrarBinario(a, "a");
    mostrarBinario(a << 1, "a << 1 (desplazamiento a la izquierda por 1 bit)");
    mostrarBinario(a << 2, "a << 2 (desplazamiento a la izquierda por 2 bits)");
    mostrarBinario(a >> 1, "a >> 1 (desplazamiento a la derecha por 1 bit)");
    mostrarBinario(a >> 2, "a >> 2 (desplazamiento a la derecha por 2 bits)");
    cout << endl;

    cout << "=== EJEMPLO EXTRA: Combinando operaciones ===" << endl;
    int resultado = ((a & b) << 1) | (a >> 1);
    mostrarBinario(resultado, "((a & b) << 1) | (a >> 1)");
    cout << endl;

    cout << "=== Nota importante ===" << endl;
    cout << "Los desplazamientos hacia la izquierda (<<) multiplican por potencias de 2.\n";
    cout << "Los desplazamientos hacia la derecha (>>) dividen entre potencias de 2 (redondeando hacia abajo).\n";

    return 0;
}
