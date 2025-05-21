#pragma once
#include <iostream>
using namespace std;

class Bateria
{
private:
	int capacidad;

public:
	Bateria(int capacidadInicial);
	~Bateria();
	bool sonIguales(Bateria bateriaA, Bateria bateriaB);
	void cambiarCapacidad(int nuevaCapacidad);
	int obtenerCapacidad() const;


};

