#include <iostream>
using namespace std;

class Nodo{
	public:
		int dato;
		Nodo* siguiente;
		
		Nodo(int valor){
			dato = valor;
			siguiente = NULL;
		}
};

class ListaEnlazada{
	private:
		Nodo* cabeza;
	public:
		ListaEnlazada(){
			cabeza=NULL;
		}
		void ingresarDatoAsc(int valor){
			Nodo* nuevoNodo = new Nodo(valor);
			if(cabeza == NULL || valor < cabeza->dato){
				nuevoNodo->siguiente = cabeza;
				cabeza = nuevoNodo;
				return;
			}
			Nodo* temp = cabeza;
			while (temp->siguiente != NULL && temp->siguiente->dato < valor){
				temp = temp->siguiente;
			}
			nuevoNodo->siguiente = temp->siguiente;
			temp->siguiente = nuevoNodo;
		}
		void ingresarDatoDesc(int valor){
			Nodo* nuevoNodo = new Nodo(valor);
			if(cabeza == NULL || valor > cabeza->dato){
				nuevoNodo->siguiente = cabeza;
				cabeza = nuevoNodo;
				return;
			}
			Nodo* temp = cabeza;
			while (temp->siguiente != NULL && temp->siguiente->dato < valor){
				temp = temp->siguiente;
			}
			nuevoNodo->siguiente = temp->siguiente;
			temp->siguiente = nuevoNodo;
		}
		void pedirElementosAsc(){
			int valor;
			int continuar;
			do{
				cout<<"Ingrese elemento: ";
				cin>>valor;
				ingresarDatoAsc(valor);
				
				cout<<"¿Desea ingresar otro elemento?"<<endl;
				cout<<"(1: Si || Otro numero: No): ";
				cin>>continuar;
			}while(continuar == 1);
		}
		void pedirElementosDesc(){
			int valor;
			int continuar;
			do{
				cout<<"Ingrese elemento: ";
				cin>>valor;
				ingresarDatoDesc(valor);
				
				cout<<"¿Desea ingresar otro elemento?"<<endl;
				cout<<"(1: Si || Otro numero: No): ";
				cin>>continuar;
			}while(continuar == 1);
		}
		void mostrarLista(){
			cout<<"\nLa lista ordenada es: "<<endl;
			Nodo* temp = cabeza;
			while (temp != NULL){
				cout<<temp->dato<<" -> ";
				temp = temp->siguiente;
			}
			cout<<""<<endl;
		}
		void cantidad(){
			Nodo* temp = cabeza;
			int con = 0;
			while (temp != NULL){
				con = con + 1;
				temp = temp->siguiente;
			}
			cout<<"La cantidad de elementos almacenados es: "<<con<<endl;
		}
		void promedio(){
			Nodo* temp = cabeza;
			int suma = 0;
			int can=0;
			int prom;
			while (temp != NULL){
				can = can + 1;
				suma = suma + temp->dato;
				temp = temp->siguiente;
			}
			prom = suma/can;
			cout<<"El promedio de los elementos almacenados es: "<<prom<<endl;		
		}
};
int main(){
	ListaEnlazada o;
	int op;
	
	cout<<"\n MENU LISTA"<<endl;
	cout<<"Elija una opcion (1/2): "<<endl;
	cout<<"\n1. Insertar elementos en orden ascendente (menor a mayor)."<<endl;
	cout<<"2. Insertar elementos en orden descendente (mayor a menor)."<<endl;
	cout<<"Opcion: ";
	cin>>op;
	
	switch(op) {
		case 1:
			o.pedirElementosAsc();
			break;
		case 2:
			o.pedirElementosDesc();
			break;
		default:
			cout<<"Elija una opcion correcta"<<endl;
			break;
	}
	
	o.mostrarLista();
	o.cantidad();
	o.promedio();
}

