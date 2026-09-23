#include <iostream>
#include <string>

using namespace std;

int main() {
    int opcion;

    cout << "=== SISTEMA DE CALIFICACIONES ===" << endl;
    cout << "1. Registrar estudiante" << endl;
    cout << "2. Ver informacion del programa" << endl;
    cout << "3. Salir" << endl;
    cout << "Opción: ";
    cin >> opcion;
    cin.ignore();

    switch (opcion) {
        case 1: {
            string nombre;
            int edad;
            int numCalificaciones;

            cout << "Ingrese el nombre del estudiante: ";
            getline(cin, nombre);

            cout << "Ingrese la edad: ";
            cin >> edad;

            while (edad <= 0 || edad > 120) {
                cout << "Error: Edad Inválida. Ingrese una edad entre 1 y 120: ";
                cin >> edad;
            }
            
            cout << "Cuántas calificaciones desea ingresar? ";
            cin >> numCalificaciones;

            while (numCalificaciones <= 0) {
                cout << "Error: ingrese una cantidad mayor a 0: ";
                cin >> numCalificaciones;
            }

            float suma = 0;
            float calificacion;
            float calificacionAlta = 0;
            float calificacionBaja = 10;
            int aprobatorias = 0;
            int reprobatorias = 0;

            // Nivel 4: Ciclo for para leer $n$ calificaciones
            for (int i = 1; i <= numCalificaciones; i++) {
                cout << "Ingrese la calificacion " << i << ": ";
                cin >> calificacion;

            while (calificacion < 0 || calificacion > 10) {
                cout << "Error: La calificación debe estar entre 0 y 10. Ingrese nuevamente: ";
                cin >> calificacion;
            }

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

            float promedio = suma / numCalificaciones;

            cout << "\n--- Resumen del Estudiante ---" << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "Edad: " << edad << endl;
            cout << "Promedio: " << promedio << endl;

            cout << "Estado: ";
            if (promedio >= 9) {
                cout << "EXCELENTE" << endl;
            } else if (promedio >= 7) {
                cout << "APROBADO" << endl;
            } else if (promedio >= 6) {
                cout << "REGULAR (aprobado con lo minimo)" << endl;
            } else {
                cout << "REPROBADO" << endl;
            }

            // Nivel 4: Imprimir conteo y calificacion max/min
            cout << "Calificaciones aprobatorias: " << aprobatorias << endl;
            cout << "Calificaciones reprobatorias: " << reprobatorias << endl;
            cout << "Calificacion mas alta: " << calificacionAlta << endl;
            cout << "Calificacion mas baja: " << calificacionBaja << endl;
            break;
        }
        case 2:
            cout << "\n--- Informacion del Programa ---" << endl;
            cout << "Sistema de Calificaciones Escolares v2.0" << endl;
            cout << "Desarrollado para la Practica #2 de Estructuras de Datos." << endl;
            break;
        case 3:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
            break;
    }

    return 0;
}