/*Gestión de Contactos, Crear una estructura llamada contactoEmail que tenga las siguientes características:
nombres completos,sexo,edad,teléfono,email,nacionalidad
El programa debe constar de un menú que permita:
a) Agregar un contacto
b) Eliminar un contacto
c) Mostrar listado general de contactos registrados hasta ese momento.
d) Mostrar listado de contactos existentes, ordenado por servidor de correo de las cuentas (gmail.com, outlook.com, yahoo.com, etc.)
e) Salir del programa
El programa debe mantenerse en ejecución continuamente hasta que usuario indique que desea salir del mismo.*/
#include <iostream>
#include <windows.h>
using namespace std;

void agregarContacto(){
	
}

void eliminarContacto(){
	
}

void mostrarListadoRegistrados(){
	
}

void mostrarListadoExistentes(){
	
}

int main(){
	SetConsoleOutputCP(CP_UTF8);
	int opcion;
	do{
		cout<< "-----Gestor de contactos-----"<<endl<<endl;
		cout<<"Seleccione la opcion que desea realizar en el programa:"<<endl;
		cout<<"1) Agregar un nuevo contacto"<<endl;
		cout<<"2) Eliminar un contacto existente"<<endl;
		cout<<"3) Mostrar todos los contactos guardados"<<endl;
		cout<<"4) Mostrar todos los contactos guardados en orden de correos"<<endl;
		cout<<"5) Salir"<<endl;
		cout<<"Selecione su opcion: ";
		cin>>opcion;
		cout<<endl;
		
		switch(opcion){
			case 1:{
				//void agregarContacto
				break;
			}
			case 2:{
				//void eliminarContacto
				break;
			}
			case 3:{
				//void mostrarListadoRegistrados
				break;
			}
			case 4:{
				//void mostrarListadoExistentes
				break;
			}
			case 5:{
				system("cls");
				cout<<"Saliendo del programa..."<<endl;
				break;
			}
			default:{
				cout<<"Opción invalida!!! Intente de nuevo..."<<endl;
				Sleep(1500);
				system("cls");
				break;
			}
		}
	}while(opcion!=5);
	
	return 0;
}