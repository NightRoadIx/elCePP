#include <iostream>     
#include <fstream>      // Para manejo de archivos (ifstream/ofstream)
#include <string>       // Para usar objetos tipo string
#include <stdexcept>    // Para usar excepciones estándar como runtime_error o invalid_argument
#include <ctime>        // Para obtener la hora y fecha del sistema

using namespace std;

/*
    Función: registrarError

    Descripción:
    Esta función recibe un mensaje de error como parámetro 
    y lo guarda en un archivo de texto llamado "errores.log", 
    agregando una marca de tiempo (hora y fecha).
    El archivo se abre en modo "append" para no sobrescribir 
    los errores anteriores.

    Parámetros:
    - mensaje: una cadena de texto que contiene la 
    descripción del error a registrar.
*/
void registrarError(const string& mensaje) {
    // Se abre el archivo en modo de anexado (append)
    ofstream log("errores.log", ios::app);
    
    if (log.is_open()) {
        // Obtener la hora actual del sistema
        time_t ahora = time(0);          // Hora en formato "time_t"
        string hora = ctime(&ahora);     // Convertir a cadena legible
        hora.pop_back();                 // Quitar el salto de línea final

        // Escribir la entrada al archivo de log
        log << "[" << hora << "] " << mensaje << endl;
        log.close();  // Cerrar el archivo después de escribir
    } else {
        cerr << "No se pudo abrir el archivo de log." << endl;
    }
}

int main() {
    try {
        // PRIMER CASO: Error numérico (división entre cero)

        int a, b;
        cout << "Introduce el numerador: ";
        cin >> a;

        cout << "Introduce el denominador: ";
        cin >> b;

        // Verificar si el denominador es cero antes de dividir
        if (b == 0) {
            // Lanzar una excepción de tipo runtime_error
            throw runtime_error("Error: División por cero.");
        }

        // Si no hubo error, se realiza la división
        cout << "Resultado: " << (a / b) << endl;

    } catch (const exception& e) {
        // Captura y muestra el error
        cerr << e.what() << endl;
        // Se registra el error en el archivo de log
        registrarError(e.what());
    }

    try {
        // SEGUNDO CASO: Validación de cadena (nombre con números)

        string nombre;
        cout << "\nIntroduce tu nombre (sin números): ";
        cin >> nombre;

        // Recorrer cada carácter para verificar si hay números
        for (char c : nombre) {
            if (isdigit(c)) {
                throw invalid_argument("Error: El nombre no debe contener números.");
            }
        }

        // Si es válido, se muestra
        cout << "Nombre aceptado: " << nombre << endl;

    } catch (const exception& e) {
        cerr << e.what() << endl;
        registrarError(e.what());
    }

    try {
        // TERCER CASO: Error al abrir un archivo

        ifstream archivo("datos.txt");  // Intentar abrir el archivo

        // Verificar si se pudo abrir correctamente
        if (!archivo.is_open()) {
            throw runtime_error("Error: No se pudo abrir el archivo 'datos.txt'.");
        }

        // Si se abrió correctamente, leer su contenido línea por línea
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }

        archivo.close();  // Cerrar el archivo después de leerlo

    } catch (const exception& e) {
        cerr << e.what() << endl;
        registrarError(e.what());
    }

    cout << "\nFin del programa.\n";
    return 0;
}
