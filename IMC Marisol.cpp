#include<wchar.h>
#include<locale.h>
#include<fstream>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <string>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <windows.h>

#define USER "Admin"
#define PASS "123"
#define user "User"
#define pass "123"

using namespace std;
void gotoxy(int x,int y);
//estructura de la cola

void titulo(){
	int x, y, z, a, i;
	system ("cls");
	gotoxy(35, 10);
	

 printf("****** BIENVENIDO ******");
 

 for(i=1; i<90; i++)
 {
  gotoxy(i,13);
  printf("%c",177);
 
  for(x=50;x<70;x++){
   for(y=1;y<70;y++){
    gotoxy(y,24);
   }
  }
 }
gotoxy(20,20);
}

void gotoxy(int x,int y){                         
      HANDLE hcon;                               
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);     
      COORD dwPos;                                 
      dwPos.X = x;                                 
      dwPos.Y= y;                                 
      SetConsoleCursorPosition(hcon,dwPos);       
 }


struct ICO{
	string nombre, app, apm, fechanac, genero, domicilio, correo, enfercro, discapacidades, alergias, fecha, hora, consultorio, Nhora, Nfecha, Nconsultorio, id_cita, idaux, folio, telefono, folioaux, diagnostico;
	string consultorio1 = "A";
	string consultorio2 = "B";
	string consultorio3 = "C";
	string fecha1 = "01/Agosto/2022";
	string fecha2 = "02/Agosto/2022";
	string fecha3 = "03/Agosto/2022";
	string hora1 = "7:00";
	string hora2 = "7:30";
	string hora3 = "8:00";
	string infrapeso = "Infrapeso..._Diagnostico:_Dolencias_Pulmonares,_anorexia_nerviosa,_desnutrición,_etc.";
	string delgadez = "Delgadez..._Diagnostico:_Sin_riesgo_pero_ten_precaución_de_no_adelgazar_más.";
	string normal = "Normal..._Diagnostico:_Estado_Saludable.";
	string obesidad = "Obesidad_Tipo_I..._Diagnostico:_Sobrecarga_de_articulaciones,_cansancio_excesivo_y_un_cierto_riesgo_de_enfermedades_cardiovasculares.";
	string obesidadd = "Obesidad_Tipo_II..._Diagnostico:_Prblemas_cardíacos,_diabetes,_hipertensión,_enfermedad_de_vesícula_y_algunos_cánceres._Alto_Riesgo_ante_el_Covid-19.";
	string obesidaddd = "Obesidad_Tipo_III..._Diagnostico:_Serios_riesgos_para_la_salud,_disminución_de_la_calidad_de_vida._Visita_un_médico._Alto_Riesgo_ante_el_Covid-19.";
	string morbida = "Obesidad_Mórbida..._Diagnostico:_Riesgo_inmediato._Precisará,_siempre_bajo_control_médico,_tratamiento_farmaceologico_o_quirúrgico._Alto_Riesgo_ante_el_Covid-19.";
	
	int edad, anonac;
	float peso, altura, imc, muneca, brazo, antebrazo, muslo, pantorrilla, cintura, cadera, humero, biceps, triceps, subescapular, suprailiaco;
};

struct Nodo{
	ICO pacientes;
	Nodo *siguiente;
};



//metodos
void login();





//Usuario
void menuuser();
void agregarDatos(ICO &);
void insertarDatos(Nodo *&, Nodo *&, ICO);
void buscarPre(ICO);
void agregarCitas(ICO &);
void insertarCitas(Nodo *&, Nodo *&, ICO);
void buscarCita(ICO);
void titulo();
void gotoxy(int x,int y);

//Admin
void menuadmin();
void menupre();
void buscarPreex(ICO);
void menucita();
void consultarCita(ICO);
void editarCita(ICO);
void eliminarCita(ICO);
void consultarCitas(ICO);
void menuexp();
void agregarMedidas(ICO &);//
void insertarMedidas(Nodo *&, Nodo *&, ICO);//
void consultarExpc(ICO);
void editarExpediente(ICO);
void eliminarExpediente(ICO);
void consultarExpedientes(ICO);
void titulo();
void gotoxy(int x,int y);

void eliminarDatos(Nodo *&, Nodo *&, ICO);//
bool c_vacia(Nodo *);//

int main(){
	
	setlocale(LC_ALL,"");
	
	system("color 9");
	
	
    
    login();
	
	return 0;
}

//LOGIN

void login(){
	string usuario, password;
	int contador = 0;
	bool ingresa = false;
	bool ingresa1 = false;
	titulo();
	gotoxy(35, 10);
	
	do{
		system("cls");
		cout<<"\n\t__________________________";
		cout<<"\n\t|                        |";
		cout<<"\n\t|                        |";
		cout<<"\n\t|    Inicio de Sesion    |";
		cout<<"\n\t|                        |";
		cout<<"\n\t|                        |";
		cout<<"\n\t|         * * *          |";
		cout<<"\n\t|              *         |";
		cout<<"\n\t|         * * *          |";
		cout<<"\n\t|                        |";
		cout<<"\n\t|________________________|";
		cout<<"\n\t";
		cout<<"\n\tUsuario:";
		getline(cin, usuario);
		cout<<"\tContraseña:";
		
		char caracter;
		caracter = getch();
		
		password = "";
		
		
		while (caracter != 13){
			password.push_back(caracter);
			cout<<"*";
			caracter = getch();
		}
		
		cout<<"\n\t|_________________________\n";
		
		if (usuario == USER && password == PASS){
			ingresa = true;
			system("cls");
		}else if(usuario == user && password == pass){
			ingresa1 = true;
			system("cls");
		}else{
			cout<<"\n\t El Usuario y/o Password son incorrectos\n"<<endl;
			contador++;
			system("pause");
		}
	}while ((ingresa == false && contador < 3) && (ingresa1 == false && contador < 3));
	
	if(ingresa != false){
		menuadmin();
	}else if(ingresa1 != false){
		menuuser();
	}else{
		system("cls");
		cout<<"\n\t Demasiados Intentos comuniquese con TI"<<endl;
	}
}

//MENUS

void menuadmin(){
	
	char opcion;
	
	cout<<endl<<"\t____________________________________";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t|      ***Menú Especialista***     |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t| 1. Consultar                     |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t| 2. Expediente Clinico            |";
    cout<<endl<<"\t|__________________________________|";
    cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t| 3. Salir                         |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\tOpción:";
	
	cin>>opcion;
	fflush(stdin);
		
	do{
		switch(opcion){
			case '1':
				system("cls");
				menupre();
			break;
			
			case '2':
				system("cls");
				menuexp();
			break;
						
			case '3':
				system("cls");
				login();
			break;
			
			default:
				cout<<"\n\tOpción Invalida T-T\n";
				break;
		}
		cout<<"\n\tPresiona Cualquier Tecla\n";
	 	getch();
		system("cls");
	}while(opcion != '3');
}

void menupre(){
	
	ICO pacientes;
	
	char opcion;
	
	cout<<endl<<"\t____________________________________";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t|         ***Consultar***          |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t| 1. Pre-Expediente                |";
    cout<<endl<<"\t|__________________________________|";
    cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t| 2. Cita                          |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t| 3. Regresar                      |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\tOpción:";
	
	cin>>opcion;
	fflush(stdin);
	
	do{
		switch(opcion){
			case '1':
				system("cls");
				buscarPreex(pacientes);
				system("pause");
			    cout<<endl;
			    system("cls");
			    fflush(stdin);
			    menupre();
			break;
			
			case '2':
				system("cls");
				menucita();
			break;
						
			case '3':
				system("cls");
				menuadmin();
			break;
			
			default:
				cout<<"\n\tOpción Invalida T-T\n";
				break;
		}
		cout<<"\n\tPresiona Cualquier Tecla\n";
	 	getch();
		system("cls");
	}while(opcion != '4');
}

void menucita(){
	
	ICO pacientes;
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	
	char opcion;
	
	cout<<endl<<"\t____________________________________";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t|            ***Cita***            |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t| 1. Cita                          |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t| 2. Editar                        |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t| 3. Eliminar                      |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t| 4. Consultar Citas               |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t| 5. Regresar                      |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\tOpción:";
	
	cin>>opcion;
	fflush(stdin);
	
	do{
		switch(opcion){
			case '1':
				system("cls");
				consultarCita(pacientes);
			break;
			
			case '2':
				system("cls");
				editarCita(pacientes);
			break;
			
			case '3':
				system("cls");
				eliminarCita(pacientes);
			break;
						
			case '4':
				system("cls");
				consultarCitas(pacientes);
			break;
			
			case '5':
				system("cls");
				menupre();
			break;
			
			default:
				cout<<"\n\tOpción Invalida T-T\n";
				break;
		}
		cout<<"\n\tPresiona Cualquier Tecla\n";
	 	getch();
		system("cls");
	}while(opcion != '4');
}

void menuexp(){
	
	ICO pacientes;
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	
	char opcion;
	
	cout<<endl<<"\t____________________________________";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t|     ***Expediente Clinico***     |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t| 1. Generar Expediente            |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t| 2. Consultar Expediente          |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t| 3. Editar Expediente             |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t| 4. Eliminar Expediente           |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t| 5. Consultar Expedientes         |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\t|                                  |";
	cout<<endl<<"\t| 6. Regresar                      |";
	cout<<endl<<"\t|__________________________________|";
	cout<<endl<<"\tOpción:";
	
	cin>>opcion;
	fflush(stdin);
	
	Nodo *aux = frente;
		
	do{
		switch(opcion){
			case '1':				
				system("cls");
				agregarMedidas(pacientes);
				insertarMedidas(frente, fin, pacientes);
			break;
			
			case '2':				
				system("cls");
				consultarExpc(pacientes);
			break;
			
			case '3':
				system("cls");
				editarExpediente(pacientes);
			break;
			
			case '4':
				system("cls");
				eliminarExpediente(pacientes);
			break;
						
			case '5':
				system("cls");
				consultarExpedientes(pacientes);
			break;
			
			case '6':
				system("cls");
				menuadmin();
			break;
			
			default:
				cout<<"\n\tOpción Invalida T-T\n";
				break;
		}
		cout<<"\n\tPresiona Cualquier Tecla\n";
	 	getch();
		system("cls");
	}while(opcion != '6');
}

void menuuser(){
	
	ICO pacientes;
	Nodo *frente = NULL;
	Nodo *fin = NULL;
		
	char opcion;
	
	
	Nodo *aux = frente;
		
	do{
		cout<<endl<<"\t____________________________________";
		cout<<endl<<"\t|                                  |";
		cout<<endl<<"\t|        ***Menú Usuario***        |";
		cout<<endl<<"\t|__________________________________|";
		cout<<endl<<"\t|                                  |";
		cout<<endl<<"\t| 1. Registrar Pre-Expediente      |";
		cout<<endl<<"\t|__________________________________|";
		cout<<endl<<"\t|                                  |";
		cout<<endl<<"\t| 2. Consultar Pre-Expediente      |";
		cout<<endl<<"\t|__________________________________|";
		cout<<endl<<"\t|                                  |";
		cout<<endl<<"\t| 3. Registrar Cita                |";
		cout<<endl<<"\t|__________________________________|";
		cout<<endl<<"\t|                                  |";
		cout<<endl<<"\t| 4. Consultar Cita                |";
		cout<<endl<<"\t|__________________________________|";
		cout<<endl<<"\t|                                  |";
		cout<<endl<<"\t| 5. Salir                         |";
		cout<<endl<<"\t|__________________________________|";
		cout<<endl<<"\tOpción:";
	
		cin>>opcion;
		fflush(stdin);
		
		switch(opcion){
			case '1':
				system("cls");
				agregarDatos(pacientes);
				insertarDatos(frente, fin, pacientes);
			break;
			
			case '2':
				system("cls");
				buscarPre(pacientes);
			break;
			
			case '3':
				system("cls");
				agregarCitas(pacientes);
				insertarCitas(frente, fin, pacientes);
			break;
			
			case '4':
				system("cls");
				buscarCita(pacientes);
			break;
						
			case '5':
				system("cls");
				login();
			break;
			
			default:
				cout<<"\n\tOpción Invalida T-T\n";
				break;
		}
		cout<<"\n\tPresiona Cualquier Tecla\n";
	 	getch();
		system("cls");
	}while(opcion != '5');
}

//EXPEDIENTE

//Usuario
void agregarDatos(ICO &pacientes){
	
	int year;

	time_t now;

	time(&now);

	struct tm *local = localtime(&now);

	year = local->tm_year + 1900;
	
	//ofstream foutput;
	ofstream Guardar;
	//ifstream finput;
	ifstream Leer;
	
	//foutput.open ("Expedientes.txt",ios::app);
    //finput.open ("Expedientes.txt");
    Guardar.open ("Expedientes.txt",ios::app);
    Leer.open ("Expedientes.txt");
	
	if(Leer.is_open()){
		
		cout<<"\n\t__________________________________";
		//foutput<<"\n_______________________________";
		
		cout<<"\n\t|\n\t|\n\t|   Datos Generales      ";
		//foutput<<"\n\t|\n\t|   Datos Generales       ;
		
		cout<<"\n\t|\n\t| Folio de Expediente Clinico:";
		cin>>pacientes.folio;
		
		//foutput<<"\t\t| Folio: " << pacientes.folio;
		cout<<"\t| Apellido Paterno:";
		
		cin>>pacientes.app;
		//foutput<<"\n\t|\n\t| Apellido Paterno: "<< pacientes.app;
		cout<<"\t| Apellido Materno:";
		
		cin>>pacientes.apm;
		//foutput<<"\t\t| Apellido Materno: "<< pacientes.apm;
		cout<<"\t| Nombre:";
		cin>>pacientes.nombre;
		
		//foutput<<"\t\t| Nombre: "<< pacientes.nombre;
		cout<<"\t| Género:";
		cin>>pacientes.genero;
		
		//foutput<<"\n\t|\n\t| Genero: "<< pacientes.genero;
		cout<<"\t| Domicilio:";
		cin>>pacientes.domicilio;
		
		//foutput<<"\t\t| Domicilio: "<< pacientes.domicilio;
		cout<<"\t| Correo:";
		cin>>pacientes.correo;
		
		//foutput<<"\n\t|\n\t| Correo: "<< pacientes.correo;
		cout<<"\t| Teléfono:";
		cin>>pacientes.telefono;
		
		//foutput<<"\t\t| Teléfono: "<< pacientes.telefono;	
		cout<<"\t| Fecha de Nacimiento (dd/mm):";
		cin>>pacientes.fechanac;
		
		//foutput<<"\t\t| Fecha de Nacimiento: " << pacientes.fechanac;
		cout<<"\t| Año de Nacimiento (aaaa):";
		cin>>pacientes.anonac;
		//foutput<<"\t\t| Año de Nacimiento: " << pacientes.anonac;	
		
		pacientes.edad=year-pacientes.anonac;
		
		cout<<"\t| Edad:";
		cout<<pacientes.edad;
		//foutput<<"\n\t|\n\t| Edad: "<< pacientes.edad;
		
		cout<<"\n\t|___________________________________";
		//foutput<<"\n______|__________________________";
		
		Guardar<<pacientes.folio<<" "<<pacientes.app<<" "<<pacientes.apm<<" "<<pacientes.nombre<<" "<<pacientes.genero<<" "<<pacientes.domicilio<<" "<<pacientes.correo<<" "<<pacientes.telefono<<" "<<pacientes.fechanac<<" "<<pacientes.anonac<<" "<<pacientes.edad<<endl;
		cout<<"\t|\n\t| Datos ingresados correctamente\n |";
	
    	Guardar.close();
    	Leer.close();
    	system("pause");
    	cout<<endl;
    	system("cls");
		fflush(stdin);
    	menuuser();
	}else{
		cout<<"\n\t***Error en Archivo***";
	}
}

void insertarDatos(Nodo *&frente, Nodo *&fin, ICO pacientes){
	//Declaro mi nuevo nodo
	Nodo *n_nodo = new Nodo();
	
	//Asignar los valores de los datos
	n_nodo -> pacientes = pacientes;
	
	//siguiente apunte a null
	n_nodo -> siguiente = NULL;
	
	//Primero verificar si esta vacia
	if(c_vacia(frente)){
		frente = n_nodo;
		//si la cola esta vacia frente = nuevo nodo
	}else{
		fin -> siguiente = n_nodo;//si la cola esta vacia
	}
	fin = n_nodo;
}

void buscarPre(ICO pacientes){
	ifstream Pre;
	Pre.open("Expedientes.txt");
	
	bool encontrado=false;
    cout<<"\t|\n\t| Ingrese Folio: ";
    cin>>pacientes.folioaux;
    
    while(Pre>> pacientes.folio >> pacientes.app >> pacientes.apm >> pacientes.nombre >> pacientes.genero >> pacientes.domicilio >> pacientes.correo >> pacientes.telefono >> pacientes.fechanac >> pacientes.anonac >> pacientes.edad){
		
		if(pacientes.folio==pacientes.folioaux){
			
			encontrado=true;
		
    		cout<<"\n\t|\n\t_______________________________________";
    		cout<<"\n\t|\n\t|                                     |";
			cout<<"\n\t|\n\t|           Pre-Expediente            |";
			cout<<"\n\t|\n\t|                                     |";
			cout<<"\n\t|\n\t| Apellido Paterno: "<< pacientes.app;
			
			cout<<"\t| Apellido Materno: "<< pacientes.apm;
			
			cout<<"\t| Nombre: "<< pacientes.nombre;
			
			cout<<"\n\t|\n\t| Genero: "<< pacientes.genero;
			
			cout<<"\n\t|\n\t| Domicilio: "<< pacientes.domicilio;
			
			cout<<"\t| Correo: "<< pacientes.correo;
			
			cout<<"\t| Telefono: "<< pacientes.telefono;
			
			cout<<"\n\t|\n\t| Fecha de Nacimiento: "<< pacientes.fechanac;
			
			cout<<"\t| Año de Nacimiento: "<< pacientes.anonac;
			
			cout<<"\t| Edad: "<< pacientes.edad;
			
			cout<<"\t| Folio: "<< pacientes.folio;
			
			cout<<"\n_________________________________________|";
			cout<<"\n\n";
		}
	}
    if(encontrado==false){
    	cout<<"\t| Pre-Expediente Sin Registro\n";
	}
    Pre.close();
    
    system("pause");
    cout<<endl;
    system("cls");
    fflush(stdin);
    menuuser();
}

//Admin
void buscarPreex(ICO pacientes){
	ifstream Pre;
	Pre.open("Expedientes.txt");
	
	bool encontrado=false;
    cout<<"\t|\n\t| Ingrese Folio: ";
    cin>>pacientes.folioaux;
    
    while(Pre>> pacientes.folio >> pacientes.app >> pacientes.apm >> pacientes.nombre >> pacientes.genero >> pacientes.domicilio >> pacientes.correo >> pacientes.telefono >> pacientes.fechanac >> pacientes.anonac >> pacientes.edad){
		
		if(pacientes.folio==pacientes.folioaux){
			
			encontrado=true;
		
    		cout<<"\n\t|\n\t_________________________________________";
            cout<<"\n\t|\n\t|                                       |";
			cout<<"\n\t|\n\t|             Pre-Expediente            |";
			cout<<"\n\t|\n\t|_______________________________________|";
			cout<<"\n\t|\n\t| Apellido Paterno: "<< pacientes.app;
			
			cout<<"\t| Apellido Materno: "<< pacientes.apm;
			
			cout<<"\t| Nombre: "<< pacientes.nombre;
			
			cout<<"\n\t|\n\t| Genero: "<< pacientes.genero;
			
			cout<<"\n\t|\n\t| Domicilio: "<< pacientes.domicilio;
			
			cout<<"\t| Correo: "<< pacientes.correo;
			
			cout<<"\t| Telefono: "<< pacientes.telefono;
			
			cout<<"\n\t|\n\t| Fecha de Nacimiento: "<< pacientes.fechanac;
			
			cout<<"\t| Año de Nacimiento: "<< pacientes.anonac;
			
			cout<<"\t| Edad: "<< pacientes.edad;
			
			cout<<"\t| Folio: "<< pacientes.folio;
			
			cout<<"\n________|_________________________________________ ";
			cout<<"\n\n";
		}
	}
    if(encontrado==false){
    	cout<<"\t| Pre-Expediente Sin Registro\n";
	}
    Pre.close();
}

void agregarMedidas(ICO &pacientes){
	
	float peso, altura;
	
	//ofstream foutput;
	ofstream Guardar;
	ifstream Leer;
	
	//foutput.open ("Citas.txt",ios::app);
	Guardar.open ("ExpedienteCompleto.txt",ios::app);
    //finput.open ("Citas.txt");
    Leer.open("ExpedienteCompleto.txt");
	
	if(Leer.is_open()){
		
		buscarPreex(pacientes);
		
		cout<<"\t|\n\t| Confirmar Folio:";
		cin>>pacientes.folio;
		
		cout<<"\t|\n\t| Enfermedades Cronicas:";
		cin>>pacientes.enfercro;
		//foutput<<"\n\t|\n\t| Muñeca: "<< pacientes.enfercro;
		
		cout<<"\t| Discapacidades:";
		cin>>pacientes.discapacidades;
		//foutput<<"\n\t|\n\t| Discapacidades: "<< pacientes.discapacidades;
		
		cout<<"\t| Alergias:";
		cin>>pacientes.alergias;
		//foutput<<"\n\t|\n\t| Alergias: "<< pacientes.discapacidades;
		
		cout<<"\t|\n\t|       Indicadores Antropométricos";
		//foutput<<"\n\t|\n\t|    Indicadores Antropométricos       ";
		cout<<"\n\t|\n\t|Los siguientes datos se registran en cm";
		
		cout<<"\n\t|\n\t|Muñeca del Paciente:";
		cin>>pacientes.muneca;
		//foutput<<"\n\t|\n\t| Muñeca: "<< pacientes.muneca <<"cm.";
	
		cout<<"\t|Brazo del Paciente:";
		cin>>pacientes.brazo;
		//foutput<<"\t| Brazo: "<< pacientes.brazo <<"cm.";
		
		cout<<"\t| Antebrazo del Paciente:";
		cin>>pacientes.antebrazo;
		//foutput<<"\t\t| Antebrazo: "<< pacientes.antebrazo <<"cm.";
		
		cout<<"\t| Muslo del Paciente:";
		cin>>pacientes.muslo;
		//foutput<<"\n\t| Muslo: "<< pacientes.muslo <<"cm.";
		
		cout<<"\t| Pantorrilla del Paciente:";
		cin>>pacientes.pantorrilla;
		//foutput<<"\t| Pantorrilla: "<< pacientes.pantorrilla <<"cm.";
		
		cout<<"\t| Cintura del Paciente:";
		cin>>pacientes.cintura;
		//foutput<<"\t| Cintura: "<< pacientes.cintura <<"cm.";
		
		cout<<"\t| Cadera del Paciente:";
		cin>>pacientes.cadera;
		//foutput<<"\n\t| Cadera: "<< pacientes.cadera <<"cm.";
		
		cout<<"\t| Humero del Paciente:";
		cin>>pacientes.humero;
		//foutput<<"\t| Humero: "<< pacientes.humero <<"cm.";
		
		cout<<"\t|   Pliegues o Panículos";
		//foutput<<"\n\t|\n\t|      Pliegues o Panículos      ;
		cout<<"\n\t|\n\t| Los siguientes datos se registran en mm";
		
		cout<<"\n\t|\n\t| Biceps del Paciente:";
		cin>>pacientes.biceps;
		//foutput<<"\n\t|\n\t| Biceps: "<< pacientes.biceps <<"mm.";
		
		cout<<"\t| Subescapular del Paciente:";
		cin>>pacientes.subescapular;
		//foutput<<"\t\t| Subescapular: "<< pacientes.subescapular <<"mm.";
		
		cout<<"\t| Triceps del Paciente:";
		cin>>pacientes.triceps;
		//foutput<<"\n\t| Triceps: "<< pacientes.triceps <<"mm.";
		
		cout<<"\t| Suprialiaco del Paciente:";
		cin>>pacientes.suprailiaco;
		//foutput<<"\t\t| Suprailiaco: "<< pacientes.suprailiaco <<"mm.";
		
		cout<<"\t|\n\t|     IMC    ";
		//foutput<<"\n\t|\n\t|    IMC   ";
		
		cout<<"\n\t|\n\t| Ingresa Peso del Paciente en kilogramos:";
		cin>>pacientes.peso;
		//foutput<<"\n\t| Peso: "<< pacientes.peso;
		
		cout<<"\t| Ingresa Altura del Paciente en metros:";
		cin>>pacientes.altura;
		//foutput<<"\t\t| Altura: "<< pacientes.altura;

		pacientes.imc=((pacientes.peso)/(pacientes.altura*pacientes.altura));
	
		cout<<"\t| IMC: ";
		cout.precision(4);
		cout<<pacientes.imc;
		//foutput<<"\t\t| IMC: "<< pacientes.imc;
		
		Guardar<<pacientes.folio<<" "<<pacientes.enfercro<<" "<< pacientes.discapacidades<<" "<<pacientes.alergias<<" "<< pacientes.muneca<<" "<<pacientes.brazo<<" "<< pacientes.antebrazo<<" "<<pacientes.muslo<<" "<< pacientes.pantorrilla<<" "<<pacientes.cintura<<" "<< pacientes.cadera<<" "<<pacientes.humero<<" "<< pacientes.biceps<<" "<<pacientes.subescapular<<" "<< pacientes.triceps<<" "<<pacientes.suprailiaco<<" "<< pacientes.peso<<" "<<pacientes.altura<<" "<< pacientes.imc;
		
		if(pacientes.imc<16){
			cout<<"\n\t|\n\t| "<<pacientes.infrapeso;
			Guardar<<" "<<pacientes.infrapeso<<endl;
			//foutput<<"\n\t|\n\t| Infrapeso... Diagnostico: Dolencias Pulmonares, anorexia nerviosa, desnutrición, etc.";
		}else if(pacientes.imc>16 && pacientes.imc<18.5){
			cout<<"\n\t|\n\t| "<<pacientes.delgadez;
			Guardar<<" "<<pacientes.delgadez<<endl;
			//foutput<<"\n\t|\n\t| Delgadez... Diagnostico: Sin riesgo pero ten precaución de no adelgazar más.";
		}else if(pacientes.imc>18.5 && pacientes.imc<25){
			cout<<"\n\t|\n\t| "<<pacientes.normal;
			Guardar<<" "<<pacientes.normal<<endl;
			//foutput<<"\n\t|\n\t| Normal... Diagnostico: Estado Saludable.";
		}else if(pacientes.imc>26 && pacientes.imc<30){
			cout<<"\n\t|\n\t| "<<pacientes.obesidad;
			Guardar<<" "<<pacientes.obesidad<<endl;
			//foutput<<"\n\t|\n\t| Obesidad Tipo I... Diagnostico: Sobrecarga de articulaciones, cansancio excesivo y un cierto riesgo de enfermedades cardiovasculares.";
		}else if(pacientes.imc>30 && pacientes.imc<35){
			cout<<"\n\t|\n\t| "<<pacientes.obesidadd;
			Guardar<<" "<<pacientes.obesidadd<<endl;
			//foutput<<"\n\t|\n\t| Obesidad Tipo II... Diagnostico: Prblemas cardíacos, diabetes, hipertensión, enfermedad de vesícula y algunos cánceres. Alto Riesgo ante el Covid.";
		}else if(pacientes.imc>35 && pacientes.imc<40){
			cout<<"\n\t|\n\t| "<<pacientes.obesidaddd;
			Guardar<<" "<<pacientes.obesidaddd<<endl;
			//foutput<<"\n\t|\n\t| Obesidad Tipo III... Diagnostico: Serios riesgos para la salud, disminución de la calidad de vida. Visita un médico. Alto Riesgo ante el Covid.";
		}else if(pacientes.imc>40){
			cout<<"\n\t|\n\t| "<<pacientes.morbida;
			Guardar<<" "<<pacientes.morbida<<endl;
			//foutput<<"\n\t|\n\t| Obesidad Mórbida... Diagnostico: Riesgo inmediato. Precisará, siempre bajo control médico, tratamiento farmaceologico o quirúrgico. Alto Riesgo ante el Covid.";
		}
		
		cout<<"\n\t|______________________________________ ";
		//foutput<<"\n_____________________________________";
		
		
		cout<<"\n\t|\n\t| Datos ingresados correctamente";
		cout<<endl;
	
    	Guardar.close();
    	Leer.close();
    	system("pause");
    	system("cls");
		fflush(stdin);
    	menuexp();
	}else{
		cout<<"\n\t***Error en Archivo***";
	}
}

void insertarMedidas(Nodo *&frente, Nodo *&fin, ICO pacientes){
	//Declaro mi nuevo nodo
	Nodo *n_nodo = new Nodo();
	
	//Asignar los valores de los datos
	n_nodo -> pacientes = pacientes;
	
	//siguiente apunte a null
	n_nodo -> siguiente = NULL;
	
	//Primero verificar si esta vacia
	if(c_vacia(frente)){
		frente = n_nodo;
		//si la cola esta vacia frente = nuevo nodo
	}else{
		fin -> siguiente = n_nodo;//si la cola esta vacia
	}
	fin = n_nodo;
}

void editarExpediente(ICO pacientes){
	
	ofstream aux;
    ifstream lectura;
    bool encontrado=false;
    string auxFolio, auxFecha, auxHora, auxConsultorio;
	aux.open("auxiliar.txt",ios::out);
	lectura.open("ExpedienteCompleto.txt",ios::in);
	if(aux.is_open() && lectura.is_open()){
		cout<<"Ingresa Folio: ";
		cin>>auxFolio;
		lectura>>pacientes.folio;
		while(!lectura.eof()){
			lectura>> pacientes.enfercro >> pacientes.discapacidades >> pacientes.alergias >> pacientes.muneca >> pacientes.brazo >> pacientes.muslo>> pacientes.pantorrilla >> pacientes.cintura >> pacientes.cadera >> pacientes.humero >> pacientes.biceps >> pacientes.subescapular>> pacientes.triceps >> pacientes.suprailiaco >> pacientes.peso >> pacientes.altura >> pacientes.imc >> pacientes.diagnostico;
			if(auxFolio==pacientes.id_cita){
				encontrado=true;
				cout<<"\n\t|\n\t|Folio:";
		cin>>pacientes.folio;
		
		cout<<"\n\t|\n\t| Enfermedades Cronicas:";
		cin>>pacientes.enfercro;
		//foutput<<"\n\t|\n\t| Muñeca: "<< pacientes.enfercro;
		
		cout<<"\t| Discapacidades:";
		cin>>pacientes.discapacidades;
		//foutput<<"\n\t|\n\t| Discapacidades: "<< pacientes.discapacidades;
		
		cout<<"\t| Alergias:";
		cin>>pacientes.alergias;
		//foutput<<"\n\t|\n\t| Alergias: "<< pacientes.discapacidades;
		
		cout<<"\t|\n\t|________________________Indicadores Antropométricos___________________";
		//foutput<<"\n\t|\n\t|______________Indicadores Antropométricos_________________";
		cout<<"\n\t|\n\t| Los siguientes datos se registran en cm";
		
		cout<<"\n\t|\n\t| Muñeca del Paciente:";
		cin>>pacientes.muneca;
		//foutput<<"\n\t|\n\t| Muñeca: "<< pacientes.muneca <<"cm.";
		
		cout<<"\t| Brazo del Paciente:";
		cin>>pacientes.brazo;
		//foutput<<"\t| Brazo: "<< pacientes.brazo <<"cm.";
		
		cout<<"\t| Antebrazo del Paciente:";
		cin>>pacientes.antebrazo;
		//foutput<<"\t\t| Antebrazo: "<< pacientes.antebrazo <<"cm.";
		
		cout<<"\t| Muslo del Paciente:";
		cin>>pacientes.muslo;
		//foutput<<"\n\t| Muslo: "<< pacientes.muslo <<"cm.";
		
		cout<<"\t| Pantorrilla del Paciente:";
		cin>>pacientes.pantorrilla;
		//foutput<<"\t| Pantorrilla: "<< pacientes.pantorrilla <<"cm.";
		
		cout<<"\t| Cintura del Paciente:";
		cin>>pacientes.cintura;
		//foutput<<"\t| Cintura: "<< pacientes.cintura <<"cm.";
		
		cout<<"\t| Cadera del Paciente:";
		cin>>pacientes.cadera;
		//foutput<<"\n\t| Cadera: "<< pacientes.cadera <<"cm.";
		
		cout<<"\t| Humero del Paciente:";
		cin>>pacientes.humero;
		//foutput<<"\t| Humero: "<< pacientes.humero <<"cm.";
		
		cout<<"\t|___________________Pliegues o Panículos___________________";
		//foutput<<"\n\t|\n\t|_____________Pliegues o Panículos_____________";
		cout<<"\n\t|\n\t| Los siguientes datos se registran en mm";
		
		cout<<"\n\t|\n\t| Biceps del Paciente:";
		cin>>pacientes.biceps;
		//foutput<<"\n\t|\n\t| Biceps: "<< pacientes.biceps <<"mm.";
		
		cout<<"\t| Subescapular del Paciente:";
		cin>>pacientes.subescapular;
		//foutput<<"\t\t| Subescapular: "<< pacientes.subescapular <<"mm.";
		
		cout<<"\t| Triceps del Paciente:";
		cin>>pacientes.triceps;
		//foutput<<"\n\t| Triceps: "<< pacientes.triceps <<"mm.";
		
		cout<<"\t| Suprialiaco del Paciente:";
		cin>>pacientes.suprailiaco;
		//foutput<<"\t\t| Suprailiaco: "<< pacientes.suprailiaco <<"mm.";
		
		cout<<"\t|\n\t|_________________IMC___________________";
		//foutput<<"\n\t|\n\t|_______________IMC________________";
		
		cout<<"\n\t|\n\t| Ingresa Peso del Paciente en kilogramos:";
		cin>>pacientes.peso;
		//foutput<<"\n\t| Peso: "<< pacientes.peso;
		
		cout<<"\t| Ingresa Altura del Paciente en metros:";
		cin>>pacientes.altura;
		//foutput<<"\t\t| Altura: "<< pacientes.altura;

		pacientes.imc=((pacientes.peso)/(pacientes.altura*pacientes.altura));
	
		cout<<"\t| IMC: ";
		cout.precision(4);
		cout<<pacientes.imc;
		//foutput<<"\t\t| IMC: "<< pacientes.imc;
		
		aux<<pacientes.folio<<" "<<pacientes.enfercro<<" "<< pacientes.discapacidades<<" "<<pacientes.alergias<<" "<< pacientes.muneca<<" "<<pacientes.brazo<<" "<< pacientes.antebrazo<<" "<<pacientes.muslo<<" "<< pacientes.pantorrilla<<" "<<pacientes.cintura<<" "<< pacientes.cadera<<" "<<pacientes.humero<<" "<< pacientes.biceps<<" "<<pacientes.subescapular<<" "<< pacientes.triceps<<" "<<pacientes.suprailiaco<<" "<< pacientes.peso<<" "<<pacientes.altura<<" "<< pacientes.imc;
		
		if(pacientes.imc<16){
			cout<<"\n\t|\n\t| "<<pacientes.infrapeso;
			aux<<" "<<pacientes.infrapeso<<endl;
			//foutput<<"\n\t|\n\t| Infrapeso... Diagnostico: Dolencias Pulmonares, anorexia nerviosa, desnutrición, etc.";
		}else if(pacientes.imc>16 && pacientes.imc<18.5){
			cout<<"\n\t|\n\t| "<<pacientes.delgadez;
			aux<<" "<<pacientes.delgadez<<endl;
			//foutput<<"\n\t|\n\t| Delgadez... Diagnostico: Sin riesgo pero ten precaución de no adelgazar más.";
		}else if(pacientes.imc>18.5 && pacientes.imc<25){
			cout<<"\n\t|\n\t| "<<pacientes.normal;
			aux<<" "<<pacientes.normal<<endl;
			//foutput<<"\n\t|\n\t| Normal... Diagnostico: Estado Saludable.";
		}else if(pacientes.imc>26 && pacientes.imc<30){
			cout<<"\n\t|\n\t| "<<pacientes.obesidad;
			aux<<" "<<pacientes.obesidad<<endl;
			//foutput<<"\n\t|\n\t| Obesidad Tipo I... Diagnostico: Sobrecarga de articulaciones, cansancio excesivo y un cierto riesgo de enfermedades cardiovasculares.";
		}else if(pacientes.imc>30 && pacientes.imc<35){
			cout<<"\n\t|\n\t| "<<pacientes.obesidadd;
			aux<<" "<<pacientes.obesidadd<<endl;
			//foutput<<"\n\t|\n\t| Obesidad Tipo II... Diagnostico: Prblemas cardíacos, diabetes, hipertensión, enfermedad de vesícula y algunos cánceres. Alto Riesgo ante el Covid.";
		}else if(pacientes.imc>35 && pacientes.imc<40){
			cout<<"\n\t|\n\t| "<<pacientes.obesidaddd;
			aux<<" "<<pacientes.obesidaddd<<endl;
			//foutput<<"\n\t|\n\t| Obesidad Tipo III... Diagnostico: Serios riesgos para la salud, disminución de la calidad de vida. Visita un médico. Alto Riesgo ante el Covid.";
		}else if(pacientes.imc>40){
			cout<<"\n\t|\n\t| "<<pacientes.morbida;
			aux<<" "<<pacientes.morbida<<endl;
			//foutput<<"\n\t|\n\t| Obesidad Mórbida... Diagnostico: Riesgo inmediato. Precisará, siempre bajo control médico, tratamiento farmaceologico o quirúrgico. Alto Riesgo ante el Covid.";
		}
		
		cout<<"\n\t|_____________________________________________________________";
		//foutput<<"\n______|________________________________________________";
		
		
				
				cout<<pacientes.fecha<<"... "<<"\t| Ingresa Nueva Fecha:";
				cin>>auxFecha;
				cout<<pacientes.hora<<"... "<<"\t| Ingresa Nueva Hora:";
				cin>>auxHora;
				cout<<pacientes.consultorio<<"... "<<"\t| Ingresa Nueva Consultorio:";
				cin>>auxConsultorio;
				aux<<pacientes.id_cita<<" "<<pacientes.app<<" "<<pacientes.apm<<" "<<pacientes.nombre<<" "<<auxFecha<<" "<<auxHora<<" "<<auxConsultorio<<endl;
				
				cout<<"\t|\n\t| Registro Modificado"<<endl<<endl;
			}else{
				aux<<pacientes.folio<<" "<<pacientes.app<<" "<<pacientes.apm<<" "<<pacientes.nombre<<" "<<pacientes.fecha<<" "<<pacientes.hora<<" "<<pacientes.consultorio<<endl;
			}
			lectura>>pacientes.folio;
		}
	}else{
		cout<<"Error de Archivo";
	}
	if(encontrado==false){
		cout<<"\n\t| Sin Registros";
	}
	aux.close();
	lectura.close();
	remove("Citas.txt");
	rename("auxiliar.txt", "Citas.txt");
    system("pause");
    cout<<endl;
    system("cls");
	fflush(stdin);
    menuexp();
}

void eliminarExpediente(ICO pacientes){
	ofstream aux;
    ifstream lectura;
    bool encontrado=false;
    string auxFolio, auxFecha, auxHora, auxConsultorio;
	aux.open("auxiliar.txt",ios::out);
	lectura.open("ExpedienteCompleto.txt",ios::in);
	if(aux.is_open() && lectura.is_open()){
		cout<<"Ingresa Folio: ";
		cin>>auxFolio;
		lectura>>pacientes.folio;
		while(!lectura.eof()){
			lectura>> pacientes.enfercro >> pacientes.discapacidades >> pacientes.alergias >> pacientes.muneca >> pacientes.brazo >> pacientes.muslo>> pacientes.pantorrilla >> pacientes.cintura >> pacientes.cadera >> pacientes.humero >> pacientes.biceps >> pacientes.subescapular>> pacientes.triceps >> pacientes.suprailiaco >> pacientes.peso >> pacientes.altura >> pacientes.imc >> pacientes.diagnostico;
			if(auxFolio==pacientes.folio){
				encontrado=true;
				cout<<"\t|\n\t| Expediente Eliminado"<<endl<<endl;
			}else{
				aux<<pacientes.folio<<" "<<pacientes.app<<" "<<pacientes.apm<<" "<<pacientes.nombre<<" "<<pacientes.fecha<<" "<<pacientes.hora<<" "<<pacientes.consultorio<<endl;
			}
			lectura>>pacientes.folio;
		}
	}else{
		cout<<"Error de Archivo";
	}
	if(encontrado==false){
		cout<<"\n\t| Sin Registros";
	}
	aux.close();
	lectura.close();
	remove("ExpedienteCompleto.txt");
	rename("auxiliar.txt", "ExpedienteCompleto.txt");
    system("pause");
    cout<<endl;
    system("cls");
	fflush(stdin);
    menuexp();
}

void consultarExpedientes(ICO pacientes){
	ifstream Leer;
	Leer.open("ExpedienteCompleto.txt");
	Leer>> pacientes.enfercro >> pacientes.discapacidades >> pacientes.alergias >> pacientes.muneca >> pacientes.brazo >> pacientes.antebrazo >> pacientes.muslo >> pacientes.pantorrilla >> pacientes.cintura >> pacientes.cadera >> pacientes.humero >> pacientes.biceps >> pacientes.subescapular >> pacientes.triceps >> pacientes.suprailiaco >> pacientes.peso >> pacientes.altura >> pacientes.imc >> pacientes.diagnostico;
	while(!Leer.eof()){
		Leer>>pacientes.folio;
			cout<<"|____________________________________________________";
			cout<<"\n\t|\n\t|____Expediente Clinico____";
			
			cout<<"\n\t|\n\t| Enfermedades Cronicas: "<<pacientes.enfercro;
			
			cout<<"\t| Discapacidades: "<<pacientes.discapacidades;
			
			cout<<"\t| Alergias: "<<pacientes.alergias;
			
			cout<<"\n\t|\n\t|___Indicadores Antropométricos____";
			
			cout<<"\n\t|\n\t| Muñeca del Paciente: "<<pacientes.muneca<< " cm.";
			
			cout<<"\t| Brazo del Paciente: "<<pacientes.brazo<< " cm.";
			
			cout<<"\t| Antebrazo del Paciente: "<<pacientes.antebrazo<< " cm.";
			
			cout<<"\n\t|\n\t| Muslo del Paciente: "<<pacientes.muslo<< " cm.";
			
			cout<<"\t| Pantorrilla del Paciente: "<<pacientes.pantorrilla<< " cm.";
			
			cout<<"\t| Cintura del Paciente: "<<pacientes.cintura<< " cm.";
			
			cout<<"\n\t|\n\t| Cad.era del Paciente: "<<pacientes.cadera<< " cm.";
			
			cout<<"\t| Humero del Paciente: "<<pacientes.humero<< " cm.";
			
			cout<<"\n\t|\n\t|______Pliegues o Panículos______";
			
			cout<<"\n\t|\n\t| Biceps del Paciente: "<<pacientes.biceps<< " mm.";
			
			cout<<"\t| Subescapular del Paciente: "<<pacientes.subescapular<< " mm.";
			
			cout<<"\t| Triceps del Paciente: "<<pacientes.triceps<< " mm.";
			
			cout<<"\n\t|\n\t| Suprialiaco del Paciente: "<<pacientes.suprailiaco<< " mm.";
			
			cout<<"\n\t|\n\t|______IMC_____";
			
			cout<<"\n\t|\n\t| Peso: "<<pacientes.peso<< " kg.";
			
			cout<<"\t| Altura: "<<pacientes.altura<< " m.";
		
			cout.precision(4);
			cout<<"\t| IMC: "<<pacientes.imc;
			
			cout<<"\n\t|\n\t| Diagnostico: "<<pacientes.diagnostico;
			
			cout<<"\t|Folio: "<<pacientes.folio;
			
			cout<<"\n________|______________________________________________";
			cout<<"\n\n";
			Leer>> pacientes.enfercro >> pacientes.discapacidades >> pacientes.alergias >> pacientes.muneca >> pacientes.brazo >> pacientes.antebrazo >> pacientes.muslo >> pacientes.pantorrilla >> pacientes.cintura >> pacientes.cadera >> pacientes.humero >> pacientes.biceps >> pacientes.subescapular >> pacientes.triceps >> pacientes.suprailiaco >> pacientes.peso >> pacientes.altura >> pacientes.imc >> pacientes.diagnostico;
	}
	
	Leer.close();
	
    system("pause");
    cout<<endl;
    system("cls");
    fflush(stdin);
    menuexp();
}

void consultarExpc(ICO pacientes){
	
	ifstream Leer;
	Leer.open("ExpedienteCompleto.txt");
	
	bool encontrado=false;
    cout<<"\t|\n\t| Ingrese Folio: |";
    cin>>pacientes.folioaux;
    
    while(Leer>> pacientes.folio >> pacientes.enfercro >> pacientes.discapacidades >> pacientes.alergias >> pacientes.muneca >> pacientes.brazo >> pacientes.antebrazo >> pacientes.muslo >> pacientes.pantorrilla >> pacientes.cintura >> pacientes.cadera >> pacientes.humero >> pacientes.biceps >> pacientes.subescapular >> pacientes.triceps >> pacientes.suprailiaco >> pacientes.peso >> pacientes.altura >> pacientes.imc >> pacientes.diagnostico){
		
		if(pacientes.folio==pacientes.folioaux){
			
			encontrado=true;
		
    		cout<<"|___________________________________________________";
			cout<<"\n\t|\n\t|        Expediente Clinico        ";
			
			cout<<"\n\t|\n\t| Enfermedades Cronicas: "<<pacientes.enfercro;
			
			cout<<"\t| Discapacidades: "<<pacientes.discapacidades;
			
			cout<<"\t| Alergias: "<<pacientes.alergias;
			
			cout<<"\n\t|\n\t|___Indicadores Antropométricos____";
			
			cout<<"\n\t|\n\t| Muñeca del Paciente: "<<pacientes.muneca<< " cm.";
			
			cout<<"\t| Brazo del Paciente: "<<pacientes.brazo<< " cm.";
			
			cout<<"\t| Antebrazo del Paciente: "<<pacientes.antebrazo<< " cm.";
			
			cout<<"\n\t|\n\t| Muslo del Paciente: "<<pacientes.muslo<< " cm.";
			
			cout<<"\t| Pantorrilla del Paciente: "<<pacientes.pantorrilla<< " cm.";
			
			cout<<"\t| Cintura del Paciente: "<<pacientes.cintura<< " cm.";
			
			cout<<"\n\t|\n\t| Cadera del Paciente: "<<pacientes.cadera<< " cm.";
			
			cout<<"\t| Humero del Paciente: "<<pacientes.humero<< " cm.";
			
			cout<<"\n\t|\n\t|____Pliegues o Panículos_____";
			
			cout<<"\n\t|\n\t| Biceps del Paciente: "<<pacientes.biceps<< " mm.";
			
			cout<<"\t| Subescapular del Paciente: "<<pacientes.subescapular<< " mm.";
			
			cout<<"\t| Triceps del Paciente: "<<pacientes.triceps<< " mm.";
			
			cout<<"\n\t|\n\t| Suprialiaco del Paciente: "<<pacientes.suprailiaco<< " mm. ";
			
			cout<<"\n\t|\n\t| IMC ";
			
			cout<<"\n\t|\n\t| Peso: "<<pacientes.peso<< " kg.";
			
			cout<<"\t| Altura: "<<pacientes.altura<< " m.";
		
			cout.precision(4);
			cout<<"\t| IMC: "<<pacientes.imc;
			
			cout<<"\n\t|\n\t| Diagnostico: "<<pacientes.diagnostico;
			
			cout<<"\n\t|\n\t|Folio: "<<pacientes.folio;
			
			cout<<"\n________|___________________________________________________";
			cout<<"\n\n";
		}
	}
    if(encontrado==false){
    	cout<<"\t| Expediente Sin Registro\n";
	}
    Leer.close();
    
    system("pause");
    cout<<endl;
    system("cls");
    fflush(stdin);
    menuexp();
	
}
//CITAS

//User
void agregarCitas(ICO &pacientes){
	
	char opcion;
	
	//ofstream foutput;
	ofstream Guardar;
	ifstream Leer;
	
	//foutput.open ("Citas.txt",ios::app);
	Guardar.open ("Citas.txt",ios::app);
    //finput.open ("Citas.txt");
    Leer.open("Citas.txt");
	
	if(Leer.is_open()){
		
		cout<<"\n\t_________________________________________";
		//foutput<<"\n______________________________________";
		cout<<"\n\t|\n\t|                Citas              ";
		//foutput<<"\n\t|\n\t|  Citas  ;  
		
		cout<<"\n\t|\n\t| ID Cita:";
		cin>>pacientes.id_cita;
		//foutput<<"\n\t|\n\t| ID Cita: "<< pacientes.id_cita;
		
		cout<<"\t|\n\t| Apellido Paterno:";
		cin>>pacientes.app;
		//foutput<<"\n\t|\n\t| Apellido Paterno: "<< pacientes.app;
		
		cout<<"\t| Apellido Materno:";
		cin>>pacientes.apm;
		//foutput<<"\t| Apellido Materno: "<< pacientes.apm;
		
		cout<<"\t| Nombre:";
		cin>>pacientes.nombre;
		//foutput<<"\t| Nombre: "<< pacientes.nombre;
		
		Guardar<<pacientes.id_cita<<" "<< pacientes.app<<" "<<pacientes.apm<<" "<< pacientes.nombre;
		
		cout<<"\t| Selecciona una Fecha: |";
		cout<<"\n\t| 1) "<<pacientes.fecha1;
		cout<<"\n\t| 2) "<<pacientes.fecha2;
		cout<<"\n\t| 3) "<<pacientes.fecha3;
		cout<<"\n\t| Opción:";
		cin>>opcion; 
		fflush(stdin);
		
		switch(opcion){
			case '1':
				cout<<"\t|\n\t| Fecha: "<<pacientes.fecha1;
				cout<<endl;
				//foutput<<"\n\t|\n\t| Fecha: "<< pacientes.fecha1;
				Guardar<<" "<<pacientes.fecha1;
				
				cout<<"\t|\n\t| Selecciona una Hora: |";
				cout<<"\n\t| 1)"<<pacientes.hora1;
				cout<<"\n\t| 2)"<<pacientes.hora2;
				cout<<"\n\t| 3)"<<pacientes.hora3;
				cout<<"\n\t| Opción:";
				cin>>opcion; 
				fflush(stdin);
				
				switch(opcion){
					case '1':
						cout<<"\t|\n\t| Hora: "<<pacientes.hora1;
						cout<<endl;
						//foutput<<"\t| Hora: "<< pacientes.hora1;
						Guardar<<" "<<pacientes.hora1;
				
						cout<<"\t|\n\t| Selecciona un Consultorio: |";
						cout<<"\n\t| 1)"<<pacientes.consultorio1;
						cout<<"\n\t| 2)"<<pacientes.consultorio2;
						cout<<"\n\t| 3)"<<pacientes.consultorio3;
						cout<<"\n\t| Opción: ";
						cin>>opcion; 
						fflush(stdin);
						
						
						switch(opcion){
							case '1':
								cout<<"\t|\n\t| Consultorio:"<<pacientes.consultorio1;
								//foutput<<"\t| Consultorio: "<< pacientes.consultorio1;
								Guardar<<" "<<pacientes.consultorio1;
							break;
			
							case '2':
								cout<<"\t|\n\t| Consultorio:"<<pacientes.consultorio2;
								//foutput<<"\t| Consultorio: "<< pacientes.consultorio2;
								Guardar<<" "<<pacientes.consultorio2;
							break;
			
							case '3':
								cout<<"\t|\n\t| Consultorio:"<<pacientes.consultorio3;
								//foutput<<"\t| Consultorio: "<< pacientes.consultorio3;
								Guardar<<" "<<pacientes.consultorio3;
							break;
							
							default:
								cout<<"\n\tOpción Invalida\n";
							break;
						}
					break;
			
					case '2':
						cout<<"\t|\n\t| Hora: "<<pacientes.hora2;
						cout<<endl;
						//foutput<<"\t| Hora: "<< pacientes.hora2;
						Guardar<<" "<<pacientes.hora2;
				
						cout<<"\t|\n\t| Selecciona un Consultorio: |";
						cout<<"\n\t| 1)"<<pacientes.consultorio1;
						cout<<"\n\t| 2)"<<pacientes.consultorio2;
						cout<<"\n\t| 3)"<<pacientes.consultorio3;
						cout<<"\n\t| Opción: ";
						cin>>opcion; 
						fflush(stdin);
						
						switch(opcion){
							case '1':
								cout<<"\t|\n\t| Consultorio: "<<pacientes.consultorio1;
								//foutput<<"\t| Consultorio: "<< pacientes.consultorio1;
								Guardar<<" "<<pacientes.consultorio1;
							break;
			
							case '2':
								cout<<"\t|\n\t| Consultorio: "<<pacientes.consultorio2;
								//foutput<<"\t| Consultorio: "<< pacientes.consultorio2;
								Guardar<<" "<<pacientes.consultorio2;
							break;
			
							case '3':
								cout<<"\t|\n\t| Consultorio: "<<pacientes.consultorio3;
								//foutput<<"\t| Consultorio: "<< pacientes.consultorio3;
								Guardar<<" "<<pacientes.consultorio3;
							break;
			                
							default:
								cout<<"\n\tOpción Invalida\n";
							break;
						}
					break;
			
					case '3':
						cout<<"\t|\n\t| Hora: "<<pacientes.hora3;
						cout<<endl;
						//foutput<<"\t| Hora: "<< pacientes.hora3;
						Guardar<<" "<<pacientes.hora3;
				
						cout<<"\t|\n\t| Selecciona un Consultorio: |";
						cout<<"\n\t| 1)"<<pacientes.consultorio1;
						cout<<"\n\t| 2)"<<pacientes.consultorio2;
						cout<<"\n\t| 3)"<<pacientes.consultorio3;
						cout<<"\n\t| Opción: ";
						cin>>opcion; 
						fflush(stdin);
						
						switch(opcion){
							case '1':
								cout<<"\t|\n\t| Consultorio: "<<pacientes.consultorio1;
								//foutput<<"\t| Consultorio: "<< pacientes.consultorio1;
								Guardar<<" "<<pacientes.consultorio1;
							break;
			
							case '2':
								cout<<"\t|\n\t| Consultorio: "<<pacientes.consultorio2;
								//foutput<<"\t| Consultorio: "<< pacientes.consultorio2;
								Guardar<<" "<<pacientes.consultorio2;
							break;
			
							case '3':
								cout<<"\t|\n\t| Consultorio: "<<pacientes.consultorio3;
								//foutput<<"\t| Consultorio: "<< pacientes.consultorio3;
								Guardar<<" "<<pacientes.consultorio3;
							break;
			                
							default:
								cout<<"\n\tOpción Invalida\n";
							break;
						}
					break;
			
					default:
						cout<<"\n\tOpción Invalida\n";
					break;
				}
			break;
			
			case '2':
				cout<<"\t|\n\t| Fecha: "<<pacientes.fecha2;
				cout<<endl;
				//foutput<<"\n\t|\n\t| Fecha: "<< pacientes.fecha2;
				Guardar<<" "<<pacientes.fecha2;
				
				cout<<"\t|\n\t| Selecciona una Hora: |";
				cout<<"\n\t| 1)"<<pacientes.hora1;
				cout<<"\n\t| 2)"<<pacientes.hora2;
				cout<<"\n\t| 3)"<<pacientes.hora3;
				cout<<"\n\t| Opción: ";
				cin>>opcion; 
				fflush(stdin);
				
				switch(opcion){
					case '1':
						cout<<"\t|\n\t| Hora: "<<pacientes.hora1;
						cout<<endl;
						//foutput<<"\t| Hora: "<< pacientes.hora1;
						Guardar<<" "<<pacientes.hora1;
				
						cout<<"\t|\n\t| Selecciona un Consultorio: |";
						cout<<"\n\t| 1)"<<pacientes.consultorio1;
						cout<<"\n\t| 2)"<<pacientes.consultorio2;
						cout<<"\n\t| 3)"<<pacientes.consultorio3;
						cout<<"\n\t| Opción: ";
						cin>>opcion; 
						fflush(stdin);
						
						
						switch(opcion){
							case '1':
								cout<<"\t|\n\t| Consultorio: "<<pacientes.consultorio1;
								//foutput<<"\t| Consultorio: "<< pacientes.consultorio1;
								Guardar<<" "<<pacientes.consultorio1;
							break;
			
							case '2':
								cout<<"\t|\n\t| Consultorio: "<<pacientes.consultorio2;
								//foutput<<"\t| Consultorio: "<< pacientes.consultorio2;
								Guardar<<" "<<pacientes.consultorio2;
							break;
			
							case '3':
								cout<<"\t|\n\t| Consultorio: "<<pacientes.consultorio3;
								//foutput<<"\t| Consultorio: "<< pacientes.consultorio3;
								Guardar<<" "<<pacientes.consultorio3;
							break;
		
							default:
								cout<<"\n\tOpción Invalida\n";
							break;
						}
					break;
			
					case '2':
						cout<<"\t|\n\t| Hora: "<<pacientes.hora2;
						cout<<endl;
						//foutput<<"\t| Hora: "<< pacientes.hora2;
						Guardar<<" "<<pacientes.hora2;
				
						cout<<"\t|\n\t| Selecciona un Consultorio: |";
						cout<<"\n\t| 1)"<<pacientes.consultorio1;
						cout<<"\n\t| 2)"<<pacientes.consultorio2;
						cout<<"\n\t| 3)"<<pacientes.consultorio3;
						cout<<"\n\t| Opción: ";
						cin>>opcion; 
						fflush(stdin);
						
						switch(opcion){
							case '1':
								cout<<"\t|\n\t| Consultorio: "<<pacientes.consultorio1;
								//foutput<<"\t| Consultorio: "<< pacientes.consultorio1;
								Guardar<<" "<<pacientes.consultorio1;
							break;
			
							case '2':
								cout<<"\t|\n\t| Consultorio: "<<pacientes.consultorio2;
								//foutput<<"\t| Consultorio: "<< pacientes.consultorio2;
								Guardar<<" "<<pacientes.consultorio2;
							break;
			
							case '3':
								cout<<"\t|\n\t| Consultorio: "<<pacientes.consultorio3;
								//foutput<<"\t| Consultorio: "<< pacientes.consultorio3;
								Guardar<<" "<<pacientes.consultorio3;
							break;
			                
							default:
								cout<<"\n\tOpción Invalida\n";
							break;
						}
					break;
			
					case '3':
						cout<<"\t|\n\t| Hora: "<<pacientes.hora3;
						cout<<endl;
						//foutput<<"\t| Hora: "<< pacientes.hora3;
						Guardar<<" "<<pacientes.hora3;
				
						cout<<"\t|\n\t| Selecciona un Consultorio: |";
						cout<<"\n\t| 1)"<<pacientes.consultorio1;
						cout<<"\n\t| 2)"<<pacientes.consultorio2;
						cout<<"\n\t| 3)"<<pacientes.consultorio3;
						cout<<"\n\t| Opción: ";
						cin>>opcion; 
						fflush(stdin);
						
						switch(opcion){
							case '1':
								cout<<"\t|\n\t| Consultorio: "<<pacientes.consultorio1;
								//foutput<<"\t| Consultorio: "<< pacientes.consultorio1;
								Guardar<<" "<<pacientes.consultorio1;
							break;
			
							case '2':
								cout<<"\t|\n\t| Consultorio: "<<pacientes.consultorio2;
								//foutput<<"\t| Consultorio: "<< pacientes.consultorio2;
								Guardar<<" "<<pacientes.consultorio2;
							break;
			
							case '3':
								cout<<"\t|\n\t| Consultorio: "<<pacientes.consultorio3;
								//foutput<<"\t| Consultorio: "<< pacientes.consultorio3;
								Guardar<<" "<<pacientes.consultorio3;
							break;
			                
							default:
								cout<<"\n\tOpción Invalida\n";
							break;
						}
					break;
			
					default:
						cout<<"\n\tOpción Invalida\n";
					break;
				}
			break;
			
			case '3':
				cout<<"\t|\n\t| Fecha: "<<pacientes.fecha3;
				cout<<endl;
				//foutput<<"\n\t|\n\t| Fecha: "<< pacientes.fecha3;
				Guardar<<" "<<pacientes.fecha3;
				
				cout<<"\t|\n\t| Selecciona una Hora: |";
				cout<<"\n\t| 1)"<<pacientes.hora1;
				cout<<"\n\t| 2)"<<pacientes.hora2;
				cout<<"\n\t| 3)"<<pacientes.hora3;
				cout<<"\n\t| Opción: ";
				cin>>opcion; 
				fflush(stdin);
				
				switch(opcion){
					case '1':
						cout<<"\t|\n\t| Hora: "<<pacientes.hora1;
						cout<<endl;
						//foutput<<"\t| Hora: "<< pacientes.hora1;
						Guardar<<" "<<pacientes.hora1;
				
						cout<<"\t|\n\t| Selecciona un Consultorio: |";
						cout<<"\n\t| 1)"<<pacientes.consultorio1;
						cout<<"\n\t| 2)"<<pacientes.consultorio2;
						cout<<"\n\t| 3)"<<pacientes.consultorio3;
						cout<<"\n\t| Opción: ";
						cin>>opcion; 
						fflush(stdin);
						
						
						switch(opcion){
							case '1':
								cout<<"\t|\n\t| Consultorio: "<<pacientes.consultorio1;
								//foutput<<"\t| Consultorio: "<< pacientes.consultorio1;
								Guardar<<" "<<pacientes.consultorio1;
							break;
			
							case '2':
								cout<<"\t|\n\t| Consultorio: "<<pacientes.consultorio2;
								//foutput<<"\t| Consultorio: "<< pacientes.consultorio2;
								Guardar<<" "<<pacientes.consultorio2;
							break;
			
							case '3':
								cout<<"\t|\n\t| Consultorio: "<<pacientes.consultorio3;
								//foutput<<"\t| Consultorio: "<< pacientes.consultorio3;
								Guardar<<" "<<pacientes.consultorio3;
							break;
			
							default:
								cout<<"\n\tOpción Invalida\n";
							break;
						}
					break;
			
					case '2':
						cout<<"\t|\n\t| Hora: "<<pacientes.hora2;
						cout<<endl;
						//foutput<<"\t| Hora: "<< pacientes.hora2;
						Guardar<<" "<<pacientes.hora2;
				
						cout<<"\t|\n\t| Selecciona un Consultorio: |";
						cout<<"\n\t| 1)"<<pacientes.consultorio1;
						cout<<"\n\t| 2)"<<pacientes.consultorio2;
						cout<<"\n\t| 3)"<<pacientes.consultorio3;
						cout<<"\n\t| Opción: ";
						cin>>opcion; 
						fflush(stdin);
						
						switch(opcion){
							case '1':
								cout<<"\t|\n\t| Consultorio: "<<pacientes.consultorio1;
								//foutput<<"\t| Consultorio: "<< pacientes.consultorio1;
								Guardar<<" "<<pacientes.consultorio1;
							break;
			
							case '2':
								cout<<"\t|\n\t| Consultorio: "<<pacientes.consultorio2;
								//foutput<<"\t| Consultorio: "<< pacientes.consultorio2;
								Guardar<<" "<<pacientes.consultorio2;
							break;
			
							case '3':
								cout<<"\t|\n\t| Consultorio: "<<pacientes.consultorio3;
								//foutput<<"\t| Consultorio: "<< pacientes.consultorio3;
								Guardar<<" "<<pacientes.consultorio3;
							break;
			
							default:
								cout<<"\n\tOpción Invalida\n";
							break;
						}
					break;
			
					case '3':
						cout<<"\t|\n\t| Hora: "<<pacientes.hora3;
						cout<<endl;
						//foutput<<"\t| Hora: "<< pacientes.hora3;
						Guardar<<" "<<pacientes.hora3;
				
						cout<<"\t|\n\t| Selecciona un Consultorio: |";
						cout<<"\n\t| 1)"<<pacientes.consultorio1;
						cout<<"\n\t| 2)"<<pacientes.consultorio2;
						cout<<"\n\t| 3)"<<pacientes.consultorio3;
						cout<<"\n\t| Opción: ";
						cin>>opcion; 
						fflush(stdin);
						
						switch(opcion){
							case '1':
								cout<<"\t|\n\t| Consultorio: "<<pacientes.consultorio1;
								//foutput<<"\t| Consultorio: "<< pacientes.consultorio1;
								Guardar<<" "<<pacientes.consultorio1;
							break;
			
							case '2':
								cout<<"\t|\n\t| Consultorio: "<<pacientes.consultorio2;
								//foutput<<"\t| Consultorio: "<< pacientes.consultorio2;
								Guardar<<" "<<pacientes.consultorio2;
							break;
			
							case '3':
								cout<<"\t|\n\t| Consultorio: "<<pacientes.consultorio3;
								//foutput<<"\t| Consultorio: "<< pacientes.consultorio3;
								Guardar<<" "<<pacientes.consultorio3;
							break;
			
							default:
								cout<<"\n\tOpción Invalida\n";
							break;
						}
					break;
			
					default:
						cout<<"\n\tOpción Invalida\n";
					break;
				}
			break;
						
				default:
					cout<<"\n\tOpción Invalida\n";
				break;
			}		
		
		Guardar<<endl;
		
		cout<<"\n\t|______________________________________________";
		//foutput<<"\n______|_____________________________________";
		
		
		cout<<"\n\t| Datos ingresados correctamente |";
	
    	Guardar.close();
    	Leer.close();
    	system("pause");
    	cout<<endl;
    	system("cls");
		fflush(stdin);
    	menuuser();
	}else{
		cout<<"\n\t***Error en Archivo***";
	}
}

void insertarCitas(Nodo *&frente, Nodo *&fin, ICO pacientes){
	//Declaro mi nuevo nodo
	Nodo *n_nodo = new Nodo();
	
	//Asignar los valores de los datos
	n_nodo -> pacientes = pacientes;
	
	//siguiente apunte a null
	n_nodo -> siguiente = NULL;
	
	//Primero verificar si esta vacia
	if(c_vacia(frente)){
		frente = n_nodo;
		//si la cola esta vacia frente = nuevo nodo
	}else{
		fin -> siguiente = n_nodo;//si la cola esta vacia
	}
	fin = n_nodo;
}

void buscarCita(ICO pacientes){
	
	ifstream Leer;
	Leer.open("Citas.txt");
	
	bool encontrado=false;
    cout<<"\t|\n\t| Ingrese ID Cita: ";
    cin>>pacientes.idaux;
    
    while(Leer>> pacientes.id_cita >> pacientes.app >> pacientes.apm >> pacientes.nombre >> pacientes.fecha >> pacientes.hora >> pacientes.consultorio){
		
		if(pacientes.id_cita==pacientes.idaux){
			
			encontrado=true;
		
    		cout<<"|_________________________________________________";
			cout<<"\n\t|\n\t|  Cita ";
			
			cout<<"\n\t|\n\t| Apellido Paterno: "<< pacientes.app;
			
			cout<<"\t| Apellido Materno: "<< pacientes.apm;
			
			cout<<"\t| Nombre: "<< pacientes.nombre;
			
			cout<<"\n\t|\n\t| Fecha: "<< pacientes.fecha;
			
			cout<<"\t| Hora: "<< pacientes.hora;
			
			cout<<"\t| Consultorio: "<< pacientes.consultorio;
			
			cout<<"\t| ID Cita: "<< pacientes.id_cita;
			
			cout<<"\n________|________________________________________";
			cout<<"\n\n";
		}
	}
    if(encontrado==false){
    	cout<<"\t| Cita Sin Registro\n";
	}
    Leer.close();
    
    system("pause");
    cout<<endl;
    system("cls");
    fflush(stdin);
    menuuser();
}

//Admin
void consultarCitas(ICO pacientes){
	ifstream Leer;
	Leer.open("Citas.txt");
	Leer>> pacientes.app >> pacientes.apm >> pacientes.nombre >> pacientes.fecha >> pacientes.hora >> pacientes.consultorio;
	while(!Leer.eof()){
		Leer>>pacientes.id_cita;
			cout<<"|___________________________________________________";
			cout<<"\n\t|\n\t|          Cita          ";
			
			cout<<"\n\t|\n\t| Apellido Paterno: "<< pacientes.app;
			
			cout<<"\t| Apellido Materno: "<< pacientes.apm;
			
			cout<<"\t| Nombre: "<< pacientes.nombre;
			
			cout<<"\n\t|\n\t| Fecha: "<< pacientes.fecha;
			
			cout<<"\t| Hora: "<< pacientes.hora;
			
			cout<<"\t| Consultorio: "<< pacientes.consultorio;
			
			cout<<"\t| ID Cita: "<< pacientes.id_cita;
			
			cout<<"\n________|___________________________________________";
			cout<<"\n\n";
			Leer>> pacientes.app >> pacientes.apm >> pacientes.nombre >> pacientes.fecha >> pacientes.hora >> pacientes.consultorio;
	}
	
	Leer.close();
	
    system("pause");
    cout<<endl;
    system("cls");
    fflush(stdin);
    menucita();
}

void consultarCita(ICO pacientes){
	ifstream Leer;
	Leer.open("Citas.txt");
	
	bool encontrado=false;
    cout<<"\t|\n\t| Ingrese ID Cita: ";
    cin>>pacientes.idaux;
    
    while(Leer>> pacientes.id_cita >> pacientes.app >> pacientes.apm >> pacientes.nombre >> pacientes.fecha >> pacientes.hora >> pacientes.consultorio){
		
		if(pacientes.id_cita==pacientes.idaux){
			
			encontrado=true;
		
    		cout<<"|_______________________________________________";
			cout<<"\n\t|\n\t|    Cita    ";
			
			cout<<"\n\t|\n\t| Apellido Paterno: "<< pacientes.app;
			
			cout<<"\t| Apellido Materno: "<< pacientes.apm;
			
			cout<<"\t| Nombre: "<< pacientes.nombre;
			
			cout<<"\n\t|\n\t| Fecha: "<< pacientes.fecha;
			
			cout<<"\t| Hora: "<< pacientes.hora;
			
			cout<<"\t| Consultorio: "<< pacientes.consultorio;
			
			cout<<"\t| ID Cita: "<< pacientes.id_cita;
			
			cout<<"\n|____________________________________________";
			cout<<"\n\n";
		}
	}
    if(encontrado==false){
    	cout<<"\t| Cita Sin Registro\n";
	}
    Leer.close();
    
    system("pause");
    cout<<endl;
    system("cls");
    fflush(stdin);
    menucita();
}

//Admin
void editarCita(ICO pacientes){
    
    ofstream aux;
    ifstream lectura;
    bool encontrado=false;
    string auxClave, auxFecha, auxHora, auxConsultorio;
	aux.open("auxiliar.txt",ios::out);
	lectura.open("Citas.txt",ios::in);
	if(aux.is_open() && lectura.is_open()){
		cout<<"Ingresa ID Cita: ";
		cin>>auxClave;
		lectura>>pacientes.id_cita;
		while(!lectura.eof()){
			lectura>> pacientes.app >> pacientes.apm >> pacientes.nombre >> pacientes.fecha >> pacientes.hora >> pacientes.consultorio;
			if(auxClave==pacientes.id_cita){
				encontrado=true;
				cout<<"|________________________________________________";
				cout<<"\n\t|\n\t|         Cita      ";
				
				cout<<"\n\t|\n\t| Apellido Paterno: "<< pacientes.app;
				
				cout<<"\t| Apellido Materno: "<< pacientes.apm;
				
				cout<<"\t| Nombre: "<< pacientes.nombre;
				
				cout<<"\n\t|\n\t| Fecha: "<< pacientes.fecha;
				
				cout<<"\t| Hora: "<< pacientes.hora;
				
				cout<<"\t| Consultorio: "<< pacientes.consultorio;
				
				cout<<"\t| ID Cita: "<< pacientes.id_cita;
				
				cout<<"\n________|______________________________________";
				cout<<"\n\t|\n";
				
				cout<<pacientes.fecha<<"... "<<"\t| Ingresa Nueva Fecha:";
				cin>>auxFecha;
				cout<<pacientes.hora<<"... "<<"\t| Ingresa Nueva Hora:";
				cin>>auxHora;
				cout<<pacientes.consultorio<<"... "<<"\t| Ingresa Nueva Consultorio:";
				cin>>auxConsultorio;
				aux<<pacientes.id_cita<<" "<<pacientes.app<<" "<<pacientes.apm<<" "<<pacientes.nombre<<" "<<auxFecha<<" "<<auxHora<<" "<<auxConsultorio<<endl;
				
				cout<<"\t|\n\t| Registro Modificado"<<endl<<endl;
			}else{
				aux<<pacientes.id_cita<<" "<<pacientes.app<<" "<<pacientes.apm<<" "<<pacientes.nombre<<" "<<pacientes.fecha<<" "<<pacientes.hora<<" "<<pacientes.consultorio<<endl;
			}
			lectura>>pacientes.id_cita;
		}
	}else{
		cout<<"Error de Archivo";
	}
	if(encontrado==false){
		cout<<"\n\t| Sin Registros";
	}
	aux.close();
	lectura.close();
	remove("Citas.txt");
	rename("auxiliar.txt", "Citas.txt");
    system("pause");
    cout<<endl;
    system("cls");
	fflush(stdin);
    menucita();
}

void eliminarCita(ICO pacientes){
	ofstream aux;
    ifstream lectura;
    bool encontrado=false;
    string auxClave, auxFecha, auxHora, auxConsultorio;
	aux.open("auxiliar.txt",ios::out);
	lectura.open("Citas.txt",ios::in);
	if(aux.is_open() && lectura.is_open()){
		cout<<"Ingresa ID Cita: ";
		cin>>auxClave;
		lectura>>pacientes.id_cita;
		while(!lectura.eof()){
			lectura>> pacientes.app >> pacientes.apm >> pacientes.nombre >> pacientes.fecha >> pacientes.hora >> pacientes.consultorio;
			if(auxClave==pacientes.id_cita){
				encontrado=true;
				cout<<"\t|\n\t| Cita Eliminada"<<endl<<endl;
			}else{
				aux<<pacientes.id_cita<<" "<<pacientes.app<<" "<<pacientes.apm<<" "<<pacientes.nombre<<" "<<pacientes.fecha<<" "<<pacientes.hora<<" "<<pacientes.consultorio<<endl;
			}
			lectura>>pacientes.id_cita;
		}
	}else{
		cout<<"Error de Archivo";
	}
	if(encontrado==false){
		cout<<"\n\t| Sin Registros";
	}
	aux.close();
	lectura.close();
	remove("Citas.txt");
	rename("auxiliar.txt", "Citas.txt");
    system("pause");
    cout<<endl;
    system("cls");
	fflush(stdin);
    menucita();
}

bool c_vacia(Nodo *frente){
	//Operador Ternario para saber si esta vacia
	return(frente == NULL)? true:false;
}


