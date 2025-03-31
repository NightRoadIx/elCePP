#include <iostream>
#include <string>

using namespace std;

// Clase para el manejo de la fecha de nacimiento
// ya que, es más fácil crear un objeto que contenga
// toooooda la fecha de nacimiento
class FechaNacimiento {
// Elementos de la clase privados
private:
    // ATRIBUTOS
    int dia, mes anno;

    // Método para revisar que un año es bisiesto
    bool esBisiesto(int annio)
    {
        return ((annio % 4 == 0) && (annio % 100 != 0)) || (annio % 400 == 0);
    }

    // Método para validar que la fecha sea correcta
    bool validarFecha() {
        // Verificar que el mes se encuentre en el intervalo [1, 12]
        // y que el día se un valor no negativo
        if (mes < 1 || mes > 12 || dia < 1) return false;
        // Después generar un arreglo con el total de días de cada mes
        int diasEnMes[] = {31, esBisiesto(anio) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        return dia <= diasEnMes[mes - 1];
    }

// Elementos de la clase públicos
public:
    // Método especial de la clase, constructor
    // Los valores de los atributos privados se inician en el constructor
    // mediante una lista de inicialización de miembros,
    // es posible hacerlo dentro del cuerpo del método mediante:
    // this->dia = d
    // pero no es tan eficiente como la lista de inicialización
    // ya que se asigan inmediatamente al construir un objeto
    FechaNacimiento(int d, int m, int a) : dia(d), mes(m), anno(a)
    {
        // Se verifica que la fecha ingresada sea válida
        if(!validarFecha()) {
            cout << "\nFecha inválida. Usar formato correcto\n";
            // Rompe el programa
            exit(1);
        }
    }

    // Método para mostrar la fecha
    void mostrarFecha() {
        cout << "Fecha de nacimiento: " << dia << "/" << mes << "/" << anno << endl;
    }

};

// Definir una clase
class Persona
{
    // Esto es la encapsulamiento
    // lo cual indica que solamente la clase
    // se puede ver sus propias "cositas"
    private:
        // ATRIBUTOS
        string nombre; // char[666] nombre;
        int edad;
        char setso;
    // Esto si lo puede ver todo el mundo
    // es la parte exhibicionista de la clase
    public:
        // MÉTODOS
        // Método especial, constructor
        // el cual se debe llamar igual que
        // la clase
        Persona(string n, int e, char s)
        {
            // Esta función se manda a llamar
            // en un inicio
            nombre = n;
            edad = e;
            setso = s;
        }

        // Este es el método para mostrar datos
        void mostrar()
        {
            cout << "Mi nombre es: " << nombre << " y tengo " << edad << " años";
        }
};

int main() {

    // Instanciar un obketo
    // Es reservar un espacio en memoria que contenga
    // toooodoooo lo que almacena la clase}
    Persona alexis("AlexisGott", 666, 'i');

    // Una vez instanciado el objeto
    // se puede usar tooooodo lo que tiene adentro
    // MENOS lo que esta encapsulado
    alexis.mostrar();

    return 0;
}
