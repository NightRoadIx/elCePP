#include <iostream>     // Librería para entrada y salida estándar
#include <string>       // Librería para usar la clase string
#include <windows.h>    // Librería para funciones específicas de Windows (como codificación UTF-8)

// Definiciones para colores en consola
#define ROJO "\033[31m"
#define VERDE "\033[32m"
#define AZUL "\033[34m"
#define REINICIA "\033[0m"

using namespace std;

// =====================================
// Clase base: Vehiculo
// =====================================
class Vehiculo {
protected:
    string marca;
    string modelo;
    int anno;

public:
    // Constructor de la clase base
    Vehiculo(string _marca, string _modelo, int _anno) 
        : marca(_marca), modelo(_modelo), anno(_anno)
    {
        cout << "VEHICULO" << endl;
    }

    // Método virtual que podrá ser sobreescrito por clases derivadas
	/*
		virtual se ocupa para permitir el polimorfismo, esto es que cuando se
		llama a un método usando un puntero a una clase base, se ejecuta
		la versión del método de la clase derivada, si esta la ha sobreescrito (override)
	*/
    virtual void mostrarInfo()
    {
        cout << "Marca : " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Año   : " << anno << endl;
    }

    // Sobrecarga del método mostrarInfo (no es polimórfico)
    void mostrarInfo(int entero)
    {
        cout << "Este es el Vehículo" << endl;
    }

    // Destructor virtual (muy importante para liberar recursos correctamente con punteros)
    virtual ~Vehiculo()
    {
        cout << "--Fin del Vehículo--" << endl;
    }
};

// =====================================
// Clase derivada: Automovil
// =====================================
class Automovil : public Vehiculo {
private:
    int numPuertas;

public:
    // Constructor que invoca al constructor de la clase base
    Automovil(string _marca, string _modelo, int _anno, int _numPuertas)
        : Vehiculo(_marca, _modelo, _anno), numPuertas(_numPuertas)
    {
        cout << "AUTOMOVIL" << endl;
    }

    // Método sobrescrito que reemplaza al de la clase base
    void mostrarInfo() override
    {
        cout << "-- Automóvil--" << endl;
        cout << "Marca : " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Número de puertas: " << numPuertas << endl;
    }
};

// =====================================
// Clase derivada: Motocicleta
// =====================================
class Motocicleta : public Vehiculo {
private:
    bool tieneCochecito;

public:
    // Constructor que llama al constructor base
    Motocicleta(string _marca, string _modelo, int _anio, bool _tieneCochecito)
        : Vehiculo(_marca, _modelo, _anio), tieneCochecito(_tieneCochecito)
    {
        cout << "MOTOCICLETA" << endl;
    }

    // Método sobrescrito para mostrar información específica
    void mostrarInfo() override
    {
        cout << "-- Motocicleta--" << endl;
        cout << "Marca : " << marca << endl;
        cout << "Año   : " << anno << endl;
        cout << "Cochecito: " << (tieneCochecito ? "Sí" : "No") << endl;
    }
};

// =====================================
// Función principal
// =====================================
int main()
{
    // Configura la consola para mostrar caracteres en UTF-8 (acentos, eñes)
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Instanciar un objeto
    // C#
    // Automovil ksimerito = new Automovil();
    // Java
    // Automovil ksimerito = new Automovil();
    // Python
    // ksimerito = Automovil()
    /*
    Automovil ksimerito("Jac", "dos", 2024, 5);
    Motocicleta alepsis("BMW", "doblePropósito", 2025, false);

    ksimerito.mostrarInfo();
    alepsis.mostrarDetalles();
    */

    // Declaración de un arreglo de punteros a objetos de tipo Vehiculo
    // Esto permite aplicar polimorfismo
    Vehiculo* vehiculos[2];

    // Creamos objetos de clases derivadas utilizando memoria dinámica (new)
	/*
		En C++, memoria dinámica se refiere a la memoria que se reserva 
		manualmente en tiempo de ejecución, es decir, cuando el programa 
		ya se está ejecutando, usando el operador new
	*/
    vehiculos[0] = new Automovil("Jac", "dos", 2024, 5);
    vehiculos[1] = new Motocicleta("BMW", "doblePropósito", 2025, false);

    // Polimorfismo: al llamar mostrarInfo() desde un puntero a la clase base,
    // se ejecuta el método específico del tipo real del objeto
    for (int i = 0; i < 2; ++i) {
        vehiculos[i]->mostrarInfo(); // Llama al método de Automovil o Motocicleta
    }

    // Liberación de memoria dinámica con delete
    // Gracias al destructor virtual en la clase base,
    // se llama al destructor correcto (de la clase derivada)
	// esto es muy importante de hacer cuando se usa asignación dinámica
	// de memoria
    for (int i = 0; i < 2; ++i) {
		// ¡Importante para evitar fugas de memoria!
		// sino, este espacio de memoria queda ocupado hasta que el programa
		// se cierra
        delete vehiculos[i]; 
    }

    return 0; // Fin del programa
}
