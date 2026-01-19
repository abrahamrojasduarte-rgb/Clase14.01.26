//
// Created by ESCINF on 19/01/2026.
//

#ifndef MAIN_CPP_SALACINE_H
#define MAIN_CPP_SALACINE_H
#include <sstream>
using namespace std;

class SalaCine {
private:
    static const int FILAS = 10;
    static const int COLUMNAS = 15;
    int m[FILAS][COLUMNAS];

public:
    SalaCine();
    void reservarAsiento(int fila, int col);
    int asientosDisponibles() const;
    bool filaCompleta(int fila) const;
    int mejorFila() const;
    void limpiar();
    string toString();
};


#endif //MAIN_CPP_SALACINE_H