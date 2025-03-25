#include <iostream>
#include <string>

using namespace std;

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
