#include <iostream> // Librería estándar de entrada/salida

using namespace std;

// Variable global
char c;

int main() {
    /*
      Apuntador a caracter:
      Para declarar un apuntador en C++:
      tipo_de_dato* nombre_variable;
      (El espacio entre * y el nombre no afecta su significado)
    */
    char* pc = nullptr; // Buenas prácticas: inicializar con nullptr
    /*
      Se asigna la dirección de la variable `c` al apuntador `pc`.
      Esto significa que `pc` ahora "apunta" al espacio en memoria de `c`.
      Se usa el operador `&` para obtener la dirección de `c`.
    */
    pc = &c;

    // Ahora se recorre la variable c desde 'A' hasta 'Z'
    cout << "Letras del alfabeto usando punteros:\n";
    for (c = 'A'; c <= 'Z'; c++) {
        /*
          `*pc` accede al valor almacenado en la dirección de memoria apuntada por `pc`.
          Es decir, en cada iteración, `*pc` mostrará el valor actualizado de `c`.
        */
        cout << *pc << " ";
    }

    cout << "\n\nAhora un entero:\n";

    // Variable entera
    int entero = 30;
    // Apuntador a entero
    int* p = &entero;

    /*
      Se imprimen valores y direcciones de memoria:
      - `entero` contiene un valor.
      - `&entero` muestra la dirección de memoria donde está almacenado.
      - `p` almacena la dirección de `entero`.
      - `*p` obtiene el valor contenido en la dirección apuntada por `p` (igual a `entero`).
      - `&p` muestra la dirección de memoria donde se almacena el apuntador.
    */
    cout << "entero = " << entero << " , &entero = " << &entero << endl;
    cout << "p = " << p << " , *p = " << *p << " , &p = " << &p << endl;

    return 0; // Finaliza el programa correctamente
}
