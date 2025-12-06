#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Departamento {
	string nombre;
	int actas;
	int votosPorActas;
public:
	Departamento();
	Departamento(string nombre);
	Departamento(string nombre, int actas, int vpc);
	~Departamento();

	int getActas();
	int getVotosPorActas();
	string getNombre();
	friend ostream& operator<<(ostream& os, Departamento* d);
	int registrarActa();
};