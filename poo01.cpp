#include <iostream>
#include <bitset>
using namespace std;

// Clase
class PanelEstado
{
    // Atributos
private:   // Privaos y solo se ven dentro de la misma clase
    unsigned char estado;   // byte con 8 bits}

    // Métodos
public:
    // Constructor
    PanelEstado() : estado(8)
    {
        cout << "Instanciar objeto" << endl;
    }

    void activar(unsigned char mask)
    {
        estado |= mask;
    }

    void apagar(unsigned char mask)
    {
        estado &= mask;
    }

    void toggle(unsigned char mask)
    {
        estado ^= mask;
    }

    bool consultar(unsigned char mask)
    {
        return (estado & mask) != 0;
    }

    void mostrar()
    {
        cout << "Estado actual: " << bitset<8>(estado) << endl;
    }
};

int main() {
    // Instanciar el objeto
    // NombreClase nombreObjeto
    PanelEstado panel;

    panel.mostrar();
    panel.activar(4);

    panel.mostrar();
}
