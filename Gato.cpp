#include "Gato.h"

Gato::Gato()
{
}

Gato::Gato(string _nombre, int _edad, int _hambre, int _vida, int _independencia) : Mascota(_nombre, _edad, _hambre, _vida) {
	this->independencia = _independencia;
}

void Gato::setIndependencia(int _independencia) {
	this->independencia = _independencia;
}

int Gato::getIndependencia() {
	return independencia;
}
