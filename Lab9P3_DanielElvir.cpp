#include <iostream>
#include <locale>
#include<vector>
#include <fstream>
#include "Mascota.h"
#include "Perro.h"
#include "Gato.h"
#include "Pez.h"
using namespace std;

static vector<Mascota*> cuerposCelestiales;
static Mascota* perro;
static Mascota* gato;
static Mascota* pez;

vector<string> mystrtok(string str, char delim) {
    vector<string> tokens;
    string temp = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == delim) {
            tokens.push_back(temp);
            temp = "";
        }
        else
            temp += str[i];
    }
    tokens.push_back(temp);
    return tokens;
}

void cargarMascotas() {
    ifstream archivo;
    string texto;
    archivo.open("Mascotas.txt", ios::in);

    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    while (!archivo.eof()) {
        getline(archivo, texto);
        string Nombre;
        int Edad;
        int Hambre;
        int Vida;
        int atributoEspecial;
        vector<string> tokens = mystrtok(texto, ',');
        if (tokens[0]=="Perro") {
            Nombre = tokens[1];
            Edad = stoi(tokens[2]);
            Hambre = stoi(tokens[3]);
            Vida = stoi(tokens[4]);
            atributoEspecial = stoi(tokens[5]);
            perro = new Perro(Nombre, Edad, Hambre, Vida, atributoEspecial);
        } else if (tokens[0] == "Gato") {
            Nombre = tokens[1];
            Edad = stoi(tokens[2]);
            Hambre = stoi(tokens[3]);
            Vida = stoi(tokens[4]);
            atributoEspecial = stoi(tokens[5]);
            gato = new Gato(Nombre, Edad, Hambre, Vida, atributoEspecial);
        } else if (tokens[0] == "Pez") {
            Nombre = tokens[1];
            Edad = stoi(tokens[2]);
            Hambre = stoi(tokens[3]);
            Vida = stoi(tokens[4]);
            atributoEspecial = stoi(tokens[5]);
            pez = new Pez(Nombre, Edad, Hambre, Vida, atributoEspecial);
        }
    }
}

void crearPerro() {

}

void crearGto() {

}

void crearPez() {

}

void crearGato() {

}

void crearMascotas() {
    int mascota;
    cout << "Que mascota desea crear?" << endl;
    cout << "1. Perro" << endl;
    cout << "2. Gato" << endl;
    cout << "3. Pez" << endl;
    cin >> mascota;
    switch (mascota) {
    case 1:        
        crearPerro();
        break;
    case 2:
        crearGato();
        break;
    case 3:
        crearPez();
        break;

    default:
        break;
    }

}

void menu() {
    int opcion;
    bool seguir = true;
    do {
        cout << "----- MENU -----" << endl;
        cout << "1. Cargar Mascotas" << endl;
        cout << "2. Listar Mascotas" << endl;
        cout << "3. Crear Mascotas" << endl;
        cout << "4. Alimentar Mascotas" << endl;
        cout << "5. Pasear Mascotas" << endl;
        cout << "6. Ver Estado Mascota" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cargarMascotas();
            break;
        case 2:
            break;
        case 3:
            crearMascotas();
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 0:
            cout << "Gracias por usar el Programa" << endl;
            cout << "Saliendo....";
            cout << endl;
            seguir = false;
            break;
        default:
            cout << "ERROR" << endl;
            cout << "INGRESE UNA OPCIÓN VALIDA" << endl;
            break;
        }
    } while (seguir);
    
}


int main() {
    setlocale(LC_ALL, "spanish");
    menu();
}

