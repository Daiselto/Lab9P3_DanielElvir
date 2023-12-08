#pragma once
#include "Mascota.h"
class Perro : public Mascota{
	int lealtad;
public:
	Perro();
	Perro(string _nombre, int _edad, int _hambre, int _vida, int _lealtad);
	void setLealtad(int _lealtad);
	int getLealtad();
};

