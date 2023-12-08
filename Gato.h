#pragma once
#include "Mascota.h"
class Gato : public Mascota {
	int independencia;
public:
	Gato();
	Gato(string _nombre, int _edad, int _hambre, int _vida, int _independencia);
	void setIndependencia(int _independencia);
	int getIndependencia();
};

