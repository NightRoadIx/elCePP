#include <iostream>  // Para entrada y salida estándar
#include <cstdlib>   // Para malloc() y free()
#include <cstring>   // Para manejo de cadenas
using namespace std;

int main()
{
    /*
    Punteros a punteros:
    - No solo es posible apuntar a variables, sino también a otros punteros.
    - Se pueden tener punteros a punteros, punteros a punteros a punteros, etc.
    - Esto permite manejar estructuras más complejas, como matrices dinámicas.
    */

    // Declaración de punteros a punteros
    char c = 'z';       // Variable de tipo char
    char *pc = &c;      // pc apunta a la dirección de c
    char **ppc = &pc;   // ppc apunta a la dirección de pc
    char ***pppc = &ppc;// pppc apunta a la dirección de ppc

    /*
    Esto implica que:
    - `pppc` tiene la dirección de `ppc`
    - `ppc` tiene la dirección de `pc`
    - `pc` tiene la dirección de `c`
    - Por lo tanto, desde `pppc` se puede acceder a `c`.
    */

    cout << "c = " << c << " en " << &c << "\n\n";
    cout << "pc apunta a " << (void*)pc << " que contiene " << *pc << ", y la direccion de pc es " << &pc << "\n\n";
    cout << "ppc apunta a " << (void*)ppc << " que contiene " << (void*)*ppc << " que contiene " << **ppc << ", direccion ppc es " << &ppc << "\n\n";
    cout << "pppc apunta a " << (void*)pppc << " que contiene " << (void*)*pppc << " que contiene " << (void*)**pppc << " que contiene " << ***pppc << "\n";
    cout << "Direccion de pppc es " << &pppc << "\n\n";

    /*
    🔹 Aplicación práctica de punteros en arreglos:
    - El nombre de un arreglo en C++ es un **puntero constante** al primer elemento.
    - Se puede acceder a un elemento con `lista[i]` o con `*(lista + i)`.
    */

    int lista[5] = {10, 20, 30, 40, 50};
    cout << "Accediendo a lista[2]   = " << lista[2] << "\n";
    cout << "Accediendo a *(lista+2) = " << *(lista+2) << "\n";
    cout << "Si se coloca solo lista = " << *lista << " es igual que colocar lista[0] = " << lista[0] << "\n";
    cout << "Y lista = " << lista << " es igual que &lista[0] = " << &lista[0] << "\n\n";

    /*
    🔹 Manejo de arreglos mediante punteros
    - Se usa un puntero `float *ap` para crear un "arreglo dinámico".
    - ⚠️ Aquí falta reservar memoria antes de usar `ap`, lo corregimos a continuación.
    */

    float *ap = (float*)malloc(10 * sizeof(float)); // Se asigna memoria para 10 elementos
    if (ap == NULL) {
        cerr << "Error: No se pudo asignar memoria.\n";
        return 1;
    }

    for (int j = 0; j < 10; j++)
    {
        *(ap + j) = j * 10.0;  // Asignación de valores al "arreglo dinámico"
        cout << "Elemento " << j << " = " << *(ap + j) << "\n";
    }

    free(ap);  // Se libera la memoria reservada con malloc()
    ap = NULL; // Se evita el acceso a memoria liberada

    /*
    🔹 Creación de una matriz dinámica con punteros a punteros
    - Se usa `int **p` para manejar una matriz donde cada fila puede tener un tamaño diferente.
    - Se pide el número de filas `n` y para cada fila `m[i]` su número de columnas.
    */

    int **p, n, m[100], i, j;

    // Se solicita el número de filas (>0)
    do {
        cout << "No. de filas: ";
        cin >> n;
    } while (n <= 0);

    // Se asigna memoria para un arreglo de punteros (una matriz dinámica)
    p = (int **)malloc(n * sizeof(int *));
    if (p == NULL) {
        cerr << "Error: No se pudo asignar memoria para las filas.\n";
        return 1;
    }

    // Se llenan los datos de la matriz
    for (i = 0; i < n; i++)
    {
        cout << "No. de elementos de fila (<100) " << i + 1 << ": ";
        cin >> m[i];

        // Se asigna memoria para cada fila de la matriz
        p[i] = (int *)malloc(m[i] * sizeof(int));
        if (p[i] == NULL) {
            cerr << "Error: No se pudo asignar memoria para la fila " << i + 1 << ".\n";
            return 1;
        }

        // Se ingresan los valores de la fila
        for (j = 0; j < m[i]; j++)
        {
            cout << "Elemento " << j << " -> ";
            cin >> p[i][j];
        }
    }

    // Se muestra la matriz
    cout << "\nMatriz ingresada:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m[i]; j++)
        {
            cout << p[i][j] << " ";
        }
        cout << "\n";
    }

    // Se libera la memoria asignada dinámicamente
    for (i = 0; i < n; i++)
    {
        free(p[i]); // Liberar cada fila
    }
    free(p); // Liberar el arreglo de punteros

    return 0;
}
