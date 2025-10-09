#include <iostream>
#include <iomanip>   // Librería para manipular la salida con formato (por ejemplo, setprecision)
using namespace std;

/*
-------------------------------------------------------------
    CLASE: Cuenta
    Descripción: Modela una cuenta bancaria con operaciones
    básicas de depósito, retiro, transferencia y consulta.
-------------------------------------------------------------
*/
class Cuenta
{
    /* ===========================
       ATRIBUTOS (ENCAPSULADOS)
       =========================== */
private:
    int numero;       // Número de cuenta único
    string titular;   // Nombre del titular de la cuenta
    double saldo;     // Monto disponible en la cuenta
    string tipo;      // Tipo de cuenta (Ahorro, Inversión, etc.)

    /* ===========================
       MÉTODOS PÚBLICOS
       =========================== */
public:

    /* ======== MÉTODOS GETTER ======== */
    // Devuelve el nombre del titular
    string getTitular() const { return titular; }

    // Devuelve el saldo actual
    double getSaldo() const { return saldo; }

    // Devuelve el tipo de cuenta
    string getTipo() const { return tipo; }

    /* ======== CONSTRUCTORES ======== */

    // Constructor por defecto
    // Se ejecuta al crear un objeto sin parámetros
    Cuenta() : numero(0), titular("Sin nombre"), saldo(0.0), tipo("Ahorro")
    {
        cout << "Constructor por defecto" << endl;
    }

    // Constructor con parámetros (Sobrecarga de constructor)
    // Permite inicializar los atributos con valores personalizados
    Cuenta(int _numero, string _titular, double _saldo, string _tipo)
        : numero(_numero), titular(_titular), saldo(_saldo), tipo(_tipo)
    {
        cout << "Constructor con parámetros" << endl;

        // Validación: el saldo no puede ser negativo
        if(_saldo < 0)
        {
            saldo = 0;
            cout << "Saldo inicial no puede ser negativo. Saldo = 0" << endl;
        }
    }

    /* ======== MÉTODOS DE OPERACIÓN ======== */

    // Realiza un depósito en la cuenta
    void depositar(double monto)
    {
        if(monto > 0)
        {
            saldo += monto;  // Aumenta el saldo
            cout << "Depósito de $" << monto << endl;
        }
        else
        {
            cout << "Monto no válido" << endl;
        }
    }

    // Realiza un retiro de la cuenta
    void retirar(double monto)
    {
        if(monto <= 0)
        {
            cout << "El monto debe ser mayor a cero" << endl;
        }
        else if(monto > saldo)
        {
            cout << "Saldo insuficiente" << endl;
        }
        else
        {
            saldo -= monto;  // Disminuye el saldo
            cout << "Retiro realizado: $" << monto << endl;
        }
    }

    /* ======== MÉTODOS DE MOSTRAR INFORMACIÓN ======== */

    // Muestra información básica de la cuenta
    void mostrar() const
    {
        // Configura la salida para mostrar dos decimales
        cout << fixed << setprecision(2);

        cout << "Titular:   " << titular << endl
             << " | Tipo:   " << tipo << endl
             << " | Saldo:  $" << saldo << endl;
    }

    // Sobrecarga del método mostrar
    // Muestra información más detallada si se pasa el parámetro 'true'
    void mostrar(bool detalle) const
    {
        cout << "----------------------------------------\n";
        cout << "Titular:           " << titular << endl;
        cout << "No de cuenta:      " << numero << endl;
        cout << "Tipo de cuenta:    " << tipo << endl;
        cout << "Saldo disponible:  $" << fixed << setprecision(2) << saldo << endl;

        // Si 'detalle' es verdadero, muestra el estado del tipo de cuenta
        if (detalle)
            cout << "Estado:            " 
                 << (saldo >= 10000 ? "Cuenta Premium" : "Cuenta estándar") 
                 << endl;

        cout << "----------------------------------------\n";
    }

    // Transfiere dinero de esta cuenta a otra
    void transferir(Cuenta &destino, double monto) 
    {
        if (monto > 0 && monto <= saldo) 
        {
            saldo -= monto;              // Se descuenta de la cuenta origen
            destino.depositar(monto);    // Se deposita en la cuenta destino
            cout << "Transferencia de $" << monto 
                 << " realizada a " << destino.getTitular() << endl;
        } 
        else 
        {
            cout << "No se puede realizar la transferencia.\n";
        }
    }
};

/*
-------------------------------------------------------------
    FUNCIÓN PRINCIPAL: main()
    Descripción: Demuestra el uso de la clase Cuenta con
    operaciones básicas y transferencias.
-------------------------------------------------------------
*/
int main()
{
    // Permite usar acentos y caracteres especiales en la consola
    setlocale(LC_CTYPE, "");

    // Creación de objetos de tipo Cuenta utilizando el constructor con parámetros
    Cuenta c1(1, "Mary Jane", 5000, "Ahorro");
    Cuenta c2(2, "Juan Nepomuceno", 12000, "Inversión");

    // Mostrar información inicial de ambas cuentas
    cout << "Estado inicial:\n";
    c1.mostrar();
    c2.mostrar();

    // Ejecución de operaciones básicas
    cout << "\nOperaciones:\n";
    c1.depositar(1500);   // Depósito válido
    c1.retirar(2000);     // Retiro válido
    c1.retirar(6000);     // Retiro inválido por saldo insuficiente

    // Transferencia entre cuentas
    cout << "\nTransferencia:\n";
    c2.transferir(c1, 3000);  // Transferencia válida desde c2 hacia c1

    // Mostrar resultados finales con información detallada
    cout << "\nEstado final:\n";
    c1.mostrar(true);
    c2.mostrar(true);

    return 0;
}
