#include <iostream>  // Librería estándar para entrada/salida
#include <cstring>   // Para funciones de manejo de cadenas como strlen() y strcpy()

using namespace std;

int main() {
    // Cadena de caracteres en memoria estática
    char cad[121];
    char* ptr = nullptr; // Inicializamos el puntero en nullptr por seguridad

    // Solicitar al usuario que ingrese una línea de texto
    cout << "Introduce una línea de texto: ";
    // cin.getline permite obtener una cadena con espacios
    cin.getline(cad, 121); 

    // Obtener la longitud de la cadena ingresada (sin contar el carácter nulo '\0')
    int lon = strlen(cad);
    cout << "\nTamaño de la cadena (sin NULL) = " << lon << endl;

    /*
      Asignación dinámica de memoria:
      Si desconocemos el tamaño exacto de una variable a asignar, podemos reservar 
      memoria en tiempo de ejecución usando `new` en C++ en lugar de `malloc()`.
      
      `ptr = new char[lon + 1];`
      - `new` reserva memoria dinámicamente para una cadena de tamaño `lon + 1` 
        (+1 para el carácter nulo `\0`).
    */
    ptr = new char[lon + 1];
    cout << "Tamaño asignado en memoria = " << (lon + 1) * sizeof(char) << " bytes" << endl;

    // Copiar la cadena ingresada a la memoria dinámica
    strcpy(ptr, cad);
    cout << "\nptr = " << ptr << endl;

    /*
      IMPORTANTE:
      Siempre que reservamos memoria con `new`, debemos liberarla con `delete[]`.
      - `delete[] ptr;` libera el bloque de memoria previamente asignado con `new`.
      - Si no liberamos la memoria, tendremos una fuga de memoria (memory leak).
    */
    delete[] ptr; // Liberar la memoria asignada dinámicamente

    return 0; // Indica que el programa finalizó correctamente
}
