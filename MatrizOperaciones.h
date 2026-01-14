//
// Created by Abraham on 1/14/2026.
//

#ifndef CLASE14_01_26_MATRIZOPERACIONES_H
#define CLASE14_01_26_MATRIZOPERACIONES_H
#include <iostream>
using namespace std;

class MatrizOperaciones
{
private:
    static const int FIL=5;
    static const int COL=5;
    int m[FIL][COL];

public:
    MatrizOperaciones();
    void llenarFila(int fila, int valor);
    void llenarColumna(int columna, int valor);
    int sumarFila(int fila);
    int sumarColumna(int columna);
    double promedioFila(int fila);
    string toString();
    void limpiar();
};


#endif //CLASE14_01_26_MATRIZOPERACIONES_H