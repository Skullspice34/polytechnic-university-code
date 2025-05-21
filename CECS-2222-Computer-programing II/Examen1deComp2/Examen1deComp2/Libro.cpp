#include "Libro.h"

Libro::Libro(int paginas)
{
	this->cantidadPaginas = paginas;
}

bool Libro::sonIguales(const Libro& otroLibro) const {
    return this->cantidadPaginas == otroLibro.cantidadPaginas;
}

void Libro::cambiarPaginas(int nuevasPaginas){
    this->cantidadPaginas = nuevasPaginas;
}

int Libro::obtenerPaginas() const {
    return this->cantidadPaginas;
}

void Libro::mostrarInformacion() const {
    cout << "Libro con " << this->cantidadPaginas << " páginas." << endl;
}


