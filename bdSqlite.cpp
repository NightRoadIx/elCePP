#include <iostream>
#include <string>
#include "sqlite3.h"
using namespace std;

// Función de ayuda para revisar los códigos de retorno de las operaciones con SQLite
// Si la operación no es exitosa, se muestra un mensaje de error y se cierra la base de datos
static void check(int rc, sqlite3* db, const char* msg) {
    if (rc != SQLITE_OK && rc != SQLITE_ROW && rc != SQLITE_DONE) {
        // Imprimir mensaje de error
        cerr << "[ERROR] " << msg << ": " << sqlite3_errmsg(db) << "\n";
        // Si la base de datos está abierta, cerrarla
        if (db) sqlite3_close(db);
        // Terminar la ejecución del programa
        exit(1);
    }
}

int main() {
    sqlite3* db = nullptr;

    // 1) Abrir (o crear) la base de datos en archivo llamado "demo.db"
    int rc = sqlite3_open("demo.db", &db);
    // Verificar que la base de datos se haya abierto correctamente
    check(rc, db, "sqlite3_open");

    // 2) Crear tabla 'usuarios' si no existe
    // La tabla tendrá tres columnas: 'id', 'nombre' y 'edad'
    const char* sqlCreate =
        "CREATE TABLE IF NOT EXISTS usuarios ("
        "  id INTEGER PRIMARY KEY AUTOINCREMENT," // columna 'id' autoincrementable
        "  nombre TEXT NOT NULL,"                  // columna 'nombre' de tipo texto
        "  edad INTEGER NOT NULL"                 // columna 'edad' de tipo entero
        ");";
    // Ejecutar la sentencia SQL para crear la tabla
    rc = sqlite3_exec(db, sqlCreate, nullptr, nullptr, nullptr);
    // Verificar que la tabla se haya creado correctamente
    check(rc, db, "CREATE TABLE");

    // 3) Insertar registros en la tabla 'usuarios' usando sentencias preparadas
    const char* sqlInsert = "INSERT INTO usuarios (nombre, edad) VALUES (?1, ?2);";
    sqlite3_stmt* stmtInsert = nullptr;
    // Preparar la sentencia SQL para la inserción
    rc = sqlite3_prepare_v2(db, sqlInsert, -1, &stmtInsert, nullptr);
    check(rc, db, "prepare INSERT");

    // Insertar el primer registro (Ana Torres, 20 años)
    rc = sqlite3_bind_text(stmtInsert, 1, "Ana Torres", -1, SQLITE_TRANSIENT);
    check(rc, db, "bind nombre 1");
    rc = sqlite3_bind_int(stmtInsert, 2, 20);
    check(rc, db, "bind edad 1");
    rc = sqlite3_step(stmtInsert);  // Ejecutar la sentencia de inserción
    check(rc, db, "step INSERT 1");
    sqlite3_reset(stmtInsert); // Reutilizar la sentencia para el siguiente registro

    // Insertar el segundo registro (Luis Perez, 22 años)
    rc = sqlite3_bind_text(stmtInsert, 1, "Luis Perez", -1, SQLITE_TRANSIENT);
    check(rc, db, "bind nombre 2");
    rc = sqlite3_bind_int(stmtInsert, 2, 22);
    check(rc, db, "bind edad 2");
    rc = sqlite3_step(stmtInsert);  // Ejecutar la sentencia de inserción
    check(rc, db, "step INSERT 2");

    // Finalizar la sentencia preparada (liberar recursos)
    sqlite3_finalize(stmtInsert);

    // 4) Consultar los registros de la tabla 'usuarios' usando una sentencia preparada (SELECT)
    const char* sqlSelect = "SELECT id, nombre, edad FROM usuarios ORDER BY id;";
    sqlite3_stmt* stmtSelect = nullptr;
    // Preparar la sentencia SQL para la consulta
    rc = sqlite3_prepare_v2(db, sqlSelect, -1, &stmtSelect, nullptr);
    check(rc, db, "prepare SELECT");

    cout << "Usuarios en la BD:\n";
    // Iterar sobre los resultados de la consulta (uno por uno)
    while ((rc = sqlite3_step(stmtSelect)) == SQLITE_ROW) {
        // Obtener los valores de las columnas 'id', 'nombre' y 'edad'
        int id = sqlite3_column_int(stmtSelect, 0);
        const unsigned char* nombre = sqlite3_column_text(stmtSelect, 1);
        int edad = sqlite3_column_int(stmtSelect, 2);
        // Imprimir el resultado de cada fila
        cout << " - #" << id << " | " << (nombre ? reinterpret_cast<const char*>(nombre) : "")
             << " | edad=" << edad << "\n";
    }
    // Verificar que se hayan procesado todas las filas correctamente
    if (rc != SQLITE_DONE) check(rc, db, "step SELECT");

    // Finalizar la sentencia preparada para la consulta
    sqlite3_finalize(stmtSelect);

    // 5) Cerrar la conexión a la base de datos
    sqlite3_close(db);
    cout << "OK.\n";
    return 0;
}
