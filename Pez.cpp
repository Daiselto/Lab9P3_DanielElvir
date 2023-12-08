#include "Pez.h"

Pez::Pez()
{
}

Pez::Pez(string _nombre, int _edad, int _hambre, int _vida, int _nivelColorido) : Mascota(_nombre, _edad, _hambre, _vida){
	this->NivelColorido = _nivelColorido;
}

void Pez::setNivelColorido(int _nivelColorido)
{
}

int Pez::getNivelColorido()
{
	return 0;
}
