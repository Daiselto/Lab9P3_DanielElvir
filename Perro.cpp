#include "Perro.h"

Perro::Perro()
{
}

Perro::Perro(string _nombre, int _edad, int _hambre, int _vida, int _lealtad) : Mascota(_nombre, _edad, _hambre, _vida) {
}

void Perro::setLealtad(int _lealtad)
{
}

int Perro::getLealtad()
{
	return 0;
}
