#include <iostream>
using namespace std;

char tablero[3][3];
char jugadorActual = 'X';

void inicializarTablero() {
    for (int fila = 0; fila < 3; fila++) {
        for (int columna = 0; columna < 3; columna++) {
            tablero[fila][columna] = ' ';
        }
    }
}

void mostrarTablero() {
    cout << "\n  0   1   2\n";
    for (int fila = 0; fila < 3; fila++) {
        cout << fila << " ";
        for (int columna = 0; columna < 3; columna++) {
            cout << tablero[fila][columna];
            if (columna < 2) cout << " | ";
        }
        cout << "\n";
        if (fila < 2) cout << "  ---------\n";
    }
    cout << "\n";
}

void cambiarTurno() {
    if (jugadorActual == 'X') {
        jugadorActual = 'O';
    } else {
        jugadorActual = 'X';
    }
}

bool hayGanador() {
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] != ' ' && tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) {
            return true;
        }
        if (tablero[0][i] != ' ' && tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) {
            return true;
        }
    }

    if (tablero[0][0] != ' ' && tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) {
        return true;
    }

    if (tablero[0][2] != ' ' && tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]) {
        return true;
    }

    return false;
}

bool tableroLleno() {
    for (int fila = 0; fila < 3; fila++) {
        for (int columna = 0; columna < 3; columna++) {
            if (tablero[fila][columna] == ' ') {
                return false; // Aún hay espacio libre
            }
        }
    }
    return true; 
}

int main() {
    inicializarTablero();
    
    int fila, columna;
    bool juegoTerminado = false;

    cout << "=== JUEGO DEL GATO EN C++ ===\n";

    while (!juegoTerminado) {
        mostrarTablero();
        cout << "Turno del Jugador (" << jugadorActual << ")\n";
        
        cout << "Ingresa la fila (0, 1 o 2): ";
        cin >> fila;
        cout << "Ingresa la columna (0, 1 o 2): ";
        cin >> columna;

        if (fila >= 0 && fila < 3 && columna >= 0 && columna < 3 && tablero[fila][columna] == ' ') {
            tablero[fila][columna] = jugadorActual; // Guardar la jugada

            if (hayGanador()) {
                mostrarTablero();
                cout << "¡Felicidades! El Jugador " << jugadorActual << " ha ganado.\n";
                juegoTerminado = true;
            } else if (tableroLleno()) {
                mostrarTablero();
                cout << "¡Empate! No quedan casillas disponibles.\n";
                juegoTerminado = true;
            } else {
                cambiarTurno();
            }
        } else {
            cout << "\n--> Posicion invalida o casilla ocupada. Intenta de nuevo.\n";
        }
    }

    return 0;
}