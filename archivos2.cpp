/*
    Manejo de archivos
    Crear, Leer, Actualizar
    Usando estructuras de datos
*/
#include <iostream> // Elemento entrada/salida
#include <fstream>  // Manejo de archivos
#include <sstream>  // Manejo de cadenas con formato
#include <vector>   // Manejo de vectores (colección de datos)
#include <string>   // Manejo de cadenas

using namespace std;

// Variables globales
// Estructura, son colecciones de datos
// que almacenan en una variable varios tipos
// de datos
struct Alumno {
    string nombre;
    int edad;
    double promedio;
};

// -----------------------------------------------------------
// Función para crear (o sobrescribir) un archivo CSV
// -----------------------------------------------------------
bool crearCSV(const string& ruta,
              const vector<Alumno>& alumnos)
{
    ofstream out(ruta); // crea y sobrescribe
    // Si algo falla al abrir el archivo
    if (!out)
    {
        cerr << "Error al crear el archivo.\n";
        return false;
    }

    // Escribir encabezado
    out << "nombre,edad,promedio\n";
    // Escribir registros
    for (const auto& a : alumnos) {
        out << a.nombre << "," << a.edad << "," << a.promedio << "\n";
    }
    out.close();
    cout << "Archivo CSV creado con éxito: " << ruta << endl;
    return true;
}

// -----------------------------------------------------------
// Función para leer un archivo CSV línea por línea
// -----------------------------------------------------------
vector<Alumno> leerCSV(const string& ruta)
{
    // abrir el archivo en modo lectura
    ifstream in(ruta);
    vector<Alumno> lista;   // Crear un vector tipo Alumno
    // Si algo falla en abrir el archivo
    if (!in)
    {
        cerr << "No se pudo abrir el archivo.\n";
        return lista; // Regresa un vector vacío
    }
    string linea;
    getline(in, linea); // Saltar encabezado

    // Recorrer el archivo línea por línea
    // hasta hallar el caracter EOF
    while (getline(in, linea))
    {
        // con este se acomoda la línea leída
        stringstream ss(linea);
        string nombre, edadStr, promedioStr;

        // Separar elementos de la línea leída
        // que se distinguen por estar separados
        // por una coma ','
        getline(ss, nombre, ',');
        getline(ss, edadStr, ',');
        getline(ss, promedioStr, ',');

        // Guardar en una estrcutura tipo Alumno
        Alumno a;
        a.nombre = nombre;
        a.edad = stoi(edadStr);
        a.promedio = stod(promedioStr);

        // Ir agregando al final del vector
        // la estructura
        lista.push_back(a);
    }
    in.close();
    return lista;
}

// -----------------------------------------------------------
// Función para agregar un registro (sin borrar los anteriores)
// -----------------------------------------------------------
bool agregarCSV(const string& ruta, const Alumno& a)
{
    ofstream out(ruta, ios::app); // modo append
    if (!out) {
        cerr << "No se pudo abrir el archivo para agregar.\n";
        return false;
    }
    out << a.nombre << "," << a.edad << "," << a.promedio << "\n";
    out.close();
    cout << "Registro agregado: " << a.nombre << endl;
    return true;
}

int main()
{
    // Archivo a leer
    string archivo = "grupo1MM4.csv";
    // NombreEstructura nombreVariable
    Alumno miEstructura;

    miEstructura.nombre = "Enya OZ";
    miEstructura.edad = 22;
    miEstructura.promedio = 6.0;

    vector<Alumno> grupo = {
        {
            "Enya OZ", 22, 6.0
        },
        {
            "Hector YAO", 17, 2.0
        },
        {
            "Pelos Cabellos", 21, 0.3
        },
    };

    //cout << "Nombre: " << miEstructura.nombre << endl;
    crearCSV(archivo, grupo);

    // Leer del archivo
    cout << "\nContenido leído del archivo:\n";
    vector<Alumno> leidos = leerCSV(archivo);
    for (const auto& a : leidos) {
        cout << "- " << a.nombre << " | Edad: " << a.edad
             << " | Promedio: " << a.promedio << endl;
    }

    // Agregar nuevo registro
    Alumno nuevo = {"Ksimerito", 24, 6.66};
    agregarCSV(archivo, nuevo);

    // Leer nuevamente
    cout << "\nArchivo actualizado:\n";
    vector<Alumno> actualizados = leerCSV(archivo);
    for (const auto& a : actualizados) {
        cout << "- " << a.nombre << " | Edad: " << a.edad
             << " | Promedio: " << a.promedio << endl;
    }

    return 0;
}
