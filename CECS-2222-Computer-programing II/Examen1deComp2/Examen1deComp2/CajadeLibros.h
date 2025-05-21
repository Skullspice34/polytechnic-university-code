#pragma once
#include <vector>
#include "Libro.h"

class CajaDeLibros {
public:
    CajaDeLibros();

    // Agregar un libro a la caja
    void agregarLibro(const Libro&);

    // Mostrar los libros en la caja
    void mostrarContenido();

    // Obtener la cantidad total de páginas en la caja
    int obtenerCantidadTotalDePaginas();

    // Determinar si dos cajas son iguales
    bool sonIguales(const CajaDeLibros& );

private:
    vector<Libro> libros;
};
