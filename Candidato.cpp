#include "Candidato.h"
#include "Partido.h"

Candidato::Candidato() {

}
Candidato::Candidato(string nombre, string mensaje, char sexo, int edad, Partido* partido) {
	this->nombre = nombre;
	this->mensaje = mensaje;
	this->sexo = sexo;
	this->edad = edad;
	this->partido = partido;
	this->votos = 0;
}
Candidato::Candidato(string nombre, string mensaje, char sexo, int edad, Partido* partido, int votos) {
	this->nombre = nombre;
	this->mensaje = mensaje;
	this->sexo = sexo;
	this->edad = edad;
	this->partido = partido;
	this->votos = votos;

}
string Candidato::getNombre() {
	return nombre;
}
string Candidato::getMensaje() {
	return mensaje;
}
char Candidato::getSexo() {
	return sexo;
}
int Candidato::getEdad() {
	return edad;
}
Partido* Candidato::getPartido() {
	return partido;
}
int Candidato::getVotos() {
	return votos;
}

void Candidato::setNombre(string nombre) {
	this->nombre = nombre;
}
void Candidato::setMensaje(string mensaje) {
	this->mensaje = mensaje;
}
void Candidato::setSexo(char sexo) {
	this->sexo = sexo;
}
void Candidato::setEdad(int edad) {
	this->edad = edad;
}
void Candidato::setPartido(Partido* partido) {
	this->partido = partido;
}
void Candidato::setVotos(int votos) {
	this->votos = votos;
}
Candidato::~Candidato() {
}		
Candidato& Candidato::operator++() {
	this->votos++;
	return *this;
}
Candidato& Candidato::operator ++(int) {
	this->votos++;
	return *this;
}
ostream& operator<<(ostream& out,Candidato* c) {
	out << "Candidato: \n" << c->nombre << "Partido: \n" << c->partido << "Votos: \n" << c->votos;
	
	return out;
}