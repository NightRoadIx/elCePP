#include <iostream>
#include <bitset>
#include <cmath>
#include <windows.h>

using namespace std;

class IEEE754 {
private:
    float numero;
    int signo;
    int exponente;
    int mantisa;

public:
    // Constructor
    IEEE754(float num) : numero(num) {
        calcularRepresentacion();
    }

    // Método para calcular la representación sin reinterpret_cast
    void calcularRepresentacion() {
        // Extraer el signo (1 bit más significativo)
        signo = (numero < 0) ? 1 : 0;

        // Obtener la parte absoluta del número
        float valorAbsoluto = fabs(numero);

        // Calcular el exponente real (sesgado con bias 127)
        int exponenteReal = 0;
        if (valorAbsoluto != 0) {
            while (valorAbsoluto >= 2.0) {
                valorAbsoluto /= 2.0;
                exponenteReal++;
            }
            while (valorAbsoluto < 1.0) {
                valorAbsoluto *= 2.0;
                exponenteReal--;
            }
        }

        // Sesgar el exponente con bias 127
        exponente = exponenteReal + 127;

        // Calcular la mantisa (tomamos los 23 bits fraccionarios)
        valorAbsoluto -= 1.0; // Eliminamos el bit implícito
        mantisa = 0;
        for (int i = 0; i < 23; i++) {
            valorAbsoluto *= 2.0;
            if (valorAbsoluto >= 1.0) {
                mantisa |= (1 << (22 - i));
                valorAbsoluto -= 1.0;
            }
        }
    }

    // Método para mostrar la representación binaria
    void mostrarRepresentacion() {
        cout << "\nNúmero original: " << numero << endl;
        cout << "Signo: " << signo << endl;
        cout << "Exponente (sesgado): " << exponente << " -> Binario: " << bitset<8>(exponente) << endl;
        cout << "Mantisa: " << bitset<23>(mantisa) << endl;

        // Mostrar el número completo en IEEE 754
        cout << "\nIEEE 754 (32 bits): "
             << bitset<1>(signo) << " "
             << bitset<8>(exponente) << " "
             << bitset<23>(mantisa) << endl;
    }
};

// Programa principal
int main() {

    // Cambiar la codificación de entrada y salida a UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    float numero;
    cout << "Ingrese un número flotante: ";
    cin >> numero;

    IEEE754 representacion(numero);
    representacion.mostrarRepresentacion();

    return 0;
}
