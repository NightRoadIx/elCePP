/*
    Manejo de archivos
*/
#include <iostream>
#include <fstream>	// Librería para el manejo de archivos
#include <string>

using namespace std;

int main()
{

    // Abrir un archivo (crear/abrir)
	// el parámetro ios::app permite actualizar el archivo y añadir
	// datos al final del mismo
    ofstream out("sukaritaz.txt", ios::app);
    // Revisar si abrió correctamente
    if(!out)
    {
        cerr << "No se puede abrir el archivo" << endl;
		// en otro caso salir del programa
        return 1;
    }
    // Escritura directamente en el archivo
    out << "Primera linea\n";
    out << "Segunda linea\n";

    string entrada;
    cout << "Escribemela: ";
    //cin >> entrada;
	// en lugar de usar cin, se usa getline para poder escribir
	// caracteres no alfanuméricos o imprimibles como los espacios
    getline(cin, entrada);
    out << entrada;

    // IMPORTANTISIMO!!!!!!!!!!!!!!!!!!!!!!!!
    out.close();

/*
    ifstream in("main.cpp");
    if(!in)
    {
        cerr << "No se puede abrir el archivo" << endl;
        return 1;
    }
    string linea;
    while(getline(in, linea))
    {
        cout << "Leida: " << linea << endl;
    }
*/
    return 0;
}
