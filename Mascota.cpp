#include "Mascota.h"
#include<stdlib.h>
#include <iostream>

Mascota::Mascota() {
}

Mascota::Mascota(string _nombre, int _edad, int _hambre, int _vida) {
	this->Nombre = _nombre;
	this->Edad = _edad;
	this->Hambre = _hambre;
	this->Vida = _vida;
}

Mascota::~Mascota()
{
}

void Mascota::alimentar() {
	
		int comida = 5 + rand() % (16 - 5);
		int vida = 5 + rand() % (11 - 5);
		int hambreActual = this->Hambre;
		int vidaActual = this->Vida;
		int hambreNueva;
		int vidaNueva;
		//cout << "Vida ahorita: " << vidaActual<<endl;
		//cout << "Hambre ahorita: " << hambreActual<<endl;
		hambreNueva = hambreActual - comida;
		vidaNueva = vidaActual + vida;
		while ((hambreNueva < 0 || hambreNueva>100) && (vidaNueva < 0 || vidaNueva>100)) {
			comida = 5 + rand() % (16 - 5);
			vida = 5 + rand() % (11 - 5);
			hambreNueva = hambreActual - comida;
			vidaNueva = vidaActual - vida;
			//cout << "Vida nueva: " << vidaNueva<<endl;
			//cout << "Hambre nueva: " << hambreNueva<<endl;
		}
		//cout << "Vida nueva: " << vidaNueva<<endl;
		//cout << "Hambre nueva: " << hambreNueva<<endl;
		this->Hambre = hambreNueva;
		this->Vida = vidaNueva;

}

void Mascota::pasear(){
	int comida = 10 + rand() % (21 - 10);
	int vida = 5 + rand() % (16 - 5);
	int hambreActual = this->Hambre;
	int vidaActual = this->Vida;
	int hambreNueva;
	int vidaNueva;
	//cout << "Vida ahorita: " << vidaActual<<endl;
	//cout << "Hambre ahorita: " << hambreActual<<endl;
	hambreNueva = hambreActual + comida;
	vidaNueva = vidaActual - vida;
	while ((hambreNueva < 0 || hambreNueva>100) && (vidaNueva < 0 || vidaNueva>100)) {
		comida = 10 + rand() % (21 - 10);
		vida = 5 + rand() % (16 - 5);
		hambreNueva = hambreActual - comida;
		vidaNueva = vidaActual - vida;
		//cout << "Vida nueva: " << vidaNueva<<endl;
		//cout << "Hambre nueva: " << hambreNueva<<endl;
	}
	//cout << "Vida nueva: " << vidaNueva<<endl;
	//cout << "Hambre nueva: " << hambreNueva<<endl;
	this->Hambre = hambreNueva;
	this->Vida = vidaNueva;
}

void Mascota::mostrarEstado() {
	if (this->Vida>=30) {
		cout << "¡" << this->Nombre << " se encuentra en estado optimo!" << endl;
	}
	else if (this->Vida<30) {
		cout << "¡" << this->Nombre << " se siente muy mal!" << endl;
	}
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
