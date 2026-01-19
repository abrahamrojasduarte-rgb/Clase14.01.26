//
// Created by Abraham on 1/18/2026.
//

#ifndef MAIN_CPP_INVENTARIO_H
#define MAIN_CPP_INVENTARIO_H
#include <sstream>

#include <string>
using namespace std;
class Inventario {
private:
    static const int PRODUCTOS = 6;
    static const int ALMACENES = 5;
    int m[PRODUCTOS][ALMACENES];

    bool indiceValido(int producto, int almacen) const;

public:
    Inventario();

    void agregarCantidad(int producto, int almacen, int cantidad);
    int totalProducto(int producto) const;
    int totalAlmacen(int almacen) const;
    int almacenConMasProductos() const;

    void limpiar();
    string toString() const;
};


#endif //MAIN_CPP_INVENTARIO_H