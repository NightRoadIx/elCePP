#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <windows.h>

using namespace std;

/************************************************************
 * Clase Sensor
 * ----------------------------------------------------------
 * Un objeto de esta clase representa un sensor con:
 * - atributos: id, temperatura, presion, iluminacion, activo
 * - métodos: generarLecturas(), mostrar(), verificarAlerta()
 ************************************************************/
class Sensor 
{
// ATRIBUTOS
private:  // Encapsulamiento de atributos
    int id;
    double temperatura;
    double presion;
    double iluminacion;
    bool activo;

// MÉTODOS
public:
    // Constructor
    Sensor(int _id) {
        id = _id;
        temperatura = 0.0;
        presion = 0.0;
        iluminacion = 0.0;
        activo = true;
    }

    // Método para generar lecturas aleatorias
    void generarLecturas(mt19937 &gen) {
        uniform_real_distribution<double> tempDist(0.0, 100.0);
        uniform_real_distribution<double> presDist(0.8, 1.2);
        uniform_real_distribution<double> ilumDist(0.0, 1000.0);
        uniform_int_distribution<int> estadoDist(0, 1);

        temperatura = tempDist(gen);
        presion = presDist(gen);
        iluminacion = ilumDist(gen);
        activo = estadoDist(gen);
    }

    // Método para mostrar la información del sensor
    void mostrar() const {
        cout << id << "\t"
             << temperatura << "\t\t"
             << presion << "\t\t"
             << iluminacion << "\t\t"
             << (activo ? "Si" : "No") << "\n";
    }

    // Método para verificar si el sensor presenta alerta
    void verificarAlerta() const {
        if (!activo) {
            cout << "- Sensor " << id << ": inactivo\n";
        }
        if (temperatura > 80.0) {
            cout << "- Sensor " << id << ": temperatura alta\n";
        }
        if (presion < 0.9 || presion > 1.1) {
            cout << "- Sensor " << id << ": presion fuera de rango\n";
        }
        if (iluminacion < 100.0) {
            cout << "- Sensor " << id << ": baja iluminacion\n";
        }
    }

    // Métodos getter (lectura)
    int getId() const {
        return id;
    }

    double getTemperatura() const {
        return temperatura;
    }

    bool estaActivo() const {
        return activo;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);

    random_device rd;
    mt19937 gen(rd());

    vector<Sensor> sensores;

    // Crear 5 objetos Sensor
    for (int i = 0; i < 5; i++) {
        sensores.push_back(Sensor(i + 1));
    }

    cout << fixed << setprecision(2);
    cout << "ID\tTemp [°C]\tPres [atm]\tIlum [lx]\tActivo\n";
    cout << "---------------------------------------------------------------\n";

    // Generar y mostrar lecturas
    for (Sensor &s : sensores) {
        s.generarLecturas(gen);
        s.mostrar();
    }

    // Mostrar alertas
    cout << "\nAlertas detectadas:\n";
    for (const Sensor &s : sensores) {
        s.verificarAlerta();
    }

    return 0;
}
