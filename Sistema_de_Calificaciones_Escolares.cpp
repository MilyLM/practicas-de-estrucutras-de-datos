#include <iostream>
#include <string>

using namespace std;

int main() {

    string nombre;
    int edad;
    float calificacion1, calificacion2, calificacion3;
    float promedio;

   
    cout << "Ingrese el nombre del estudiante: ";
    cin >> nombre; 

    cout << "Ingrese la edad: ";
    cin >> edad;


    if (edad < 0 || edad > 120) {
        cout << "Edad invalida" << endl;
        return 0; 
    }

    cout << "Ingrese la calificacion 1: ";
    cin >> calificacion1;
    cout << "Ingrese la calificacion 2: ";
    cin >> calificacion2;
    cout << "Ingrese la calificacion 3: ";
    cin >> calificacion3;

    
    if (calificacion1 < 0 || calificacion1 > 10 || 
        calificacion2 < 0 || calificacion2 > 10 || 
        calificacion3 < 0 || calificacion3 > 10) {
        cout << "Error: Las calificaciones deben estar entre 0 y 10." << endl;
        return 0; 
    }

   
    promedio = (calificacion1 + calificacion2 + calificacion3) / 3;

   
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

    return 0;
}