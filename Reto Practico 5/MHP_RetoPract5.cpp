#include <iostream>
#include <string>
using namespace std;

class Nodo {
public:
    string nombre;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo(string n) {
        nombre = n;
        siguiente = NULL;
        anterior = NULL;
    }
};
class ListaEnlazada {
private:
    Nodo* cabeza;
    Nodo* cola;
public:
    ListaEnlazada() {
        cabeza = NULL;
        cola = NULL;
    }
    void registrarInvitado(string nombre) {
        Nodo* nuevoN = new Nodo(nombre);
        if (cabeza == NULL) {
            cabeza = nuevoN;
			cola = nuevoN;
            return;
        } else {
        	cola->siguiente = nuevoN;
            nuevoN->anterior = cola;
            cola = nuevoN;
		}
    }
    void mostrarInicio() {
        if (cabeza == NULL) {
            cout<<"La lista de invitados esta vacia."<<endl;
            return;
        }
        Nodo* temp = cabeza;
        int contador = 1;
        cout<<"\n I N V I T A D O S."<<endl;
        cout<<"(De inicio a fin.)"<<endl;
        while(temp != NULL){
            cout<<"Invitado #"<<contador <<". "<< temp->nombre<<endl;
            temp = temp->siguiente;
            contador++;
        }
        cout<<"\n"<<endl;
    }
    int contar(){
        int contador = 0;
        Nodo* temp = cabeza;
        while(temp != NULL){
            contador++;
            temp = temp->siguiente;
        }
        return contador;
	}
    void mostrarFinal(){
        if(cola == NULL){
            cout<<"La lista de invitados esta vacia."<<endl;
            return;
        }
        Nodo* temp = cola;
        int contador = contar();
        
        cout<<"\n I N V I T A D O S"<<endl;
        cout<<"(De fin a inicio.)"<<endl;
        while (temp != NULL) {
            cout<<"Invitado #"<<contador<<". "<<temp->nombre<<endl;
            temp = temp->anterior;
            contador = contador-1;
        }
        cout<<"\n"<<endl;
    }
    void buscarInvitados(string nombre) {
        if (cabeza == NULL || cola == NULL) {
            cout<<"La lista de invitados esta vacia."<<endl;
            return;
        }
        Nodo* temp = cabeza;
        int contador = 1;
        bool encontrado = false;
        cout<<"\nRESULTADO DE BUSQUEDA"<<endl;
        while (temp != NULL) {
            if (temp->nombre.find(nombre) != string::npos) {
                cout<<contador<<". "<<temp->nombre<<endl;
                encontrado = true;
            }
            temp = temp->siguiente;
            contador++;
        }
        if (!encontrado) {
            cout<<"No se encontraron invitados con el nombre: "<<nombre <<endl;
        }
        cout<<"\n"<<endl;
    }
};

int main() {
    ListaEnlazada evento;
    int op;
    string nombreInvitado;
    char reg = 'n';

    cout<<"\nBienvenido al evento."<<endl;
    do{
        cout<<"\n1. Registrar nuevo invitado."<<endl;
        cout<<"2. Mostrar lista de invitados desde el inicio."<<endl;
        cout<<"3. Mostrar lista de invitados desde el final."<<endl;
        cout<<"4. Buscar invitados."<<endl;
        cout<<"0. Salir."<<endl;
        cout<<"\nElige una opcion: ";
        cin>>op;

		cin.ignore();
		
        switch (op) {
            case 1:
            	do {
	                cout<<"Ingresa el nombre y apellido del invitado: ";
	                getline(cin, nombreInvitado);
	                
	                evento.registrarInvitado(nombreInvitado);
	                cout<<"Invitado registrado con exito.\n"<<endl;
	                
	                cout<<"\n¿Desea añadir otro invitado?"<<endl;
	                cout<<"Escriba una opcion: (s/n)"<<endl;
	                cin>>reg;
	                cin.ignore();
	        	} while(reg == 's' || reg == 'S');
                break;
            case 2:
                evento.mostrarInicio();
                break;
            case 3:
                evento.mostrarFinal();
                break;
			case 4:
                cout<<"Ingresa el nombre del invitado a buscar: ";
                getline(cin, nombreInvitado);
                evento.buscarInvitados(nombreInvitado);
                break;
            case 0:
                cout<<"Saliendo del programa..."<<endl;
                break;
            default:
                cout<<"Opcion invalida. Intente de nuevo."<<endl;
                break;
        }
    } while(op != 0);
    return 0;
}
