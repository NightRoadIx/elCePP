#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <windows.h>

using namespace std;

/************************************************************
 * Clase base: Sensor
 * ----------------------------------------------------------
 * Representa las características comunes de cualquier sensor.
 ************************************************************/
class Sensor {
protected:
    int id;
    bool activo;

public:
    // Constructor
    Sensor(int _id) {
        id = _id;
        activo = true;
    }

    // Método para cambiar el estado
    void setActivo(bool estado) {
        activo = estado;
    }

    // Método para consultar el estado
    bool estaActivo() const {
        return activo;
    }

    // Método para consultar el ID
    int getId() const {
        return id;
    }

    // Método común para mostrar estado general
    void mostrarEstado() const {
        cout << "Sensor ID: " << id
             << " | Estado: " << (activo ? "Activo" : "Inactivo");
    }
};

/************************************************************
 * Clase derivada: SensorTemperatura
 * ----------------------------------------------------------
 * Hereda de Sensor y agrega la variable temperatura.
 ************************************************************/
class SensorTemperatura : public Sensor {
private:
    // Atributo particular de la clase
    double temperatura;

public:
    // Constructor de la clase hija que hereda de la clase padre
    SensorTemperatura(int _id) : Sensor(_id) {
        temperatura = 0.0;
    }

    void generarLectura(mt19937 &gen) {
        uniform_real_distribution<double> dist(0.0, 100.0);
        temperatura = dist(gen);
    }

    void mostrar() const {
        mostrarEstado();
        cout << " | Temperatura: " << temperatura << " °C";
        if (temperatura > 80.0) {
            cout << " | ALERTA";
        }
        cout << endl;
    }
};

/************************************************************
 * Clase derivada: SensorPresion
 * ----------------------------------------------------------
 * Hereda de Sensor y agrega la variable presion.
 ************************************************************/
class SensorPresion : public Sensor {
private:
    double presion;

public:
    SensorPresion(int _id) : Sensor(_id) {
        presion = 0.0;
    }

    void generarLectura(mt19937 &gen) {
        uniform_real_distribution<double> dist(0.8, 1.2);
        presion = dist(gen);
    }

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
 * Clase derivada: SensorIluminacion
 * ----------------------------------------------------------
 * Hereda de Sensor y agrega la variable iluminacion.
 ************************************************************/
class SensorIluminacion : public Sensor {
private:
    double iluminacion;

public:
    SensorIluminacion(int _id) : Sensor(_id) {
        iluminacion = 0.0;
    }

    void generarLectura(mt19937 &gen) {
        uniform_real_distribution<double> dist(0.0, 1000.0);
        iluminacion = dist(gen);
    }

    void mostrar() const {
        mostrarEstado();
        cout << " | Iluminacion: " << iluminacion << " lx";
        if (iluminacion < 100.0) {
            cout << " | ALERTA";
        }
        cout << endl;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    cout << fixed << setprecision(2);

    // Generador pseudoaleatorio
    random_device rd;
    mt19937 gen(rd());

    // Crear objetos de clases derivadas
    SensorTemperatura sTemp(1);
    SensorPresion sPres(2);
    SensorIluminacion sIlum(3);

    // Generar lecturas
    sTemp.generarLectura(gen);
    sPres.generarLectura(gen);
    sIlum.generarLectura(gen);

    // Mostrar información
    sTemp.mostrar();
    sPres.mostrar();
    sIlum.mostrar();

    return 0;
}
