#include "CajaDeLibros.h"

CajaDeLibros::CajaDeLibros() {}

void CajaDeLibros::agregarLibro(const Libro& libro) {
    this->libros.push_back(libro);
}

void CajaDeLibros::mostrarContenido() {
    for (const Libro& libro : this->libros) {
        libro.mostrarInformacion();
    }
}

int CajaDeLibros::obtenerCantidadTotalDePaginas() {
    int totalPaginas = 0;
    for (const Libro& libro : this->libros) {
        totalPaginas += libro.obtenerPaginas();
    }
    return totalPaginas;
}

bool CajaDeLibros::sonIguales(const CajaDeLibros& otraCaja) {
    // Dos cajas son iguales si tienen la misma cantidad de libros y los libros son iguales en orden
    if (this->libros.size() != otraCaja.libros.size()) {
        return false;
    }

    for (size_t i = 0; i < this->libros.size(); i++) {
        if (!this->libros[i].sonIguales(otraCaja.libros[i])) {
            return false;
        }
    }

    return true;
}
