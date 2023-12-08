#include <iostream>
#include <locale>
#include<vector>
#include <fstream>
#include "Mascota.h"
#include "Perro.h"
#include "Gato.h"
#include "Pez.h"
using namespace std;

static vector<Mascota*> mascotas;
static Mascota* perro;
static Mascota* gato;
static Mascota* pez;
static Mascota* nPerro;
static Mascota* nGato;
static Mascota* nPez;

void listarGeneral() {
    int cont = 0;
    cout << "Mascotas:" << endl;
    for (Mascota* wows : mascotas) {
        Perro* tempPerro = dynamic_cast<Perro*>(wows);
        Gato* tempGato = dynamic_cast<Gato*>(wows);
        Pez* tempPez = dynamic_cast<Pez*>(wows);
        if (tempPerro != nullptr) {
            cout << ++cont << "- "<< tempPerro->getNombre() << endl;            
        }
        else if (tempGato != nullptr) {
            cout << ++cont << "- " << tempGato->getNombre() << endl;
        }
        else if (tempPez != nullptr) {
            cout << ++cont << "- " << tempPez->getNombre() << endl;
        }

    }
}

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
    ifstream archivo("Mascotas.txt", ios::in);
    string texto;

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
            mascotas.push_back(perro);
        } else if (tokens[0] == "Gato") {
            Nombre = tokens[1];
            Edad = stoi(tokens[2]);
            Hambre = stoi(tokens[3]);
            Vida = stoi(tokens[4]);
            atributoEspecial = stoi(tokens[5]);
            gato = new Gato(Nombre, Edad, Hambre, Vida, atributoEspecial);
            mascotas.push_back(gato);
        } else if (tokens[0] == "Pez") {
            Nombre = tokens[1];
            Edad = stoi(tokens[2]);
            Hambre = stoi(tokens[3]);
            Vida = stoi(tokens[4]);
            atributoEspecial = stoi(tokens[5]);
            pez = new Pez(Nombre, Edad, Hambre, Vida, atributoEspecial);
            mascotas.push_back(pez);
        }
        
    }
    cout << "Mascotas cargadas exitosamente" << endl;
}

void listarMascotas() {
    if (mascotas.size() > 0) {
        cout << "Mascotas existentes" << endl;
        cout << endl;
        int cont = 0;
        for (Mascota* wows : mascotas) {
            Perro* tempPerro = dynamic_cast<Perro*>(wows);
            Gato* tempGato = dynamic_cast<Gato*>(wows);
            Pez* tempPez = dynamic_cast<Pez*>(wows);
            if (tempPerro != nullptr) {
                cout << "Perro" << endl;
                cout << "Nombre: " << tempPerro->getNombre() << endl;
                cout << "Edad: " << tempPerro->getEdad() << endl;
                cout << "Hambre: " << tempPerro->getHambre() << endl;
                cout << "Vida: " << tempPerro->getVida() << endl;
                cout << "Lealtad: " << tempPerro->getLealtad() << endl;
                cout << endl;
            } else if (tempGato != nullptr) {
                cout << "Gato" << endl;
                cout << "Nombre: " << tempGato->getNombre() << endl;
                cout << "Edad: " << tempGato->getEdad() << endl;
                cout << "Hambre: " << tempGato->getHambre() << endl;
                cout << "Vida: " << tempGato->getVida() << endl;
                cout << "Independencia: " << tempGato->getIndependencia() << endl;
                cout << endl;
            } else if (tempPez != nullptr) {
                cout << "Pez" << endl;
                cout << "Nombre: " << tempPez->getNombre() << endl;
                cout << "Edad: " << tempPez->getEdad() << endl;
                cout << "Hambre: " << tempPez->getHambre() << endl;
                cout << "Vida: " << tempPez->getVida() << endl;
                cout << "Colorido: " << tempPez->getNivelColorido() << endl;
                cout << endl;
            }

        }
    }
    else {
        cout << "Tiene que cargar las mascotas primero" << endl;
    }
}

void escribirEnArchivo(Mascota* temp) {
    ofstream archivo("Mascotas.txt", ios::app);
    Perro* tempPerro = dynamic_cast<Perro*>(temp);
    Gato* tempGato = dynamic_cast<Gato*>(temp);
    Pez* tempPez = dynamic_cast<Pez*>(temp);
    if (mascotas[8]) {
        cout << endl;
    }
    if (tempPerro != nullptr) {
        archivo << "Perro," << tempPerro->getNombre() << "," << tempPerro->getEdad() << "," << tempPerro->getHambre() << "," << tempPerro->getVida() << "," << tempPerro->getLealtad() << endl;
    }
    if (tempGato != nullptr) {
        archivo << "Gato," << tempGato->getNombre() << "," << tempGato->getEdad() << "," << tempGato->getHambre() << "," << tempGato->getVida() <<","<< tempGato->getIndependencia() << endl;
    }
    if (tempPez != nullptr) {
        archivo << "Pez," << tempPez->getNombre() << "," << tempPez->getEdad() << "," << tempPez->getHambre() << "," << tempPez->getVida() <<","<< tempPez->getNivelColorido() << endl;
    }
}

void crearPerro() {
    string Nombre;
    int Edad;
    int Hambre;
    int Vida;
    int Lealtad;
    cout << "Bienvenido a la opción de crear un Perro" << endl;
    cout << "Ingrese el nombre del Perro: ";
    cin >> Nombre;
    cout << "Ingrese la Edad del perro (Tiene que ser un valor entre 0 y 20): ";
    cin >> Edad;
    while (Edad<0||Edad>20){
        cout << "Error de input" << endl;
        cout << "Ingrese la Edad del perro (Tiene que ser un valor entre 0 y 20): ";
        cin >> Edad;
    }
    cout << "Ingrese el hambre del perro (Tiene que ser un valor entre 0 y 100): ";
    cin >> Hambre;
    while (Hambre < 0 || Hambre>100) {
        cout << "Error de input" << endl;
        cout << "Ingrese el hambre del perro (Tiene que ser un valor entre 0 y 100): ";
        cin >> Hambre;
    }
    cout << "Ingrese los puntos de vida del perro (Tiene que ser un valor entre 0 y 100): ";
    cin >> Vida;
    while (Vida < 0 || Vida>100) {
        cout << "Error de input" << endl;
        cout << "Ingrese los puntos de vida del perro (Tiene que ser un valor entre 0 y 100): ";
        cin >> Vida;
    }
    cout << "Ingrese la lealtad del perro (Tiene que ser un valor entre 0 y 100): ";
    cin >> Lealtad;
    while (Lealtad < 0 || Lealtad>100) {
        cout << "Error de input" << endl;
        cout << "Ingrese la lealtad del perro (Tiene que ser un valor entre 0 y 100): ";
        cin >> Lealtad;
    }
    nPerro = new Perro(Nombre, Edad, Hambre, Vida, Lealtad);
    mascotas.push_back(nPerro);
    escribirEnArchivo(nPerro);
}

void crearPez() {
    string Nombre;
    int Edad;
    int Hambre;
    int Vida;
    int NivelColorido;
    cout << "Bienvenido a la opción de crear un Pez" << endl;
    cout << "Ingrese el nombre del Perro: ";
    cin >> Nombre;
    cout << "Ingrese la Edad del pez (Tiene que ser un valor entre 0 y 20): ";
    cin >> Edad;
    while (Edad < 0 || Edad>20) {
        cout << "Error de input" << endl;
        cout << "Ingrese la Edad del pez (Tiene que ser un valor entre 0 y 20): ";
        cin >> Edad;
    }
    cout << "Ingrese el hambre del pez (Tiene que ser un valor entre 0 y 100): ";
    cin >> Hambre;
    while (Hambre < 0 || Hambre>100) {
        cout << "Error de input" << endl;
        cout << "Ingrese el hambre del pez (Tiene que ser un valor entre 0 y 100): ";
        cin >> Hambre;
    }
    cout << "Ingrese los puntos de vida del pez (Tiene que ser un valor entre 0 y 100): ";
    cin >> Vida;
    while (Vida < 0 || Vida>100) {
        cout << "Error de input" << endl;
        cout << "Ingrese los puntos de vida del pez (Tiene que ser un valor entre 0 y 100): ";
        cin >> Vida;
    }
    cout << "Ingrese el Nivel Colorido del pez (Tiene que ser un valor entre 0 y 100): ";
    cin >> NivelColorido;
    while (NivelColorido < 0 || NivelColorido>100) {
        cout << "Error de input" << endl;
        cout << "Ingrese el Nivel Colorido del pez (Tiene que ser un valor entre 0 y 100): ";
        cin >> NivelColorido;
    }
    nPez = new Pez(Nombre, Edad, Hambre, Vida, NivelColorido);
    mascotas.push_back(nPez);
    escribirEnArchivo(nPez);
}

void crearGato() {
    string Nombre;
    int Edad;
    int Hambre;
    int Vida;
    int Independencia;
    cout << "Bienvenido a la opción de crear un Perro" << endl;
    cout << "Ingrese el nombre del Perro: ";
    cin >> Nombre;
    cout << "Ingrese la Edad del perro (Tiene que ser un valor entre 0 y 20): ";
    cin >> Edad;
    while (Edad < 0 || Edad>20) {
        cout << "Error de input" << endl;
        cout << "Ingrese la Edad del perro (Tiene que ser un valor entre 0 y 20): ";
        cin >> Edad;
    }
    cout << "Ingrese el hambre del perro (Tiene que ser un valor entre 0 y 100): ";
    cin >> Hambre;
    while (Hambre < 0 || Hambre>100) {
        cout << "Error de input" << endl;
        cout << "Ingrese el hambre del perro (Tiene que ser un valor entre 0 y 100): ";
        cin >> Hambre;
    }
    cout << "Ingrese los puntos de vida del perro (Tiene que ser un valor entre 0 y 100): ";
    cin >> Vida;
    while (Vida < 0 || Vida>100) {
        cout << "Error de input" << endl;
        cout << "Ingrese los puntos de vida del perro (Tiene que ser un valor entre 0 y 100): ";
        cin >> Vida;
    }
    cout << "Ingrese la independencia del gato (Tiene que ser un valor entre 0 y 100): ";
    cin >> Independencia;
    while (Independencia < 0 || Independencia>100) {
        cout << "Error de input" << endl;
        cout << "Ingrese la independencia del gato (Tiene que ser un valor entre 0 y 100): ";
        cin >> Independencia;
    }
    nGato = new Gato(Nombre, Edad, Hambre, Vida, Independencia);
    mascotas.push_back(nGato);
    escribirEnArchivo(nGato);
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
        cout << "No ingresó una opción valida" << endl;
        cout << "Regresando...." << endl;
        cout << endl;
        break;
    }

}

void alimentarMascotas() {
    if (mascotas.size() > 0) {
        int indice;
        listarGeneral();
        cout << "Selecciona mascota a alimentar: ";
        cin >> indice;
        if (indice>=1&&indice<mascotas.size()) {
            cout << "Atributos antes de alimentar" << endl;
            Mascota* wows = mascotas[indice - 1];
            Perro* tempPerro = dynamic_cast<Perro*>(wows);
            Gato* tempGato = dynamic_cast<Gato*>(wows);
            Pez* tempPez = dynamic_cast<Pez*>(wows);
            if (tempPerro != nullptr) {
                cout << "Perro" << endl;
                cout << "Nombre: " << tempPerro->getNombre() << endl;
                cout << "Edad: " << tempPerro->getEdad() << endl;
                cout << "Hambre: " << tempPerro->getHambre() << endl;
                cout << "Vida: " << tempPerro->getVida() << endl;
                cout << "Lealtad: " << tempPerro->getLealtad() << endl;
                cout << endl;
            }
            else if (tempGato != nullptr) {
                cout << "Gato" << endl;
                cout << "Nombre: " << tempGato->getNombre() << endl;
                cout << "Edad: " << tempGato->getEdad() << endl;
                cout << "Hambre: " << tempGato->getHambre() << endl;
                cout << "Vida: " << tempGato->getVida() << endl;
                cout << "Independencia: " << tempGato->getIndependencia() << endl;
                cout << endl;
            }
            else if (tempPez != nullptr) {
                cout << "Pez" << endl;
                cout << "Nombre: " << tempPez->getNombre() << endl;
                cout << "Edad: " << tempPez->getEdad() << endl;
                cout << "Hambre: " << tempPez->getHambre() << endl;
                cout << "Vida: " << tempPez->getVida() << endl;
                cout << "Colorido: " << tempPez->getNivelColorido() << endl;
                cout << endl;
            }
            cout << "Atributos despues de alimentar" << endl;
            wows->alimentar();
            tempPerro = dynamic_cast<Perro*>(wows);
            tempGato = dynamic_cast<Gato*>(wows);
            tempPez = dynamic_cast<Pez*>(wows);
            if (tempPerro != nullptr) {
                cout << "Perro" << endl;
                cout << "Nombre: " << tempPerro->getNombre() << endl;
                cout << "Edad: " << tempPerro->getEdad() << endl;
                cout << "Hambre: " << tempPerro->getHambre() << endl;
                cout << "Vida: " << tempPerro->getVida() << endl;
                cout << "Lealtad: " << tempPerro->getLealtad() << endl;
                cout << endl;
            }
            else if (tempGato != nullptr) {
                cout << "Gato" << endl;
                cout << "Nombre: " << tempGato->getNombre() << endl;
                cout << "Edad: " << tempGato->getEdad() << endl;
                cout << "Hambre: " << tempGato->getHambre() << endl;
                cout << "Vida: " << tempGato->getVida() << endl;
                cout << "Independencia: " << tempGato->getIndependencia() << endl;
                cout << endl;
            }
            else if (tempPez != nullptr) {
                cout << "Pez" << endl;
                cout << "Nombre: " << tempPez->getNombre() << endl;
                cout << "Edad: " << tempPez->getEdad() << endl;
                cout << "Hambre: " << tempPez->getHambre() << endl;
                cout << "Vida: " << tempPez->getVida() << endl;
                cout << "Colorido: " << tempPez->getNivelColorido() << endl;
                cout << endl;
            }
            delete tempPerro;
            delete tempGato;
            delete tempPez;
        }
        else {
            cout << "Escogió una mascota no existente" << endl;
            cout << "Regresando" << endl;
        }
    }
    else {
        cout << "Debe agregar mascotas para ingresar a esta opcion" << endl;
    }
}

void pasearMascotas() {
    if (mascotas.size() > 0) {
        int indice;
        listarGeneral();
        cout << "Selecciona mascota a pasear: ";
        cin >> indice;
        if (indice >= 1 && indice < mascotas.size()) {
            cout << "Atributos antes de pasear" << endl;
            Mascota* wows = mascotas[indice - 1];
            Perro* tempPerro = dynamic_cast<Perro*>(wows);
            Gato* tempGato = dynamic_cast<Gato*>(wows);
            Pez* tempPez = dynamic_cast<Pez*>(wows);
            if (tempPerro != nullptr) {
                cout << "Perro" << endl;
                cout << "Nombre: " << tempPerro->getNombre() << endl;
                cout << "Edad: " << tempPerro->getEdad() << endl;
                cout << "Hambre: " << tempPerro->getHambre() << endl;
                cout << "Vida: " << tempPerro->getVida() << endl;
                cout << "Lealtad: " << tempPerro->getLealtad() << endl;
                cout << endl;
            }
            else if (tempGato != nullptr) {
                cout << "Gato" << endl;
                cout << "Nombre: " << tempGato->getNombre() << endl;
                cout << "Edad: " << tempGato->getEdad() << endl;
                cout << "Hambre: " << tempGato->getHambre() << endl;
                cout << "Vida: " << tempGato->getVida() << endl;
                cout << "Independencia: " << tempGato->getIndependencia() << endl;
                cout << endl;
            }
            else if (tempPez != nullptr) {
                cout << "Pez" << endl;
                cout << "Nombre: " << tempPez->getNombre() << endl;
                cout << "Edad: " << tempPez->getEdad() << endl;
                cout << "Hambre: " << tempPez->getHambre() << endl;
                cout << "Vida: " << tempPez->getVida() << endl;
                cout << "Colorido: " << tempPez->getNivelColorido() << endl;
                cout << endl;
            }
            cout << "Atributos despues de pasear" << endl;
            wows->pasear();
            tempPerro = dynamic_cast<Perro*>(wows);
            tempGato = dynamic_cast<Gato*>(wows);
            tempPez = dynamic_cast<Pez*>(wows);
            if (tempPerro != nullptr) {
                cout << "Perro" << endl;
                cout << "Nombre: " << tempPerro->getNombre() << endl;
                cout << "Edad: " << tempPerro->getEdad() << endl;
                cout << "Hambre: " << tempPerro->getHambre() << endl;
                cout << "Vida: " << tempPerro->getVida() << endl;
                cout << "Lealtad: " << tempPerro->getLealtad() << endl;
                cout << endl;
            }
            else if (tempGato != nullptr) {
                cout << "Gato" << endl;
                cout << "Nombre: " << tempGato->getNombre() << endl;
                cout << "Edad: " << tempGato->getEdad() << endl;
                cout << "Hambre: " << tempGato->getHambre() << endl;
                cout << "Vida: " << tempGato->getVida() << endl;
                cout << "Independencia: " << tempGato->getIndependencia() << endl;
                cout << endl;
            }
            else if (tempPez != nullptr) {
                cout << "Pez" << endl;
                cout << "Nombre: " << tempPez->getNombre() << endl;
                cout << "Edad: " << tempPez->getEdad() << endl;
                cout << "Hambre: " << tempPez->getHambre() << endl;
                cout << "Vida: " << tempPez->getVida() << endl;
                cout << "Colorido: " << tempPez->getNivelColorido() << endl;
                cout << endl;
            }
            delete tempPerro;
            delete tempGato;
            delete tempPez;
        }
        else {
            cout << "Escogió una mascota no existente" << endl;
            cout << "Regresando" << endl;
        }
    }
    else {
        cout << "Debe agregar mascotas para ingresar a esta opcion" << endl;
    }
}

void verEstadoMascota() {
    if (mascotas.size() > 0) {
        int indice;
        listarGeneral();
        cout << "Selecciona mascota a revisar: ";
        cin >> indice;
        if (indice >= 1 && indice <= mascotas.size()) {
            Mascota* wows = mascotas[indice - 1];
            Perro* tempPerro = dynamic_cast<Perro*>(wows);
            Gato* tempGato = dynamic_cast<Gato*>(wows);
            Pez* tempPez = dynamic_cast<Pez*>(wows);
            if (tempPerro != nullptr) {
                cout << "Perro" << endl;
                cout << "Nombre: " << tempPerro->getNombre() << endl;
                cout << "Edad: " << tempPerro->getEdad() << endl;
                cout << "Hambre: " << tempPerro->getHambre() << endl;
                cout << "Vida: " << tempPerro->getVida() << endl;
                cout << "Lealtad: " << tempPerro->getLealtad() << endl;
                tempPerro->mostrarEstado();
                cout << endl;
            }
            else if (tempGato != nullptr) {
                cout << "Gato" << endl;
                cout << "Nombre: " << tempGato->getNombre() << endl;
                cout << "Edad: " << tempGato->getEdad() << endl;
                cout << "Hambre: " << tempGato->getHambre() << endl;
                cout << "Vida: " << tempGato->getVida() << endl;
                cout << "Independencia: " << tempGato->getIndependencia() << endl;
                tempGato->mostrarEstado();
                cout << endl;
            }
            else if (tempPez != nullptr) {
                cout << "Pez" << endl;
                cout << "Nombre: " << tempPez->getNombre() << endl;
                cout << "Edad: " << tempPez->getEdad() << endl;
                cout << "Hambre: " << tempPez->getHambre() << endl;
                cout << "Vida: " << tempPez->getVida() << endl;
                cout << "Colorido: " << tempPez->getNivelColorido() << endl;
                tempPez->mostrarEstado();
                cout << endl;
            }
            delete tempPerro;
            delete tempGato;
            delete tempPez;
        }
    }
    else {
        cout << "Debe agregar mascotas para ingresar a esta opcion" << endl;
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
            listarMascotas();
            break;
        case 3:
            crearMascotas();
            break;
        case 4:
            alimentarMascotas();
            break;
        case 5:
            pasearMascotas();
            break;
        case 6:
            verEstadoMascota();
            break;
        case 0:
            cout << "Gracias por usar el Programa" << endl;
            cout << "Saliendo....";
            cout << endl;
            for (int i = 0; i < mascotas.size(); i++) {
                delete mascotas[i];
            }
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
    delete perro;
    delete gato;
    delete pez;
    delete nPerro;
    delete nPez;
    delete nGato;
    
}

