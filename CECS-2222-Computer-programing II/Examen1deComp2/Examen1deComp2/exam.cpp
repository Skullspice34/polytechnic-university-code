#include "CajaDeLibros.h"

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
