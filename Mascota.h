#pragma once
#include <string>
using namespace std;
class Mascota {
	string Nombre;
	int Edad;
	int Hambre;
	int Vida;
public:
	Mascota();
	Mascota(string _nombre, int _edad, int _hambre, int _vida);
	void alimentar();
	void pasear();
	void mostrarEstado();
	void setNombre(string _nombre);
	string getNombre();
	void setEdad(int _edad);
	int getEdad();
	void setHambre(int _hambre);
	int getHambre();
	void setVida(int _vida);
	int getVida();
};

