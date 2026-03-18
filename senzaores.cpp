#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <windows.h>
using namespace std;

/************************************************************
 * Estructura Sensor
 * ----------------------------------------------------------
 * Representa un sensor con:
 * - id: identificador
 * - temperatura: lectura en °C
 * - presion: lectura en atm
 * - iluminacion: lectura en lx
 * - activo: indica si el sensor está funcionando
 ************************************************************/
struct Sensor {
    int id;
    double temperatura;
    double presion;
    double iluminacion;
    bool activo;
};

/************************************************************
 * Función: mostrarSensores
 * ----------------------------------------------------------
 * Muestra en formato de tabla el contenido del vector.
 ************************************************************/
 
// Aquí se muestra un concepto interesante, el paso por referencia &variable
// Esto permite modificar la variable que se envía como parámetro a la función
// dentro de la misma función, algo que en general, no está permitido en las
// funciones
// Para este caso en particular, al volver el parámetro const, se evita hacer
// alteraciones innecesarias, ya que se vuelve una variable constante
void mostrarSensores(const vector<Sensor> &sensores) {
    cout << "\nID\tTemp [°C]\tPres [atm]\tIlum [lx]\tActivo\n";
    cout << "---------------------------------------------------------------\n";

    // Recorrer el vector recibido, de la misma forma, como constante
    for (const Sensor &s : sensores) {
        cout << s.id << "\t"
             << s.temperatura << "\t\t"
             << s.presion << "\t\t"
             << s.iluminacion << "\t\t"
             << (s.activo ? "Si" : "No") << "\n";
    }
}

/************************************************************
 * Función: contarActivos
 * ----------------------------------------------------------
 * Cuenta cuántos sensores están activos.
 ************************************************************/
int contarActivos(const vector<Sensor> &sensores) {
    int contador = 0;

    for (const Sensor &s : sensores) {
        if (s.activo) {
            contador++;
        }
    }

    return contador;
}

/************************************************************
 * Función: promedioTemperatura
 * ----------------------------------------------------------
 * Calcula la temperatura promedio considerando solamente
 * sensores activos.
 ************************************************************/
double promedioTemperatura(const vector<Sensor> &sensores) {
    double suma = 0.0;
    int contador = 0;

    for (const Sensor &s : sensores) {
        if (s.activo) {
            suma += s.temperatura;
            contador++;
        }
    }

    if (contador == 0) {
        return 0.0;
    }

    return suma / contador;
}

/************************************************************
 * Función: sensorMayorTemperatura
 * ----------------------------------------------------------
 * Devuelve el índice del sensor con mayor temperatura.
 ************************************************************/
int sensorMayorTemperatura(const vector<Sensor> &sensores) {
    int indiceMayor = 0;

    for (int i = 1; i < sensores.size(); i++) {
        if (sensores[i].temperatura > sensores[indiceMayor].temperatura) {
            indiceMayor = i;
        }
    }

    return indiceMayor;
}

/************************************************************
 * Función: mostrarAlertas
 * ----------------------------------------------------------
 * Revisa si algún sensor supera límites de operación.
 ************************************************************/
void mostrarAlertas(const vector<Sensor> &sensores) {
    cout << "\nALERTAS DEL SISTEMA\n";
    cout << "-------------------\n";

    bool hayAlertas = false;

    for (const Sensor &s : sensores) {
        if (!s.activo) {
            cout << "Sensor " << s.id << ": INACTIVO\n";
            hayAlertas = true;
        }

        if (s.temperatura > 80.0) {
            cout << "Sensor " << s.id << ": Temperatura alta ("
                 << s.temperatura << " °C)\n";
            hayAlertas = true;
        }

        if (s.presion < 0.9 || s.presion > 1.1) {
            cout << "Sensor " << s.id << ": Presion fuera de rango ("
                 << s.presion << " atm)\n";
            hayAlertas = true;
        }

        if (s.iluminacion < 100.0) {
            cout << "Sensor " << s.id << ": Baja iluminacion ("
                 << s.iluminacion << " lx)\n";
            hayAlertas = true;
        }
    }

    if (!hayAlertas) {
        cout << "No se detectaron alertas.\n";
    }
}

/************************************************************
 * Función: actualizarLecturas
 * ----------------------------------------------------------
 * Simula una nueva ronda de monitoreo actualizando las
 * lecturas de todos los sensores.
 ************************************************************/
// en este caso, si se actualiza el valor del parámetro enviado &sensores de
// manera referencial
void actualizarLecturas(vector<Sensor> &sensores, mt19937 &gen) {
    uniform_real_distribution<double> tempDist(0.0, 100.0);
    uniform_real_distribution<double> presDist(0.8, 1.2);
    uniform_real_distribution<double> ilumDist(0.0, 1000.0);
    uniform_int_distribution<int> estadoDist(0, 1);

    for (Sensor &s : sensores) {
        s.temperatura = tempDist(gen);
        s.presion = presDist(gen);
        s.iluminacion = ilumDist(gen);
        s.activo = estadoDist(gen);
    }
}

int main() {
    // OJO, esto solamente funciona en Windows
    // permite manejar caracteres UTF8
    SetConsoleOutputCP(CP_UTF8);

    // Crear un vector de Sensor
    vector<Sensor> sensores;

    // Generadores pseudoaleatorios
    random_device rd;
    mt19937 gen(rd());

    // Generador para temperatura [0, 100] °C
    uniform_real_distribution<double> tempDist(0.0, 100.0);
    // Generador para presión [0.8, 1.2] atm
    uniform_real_distribution<double> presDist(0.8, 1.2);
    // Generador para iluminancia [0, 1000] lx
    uniform_real_distribution<double> ilumDist(0.0, 1000.0);
    // Generador para estado del sensor
    uniform_int_distribution<int> estadoDist(0, 1);

    // Crear sensores iniciales
    for (int i = 0; i < 5; i++) 
    {
        // Crar una estructura Sensor para llenar
        Sensor s;
        // Armar la estructura
        s.id = i + 1;
        // Con los valores aleatorios
        s.activo = estadoDist(gen);
        s.temperatura = tempDist(gen);
        s.presion = presDist(gen);
        s.iluminacion = ilumDist(gen);

        // Aquí se manda al vector
        sensores.push_back(s);
    }

    // Colocar la precisión a 2 dígitos
    cout << fixed << setprecision(2);

    cout << "=========================================\n";
    cout << "   MINI SISTEMA DE MONITOREO DE SENSORES\n";
    cout << "=========================================\n";

    // Mostrar estado inicial
    cout << "\nLECTURAS INICIALES\n";
    mostrarSensores(sensores);

    // Resumen del sistema
    cout << "\nRESUMEN DEL SISTEMA\n";
    cout << "-------------------\n";
    cout << "Sensores totales: " << sensores.size() << endl;
    cout << "Sensores activos: " << contarActivos(sensores) << endl;
    cout << "Temperatura promedio (sensores activos): "
         << promedioTemperatura(sensores) << " °C\n";

    int indiceMayor = sensorMayorTemperatura(sensores);
    cout << "Mayor temperatura registrada: Sensor "
         << sensores[indiceMayor].id << " con "
         << sensores[indiceMayor].temperatura << " °C\n";

    // Mostrar alertas
    mostrarAlertas(sensores);

    // Simular una segunda ronda de monitoreo
    cout << "\n\nACTUALIZANDO LECTURAS...\n";
    actualizarLecturas(sensores, gen);

    cout << "\nNUEVAS LECTURAS\n";
    mostrarSensores(sensores);

    cout << "\nNUEVO RESUMEN DEL SISTEMA\n";
    cout << "------------------------\n";
    cout << "Sensores totales: " << sensores.size() << endl;
    cout << "Sensores activos: " << contarActivos(sensores) << endl;
    cout << "Temperatura promedio (sensores activos): "
         << promedioTemperatura(sensores) << " °C\n";

    indiceMayor = sensorMayorTemperatura(sensores);
    cout << "Mayor temperatura registrada: Sensor "
         << sensores[indiceMayor].id << " con "
         << sensores[indiceMayor].temperatura << " °C\n";

    mostrarAlertas(sensores);

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
