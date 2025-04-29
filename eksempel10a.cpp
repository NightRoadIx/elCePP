#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

/*
    El programa simula como se manejan
    los diferentes tipos de notificaciones
    en un dispositivo móvil, todo manejado
    desde una clase genérica
*/

// Clase base que representa una notificación genérica
class Notificacion
{
public:
    // Método virtual puro (interfaz)
    /*
        El Método usa la palabra const
        para indicar que no modificará
        el estado del objeto, esto es,
        que no hará modificaciones de los
        atributos
    */
    virtual void enviar() const = 0;

    // Destructor virtual
    virtual ~Notificacion() {}
};

// Clase derivada para notificaciones por correo
class NotificacionCorreo : public Notificacion
{
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
class NotificacionSMS : public Notificacion
{
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
class NotificacionPopup : public Notificacion
{
private:
    string mensaje;

public:
    NotificacionPopup(const string& _mensaje)
        : mensaje(_mensaje) {}

    void enviar() const override {
        cout << "[💻 Popup] Mostrando en pantalla: " << mensaje << endl;
    }
};

int main()
{
    // Configura la consola para mostrar caracteres en UTF-8 (acentos, eñes)
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Arreglo de punteros a la clase base
    const int MAX_NOTIFICACIONES = 3;
    Notificacion* lista[MAX_NOTIFICACIONES];

    // Asignación dinámica de memoria: creación de objetos usando "new"
    // Estas notificaciones se van creando cuando sea necesario
    // y una iría detrás de la otra
    lista[0] = new NotificacionCorreo("alumno@correo.com", "Tienes una nueva tarea pendiente.");
    lista[1] = new NotificacionSMS("5512345678", "¡Tu paquete ha sido entregado!");
    lista[2] = new NotificacionPopup("¡Recuerda guardar tu trabajo!");

    // Uso de polimorfismo para enviar todas las notificaciones
    for (int i = 0; i < MAX_NOTIFICACIONES; i++) {
        lista[i]->enviar();
        cout << endl;
    }

    // Liberación de memoria dinámica
    for (int i = 0; i < MAX_NOTIFICACIONES; i++) {
        delete lista[i]; // Llama al destructor apropiado gracias al `virtual`
    }

    return 0;
}
