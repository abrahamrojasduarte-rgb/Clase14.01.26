//
// Created by Abraham on 1/14/2026.
//

#include "MatrizOperaciones.h"
#include <sstream>

MatrizOperaciones::MatrizOperaciones() {
    this -> limpiar();
}


void MatrizOperaciones::llenarFila(int fila, int valor) {
    if (fila >= 0 && fila <= FIL) {
        m[fila][fila] = valor;
    }
}
void MatrizOperaciones::llenarColumna(int columna, int valor) {
    if (columna >= 0 && columna <= COL) {
        m[columna][columna]=valor;
    }
}
int MatrizOperaciones::sumarFila(int fila) {
    int suma = 0;
    if (fila >= 0 && fila < FIL) {
        for (int j = 0; j < COL; j++) {
            suma += m[fila][j];
        }
    }
    return suma;
    }
int MatrizOperaciones::sumarColumna(int columna) {
    int suma = 0;
    if (columna >= 0 && columna < COL) {
        for (int i = 0; i < FIL; i++) {
            suma += m[i][columna];
        }
    }
    return suma;
}
double MatrizOperaciones::promedioFila(int fila) {
    if (fila >= 0 && fila < FIL) {
        return (double) sumarFila(fila) / COL;
    }
    return 0.0;   // fila inválida
}

string MatrizOperaciones::toString() {
    stringstream ss;
    for (int i = 0; i < FIL; i++) {
        for (int j = 0; j < COL; j++) {
            ss << m[i][j] << " ";
        }
        ss << endl;
    }
    return ss.str();
}
void MatrizOperaciones::limpiar() {
    for (int i = 0; i < FIL; i++) {
        for (int j = 0; j < COL; j++) {
            m[i][j] = 0;
        }
    }
}