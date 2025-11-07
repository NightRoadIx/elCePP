#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <string>
#include <algorithm>

using namespace std;

// Declaración de la función de procedimiento de ventana
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

// Declaración de la función de cifrado César
wstring CifradoCesar(const wstring& texto, int desplazamiento);
string CifradoCesarANSI(const string& texto, int desplazamiento);

// Nombres de clase y variables globales para los controles
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");

// IDs para los controles de la interfaz
#define ID_TEXTO_ORIGINAL 1001
#define ID_TEXTO_CIFRADO 1002
#define ID_BOTON_CONVERTIR 1003

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               // Manejo de nuestra ventana
    MSG messages;            // Donde se guardan los mensajes de la aplicación
    WNDCLASSEX wincl;        // Estructura de datos para la clase de ventana

    // Estructura de la ventana
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      // Función llamada por Windows
    wincl.style = CS_DBLCLKS;                 // Captura doble-clics
    wincl.cbSize = sizeof (WNDCLASSEX);

    // Usar icono y cursor predeterminados
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);  // Cambiado a flecha normal
    wincl.lpszMenuName = NULL;                 // Sin menú
    wincl.cbClsExtra = 0;                      // Sin bytes extra después de la clase
    wincl.cbWndExtra = 0;                      // de ventana o instancia
    // Usar color personalizado como fondo de la ventana
    wincl.hbrBackground = CreateSolidBrush(RGB(202, 238, 255));

    // Registrar la clase de ventana, si falla terminar el programa
    if (!RegisterClassEx (&wincl))
        return 0;

    // La clase está registrada, creemos el programa
    hwnd = CreateWindowEx (
           0,                   // Posibilidades extendidas para variación
           szClassName,         // Nombre de clase
           _T("Cifrado César - Convertidor de Texto"), // Texto del título
           WS_OVERLAPPEDWINDOW, // Ventana por defecto
           CW_USEDEFAULT,       // Windows decide la posición
           CW_USEDEFAULT,       // Donde termina la ventana en pantalla
           720,                 // Ancho del programa
           512,                 // Alto en píxeles
           HWND_DESKTOP,        // La ventana es hija del escritorio
           NULL,                // Sin menú
           hThisInstance,       // Manejador de instancia del programa
           NULL                 // Sin datos de creación de ventana
           );

    // Hacer la ventana visible en pantalla
    ShowWindow (hwnd, nCmdShow);

    // Ejecutar el bucle de mensajes hasta que GetMessage() retorne 0
    while (GetMessage (&messages, NULL, 0, 0))
    {
        // Traducir mensajes de teclas virtuales a mensajes de caracteres
        TranslateMessage(&messages);
        // Enviar mensaje a WindowProcedure
        DispatchMessage(&messages);
    }

    // El valor de retorno del programa es 0 - Valor que dio PostQuitMessage()
    return messages.wParam;
}

// Función que implementa el cifrado César para Unicode (wstring)
wstring CifradoCesar(const wstring& texto, int desplazamiento) {
    wstring resultado = texto;

    // Aplicar el cifrado a cada carácter
    for (size_t i = 0; i < texto.length(); i++) {
        wchar_t c = texto[i];

        // Cifrar solo letras, dejar otros caracteres igual
        if (iswalpha(c)) {
            wchar_t base = iswlower(c) ? L'a' : L'A';
            c = base + (c - base + desplazamiento) % 26;
        }

        resultado[i] = c;
    }

    return resultado;
}

// Función que implementa el cifrado César para ANSI (string)
string CifradoCesarANSI(const string& texto, int desplazamiento) {
    string resultado = texto;

    // Aplicar el cifrado a cada carácter
    for (size_t i = 0; i < texto.length(); i++) {
        char c = texto[i];

        // Cifrar solo letras, dejar otros caracteres igual
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = base + (c - base + desplazamiento) % 26;
        }

        resultado[i] = c;
    }

    return resultado;
}

// Función llamada por la función de Windows DispatchMessage()
LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    // Variables estáticas para mantener los controles entre llamadas
    static HWND hEditOriginal, hEditCifrado, hBotonConvertir;
    static HWND hLabelOriginal, hLabelCifrado;

    switch (message) {         // Manejar los mensajes
        case WM_CREATE:
            // Este mensaje se envía cuando se crea la ventana
            // Es donde creamos nuestros controles (textboxes, botones, etc.)

            // Crear etiqueta para el texto original
            hLabelOriginal = CreateWindow(
                _T("STATIC"), _T("Texto Original:"),
                WS_CHILD | WS_VISIBLE | SS_LEFT,
                20, 20, 200, 20,
                hwnd, NULL, NULL, NULL
            );

            // Crear caja de texto para entrada
            hEditOriginal = CreateWindow(
                _T("EDIT"), _T(""),
                WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_AUTOHSCROLL,
                20, 45, 650, 25,
                hwnd, (HMENU)ID_TEXTO_ORIGINAL, NULL, NULL
            );

            // Crear etiqueta para el texto cifrado
            hLabelCifrado = CreateWindow(
                _T("STATIC"), _T("Texto Cifrado:"),
                WS_CHILD | WS_VISIBLE | SS_LEFT,
                20, 90, 200, 20,
                hwnd, NULL, NULL, NULL
            );

            // Crear caja de texto para salida (solo lectura)
            hEditCifrado = CreateWindow(
                _T("EDIT"), _T(""),
                WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_READONLY,
                20, 115, 650, 25,
                hwnd, (HMENU)ID_TEXTO_CIFRADO, NULL, NULL
            );

            // Crear botón para convertir
            hBotonConvertir = CreateWindow(
                _T("BUTTON"), _T("Convertir a Cifrado César"),
                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                20, 160, 200, 30,
                hwnd, (HMENU)ID_BOTON_CONVERTIR, NULL, NULL
            );

            break;

        case WM_COMMAND:
            // Este mensaje se envía cuando se interactúa con controles
            if (LOWORD(wParam) == ID_BOTON_CONVERTIR) {
                // El botón "Convertir" fue presionado

                // Buffer para almacenar el texto
                TCHAR buffer[256];

                // Obtener el texto del cuadro de entrada
                GetWindowText(hEditOriginal, buffer, 256);

                // Verificar si estamos compilando con UNICODE
                #ifdef UNICODE
                    // Versión Unicode: usar wstring
                    wstring textoOriginal = buffer;
                    if (!textoOriginal.empty()) {
                        wstring textoCifrado = CifradoCesar(textoOriginal, 5);
                        SetWindowText(hEditCifrado, textoCifrado.c_str());
                    } else {
                        SetWindowText(hEditCifrado, _T(""));
                    }
                #else
                    // Versión ANSI: usar string
                    string textoOriginal = buffer;
                    if (!textoOriginal.empty()) {
                        string textoCifrado = CifradoCesarANSI(textoOriginal, 5);
                        SetWindowText(hEditCifrado, textoCifrado.c_str());
                    } else {
                        SetWindowText(hEditCifrado, _T(""));
                    }
                #endif
            }
            break;

        case WM_DESTROY:
            // Mensaje enviado cuando se cierra la ventana
            PostQuitMessage(0);  // Enviar WM_QUIT a la cola de mensajes
            break;

        default:
            // Para mensajes que no manejamos específicamente
            return DefWindowProc(hwnd, message, wParam, lParam);
    }

    return 0;
}
