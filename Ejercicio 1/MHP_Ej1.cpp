//Las tin del tan.
#include <iostream>
#include <string>
using namespace std;

/*Escribe un programa que almacene las temperaturas diarias de una semana (7 días).
Calcule la temperatura media, la temperatura más alta y la más baja.
Requerimientos: Un arreglo de tamaño 7 y
Aplicar bucles para calcular media, máximo y mínimo.*/

//Declaracion de vector y funciones;
float sem[7] = {0};
void llenarVector();
void organizarVector();
void calcTempMedia();
void calcTempAlta();
void calcTempBaja();

//Main del programa;
int main (){
    //Declaracion de variables locales;
    int op;
    bool ban = true;

    //Menu bucle de seleccion
    do{
        cout<<"\nBienvenido al SCT (Sistema de Control de Temperatura)"<<endl;
        cout<<"Seleccione una de las siguientes opciones."<<endl;
        cout<<"\n1. Ingresar datos de temperatura semanal"<<endl;
        cout<<"2. Calcular la temperatura media"<<endl;
        cout<<"3. Calcular la temperatura máxima"<<endl;
        cout<<"4. Calcular la temperatura mínima"<<endl;
        cout<<"0. Salir."<<endl;
        cout<<"\nSeleccione la opcion que desea realizar: "<<endl;
        cin>>op;
        cout<<"\n"<<endl;

        //Estructura switch;
        switch(op){
            case 1:
                //Pedida de datos;
                llenarVector();
                //organizacion de los datos;
                organizarVector();
                break;
            case 2:
                if (sem[0] == 0){
                    cout<<"No se han ingresado datos de temperatura, por favor ingrese los datos primero."<<endl;
                    break;
                } else {
                    calcTempMedia();
                    break;
                }
            case 3:
                if (sem[0] == 0){
                    cout<<"No se han ingresado datos de temperatura, por favor ingrese los datos primero."<<endl;
                    break;
                } else {
                    calcTempAlta();
                    break;
                }
            case 4:
                if (sem[0] == 0){
                    cout<<"No se han ingresado datos de temperatura, por favor ingrese los datos primero."<<endl;
                    break;
                } else {
                    calcTempBaja();
                    break;
                }
            case 0:
                cout<<"\nGracias por usar el SCT, Saliendo..."<<endl;
                ban = false;
                break;
            default:
                cout<<"Elija una opcion valida"<<endl;
                break;
        }
    }while(ban == true);
}
//Funcion para llenar el vector de temperaturas;
void llenarVector(){
    //Vector local para identificar el dia de la semana;
    string dias[7] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
    //Ciclo for para llenar el vector de temperaturas;
    for (int i = 0; i < 7; i++){
        cout<<"Ingrese la temperatura del dia "<<dias[i]<<": ";
        cin>>sem[i];
    }
}
//Funcion para organizar el vector de temperaturas de menor a mayor;
void organizarVector(){
    float temp;
    for (int i= 0; i<7; i++){
        for (int j=0; j<7;j++){
            if (sem[i]<sem[j]){
                temp = sem[i];
                sem[i] = sem[j];
                sem[j] = temp;
            }
        }
    }
}
//Funcion para calcular la temperatura media;
void calcTempMedia(){
    float suma = 0;
    for (int i=0; i<7; i++){
        suma = suma + sem[i];
    }
    float media = suma / 7;
    cout<<"La temperatura media es: "<<media<<endl;
}
//Funcion para calcular la temperatura maxima;
void calcTempAlta(){
    cout<<"La temperatura máxima es: "<<sem[6]<<endl;
}
//Funcion para calcular la temperatura minima;
void calcTempBaja(){
    cout<<"La temperatura minima es: "<<sem[0]<<endl;
}
