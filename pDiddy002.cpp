#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    // Cadenas de caracteres
    // Evitan el problema de un espacio estático
    // de memoria con los arreglos de caracteres
    // esto es, la cadena puede modificar su tamaño
    // durante el desarrollo del programa
    string s = "Jeffrey";

    // Y con ello podemos conocer varias cosas de la cadena
    cout << s.length() << endl;     // Longitud
    cout << s.size() << endl;       // Tamaño
    cout << s.empty() << endl;      // es vacía???

    // Podemos acceder a sus elementos, como un arreglo
    cout << s[3] << endl;

    // Recorrerla con un foreach
    for(char c : s)
        cout << c << " ";
    cout << endl;

    // Sin embargo, una forma más eficiente en memoria
    // es usando const auto apuntador
    // const deja el objeto fijo sin modificaciones
    // auto deja que el compilador decida el tipo de dato
    // y se hace referencia a la dirección del objeto & en si
    // sin hacer copias del mismo
    for(const auto& c : s)
        cout << c << " ";
    cout << endl;

    // Es posible concatenar con un solo operador
    // dándole otra funcionalidad al '+'
    string res = s + " Epstein";
    cout << res << endl;

    // Substrings
    // a partir de que caracter y cuantos
    string sub = res.substr(8, 3);
    cout << sub << endl;

    // Localización de patrones
    // Buscar si se halla una subcadena en otra
    // si esto es diferente a la constante "npos"
    // entonces, se encuentra la subcadena
    // esta es la forma adecuada de buscar en una cadena
    if(res.find("Epstein") != string::npos)
        cout << "Encontrado Epstein files" << endl;


    // Lo interesante viene con el uso de arreglos de cadenas
    // pero con un tipo diferente, llamado vector
    vector<string> sensores = {"Temp", "Presion", "Velocidad"};
    // Obviamente, así es más elegante y limpio recorrerlo
    for(const auto& sens : sensores)
    {
        cout << sens << endl;
    }

    /*
        Todo esto puede servir para la recepción de comandos
        en transmisión, por ejemplo en protocolo UART (serial)
    */
    string comando = "MOTOR:1200";
    // Extracción de datos
    // Obtener la posición de los :
    size_t pos = comando.find(":");
    // Hallar el dispositivo
    string dispositivo = comando.substr(0, pos);
    // y el valor del comando
    string valor = comando.substr(pos+1);
    // convertir a un valor entero
    int rpm = stoi(valor);
    
    cout << "Dispositivo: " << dispositivo << endl;
    cout << "Valor      : " << rpm << endl;
    
    return 0;
}
