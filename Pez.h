#pragma once
#include "Mascota.h"
class Pez : public Mascota {
	int NivelColorido;
public:
	Pez();
	Pez(string _nombre, int _edad, int _hambre, int _vida, int _nivelColorido);
	void setNivelColorido(int _nivelColorido);
	int getNivelColorido();
};

