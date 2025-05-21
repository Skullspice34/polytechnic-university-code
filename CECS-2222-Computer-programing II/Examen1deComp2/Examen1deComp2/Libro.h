#pragma once
#include <iostream>
using namespace::std;

class Libro {
public:
    Libro(int);
    bool sonIguales(const Libro&) const; // Marcar como const
    void cambiarPaginas(int);
    int obtenerPaginas() const; // Marcar como const
    void mostrarInformacion() const; // Marcar como const

private:
    int cantidadPaginas;
};