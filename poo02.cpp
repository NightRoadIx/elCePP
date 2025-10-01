#include <iostream>
using namespace std;

// =====================================================================
// Definición de la clase base "Dispositivo"
// =====================================================================

// Una clase base es aquella de la cual pueden derivar otras clases.
// En este caso, se modela un dispositivo genérico que tendrá un identificador.
class Dispositivo {
protected:
    int id;  // Atributo protegido: puede ser accedido por esta clase y por las clases derivadas

public:
    // Constructor que inicializa el atributo "id" con el valor recibido
    Dispositivo(int _id) : id(_id) {}

    // Método que muestra el identificador del dispositivo
    void mostrarID() {
        cout << "ID del dispositivo: " << id << endl;
    }
};

// =====================================================================
// Definición de la clase derivada "Sensor"
// =====================================================================

// La clase "Sensor" hereda de "Dispositivo".
// Esto significa que "Sensor" posee también el atributo "id" y el método "mostrarID()".
class Sensor : public Dispositivo {
private:
    double valor;  // Atributo propio de la clase "Sensor"

public:
    // Constructor que recibe un identificador y un valor
    // El identificador se envía al constructor de la clase base "Dispositivo"
    // El valor se asigna directamente al atributo "valor"
    Sensor(int _id, double _valor) : Dispositivo(_id), valor(_valor) {}

    // Método que muestra la información del sensor
    void mostrar() {
        mostrarID();  // Se invoca al método heredado de la clase base
        cout << "Valor del sensor: " << valor << endl;
    }
};

// =====================================================================
// Definición de la clase derivada "Motor"
// =====================================================================

// La clase "Motor" también hereda de "Dispositivo".
// Esto significa que comparte el atributo "id" y el método "mostrarID()".
class Motor : public Dispositivo {
private:
    int rpm;  // Atributo propio de la clase "Motor"

public:
    // Constructor que recibe un identificador y un número de revoluciones por minuto (rpm)
    // El identificador se pasa a la clase base y las rpm se asignan al atributo "rpm"
    Motor(int _id, int _rpm) : Dispositivo(_id), rpm(_rpm) {}

    // Método que muestra la información del motor
    void mostrar() {
        mostrarID();  // Se invoca al método heredado de la clase base
        cout << "RPM del motor: " << rpm << endl;
    }
};

// =====================================================================
// Función principal (main)
// =====================================================================

int main() {
    // Creación de un objeto "Sensor" con id = 101 y valor = 25.7
    Sensor s1(101, 25.7);

    // Creación de un objeto "Motor" con id = 202 y rpm = 3000
    Motor m1(202, 3000);

    // Llamada al método "mostrar" del sensor
    s1.mostrar();

    // Llamada al método "mostrar" del motor
    m1.mostrar();

    return 0;
}
