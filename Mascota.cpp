#include "Mascota.h"

Mascota::Mascota() {
}

Mascota::Mascota(string _nombre, int _edad, int _hambre, int _vida) {
	this->Nombre = _nombre;
	this->Edad = _edad;
	this->Hambre = _hambre;
	this->Vida = _vida;
}

void Mascota::alimentar()
{
}

void Mascota::pasear()
{
}

void Mascota::mostrarEstado()
{
}

void Mascota::setNombre(string _nombre)
{
}

string Mascota::getNombre()
{
	return string();
}

void Mascota::setEdad(int _edad)
{
}

int Mascota::getEdad()
{
	return 0;
}

void Mascota::setHambre(int _hambre)
{
}

int Mascota::getHambre()
{
	return 0;
}

void Mascota::setVida(int _vida)
{
}

int Mascota::getVida()
{
	return 0;
}
