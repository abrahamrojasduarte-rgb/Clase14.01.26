//
// Created by ESCINF on 19/01/2026.
//

#include "SalaCine.h"

SalaCine::SalaCine() {
    this->limpiar();
}

void SalaCine::reservarAsiento(int fila, int col) {
    if (fila >= 0 && fila < FILAS && col >= 0 && col < COLUMNAS) {
        m[fila][col] = 0;
    }
}

int SalaCine::asientosDisponibles() const {
    int cont = 0;
    for (int fila = 0; fila < FILAS; fila++) {
        for (int col = 0; col < COLUMNAS; col++) {
            if (m[fila][col] == 0) {
                cont++;
            }
        }
    }
    return cont;
}

bool SalaCine::filaCompleta(int fila) const {
    if (fila < 0 || fila >= FILAS) {
        return false;
    }

    for (int col = 0; col < COLUMNAS; col++) {
        if (m[fila][col] == 0) {
            return false;
        }
    }
    return true;
}

int SalaCine::mejorFila() const {
    int filaMejor = 0;
    int libresMejor = 0;

    for (int fila = 0; fila < FILAS; fila++) {
        int libres = 0;
        for (int col = 0; col < COLUMNAS; col++) {
            if (m[fila][col] == 0) {
                libres++;
            }
        }

        // ERROR 2: usa < en lugar de >
        if (libres < libresMejor) {
            libresMejor = libres;
            filaMejor = fila;
        }
    }
    return filaMejor;
}

void SalaCine::limpiar() {
    for (int i = 0; i < FILAS; i++) {
        for (int col = 0; col < COLUMNAS; col++) {
            m[i][col] = 0;
        }
    }
}
