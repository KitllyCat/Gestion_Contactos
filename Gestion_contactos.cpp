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

const int tam=99;
int cantCont=0;
int indice;
struct contactoEmail{
	string nombres;
	string sexo;
	string edad;
	string telefono;
	string email;
	string nacionalidad;
};
contactoEmail conEm[tam];

void agregarContacto(){
	if(cantCont>=tam){
        cout<<"Ya no se pueden agregar más contactos. Límite alcanzado~!!!";
        Sleep(2000);
        system("cls");
        return;
    }
    contactoEmail aniadir;
    
    cout<<"----- Añadir Contacto -----"<<endl<<endl;
	cout<<"Ingrese el nombre los nombres completos de la persona: ";
	cin.ignore();
	getline(cin, aniadir.nombres);
	do{
    	cout<<endl<<"Ingrese el sexo (M/F): ";
    	getline(cin, aniadir.sexo);
    	if(aniadir.sexo!="M" && aniadir.sexo!="F" && aniadir.sexo!="m" && aniadir.sexo!="f"){
    	    cout<<"Error al momento de guardar dato. Solo se acepta 'M' o 'F' !!!"<<endl;
    	}
	}while(aniadir.sexo!="M" && aniadir.sexo!="F" && aniadir.sexo!="m" && aniadir.sexo!="f");
    int salirE=0;
	do{	
		salirE=1;
		cout<<endl<<"Ingrese la edad: ";
   		cin>>aniadir.edad;
    	cin.ignore();
    	for(char c:aniadir.edad){
	        if(!isdigit(c)){
	            cout<<"La edad tiene que ser solo con números!!!"<<endl;
	            salirE=0;
	            break;
	        }
        }
	}while(salirE!=1);
	int salirT=0;
	do{
		salirT=1;
	    cout<<endl<<"Ingrese el teléfono: ";
    	getline(cin, aniadir.telefono);
		int tamTel=aniadir.telefono.length();
	    if(tamTel!=9){
	        cout<<"El telefono tiene que tener 9 dígitos!!!"<<endl;
	        salirT=0;
	        continue;
	    }
	    for(char c:aniadir.telefono){
        if(!isdigit(c)){
            cout<<"El teléfono solo debe contener números!!!"<<endl;
            salirT=0;
            break;
        }
    }
	}while(salirT!=1);    
    do{
	    cout<<endl<<"Ingrese el Email: ";
    	getline(cin, aniadir.email);
	    if(aniadir.email.find('@')==string::npos){
	        cout<<"Email incorrecto. Debe contener un '@' para ser considerado!!!"<<endl;
	    }
	}while(aniadir.email.find('@')==string::npos);
    cout<<endl<<"Ingrese la nacionalidad: ";
    getline(cin, aniadir.nacionalidad);
	conEm[cantCont]=aniadir;
    cantCont++;
    cout<<endl<<"El contacto se añadio correctamente, regresando al menu..."<<endl;
    Sleep(2000);
    system("cls");
}

void eliminarContacto(){
	if(cantCont==0){
        cout<<"Ya no existen contactos, no se puede eliminar más!!!";
        Sleep(2000);
        system("cls");
        return;
    }
	cout<<"----- Eliminar contacto -----"<<endl<<endl;
	cout<<"Ingrese el numero de orden del contacto a eliminar(Índice): ";
	cin>>indice;
	cin.ignore();
	indice=indice-1;	
	if(indice>=0 && indice<cantCont){
		for(int i=indice;i<cantCont-1;i++){
			conEm[i]=conEm[i+1];
		}
	}else{
		cout<<"El número es incorrecto o inexistente. Regresando al menú..."<<endl;
        Sleep(2000);
        system("cls");
        return;
	}
	cantCont--;
	cout<<"Contacto eliminado correctamente, regresando al menu...";
    Sleep(2000);
    system("cls");
}

void mostrarListadoRegistrados(){
	if(cantCont==0){
        cout<<"No existen contactos que se puedan mostrar!!!";
        Sleep(2000);
        system("cls");
        return;
    }
    cout<<"----- Listado general de contactos -----"<<endl<<endl;
    for(int i=0;i<cantCont;i++){
    	cout<<i+1<<"._ Contacto:"<<endl<<endl;
        cout<<"Nombre: "<<conEm[i].nombres<<endl;
        cout<<"Sexo: "<<conEm[i].sexo<<endl;
        cout<<"Edad: "<<conEm[i].edad<<endl;
        cout<<"Teléfono: "<<conEm[i].telefono<<endl;
        cout<<"Email: "<<conEm[i].email<<endl;
        cout<<"Nacionalidad: "<<conEm[i].nacionalidad<<endl;
        cout<<"----------------------------------"<<endl<<endl;
	}
	cout<<"Presione enter para volver al menu principal...";
	cin.ignore();
	cin.get();
	system("cls");
}

void mostrarListadoExistentes(){
	
}

int main(){
	SetConsoleOutputCP(CP_UTF8);
	int opcion;
	
	do{
		cout<< "-----Gestor de contactos-----"<<endl<<endl;
		cout<<"Elija la opcion que desea realizar en el programa:"<<endl;
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
				system("cls");
				agregarContacto();
				break;
			}
			case 2:{
				system("cls");
				eliminarContacto();
				break;
			}
			case 3:{
				system("cls");
				mostrarListadoRegistrados();
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