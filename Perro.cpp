#include "Perro.h"

Perro::Perro()
{
}

Perro::Perro(string _nombre, int _edad, int _hambre, int _vida, int _lealtad) : Mascota(_nombre, _edad, _hambre, _vida) {
	this->lealtad = _lealtad;
}

void Perro::setLealtad(int _lealtad) {
	this->lealtad = _lealtad;
}

int Perro::getLealtad() {
	return lealtad;
}
