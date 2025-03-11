#include <iostream>
#include <conio.h>   // Para getch()
#include <cctype>    // Para isdigit()
#include <stdlib.h>  // Para atoi()
using namespace std;

int main()
{
    // Variables
    char edad[4], tmp;
    int i = 0, edadInt = 0;

    cout << "Ingrese su edad: ";
    while (true)
    {
        // Captura un carácter sin necesidad de presionar Enter
        tmp = getch();

        // Solo permite números y hasta 3 dígitos
        if (isdigit(tmp) && i < 3)
        {
            // Asignar el valor leído
            edad[i] = tmp;
            // Muestra el número en pantalla
            cout << tmp;
            // Incrementar el contador
            i++;
        }
        else if (tmp == '\b' && i > 0) // Si se presiona Backspace
        {
            // Borra el último carácter en pantalla
            cout << "\b \b";
            // Decrementa el contador, pues se borró un caracter
            i--;
            // Borra el último número ingresado
            edad[i] = '\0';
        }
        else if (tmp == '\r') // Si se presiona Enter, finaliza la entrada
        {
            // Asegura el fin de cadena con caracter NULL
            edad[i] = '\0';
            break;
        }
    }
    cout << "\nEdad ingresada: " << edad << endl;

    // Convertir de arreglo de caracteres a entero
    edadInt = atoi(edad);
    cout << "Su edad en 5 annos sera: " << edadInt+5;

    return 0;
}
