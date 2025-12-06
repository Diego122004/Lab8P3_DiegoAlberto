#include "Departamento.h"

Departamento::Departamento()
{
}
Departamento::Departamento(string name) {
	this->nombre = name;
};
Departamento::Departamento(string nombre, int actas, int vpc)
{
	this->nombre = nombre;
	actas = 200 + rand() % 101;
	this->actas = actas;
	vpc = 1000 + rand() % 1001;
	this->votosPorActas = vpc;
}
int Departamento::getActas()
{
	return actas;
}
int Departamento::getVotosPorActas()
{
	return votosPorActas;
}


Departamento::~Departamento()
{
}


int Departamento::registrarActa()
{
	return getActas() * getVotosPorActas();
}

string Departamento::getNombre()
{
	return nombre;
}

ostream& operator<<(ostream& out, Departamento* d)
{
	out << "Departamento: " << d->getNombre() << ", Actas: " << d->getActas() << ", Votos por Acta: " << d->getVotosPorActas() << endl;
	return out;
}
