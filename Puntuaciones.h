//
// Created by Abraham on 1/14/2026.
//

#ifndef CLASE14_01_26_PUNTUACIONES_H
#define CLASE14_01_26_PUNTUACIONES_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

const int ESTUDIANTES = 5;
const int EXAMENES = 3;

    class Puntuaciones {
    private:
        double m[ESTUDIANTES][EXAMENES];

    public:
        Puntuaciones();
        void agregarPuntuacion(int estudiante, int examen, double puntuacion);
        double promedioEstudiante(int estudiante);
        double promedioExamen(int examen);
        int mejorEstudiante();
        string toString();
        void limpiar();
    };

#endif //CLASE14_01_26_PUNTUACIONES_H