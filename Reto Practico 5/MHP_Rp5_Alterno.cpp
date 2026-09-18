#include <iostream>
#include <string>
#include <variant>
using namespace std;

template <typename T>
class Nodo {
public:
    T dato;
    Nodo* siguiente;

    Nodo(T valor) {
        dato = valor;
        siguiente = nullptr;
    }
};

template <typename T>
class ListaEnlazada {
private:
    Nodo<T>* cabeza;

public:
    ListaEnlazada() {
        cabeza = nullptr;
    }

    void registrarInvitado(T dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>(dato);

        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
            return;
        }

        Nodo<T>* temp = cabeza;
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

        Nodo<T>* temp = cabeza;
        int contador = 1;
        
        cout << "\n--- LISTA DE INVITADOS ---" << endl;
        while (temp != nullptr) {
            cout << contador << ". " << temp->dato << endl;
            temp = temp->siguiente;
            contador++;
        }
        cout << "--------------------------\n" << endl;
    }
    void buscarInvitados(T dato) {
        if (cabeza == nullptr) {
            cout << "La lista de invitados esta vacia." << endl;
            return;
        }

        Nodo<T>* temp = cabeza;
        int contador = 1;
        bool encontrado = false;

        cout << "\n--- RESULTADOS DE BUSQUEDA ---" << endl;
        while (temp != nullptr) {
            if (temp->dato == dato) {
                cout << contador << ". " << temp->dato << endl;
                encontrado = true;
            }
            temp = temp->siguiente;
            contador++;
        }

        if (!encontrado) {
            cout << "No se encontraron invitados con el dato: " << dato << endl;
        }
        cout << "-------------------------------\n" << endl;
    }
    void eliminarInvitado(T dato) {
        if (cabeza == nullptr) {
            cout << "La lista de invitados esta vacia." << endl;
            return;
        }

        Nodo<T>* temp = cabeza;
        Nodo<T>* anterior = nullptr;

        while (temp != nullptr) {
            if (temp->dato == dato) {
                if (anterior == nullptr) {
                    cabeza = temp->siguiente;
                } else {
                    anterior->siguiente = temp->siguiente;
                }
                delete temp;
                cout << "Invitado eliminado con exito: " << dato << endl;
                return;
            }
            anterior = temp;
            temp = temp->siguiente;
        }
        cout << "No se encontro el invitado con el dato: " << dato << endl;
    }
    void eliminarTodos() {
        Nodo<T>* temp = cabeza;
        while (temp != nullptr) {
            Nodo<T>* siguiente = temp->siguiente;
            delete temp;
            temp = siguiente;
        }
        cabeza = nullptr;
    }
};

int main() {
    ListaEnlazada<string> fiesta;
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

/*class Nod {
    public:
        variant<int, string> dat;
        Nod* sig;

        Nod(variant<int, string> val) {
            dat = val;
            sig = nullptr;
        }
};

class ListEnlazad {
    private:
        Nod* cab;

    public:
        ListEnlazad() {
            cab = nullptr;
        }

        void insert(variant<int, string> val) {
            Nod* nuevoNod = new Nod(val);
            Nod* temp = cab;
            while (temp->sig != nullptr) {
                temp = temp->sig;
            }
            temp->sig = nuevoNod;
            cab = nuevoNod;
        }

        void MostrarInv() {
            if (cab == nullptr) {
                cout << "La lista de invitados esta vacia." << endl;
                return;
            }
            Nod* temp = cab;
            int count = 1;

            cout << "\n--- LISTA DE INVITADOS ---" << endl;
            while (temp != nullptr) {
                visit([](auto&& arg) {cout << count << ". " << arg << endl;}, temp->dat);
                temp = temp->sig;
            }
            cout << "--------------------------\n" << endl;
        }
};

int main() {
    ListEnlazad fiest;
    fiest.insert("1");
    fiest.insert("Juan");
    fiest.insert("Maria");

    fiest.MostrarInv();
    return 0;
}
*/