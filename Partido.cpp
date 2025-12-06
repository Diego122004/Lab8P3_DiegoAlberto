#include "Partido.h"

Partido::Partido(string n) {
	
		this->nombre = n;
};
string Partido::getNombre() {
	return this->nombre;
}
Partido::~Partido() {};