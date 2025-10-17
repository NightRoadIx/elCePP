/************************************************************
 * Fecha y hora actual con <chrono> y <ctime>
 * -----------------------------------------------------
 * - chrono::system_clock::now() devuelve el "tiempo actual".
 * - to_time_t() lo transforma a time_t (segundos desde época).
 * - localtime() convierte time_t a fecha/hora local (struct tm*).
 * - put_time() formatea la salida según especificador strftime.
 *   Formato usado: "%d/%m/%Y %H:%M:%S".
 * Nota: localtime() no es thread-safe en muchas plataformas.
 ************************************************************/

#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
using namespace std;

int main() {
    auto ahora = chrono::system_clock::now();                 // reloj del sistema
    time_t t = chrono::system_clock::to_time_t(ahora);        // a time_t (segundos)

    cout << "Fecha y hora actual: "
         << put_time(localtime(&t), "%d/%m/%Y %H:%M:%S")
         << endl;

    return 0;
}
