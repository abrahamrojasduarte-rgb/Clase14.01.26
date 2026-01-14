//
// Created by Abraham on 1/14/2026.
//

#include "Puntuaciones.h"


Puntuaciones::Puntuaciones() {
    this -> limpiar();
}

void Puntuaciones::agregarPuntuacion(int estudiante, int examen, double puntuacion) {
    if (estudiante >= 0 && estudiante < ESTUDIANTES && examen >= 0 && examen < EXAMENES && m[estudiante][examen] == 0) {
        m[estudiante][examen] = puntuacion;
    }
}

double Puntuaciones::promedioEstudiante(int estudiante) {
    double puntuacion = 0.0;
    if (estudiante >= 0 && estudiante < ESTUDIANTES) {
        for (int i = 0; i<EXAMENES; i++) {
            puntuacion += m[estudiante][i];
        }
        puntuacion = puntuacion / EXAMENES;
    }
    return puntuacion;
}

double Puntuaciones::promedioExamen(int examen) {
    double puntuacion = 0;
    if (examen >= 0 && examen < EXAMENES) {
        for (int i = 0; i<EXAMENES; i++) {
            puntuacion += m[i][examen];
        }
        puntuacion = puntuacion / ESTUDIANTES;
    }
    return puntuacion;
}

int Puntuaciones::mejorEstudiante() {
    int mejor = m[0][0];
    for (int i = 0; i<ESTUDIANTES; i++) {

    }
}

string Puntuaciones::toString() {
    stringstream ss;
    for (int i = 0; i<ESTUDIANTES; i++) {
        for (int j = 0; j<EXAMENES; j++) {
            ss<<m[i][j]<<" ";
        }
        ss<<endl;
    }
    return ss.str();
}

void Puntuaciones::limpiar() {
    for (int i = 0; i<ESTUDIANTES; i++) {
        for (int j =0; j<EXAMENES; j++) {
            m[i][j] = 0;
        }
    }
}
