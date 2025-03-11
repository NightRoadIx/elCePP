#include <iostream>
#include <conio.h>   // Para getch()

using namespace std;

/* Sustitución de la función isdigit() */
bool esUnDigito(char c)
{
    // Regresar si el caracter 'c' está en
    // el intervalo ASCII de '0' y '9'
    return ((c >= '0')&&(c <= '9'));
}

/* Sustitución de la función atoi*/
// Recibe como parámetro el apuntador a char
int miAtoi(char *str)
{
    // Iniciar la variable para almacenar el resultado
    int resultado = 0;
    // Recorre la cadena hasta el carácter nulo '\0'
    // que es como está conformada la cadena
    // esto quiere decir que, while trabajará hasta
    // que sea falso, 0 o nulo
    while (*str) {
        // Verifica que todos los caracteres sean dígitos,
        // para evitar errores
        if (!esUnDigito(*str))
            return -1;  // Retorna -1 si hay caracteres inválidos
        // Construcción del número
        // dependiendo de la posición que tenga cada
        // dígito (como en descomposición de los números)
        // Se resta un '0' dado que se obtendrá su valor
        // en ASCII para llegar al valor numérico
        // ejemplo:
        // '1' es ASCII es 49
        // '0' es 48
        // '1' - '0' = 49 - 48 = 1
        resultado = resultado * 10 + (*str - '0');
        // Se avanza al siguiente caracter, incrementando
        // el apuntador, lo que mueve la posición a apuntar
        // en el arreglo
        str++;
    }
    // Regresamos el número convertido
    return resultado;
}

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
        if (esUnDigito(tmp) && i < 3)
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
    edadInt = miAtoi(edad);
    cout << "Su edad en 5 annos sera: " << edadInt+5;

    return 0;
}
