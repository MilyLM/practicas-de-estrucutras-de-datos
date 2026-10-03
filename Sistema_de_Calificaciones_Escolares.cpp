#include <iostream>
#include <string>

using namespace std;

// =========================================================
// PROTOTIPOS DE FUNCIONES (Declaraciones antes de main)
// =========================================================
void mostrarMenu();
int leerEntero(string mensaje, int min, int max);
float leerCalificacion(int numero);
float calcularPromedio(float suma, int n);
string obtenerEstado(float promedio);
void registrarEstudiante();

// =========================================================
// FUNCIÓN PRINCIPAL MAIN
// =========================================================
int main() {
    int opcion;

    do {
        mostrarMenu();
        opcion = leerEntero("Opción: ", 1, 3);
        cin.ignore(); // Limpia el buffer de entrada para permitir el uso de getline

        switch (opcion) {
            case 1:
                registrarEstudiante();
                break;
            case 2:
                cout << "\n--- Informacion del Programa ---" << endl;
                cout << "Sistema de Calificaciones Escolares v4.0" << endl;
                cout << "Desarrollado para la Practica de Estructuras de Datos (Nivel 7)." << endl;
                break;
            case 3:
                cout << "Saliendo del programa... ¡Hasta luego!" << endl;
                break;
        }
    } while (opcion != 3);

    return 0;
}

// =========================================================
// DEFINICIÓN DE FUNCIONES (Implementaciones después de main)
// =========================================================

// 1. Imprime las opciones del menú
void mostrarMenu() {
    cout << "\n=== SISTEMA DE CALIFICACIONES ===" << endl;
    cout << "1. Registrar estudiante" << endl;
    cout << "2. Ver informacion del programa" << endl;
    cout << "3. Salir" << endl;
}

// 2. Pide y valida que un entero esté dentro del rango [min, max]
int leerEntero(string mensaje, int min, int max) {
    int valor;
    cout << mensaje;
    cin >> valor;

    while (valor < min || valor > max) {
        cout << "Error: Ingrese un valor valido entre " << min << " y " << max << ": ";
        cin >> valor;
    }
    return valor;
}

// 3. Pide y valida una calificación en el rango [0, 10]
float leerCalificacion(int numero) {
    float calificacion;
    cout << "Ingrese la calificacion " << numero << ": ";
    cin >> calificacion;

    while (calificacion < 0 || calificacion > 10) {
        cout << "Error: La calificacion debe estar entre 0 y 10. Ingrese nuevamente: ";
        cin >> calificacion;
    }
    return calificacion;
}

// 4. Retorna la división suma / n
float calcularPromedio(float suma, int n) {
    if (n <= 0) return 0;
    return suma / n;
}

// 5. Retorna la etiqueta según la escala del promedio
string obtenerEstado(float promedio) {
    if (promedio >= 9) {
        return "EXCELENTE";
    } else if (promedio >= 7) {
        return "APROBADO";
    } else if (promedio >= 6) {
        return "REGULAR (aprobado con lo minimo)";
    } else {
        return "REPROBADO";
    }
}

// 6. Contiene todo el flujo del registro de un estudiante (Opción 1)
void registrarEstudiante() {
    string nombre;
    cout << "\n--- Registro de Estudiante ---" << endl;
    cout << "Ingrese el nombre del estudiante: ";
    getline(cin, nombre);

    int edad = leerEntero("Ingrese la edad: ", 1, 120);
    int numCalificaciones = leerEntero("Cuantas calificaciones deseas registrar? ", 1, 100);

    float suma = 0;
    float calificacionAlta = 0;
    float calificacionBaja = 10;
    int aprobatorias = 0;
    int reprobatorias = 0;

    for (int i = 1; i <= numCalificaciones; i++) {
        float calificacion = leerCalificacion(i);
        suma += calificacion;

        if (calificacion >= 6) {
            aprobatorias++;
        } else {
            reprobatorias++;
        }

        if (i == 1) {
            calificacionAlta = calificacion;
            calificacionBaja = calificacion;
        } else {
            if (calificacion > calificacionAlta) calificacionAlta = calificacion;
            if (calificacion < calificacionBaja) calificacionBaja = calificacion;
        }
    }

    float promedio = calcularPromedio(suma, numCalificaciones);
    string estado = obtenerEstado(promedio);

    cout << "\n--- Resumen del Estudiante ---" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Estado: " << estado << endl;
    cout << "Calificaciones aprobatorias: " << aprobatorias << endl;
    cout << "Calificaciones reprobatorias: " << reprobatorias << endl;
    cout << "Calificacion mas alta: " << calificacionAlta << endl;
    cout << "Calificacion mas baja: " << calificacionBaja << endl;
}