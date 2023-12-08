#include <iostream>
#include <locale>
using namespace std;

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
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 0:
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

