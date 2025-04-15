#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

#define ROJO "\033[31m"
#define VERDE "\033[32m"
#define AZUL "\033[34m"
#define REINICIA "\033[0m"

using namespace std;

class Jugador
{
private:
    string nombre;
    int saldo;

public:
    Jugador(string _nombre, int _saldo) : nombre(_nombre), saldo(_saldo)
    {
        cout << "Jugador " << nombre << "con saldo $" << saldo << endl;
    }

    string getNombre() const { return nombre; }
    int getSaldo() const { return saldo; }

    void ajustarSaldo(int cantidad)
    {
        saldo += cantidad;
    }
};

// Clase Ruleta
class Ruleta
{
private:
    int numeroGanador;
public:
    Ruleta()
    {
        // Iniciar número semilla
        srand(time(0));
    }

    void girar()
    {
        numeroGanador = rand() % 37;
    }

    // Método para obtener el número ganador
    int getNumeroGanador() const {
        return numeroGanador;
    }
};

int main()
{
    // Cambiar la codificación de entrada y salida a UTF-8
    // UTF/8 e sla extension de ASCII para poder manejar
    // ñ y acentos
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    string nombreJugador; // Variable para almacenar el nombre del jugador
    int apuesta;          // Monto que el jugador apuesta en cada ronda
    int numeroElegido;    // Número elegido por el jugador

    // Mostrar algo bonito
    cout << ROJO <<"Bienvenido al juego de la ruleta!" << endl;
    cout << VERDE <<"Ingresa tu nombre: " << REINICIA;
    getline(cin, nombreJugador);

    Jugador jugador(nombreJugador, 1500);

    // Crear un objeto Ruleta
    Ruleta ruleta;

    // Variable para controlar si el jugador quiere seguir jugando
    char jugarDeNuevo = 's';

    // Bucle principal del juego
    while (jugarDeNuevo == 's' && jugador.getSaldo() > 0) {
        cout << "\nTu saldo actual es: $" << jugador.getSaldo() << endl;
        cout << "¿Cuánto deseas apostar?: ";
        cin >> apuesta;

        // Verificar que la apuesta sea válida
        if (apuesta > jugador.getSaldo() || apuesta <= 0) {
            cout << "Apuesta inválida. Intenta de nuevo." << endl;
            continue; // Saltar al siguiente ciclo del bucle
        }

        // Solicitar al jugador que elija un número
        cout << "Elige un número entre 0 y 36: ";
        cin >> numeroElegido;

        // Validar que el número esté en el rango correcto
        if (numeroElegido < 0 || numeroElegido > 36) {
            cout << "Número inválido. Intenta de nuevo." << endl;
            continue;
        }

        // Girar la ruleta
        ruleta.girar();
        cout << "La ruleta gira... y cae en el número: " << ruleta.getNumeroGanador() << "!" << endl;

        // Verificar si el jugador acertó el número
        if (numeroElegido == ruleta.getNumeroGanador()) {
            cout << "¡Felicidades! Has ganado 35 veces tu apuesta!" << endl;
            jugador.ajustarSaldo(apuesta * 35); // Se paga 35 a 1 como en la ruleta real
        } else {
            cout << "Lo siento, has perdido tu apuesta." << endl;
            jugador.ajustarSaldo(-apuesta); // Se descuenta la apuesta
        }

        // Verificar si el jugador tiene saldo para seguir jugando
        if (jugador.getSaldo() > 0) {
            cout << "\n¿Deseas jugar de nuevo? (s/n): ";
            cin >> jugarDeNuevo;
        } else {
            cout << "Te has quedado sin saldo. ¡Gracias por jugar!" << endl;
            break; // Salir del bucle
        }
    }

    // Mostrar saldo final y despedida
    cout << "\nTu saldo final es: $" << jugador.getSaldo() << endl;
    cout << "¡Hasta luego, " << jugador.getNombre() << "!" << endl;

    return 0; // Fin del programa
}
