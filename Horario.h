//
// Created by ESCINF on 19/01/2026.
//

#ifndef MAIN_CPP_HORARIO_H
#define MAIN_CPP_HORARIO_H
#include <iostream>
#include <sstream>
using namespace std;

class Horario {
private:
    static const int DIAS = 7;
    static const int HORAS = 8;
    string m[DIAS][HORAS];
    public:
    Horario();
    void agregarClase(int dia, int hora, string nombreClase);
    int clasesPorDia(int dia);
    int diaMasOcupado();
    bool estaLibre(int dia, int hora);
    void limpiar();
    string toString();
};


#endif //MAIN_CPP_HORARIO_H