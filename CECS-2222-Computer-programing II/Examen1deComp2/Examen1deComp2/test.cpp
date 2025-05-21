#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

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

Libro::Libro(int paginas) {
    this->cantidadPaginas = paginas;
}

bool Libro::sonIguales(const Libro& otroLibro) const {
    return this->cantidadPaginas == otroLibro.cantidadPaginas;
}

void Libro::cambiarPaginas(int nuevasPaginas) {
    this->cantidadPaginas = nuevasPaginas;
}

int Libro::obtenerPaginas() const {
    return this->cantidadPaginas;
}

void Libro::mostrarInformacion() const {
    cout << "Libro con " << this->cantidadPaginas << " páginas." << endl;
}

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
    bool sonIguales(const CajaDeLibros&);

private:
    vector<Libro> libros;
};

CajaDeLibros::CajaDeLibros() {}

void CajaDeLibros::agregarLibro(const Libro& libro) {
    libros.push_back(libro);
}

void CajaDeLibros::mostrarContenido() {
    for (const Libro& libro : libros) {
        libro.mostrarInformacion();
    }
}

int CajaDeLibros::obtenerCantidadTotalDePaginas() {
    int totalPaginas = 0;
    for (const Libro& libro : libros) {
        totalPaginas += libro.obtenerPaginas();
    }
    return totalPaginas;
}

bool CajaDeLibros::sonIguales(const CajaDeLibros& otraCaja) {
    // Dos cajas son iguales si tienen la misma cantidad de libros y los libros son iguales en orden
    if (libros.size() != otraCaja.libros.size()) {
        return false;
    }

    for (size_t i = 0; i < libros.size(); i++) {
        if (!libros[i].sonIguales(otraCaja.libros[i])) {
            return false;
        }
    }

    return true;
}

int main() {
    // Crear algunos libros
    Libro libro1(200);
    Libro libro2(300);
    Libro libro3(150);

    // Crear una caja de libros
    CajaDeLibros caja1;
    CajaDeLibros caja2;

    // Agregar libros a las cajas
    caja1.agregarLibro(libro1);
    caja1.agregarLibro(libro2);
    caja2.agregarLibro(libro1);
    caja2.agregarLibro(libro3);

    // Mostrar el contenido de las cajas
    cout << "Contenido de la Caja 1:" << endl;
    caja1.mostrarContenido();

    cout << "Contenido de la Caja 2:" << endl;
    caja2.mostrarContenido();

    // Obtener la cantidad total de páginas en cada caja
    int totalPaginasCaja1 = caja1.obtenerCantidadTotalDePaginas();
    int totalPaginasCaja2 = caja2.obtenerCantidadTotalDePaginas();

    cout << "Total de páginas en la Caja 1: " << totalPaginasCaja1 << " páginas." << endl;
    cout << "Total de páginas en la Caja 2: " << totalPaginasCaja2 << " páginas." << endl;

    // Determinar si las cajas son iguales
    if (caja1.sonIguales(caja2)) {
        cout << "Las cajas son iguales." << endl;
    }
    else {
        cout << "Las cajas no son iguales." << endl;
    }

    return 0;
}
