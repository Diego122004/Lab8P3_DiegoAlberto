#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Partido.h"
#include "Candidato.h"
#include "Departamento.h"


// --- Prototipos ---
// Sirve para poder hacer las funciones abajo del main
void mostrarMenuRecursivo();
void ejercicio1();
void limpiarMemoria();

void limpiarMemoria(Partido* partidos[], Candidato* candidatos[]) {
    for (int i = 0; i < 5; i++ ) {
		delete partidos[i];
		delete candidatos[i];
    };
}

void mostrarMenuRecursivo() {
    cout << "==================== MENU PRINCIPAL ====================\n";
    cout << "Seleccione una opcion:\n";
    cout << "1. CNE\n";
    cout << "0. Salir\n";
    cout << "Opcion: ";

    int opcion;
    cin >> opcion;

    switch (opcion) {
    case 1:
        ejercicio1();
        break;
    
    case 0:
        cout << "Saliendo... Gracias.\n";
        return; // finaliza la recursión
    default:
        cout << "Opcion no valida. Intente de nuevo.\n";
    }



    // Llamada recursiva al menú
    mostrarMenuRecursivo();
}

// --------------------
// Ejercicio 1: CNE
// --------------------
void ejercicio1() {

	Partido* listaPartidos[5];
	Candidato* listaCandidatos[5];

    for (int i = 0; i < 5; i++) {
        string name;
		cout << "Ingrese el nombre del partido " << i + 1 << ": ";
        cin >> name;
		listaPartidos[i] = new Partido(name);
    }
    for (int i = 0; i < 5; i++) {
    
        string nombre, mensaje;
        char sexo;
		int edad;
		cout <<"Datos del candidato del partido " <<
		listaPartidos[i]->getNombre()<< endl ;

        cout << "Ingrese el nombre del candidato " << i + 1 << ": ";
        cin >> nombre;
        cout << "Ingrese la edad del candidato " << i + 1 << ": ";
        cin >> edad;
        cout << "Ingrese el sexo del candidato " << i + 1 << " (M/F): ";
        cin >> sexo;
        cout << "Ingrese el mensaje del candidato " << i + 1 << ": ";
		cin >> mensaje;

		listaCandidatos[i] = new Candidato(nombre, mensaje, sexo, edad, listaPartidos[i]);
    };
    // vector de nmes deps por comodidad
    vector<string> nombresDepartamentos = {
        "Atlántida ","Choluteca ","Colón "," Comayagua"," Copán"," Cortés","El Paraíso ","Francisco Morazán ",
        " Gracias a Dios","Intibucá ","Islas de la Bahía ","La Paz ","Lempira ","Ocotepeque ","Olancho ","Santa Bárbara ",
        "Valle ","Yoro "
	};

	vector<Departamento*> departamentos;
    for (int i = 0; i < 18; i++) {
		departamentos.push_back(new Departamento(nombresDepartamentos[i]));
    };
    for (int i = 0; i < 18; i++) {
		Departamento* depto = departamentos[i];
        int totalVotos = depto->registrarActa();
        for (int vot = 0; vot < totalVotos; vot++) {
			int candidatoIndex = rand() % 5; // Selecciona un candidato aleatorio
			(*listaCandidatos[candidatoIndex])++;
        };

        for (int k = 0; k < 5; k++) {
            cout << "Candidato: " << listaCandidatos[k]->getNombre()
                 << " del partido " << listaCandidatos[k]->getPartido()->getNombre()
				<< " tiene " << listaCandidatos[k]->getVotos() << " votos.\n";
        };
        if (i < 17) {
			cout << "-------Continuar simulacion-------"<< "1 si; else no"<<endl;
			int cont;
			cin >> cont;
            if (cont != 1) {
                break;

            };

        };
    };
	Candidato* ganador = listaCandidatos[0];
    for (int i = 1; i < 5; i++) {
        if (listaCandidatos[i]->getVotos() > ganador->getVotos()) {
            ganador = listaCandidatos[i];
        };
    };
    cout << "El ganador de las elecciones es: " << ganador->getNombre()
         << " del partido " << ganador->getPartido()->getNombre()
		<< " con " << ganador->getVotos() << " votos." << endl;
};


// --------------------
// Funcion Principal
// --------------------
int main()
{
    srand(time(0));
	mostrarMenuRecursivo();
	return 0;
}

