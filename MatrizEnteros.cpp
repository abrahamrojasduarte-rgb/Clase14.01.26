//
// Created by Abraham on 1/14/2026.
//

#include "MatrizEnteros.h"


MatrizEnteros::MatrizEnteros() {
    this -> limpiar();
}

void MatrizEnteros::limpiar() {
    for (int i = 0; i < FIL; i++) {
        for (int j = 0; j < COL; j++) {
            m[i][j] = 0;
        }
    }
}

void MatrizEnteros::insertar(int Fila, int Columna, int valor) {
    if (Fila >= 0 && Fila < FIL && Columna >= 0 && Columna < COL) {
        m[Fila][Columna] = valor;
    }
}

int MatrizEnteros::obtener(int Fila, int Columna) {
    if (Fila >= 0 && Fila < FIL && Columna >= 0 && Columna < COL) {
        return m[Fila][Columna];
    }
    return -1;
}

string MatrizEnteros::toString() {
    stringstream ss;
    for (int i = 0; i < FIL; i++) {
        for (int j = 0; j < COL; j++) {
            ss << m[i][j] << " ";
        }
        ss << endl;
    }
    return ss.str();
}

bool MatrizEnteros::buscar(int valor) {
    bool resultado = false;
    for (int i = 0; i < FIL; i++) {
        for (int j = 0; j < COL; j++) {
            if (m[i][j] == valor) {
                resultado = true;
            }
        }
    }
    return resultado;
}

int MatrizEnteros::contarApariciones(int valor) {
    int contador = 0;
    for (int i = 0; i < FIL; i++) {
        for (int j = 0; j < COL; j++) {
            if (m[i][j] == valor) {
                contador++;
            }
        }
    }
    return contador;
}

bool MatrizEnteros::buscarEnColumna(int columna, int valor) {
    bool resultado = false;
    if (columna >= 0 && columna < COL) {
        for (int i = 0; i < FIL; i++) {
            if (m[i][columna] == valor) {
                resultado = true;
                break;
            }
        }
    }
    return resultado;
}

bool MatrizEnteros::buscarEnFila(int fila, int valor) {
    bool resultado = false;
    if (fila >= 0 && fila < FIL) {
        for (int i = 0; i < COL; i++) {
            if (m[fila][i] == valor) {
                resultado = true;
                break;
            }
        }
    }
    return resultado;
}