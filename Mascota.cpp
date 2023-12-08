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

void Mascota::setNombre(string _nombre) {
	this->Nombre = _nombre;
}

string Mascota::getNombre() {
	return this->Nombre;
}

void Mascota::setEdad(int _edad) {
	this->Edad = _edad;
}

int Mascota::getEdad() {
	return Edad;
}

void Mascota::setHambre(int _hambre) {
	this->Hambre = _hambre;
}

int Mascota::getHambre() {
	return Hambre;
}

void Mascota::setVida(int _vida) {
	this->Vida = _vida;
}

int Mascota::getVida() {
	return Vida;
}
