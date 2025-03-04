#include <iostream>

using namespace std;

int main() {
    // Apuntador a bloques de memoria entera (32 bits)
    // los cuales son en total 5
    // OJO: NUNCA DECLAREN UN PUNTERO SIN INICIARLO
    int *numeros = new int(5);  // int numeros[5];
    int i;

    for(i = 0; i < 5; i++)
    {
        // Recorrer los bloques de memoria para asignarles un valor
        *(numeros+i) = 666 - i;   // numeros[i]
        cout<<*(numeros+i)<<"\n";
    }

    /* * * * ASIGNACIÓN DINÁMICA DE MEMORIA * * * */
    int *ptr = new int;   // int *ptr = nullptr;
    
    // Solicitar que se ingrese un número
    cout<<"Ingrese un número: ";
    // Se asigna al espacio en memoria apuntado por ptr
    cin>>*ptr;

    // Mostrar el valor y la dirección de memoria
    cout<<"Valor: "<<*ptr<<" en la dirección: "<<&ptr;

    delete ptr;

    return 0;
}
