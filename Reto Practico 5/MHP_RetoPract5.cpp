#include <iostream>
#include <string>
using namespace std;

class Nodo {
public:
    string nombre;
    Nodo* siguiente;

    Nodo(string n) {
        nombre = n;
        siguiente = nullptr;
    }
};

class ListaEnlazada {
private:
    Nodo* cabeza;

public:
    ListaEnlazada() {
        cabeza = nullptr;
    }

    void registrarInvitado(string nombre) {
        Nodo* nuevoNodo = new Nodo(nombre);

        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
            return;
        }

        Nodo* temp = cabeza;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }

        temp->siguiente = nuevoNodo;
    }

    void mostrarInvitados() {
        if (cabeza == nullptr) {
            cout << "La lista de invitados esta vacia." << endl;
            return;
        }

        Nodo* temp = cabeza;
        int contador = 1;
        
        cout << "\n--- LISTA DE INVITADOS ---" << endl;
        while (temp != nullptr) {
            cout << contador << ". " << temp->nombre << endl;
            temp = temp->siguiente;
            contador++;
        }
        cout << "--------------------------\n" << endl;
    }
    void buscarInvitados(string nombre) {
        if (cabeza == nullptr) {
            cout << "La lista de invitados esta vacia." << endl;
            return;
        }

        Nodo* temp = cabeza;
        int contador = 1;
        bool encontrado = false;

        cout << "\n--- RESULTADOS DE BUSQUEDA ---" << endl;
        while (temp != nullptr) {
            if (temp->nombre.find(nombre) != string::npos) {
                cout << contador << ". " << temp->nombre << endl;
                encontrado = true;
            }
            temp = temp->siguiente;
            contador++;
        }

        if (!encontrado) {
            cout << "No se encontraron invitados con el nombre: " << nombre << endl;
        }
        cout << "-------------------------------\n" << endl;
    }
    void eliminarInvitado(string nombre) {
        if (cabeza == nullptr) {
            cout << "La lista de invitados esta vacia." << endl;
            return;
        }

        Nodo* temp = cabeza;
        Nodo* anterior = nullptr;

        while (temp != nullptr) {
            if (temp->nombre == nombre) {
                if (anterior == nullptr) {
                    cabeza = temp->siguiente;
                } else {
                    anterior->siguiente = temp->siguiente;
                }
                delete temp;
                cout << "Invitado eliminado con exito: " << nombre << endl;
                return;
            }
            anterior = temp;
            temp = temp->siguiente;
        }
        cout << "No se encontro el invitado con el nombre: " << nombre << endl;
    }
    void eliminarTodos() {
        Nodo* temp = cabeza;
        while (temp != nullptr) {
            Nodo* siguiente = temp->siguiente;
            delete temp;
            temp = siguiente;
        }
        cabeza = nullptr;
    }
};

int main() {
    ListaEnlazada fiesta;
    int op;
    string nombreInvitado;

    cout << "\nBienvenido al Sistema de Gestion de Eventos" << endl;

    do {
        cout << "\n1. Registrar nuevo invitado" << endl;
        cout << "2. Mostrar lista de invitados" << endl;
        cout << "3. Buscar invitados" << endl;
        cout << "4. Eliminar invitado" << endl;
        cout << "5. Eliminar todos los invitados" << endl;
        cout << "0. Salir" << endl;
        cout << "\nElige una opcion: ";
        cin >> op;

        switch (op) {
            case 1:
                cin.ignore(); 
                cout << "Ingresa el nombre y apellido del invitado: ";
                getline(cin, nombreInvitado);
                
                fiesta.registrarInvitado(nombreInvitado);
                cout << "¡Invitado registrado con exito!\n" << endl;
                break;
            case 2:
                fiesta.mostrarInvitados();
                break;
            case 3:
                cin.ignore();
                cout << "Ingresa el nombre del invitado a buscar: ";
                getline(cin, nombreInvitado);
                fiesta.buscarInvitados(nombreInvitado);
                break;
            case 4:
                cin.ignore();
                cout << "Ingresa el nombre del invitado a eliminar: ";
                getline(cin, nombreInvitado);
                fiesta.eliminarInvitado(nombreInvitado);
                break;
            case 5:
                fiesta.eliminarTodos();
                cout << "Todos los invitados han sido eliminados." << endl;
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, intenta de nuevo." << endl;
        }
    } while (op != 0);
    return 0;
}

