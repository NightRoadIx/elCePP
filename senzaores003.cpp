#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <windows.h>

using namespace std;

/************************************************************
 * CLASE BASE ABSTRACTA: Sensor
 * ----------------------------------------------------------
 * Representa las características comunes de todos los
 * sensores del sistema.
 *
 * Ahora esta clase usa POLIMORFISMO:
 * - tiene métodos virtuales
 * - permite trabajar con objetos derivados mediante
 *   punteros a la clase base
 ************************************************************/
class Sensor {
protected:
    int id;
    bool activo;

public:
    /********************************************************
     * Constructor
     ********************************************************/
    Sensor(int _id) {
        id = _id;
        activo = true;
    }

    /********************************************************
     * Destructor virtual
     * ------------------------------------------------------
     * Es importante su uso cuando se trabaja con herencia y 
     * punteros a la clase base.
     ********************************************************/
    virtual ~Sensor() {}

    /********************************************************
     * Métodos comunes
     ********************************************************/
    void setActivo(bool estado) {
        activo = estado;
    }

    bool estaActivo() const {
        return activo;
    }

    int getId() const {
        return id;
    }

    void mostrarEstado() const {
        cout << "Sensor ID: " << id
             << " | Estado: " << (activo ? "Activo" : "Inactivo");
    }

    /********************************************************
     * Métodos virtuales puros
     * ------------------------------------------------------
     * Obligan a las clases derivadas a implementar su propia
     * versión de estos métodos.
     *
     * Esto convierte a Sensor en una clase abstracta.
     ********************************************************/
    virtual void generarLectura(mt19937 &gen) = 0;
    virtual void mostrar() const = 0;
};

/************************************************************
 * CLASE DERIVADA: SensorTemperatura
 ************************************************************/
class SensorTemperatura : public Sensor {
private:
    double temperatura;

public:
    SensorTemperatura(int _id) : Sensor(_id) {
        temperatura = 0.0;
    }

    void generarLectura(mt19937 &gen) override {
        uniform_real_distribution<double> dist(0.0, 100.0);
        temperatura = dist(gen);
    }

    void mostrar() const override {
        mostrarEstado();
        cout << " | Temperatura: " << temperatura << " °C";

        if (temperatura > 80.0) {
            cout << " | ALERTA";
        }

        cout << endl;
    }
};

/************************************************************
 * CLASE DERIVADA: SensorPresion
 ************************************************************/
class SensorPresion : public Sensor {
private:
    double presion;

public:
    SensorPresion(int _id) : Sensor(_id) {
        presion = 0.0;
    }

    void generarLectura(mt19937 &gen) override {
        uniform_real_distribution<double> dist(0.8, 1.2);
        presion = dist(gen);
    }

    void mostrar() const override {
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
 ************************************************************/
class SensorIluminacion : public Sensor {
private:
    double iluminacion;

public:
    SensorIluminacion(int _id) : Sensor(_id) {
        iluminacion = 0.0;
    }

    void generarLectura(mt19937 &gen) override {
        uniform_real_distribution<double> dist(0.0, 1000.0);
        iluminacion = dist(gen);
    }

    void mostrar() const override {
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
 * Aquí se muestra el polimorfismo:
 * - se crea un vector de punteros a Sensor
 * - dentro se guardan objetos de distintas clases derivadas
 * - al recorrer el vector, cada objeto responde con su
 *   propio comportamiento
 ************************************************************/
int main() {
    SetConsoleOutputCP(CP_UTF8);
    cout << fixed << setprecision(2);

    /********************************************************
     * Generador pseudoaleatorio
     ********************************************************/
    random_device rd;
    mt19937 gen(rd());

    /********************************************************
     * Vector de punteros a la clase base
     ********************************************************/
    vector<Sensor*> sensores;

    /********************************************************
     * Crear objetos derivados y guardarlos en el vector
     ********************************************************/
    sensores.push_back(new SensorTemperatura(1));
    sensores.push_back(new SensorPresion(2));
    sensores.push_back(new SensorIluminacion(3));
    sensores.push_back(new SensorTemperatura(4));
    sensores.push_back(new SensorPresion(5));

    /********************************************************
     * Recorrer el vector polimórfico
     * ------------------------------------------------------
     * Aunque todos se almacenan como Sensor*, cada objeto
     * ejecuta su propia versión de generarLectura() y mostrar()
     ********************************************************/
    for (Sensor* s : sensores) {
        s->generarLectura(gen);
        s->mostrar();
    }

    /********************************************************
     * Liberar memoria
     * ------------------------------------------------------
     * Como se usó new, es necesario usar delete.
     ********************************************************/
    for (Sensor* s : sensores) {
        delete s;
    }

    return 0;
}
