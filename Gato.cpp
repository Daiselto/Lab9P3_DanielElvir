#include "Gato.h"

Gato::Gato()
{
}

Gato::Gato(string _nombre, int _edad, int _hambre, int _vida, int _independencia) : Mascota(_nombre, _edad, _hambre, _vida) {
}

void Gato::setIndependencia(int _independencia)
{
}

int Gato::getIndependencia()
{
	return 0;
}
