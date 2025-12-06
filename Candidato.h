#include <iostream>
#include <string>
#include "Partido.h"
using namespace std;

class Candidato {
	string nombre;
	string mensaje;
	char sexo;
	int edad;	
	Partido* partido;
	int votos;
public:
	Candidato();
	Candidato(string nombre, string mensaje, char sexo, int edad, Partido* partido);
	Candidato(string nombre, string mensaje, char sexo, int edad, Partido* partido, int votos);
	string getNombre();
	void setNombre(string nombre);
	string getMensaje();
	void setMensaje(string mensaje);
	char getSexo();
	void setSexo(char sexo);
	int getEdad();
	void setEdad(int edad);
	Partido* getPartido();
	void setPartido(Partido* partido);
	int getVotos();
	void setVotos(int votos);
	~Candidato();
	
	Candidato& operator ++();
	Candidato& operator ++(int);

	friend ostream& operator <<(ostream& out, Candidato* c);

	void mostrarInfo() const {
		cout << "Nombre: " << nombre << endl;
		cout << "Mensaje: " << mensaje << endl;
		cout << "Sexo: " << sexo << endl;
		cout << "Edad: " << edad << endl;
		if (partido) {
			cout << "Partido: " << partido->getNombre() << endl;
		} else {
			cout << "Partido: No afiliado" << endl;
		}
	}
};