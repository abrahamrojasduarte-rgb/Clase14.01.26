//
// Created by Abraham on 1/18/2026.
//

#ifndef MAIN_CPP_TEMPERATURAS_H
#define MAIN_CPP_TEMPERATURAS_H
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
const int DIAS = 7;
const int CIUDADES = 4;


class Temperaturas {
    private:
    double m[DIAS][CIUDADES];
    public:
    Temperaturas();
    void registrarTemperatura(int dia, int ciudad, double temp);
    double temperaturaPromCiudad(int ciudad);
    int diaMasCaliente()const;
    int ciudadMasFria()const;
    void limpiar();
    string toString();
};


#endif //MAIN_CPP_TEMPERATURAS_H