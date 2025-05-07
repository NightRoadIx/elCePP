#include <iostream>
#include <string>
#include <stack>
#include <windows.h>

using namespace std;

// Clase base que representa una notificación genérica
class Notificacion {
public:
    // Método virtual puro (interfaz)
    virtual void enviar() const = 0;

    // Destructor virtual
    virtual ~Notificacion() {}
};

// Clase derivada para notificaciones por correo
class NotificacionCorreo : public Notificacion {
private:
    string correo;
    string mensaje;

public:
    NotificacionCorreo(const string& _correo, const string& _mensaje)
        : correo(_correo), mensaje(_mensaje) {}

    void enviar() const override {
        cout << "[📧 Email] Enviando correo a: " << correo << endl;
        cout << "Contenido: " << mensaje << endl;
    }
};

// Clase derivada para notificaciones por SMS
class NotificacionSMS : public Notificacion {
private:
    string numero;
    string mensaje;

public:
    NotificacionSMS(const string& _numero, const string& _mensaje)
        : numero(_numero), mensaje(_mensaje) {}

    void enviar() const override {
        cout << "[📱 SMS] Enviando mensaje a: " << numero << endl;
        cout << "Mensaje: " << mensaje << endl;
    }
};

// Clase derivada para notificaciones en pantalla
class NotificacionPopup : public Notificacion {
private:
    string mensaje;

public:
    NotificacionPopup(const string& _mensaje)
        : mensaje(_mensaje) {}

    void enviar() const override {
        cout << "[💻 Popup] Mostrando en pantalla: " << mensaje << endl;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Pila de notificaciones usando punteros
    stack<Notificacion*> pila;

    // Agregar notificaciones
    pila.push(new NotificacionCorreo("alumno@correo.com", "Tienes una nueva tarea pendiente."));
    pila.push(new NotificacionSMS("5512345678", "Tu paquete ha sido entregado!"));
    pila.push(new NotificacionPopup("Recuerda guardar tu trabajo!"));

    // Guardar temporalmente los punteros para luego liberar memoria
    const int MAX = 3;
    Notificacion* almacen[MAX];
    int index = 0;

    // Sacar elementos de la pila y mostrarlos
    while (!pila.empty() && index < MAX) {
        almacen[index] = pila.top();     // Guardamos puntero para liberar después
        pila.top()->enviar();            // Enviamos la notificación
        pila.pop();                      // Quitamos de la pila
        index++;
        cout << endl;
    }

    // Liberación de memoria dinámica
    for (int i = 0; i < index; i++) {
        delete almacen[i];  // Llama al destructor apropiado gracias al `virtual`
    }

    return 0;
}
