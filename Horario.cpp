//
// Created by ESCINF on 19/01/2026.
//

#include "Horario.h"

Horario::Horario() {
    this->limpiar();
}

void Horario::agregarClase(int dia, int hora, string nombreClase) {
    if (dia >= 0 && dia < DIAS && hora >= 0 && hora < HORAS) {
        m[dia][hora] = nombreClase;
    }
}

int Horario::clasesPorDia(int dia) {
    if (dia < 0 && dia > DIAS) {
        return 0;
    }
    int tot = 0;
    for (int j = 0; j < HORAS; j++) {
        if (m[dia][j] == "") {
            tot++;
        }
    }
    return HORAS - tot;
}

int Horario::diaMasOcupado() {
    int maxClases = clasesPorDia(0);
    int indice = 0;

    for (int dia = 1; dia < DIAS; dia++) {
        int clases = clasesPorDia(dia);

        if (clases > maxClases) {
            maxClases = clases;
            indice = dia;
        }
    }

    return indice;
}


bool Horario::estaLibre(int dia, int hora) {
    bool estaLibre = false;
    if (dia >= 0 && dia < DIAS && hora >= 0 && hora < HORAS) {
        if (m[dia][hora] == "") {
            estaLibre = true;
        }
    }
    return estaLibre;
}

void Horario::limpiar() {
    for (int i = 0; i < DIAS; i++) {
        for (int j = 0; j < HORAS; j++) {
            m[i][j] = " ";
        }
    }
}

string Horario::toString() {
    stringstream ss;
    for (int i = 0; i < DIAS; i++) {
        for (int j = 0; j < HORAS; j++) {
            ss<<m[i][j];
        }
        ss<<endl;
    }
    return ss.str();
}
