#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    /* ESCRITURA */
    // Crear el objeto para manejar archivos
    ofstream MyFile("sixela.rafa");

    // Escribir en un archivo
    MyFile << "Esto es un escrito guardado";

    // IMPORTANTE: Cerrar el archivo
    MyFile.close();

    /* LEPTURA */
    // Crear una cadena de texto donde se va a ler
    string miTexto;

    // Crear el objeto pa' ler
    ifstream MiArchivo("main.cpp");

    // Se va a leer línea por línea sniffff
    while(getline(MiArchivo, miTexto))
    {
        // Escribir en la linea de comando
        cout << miTexto << endl;
    }

    // Cerrar
    MiArchivo.close();

    /* ORA 'amos a echar a perder un archivo. */
    ifstream MiArchivo2("Coreanovirus.pdf");

    // Revisar si el archivo se logra abrir
    if(!MiArchivo2.is_open())
    {
        cerr << "11No se pudo abrir el archivo para lectura." << endl;
        return 1;
    }


    // Ler todo de guamazo y guardarlo como un
    // objeto stringstream
    stringstream buffer;
    // Cargar todo el archivo en el stringstream
    // mediante el buffer interno del archivo
    buffer << MiArchivo2.rdbuf();

    // Obtener una cadena de texto con el método
    // str()
    cout << buffer.str();

    // Cerrar el archivo
    MiArchivo2.close();

    // Agregar algo al archivo
    buffer << "666";

    // Abrir el archivo para sobreescritura
    ofstream MiArchivo3("Coreanovirus.pdf");

    if (!MiArchivo3.is_open()) {
        cerr << "No se pudo abrir el archivo para escritura." << endl;
        return 1;
    }

    // Escribir el nuevo contenido del archivo
    MiArchivo3 << buffer.str();

    // Cerrar el archivo
    MiArchivo3.close();

    return 0;
}
