//
// Created by Abraham on 1/18/2026.
//

#include "Inventario.h"

Inventario::Inventario() {
 this->limpiar();
}

void Inventario::agregarCantidad(int producto, int almacen, int cantidad) {
    if (producto >= 0 && producto < PRODUCTOS && almacen >= 0 && almacen < PRODUCTOS) {
        m[almacen][producto] += cantidad;
    }
}

int Inventario::totalProducto(int producto) const {
    int total = 0;
    for (int i = 0; i < ALMACENES; ++i) {
        total += m[producto][i];
    }
    return total;
}

int Inventario::totalAlmacen(int almacen) const {
    int total = 0;
    for (int i = 0; i < PRODUCTOS; ++i) {
        total += m[i][almacen];
    }
    return total;
}

int Inventario::almacenConMasProductos() const {
    int total = 0;
    int indice = 0;

    for (int i = 0; i < PRODUCTOS; ++i) {
        total += m[i][0];
    }

    for (int j = 1; j < ALMACENES; ++j) {
        int otroTotal = 0;
        for (int i = 0; i < PRODUCTOS; ++i) {
            otroTotal += m[i][j];
        }

        if (otroTotal > total) {
            total = otroTotal;
            indice = j;
        }
    }

    return indice;
}

void Inventario::limpiar() {
    for (int i = 0; i < PRODUCTOS; ++i) {
        for (int j = 0; j < PRODUCTOS; ++j) {
            m[i][j]=0;
        }
    }
}

string Inventario::toString() const {
    stringstream ss;
    for (int i = 0; i < PRODUCTOS; ++i) {
        for (int j = 0; j < PRODUCTOS; ++j) {
            ss<<m[i][j];
        }
        ss<<endl;
    }
    return ss.str();
}
