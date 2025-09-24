#include <iostream>
using namespace std;

int main() {
    // Colores de consola en código ASCII
    cout << "\033[30m Negro\033[0m\n";
    cout << "\033[31m Rojo\033[0m\n";
    cout << "\033[32m Verde\033[0m\n";
    cout << "\033[33m Amarillo\033[0m\n";
    cout << "\033[34m Azul\033[0m\n";
    cout << "\033[35m Magenta\033[0m\n";
    cout << "\033[36m Cian\033[0m\n";
    cout << "\033[37m Blanco\033[0m\n";

    cout << "--------------------------\n";

    // Colores brillantes (alta intensidad)
    cout << "\033[90m Gris claro\033[0m\n";
    cout << "\033[91m Rojo brillante\033[0m\n";
    cout << "\033[92m Verde brillante\033[0m\n";
    cout << "\033[93m Amarillo brillante\033[0m\n";
    cout << "\033[94m Azul brillante\033[0m\n";
    cout << "\033[95m Magenta brillante\033[0m\n";
    cout << "\033[96m Cian brillante\033[0m\n";
    cout << "\033[97m Blanco brillante\033[0m\n";

    cout << "--------------------------\n";

    // Subrayados
    cout << "\033[4;90m Gris claro subrayado\033[0m\n";

    cout << "--------------------------\n";

    // Itálica
    cout << "\033[3;90m Gris claro italica\033[0m\n";

    cout << "--------------------------\n";

    // Parpadeo
    cout << "\033[5;90m Gris claro parpadeo \033[0m\n";

    cout << "--------------------------\n";

    // Color de fondo
    cout << "\033[44m Gris claro fondo azul\033[0m\n";
}
