#include <iostream>
#include "MatrizEnteros.h"
#include "MatrizOperaciones.h"
using namespace std;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    MatrizEnteros mat;
    cout << "=== PRUEBA 1: Matriz inicial (debe estar en 0) ===\n";
    cout << mat.toString() << endl;

    cout << "=== PRUEBA 2: Insertar valores válidos ===\n";
    mat.insertar(0, 0, 10);
    mat.insertar(0, 1, 20);
    mat.insertar(1, 1, 99);
    mat.insertar(2, 2, 7);
    cout << mat.toString() << endl;

    cout << "=== PRUEBA 3: Obtener valores válidos ===\n";
    cout << "mat(0,0) = " << mat.obtener(0, 0) << " (esperado 10)\n";
    cout << "mat(0,1) = " << mat.obtener(0, 1) << " (esperado 20)\n";
    cout << "mat(1,1) = " << mat.obtener(1, 1) << " (esperado 99)\n";
    cout << "mat(2,2) = " << mat.obtener(2, 2) << " (esperado 7)\n\n";

    cout << "=== PRUEBA 4: Insertar en índices inválidos (NO debe cambiar nada) ===\n";
    mat.insertar(-1, 0, 111);     // fila inválida
    mat.insertar(0, -1, 222);     // columna inválida
    mat.insertar(FIL, 0, 333);    // fila fuera de rango
    mat.insertar(0, COL, 444);    // columna fuera de rango
    cout << mat.toString() << endl;

    cout << "=== PRUEBA 5: Obtener en índices inválidos (debe devolver -1) ===\n";
    cout << "mat(-1,0) = " << mat.obtener(-1, 0) << " (esperado -1)\n";
    cout << "mat(0,-1) = " << mat.obtener(0, -1) << " (esperado -1)\n";
    cout << "mat(FIL,0) = " << mat.obtener(FIL, 0) << " (esperado -1)\n";
    cout << "mat(0,COL) = " << mat.obtener(0, COL) << " (esperado -1)\n\n";

    cout << "=== PRUEBA 6: Limpiar matriz (todo vuelve a 0) ===\n";
    mat.limpiar();
    cout << mat.toString() << endl;

    MatrizEnteros m;

    // Insertar valores en la matriz
    m.insertar(0, 0, 5);
    m.insertar(0, 1, 3);
    m.insertar(0, 2, 5);

    m.insertar(1, 0, 1);
    m.insertar(1, 1, 5);
    m.insertar(1, 2, 7);

    m.insertar(2, 0, 9);
    m.insertar(2, 1, 3);
    m.insertar(2, 2, 5);

    cout << "Matriz completa:" << endl;
    cout << m.toString() << endl;

    int valor = 5;

    // Probar buscar
    if (m.buscar(valor)) {
        cout << "El valor " << valor << " SI existe en la matriz." << endl;
    } else {
        cout << "El valor " << valor << " NO existe en la matriz." << endl;
    }

    // Probar contar apariciones
    cout << "El valor " << valor << " aparece "
<< m.contarApariciones(valor)
<< " veces en la matriz." << endl;

    // Probar buscar en fila
    int fila = 0;
    if (m.buscarEnFila(fila, valor)) {
        cout << "El valor " << valor << " SI esta en la fila " << fila << "." << endl;
    } else {
        cout << "El valor " << valor << " NO esta en la fila " << fila << "." << endl;
    }

    // Probar buscar en columna
    int columna = 2;
    if (m.buscarEnColumna(columna, valor)) {
        cout << "El valor " << valor << " SI esta en la columna " << columna << "." << endl;
    } else {
        cout << "El valor " << valor << " NO esta en la columna " << columna << "." << endl;
    }

    MatrizOperaciones mo;

    cout << "=== PRUEBA 1: Constructor (todo en 0) ===" << endl;
    cout << mo.toString() << endl;

    // Esperado: suma fila 0 = 0, suma col 0 = 0, promedio fila 0 = 0
    cout << "sumarFila(0) = " << mo.sumarFila(0) << " (esperado 0)" << endl;
    cout << "sumarColumna(0) = " << mo.sumarColumna(0) << " (esperado 0)" << endl;
    cout << "promedioFila(0) = " << mo.promedioFila(0) << " (esperado 0)" << endl;

    cout << "\n=== PRUEBA 2: llenarFila(1, 5) ===" << endl;
    mo.llenarFila(1, 5);
    cout << mo.toString() << endl;

    // Esperado: sumarFila(1) = 5 * COL
    cout << "sumarFila(1) = " << mo.sumarFila(1)
<< " (esperado " << (5 * COL) << ")" << endl;

    // Promedio esperado: 5
    double prom1 = mo.promedioFila(1);
    cout << "promedioFila(1) = " << prom1 << " (esperado 5)" << endl;

    cout << "\n=== PRUEBA 3: llenarColumna(2, 9) ===" << endl;
    mo.llenarColumna(2, 9);
    cout << mo.toString() << endl;

    // Esperado: sumarColumna(2) = 9 * FIL
    cout << "sumarColumna(2) = " << mo.sumarColumna(2)
<< " (esperado " << (9 * FIL) << ")" << endl;

    cout << "\n=== PRUEBA 4: Verificar efecto combinado (fila 1 y columna 2 cruzan) ===" << endl;
    cout << "Nota: La celda (1,2) queda con 9 por el ultimo llenado de columna." << endl;
    cout << "sumarFila(1) = " << mo.sumarFila(1) << " (esperado " << ( (5 * (COL - 1)) + 9 ) << ")" << endl;

    double prom2 = mo.promedioFila(1);
    cout << "promedioFila(1) = " << prom2 << " (esperado " << (( (5 * (COL - 1)) + 9 ) / (double)COL) << ")" << endl;

    cout << "\n=== PRUEBA 5: Casos invalidos (no deberia cambiar nada) ===" << endl;
    cout << "Intentando llenarFila(-1, 7) y llenarColumna(999, 4)..." << endl;

    // Guardamos valores de control antes
    int sumaFila0Antes = mo.sumarFila(0);
    int sumaCol0Antes = mo.sumarColumna(0);

    mo.llenarFila(-1, 7);
    mo.llenarColumna(999, 4);

    int sumaFila0Despues = mo.sumarFila(0);
    int sumaCol0Despues = mo.sumarColumna(0);

    cout << "sumarFila(0) antes=" << sumaFila0Antes << " despues=" << sumaFila0Despues << endl;
    cout << "sumarColumna(0) antes=" << sumaCol0Antes << " despues=" << sumaCol0Despues << endl;

    if (sumaFila0Antes == sumaFila0Despues && sumaCol0Antes == sumaCol0Despues) {
        cout << "OK: Operaciones invalidas no alteraron la matriz." << endl;
    } else {
        cout << "ERROR: Cambios detectados con indices invalidos." << endl;
    }

    cout << "\n=== FIN DE PRUEBAS ===" << endl;
    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}