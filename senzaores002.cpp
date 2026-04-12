#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <windows.h>

using namespace std;

/************************************************************
 * CLASE BASE: Sensor
 * ----------------------------------------------------------
 * Esta clase representa las características comunes de todos
 * los sensores del sistema.
 *
 * CONCEPTOS CLAVE:
 * - Clase base (superclase)
 * - Encapsulamiento (atributos protected)
 * - Reutilización de código
 *
 * ATRIBUTOS:
 * - id: identificador único del sensor
 * - activo: indica si el sensor está funcionando
 ************************************************************/
class Sensor {
protected:
    int id;        // Identificador del sensor
    bool activo;   // Estado del sensor

public:

    /********************************************************
     * Constructor
     * ------------------------------------------------------
     * Inicializa el sensor con un ID.
     * Por defecto, el sensor comienza activo.
     ********************************************************/
    Sensor(int _id) {
        id = _id;
        activo = true;
    }

    /********************************************************
     * setActivo()
     * ------------------------------------------------------
     * Permite cambiar el estado del sensor.
     ********************************************************/
    void setActivo(bool estado) {
        activo = estado;
    }

    /********************************************************
     * estaActivo()
     * ------------------------------------------------------
     * Devuelve true si el sensor está activo.
     ********************************************************/
    bool estaActivo() const {
        return activo;
    }

    /********************************************************
     * getId()
     * ------------------------------------------------------
     * Devuelve el identificador del sensor.
     ********************************************************/
    int getId() const {
        return id;
    }

    /********************************************************
     * mostrarEstado()
     * ------------------------------------------------------
     * Muestra información básica común a todos los sensores.
     *
     * NOTA:
     * Este método será reutilizado por las clases derivadas.
     ********************************************************/
    void mostrarEstado() const {
        cout << "Sensor ID: " << id
             << " | Estado: " << (activo ? "Activo" : "Inactivo");
    }
};

/************************************************************
 * CLASE DERIVADA: SensorTemperatura
 * ----------------------------------------------------------
 * Hereda de la clase Sensor.
 *
 * CONCEPTOS CLAVE:
 * - Herencia (public Sensor)
 * - Especialización
 *
 * AGREGA:
 * - temperatura
 * - comportamiento específico de medición
 ************************************************************/
class SensorTemperatura : public Sensor {
private:
    double temperatura;  // Variable específica de este sensor

public:

    /********************************************************
     * Constructor
     * ------------------------------------------------------
     * Inicializa el sensor de temperatura.
     * Llama al constructor de la clase base (Sensor).
     ********************************************************/
    SensorTemperatura(int _id) : Sensor(_id) {
        temperatura = 0.0;
    }

    /********************************************************
     * generarLectura()
     * ------------------------------------------------------
     * Simula una medición de temperatura usando valores
     * pseudoaleatorios.
     ********************************************************/
    void generarLectura(mt19937 &gen) {
        uniform_real_distribution<double> dist(0.0, 100.0);
        temperatura = dist(gen);
    }

    /********************************************************
     * mostrar()
     * ------------------------------------------------------
     * Muestra la información del sensor, reutilizando
     * el método de la clase base.
     *
     * También evalúa condiciones de alerta.
     ********************************************************/
    void mostrar() const {
        mostrarEstado(); // Método heredado
        cout << " | Temperatura: " << temperatura << " °C";

        // Condición de alerta
        if (temperatura > 80.0) {
            cout << " | ALERTA";
        }

        cout << endl;
    }
};

/************************************************************
 * CLASE DERIVADA: SensorPresion
 * ----------------------------------------------------------
 * Representa un sensor especializado en presión.
 *
 * AGREGA:
 * - variable presion
 ************************************************************/
class SensorPresion : public Sensor {
private:
    double presion;

public:

    SensorPresion(int _id) : Sensor(_id) {
        presion = 0.0;
    }

    /********************************************************
     * generarLectura()
     * ------------------------------------------------------
     * Simula medición de presión.
     ********************************************************/
    void generarLectura(mt19937 &gen) {
        uniform_real_distribution<double> dist(0.8, 1.2);
        presion = dist(gen);
    }

    /********************************************************
     * mostrar()
     * ------------------------------------------------------
     * Muestra información del sensor y evalúa alertas.
     ********************************************************/
    void mostrar() const {
        mostrarEstado();
        cout << " | Presion: " << presion << " atm";

        if (presion < 0.9 || presion > 1.1) {
            cout << " | ALERTA";
        }

        cout << endl;
    }
};

/************************************************************
 * CLASE DERIVADA: SensorIluminacion
 * ----------------------------------------------------------
 * Representa un sensor especializado en iluminación.
 *
 * AGREGA:
 * - variable iluminacion
 ************************************************************/
class SensorIluminacion : public Sensor {
private:
    double iluminacion;

public:

    SensorIluminacion(int _id) : Sensor(_id) {
        iluminacion = 0.0;
    }

    /********************************************************
     * generarLectura()
     * ------------------------------------------------------
     * Simula medición de iluminación.
     ********************************************************/
    void generarLectura(mt19937 &gen) {
        uniform_real_distribution<double> dist(0.0, 1000.0);
        iluminacion = dist(gen);
    }

    /********************************************************
     * mostrar()
     * ------------------------------------------------------
     * Muestra datos y evalúa condiciones de alerta.
     ********************************************************/
    void mostrar() const {
        mostrarEstado();
        cout << " | Iluminacion: " << iluminacion << " lx";

        if (iluminacion < 100.0) {
            cout << " | ALERTA";
        }

        cout << endl;
    }
};

/************************************************************
 * FUNCIÓN PRINCIPAL
 * ----------------------------------------------------------
 * Demuestra el uso de herencia creando diferentes tipos
 * de sensores y ejecutando sus comportamientos.
 ************************************************************/
int main() {
    // Permite mostrar caracteres UTF-8 en consola (Windows)
    SetConsoleOutputCP(CP_UTF8);

    cout << fixed << setprecision(2);

    /********************************************************
     * Inicialización del generador pseudoaleatorio
     ********************************************************/
    random_device rd;
    mt19937 gen(rd());

    /********************************************************
     * Creación de objetos de clases derivadas
     ********************************************************/
    SensorTemperatura sTemp(1);
    SensorPresion sPres(2);
    SensorIluminacion sIlum(3);

    /********************************************************
     * Generación de lecturas simuladas
     ********************************************************/
    sTemp.generarLectura(gen);
    sPres.generarLectura(gen);
    sIlum.generarLectura(gen);

    cout << "========================================\n";
    cout << "   EJEMPLO DE HERENCIA EN C++\n";
    cout << "========================================\n\n";

    /********************************************************
     * Mostrar información de cada sensor
     ********************************************************/
    sTemp.mostrar();
    sPres.mostrar();
    sIlum.mostrar();

    return 0;
}
