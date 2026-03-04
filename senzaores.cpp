#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <windows.h>
using namespace std;

struct Sensor {
    int id;
    double temperatura;
    double presion;
    double iluminacion;
    bool activo;
};

int main()
{
    // OJO, esto solamente funciona en windows
    SetConsoleOutputCP(CP_UTF8);

    vector<Sensor> sensores;

    // Generadores pseudoaleatorios
    random_device rd;
    mt19937 gen(rd());
    // Generador para temperatura [0, 100] °C
    uniform_real_distribution<double> tipoDist(0, 100);
    // Generador para presión [0.8, 1.2] atm
    uniform_real_distribution<double> presDist(0.8, 1.2);
    // Generador para iluminancia [0, 1000] lx
    uniform_real_distribution<double> ilumDist(0.0, 1000.0);

    for(int i = 0; i < 5; i++)
    {
        // Crear un Sensor temporal
        Sensor s;
        s.id = i;
        s.activo = true;
        s.temperatura = tipoDist(gen);
        s.presion = presDist(gen);
        s.iluminacion = ilumDist(gen);

        // Guardarlo en el vector
        sensores.push_back(s);
    }

    // Mostrar
    cout << fixed << setprecision(2);
    cout << "ID\tTemp [°C]\tPres [atm]\tIlum [lx]\tActivo\n";
    for (const Sensor &s : sensores) {
        cout << s.id << "\t"
             << s.temperatura << "\t\t"
             << s.presion << "\t\t"
             << s.iluminacion << "\t\t"
             << (s.activo ? "Si" : "No") << "\n";
    }

    return 0;

}



/************************************************************
 * Generación de números pseudoaleatorios en C++
 * ----------------------------------------------
 * random_device rd;
 *  - Proporciona un número basado en una fuente de entropía
 *    del sistema (hardware o sistema operativo).
 *  - Se usa principalmente para generar una "semilla"
 *    inicial más impredecible.
 *
 * mt19937 gen(rd());
 *  - mt19937 es el algoritmo Mersenne Twister (19937 bits).
 *  - Es un generador pseudoaleatorio muy usado por su
 *    gran periodo (2^19937 − 1) y buena distribución.
 *  - "gen" es el motor generador que producirá los números.
 *  - Se inicializa con la semilla obtenida de rd().
 *
 * Después de esto, normalmente se usa una distribución
 * (uniform_real_distribution, uniform_int_distribution, etc.)
 * para obtener números en un intervalo específico.
 ************************************************************/
