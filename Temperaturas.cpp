//
// Created by Abraham on 1/18/2026.
//

#include "Temperaturas.h"

Temperaturas::Temperaturas() {
    for (int i = 0; i<DIAS; i++) {
        for (int j =0; j<CIUDADES; j++) {
            m[i][j] = 0;
        }
    }
}

void Temperaturas::registrarTemperatura(int dia, int ciudad, double temp) {
    if (dia >= 0 && dia < DIAS && ciudad >= 0 && ciudad < CIUDADES) {
        m[dia][ciudad] = temp;
    }
}

double Temperaturas::temperaturaPromCiudad(int ciudad) {
    double total = 0;
    for (int i = 0; i<DIAS; i++) {
        total += m[i][ciudad];
    }
    return total/DIAS;
}

int Temperaturas::diaMasCaliente() const {
    int dia = 0;
    double mejorPromedio = 0.0;
        for (int j = 0; j<CIUDADES; j++) {
            mejorPromedio += m[0][j];
        }
    mejorPromedio /= CIUDADES;
    for (int i = 1; i<DIAS; i++) {
        double promDia = 0.0;
        for (int j = 0; j<CIUDADES; j++) {
            promDia += m[i][j];
        }
        promDia /= CIUDADES;
        if (mejorPromedio < promDia) {
            mejorPromedio = promDia;
            dia = i;
        }
    }
    return dia;
}

int Temperaturas::ciudadMasFria() const {
    int ciudad = 0;
    double masFria = 0.0;
    for (int j = 0; j<DIAS; j++) {
        masFria += m[j][0];
    }
    masFria /= DIAS;
    for (int i = 1; i<CIUDADES; i++) {
        double promCiudad = 0.0;
        for (int j = 0; j<DIAS; j++) {
            promCiudad += m[j][i];
        }
        promCiudad /= DIAS;
        if (masFria > promCiudad) {
            ciudad = i;
            masFria = promCiudad;
        }
    }
    return ciudad;
}

void Temperaturas::limpiar() {
    for (int i = 0; i<DIAS; i++) {
        for (int j =0; j<CIUDADES; j++) {
            m[i][j] = 0;
        }
    }
}

string Temperaturas::toString() {
    stringstream ss;
    for (int i = 0; i<DIAS; i++) {
        for (int j = 0; j<CIUDADES; j++) {
            ss<<m[i][j]<<" ";
        }
        ss<<endl;
    }
    return ss.str();
}
