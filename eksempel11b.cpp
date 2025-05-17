// Este programa modifica los atributos de un archivo para
// hacerlo oculto.
// Funciona exclusivamente en sistemas Windows debido
// al uso de la API de Windows
#include <windows.h>
#include <iostream>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    // Nombre del archivo que se desea ocultar.
    // Hay que asegurarse que el archivo exista en el
    // mismo directorio que el ejecutable
    // en otro caso cambiar la ruta de acceso
    const char* archivo = "archivo.ext";

    /*
        SetFileAttributesA permite establecer atributos a
        un archivo.
        En este caso, FILE_ATTRIBUTE_HIDDEN indica que el
        archivo debe ser oculto.

        La función devuelve TRUE si tuvo éxito,
        o FALSE si hubo un error.
    */
    if (SetFileAttributesA(archivo, FILE_ATTRIBUTE_HIDDEN)) {
        cout << "Archivo '" << archivo << "' oculto exitosamente." << endl;
    } else {
        cout << "❌ Error al ocultar el archivo." << endl;
        // Obtener el código de error del sistema
        // para saber que sucedió
        DWORD errorCode = GetLastError();
        cout << "Código de error: " << errorCode << endl;
    }

    return 0;
}

/*
    🐧 Para el caso de Linux
    - En sistemas tipo UNIX (Linux/macOS), un archivo se
      considera oculto si su nombre comienza con un punto (.).
    - No se requiere cambiar atributos con funciones del
      sistema operativo, simplemente se puede renombrar el archivo:

        rename("archivo.ext", ".archivo.ext");

      Esto puede hacerse con la función estándar 'rename()'
      de C/C++:

        #include <cstdio>
        rename("archivo.ext", ".archivo.ext");

      Eso hará que sea oculto en la mayoría de exploradores
      y comandos como 'ls', a menos que se use 'ls -a'.

*/
