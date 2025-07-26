#include "Nodo.h"
#include <cstring>
#include <iostream>
#include <cmath>

Nodo::Nodo() {
    id = -1;
    nombre[0] = '\0';
    x = y = 0;
    vecinos = nullptr;
}

Nodo::Nodo(int _id, const char* _nombre, float _x, float _y) {
    id = _id;
    strncpy(nombre, _nombre, MAX_NOMBRE);
    x = _x;
    y = _y;
    vecinos = nullptr;
}

Nodo::~Nodo() {
    Vecino* actual = vecinos;
    while (actual) {
        Vecino* tmp = actual;
        actual = actual->siguiente;
        delete tmp;
    }
}

int Nodo::getId() { return id; }
const char* Nodo::getNombre() { return nombre; }
float Nodo::getX() { return x; }
float Nodo::getY() { return y; }
Vecino* Nodo::getVecinos() { return vecinos; }

void Nodo::agregarVecino(int idVecino, float distancia) {
    Vecino* nuevo = new Vecino;
    nuevo->id = idVecino;
    nuevo->distancia = distancia;
    nuevo->siguiente = vecinos;
    vecinos = nuevo;
}

void Nodo::imprimirVecinos() {
    Vecino* actual = vecinos;
    while (actual) {
        std::cout << "  -> Vecino ID: " << actual->id << " (distancia: " << actual->distancia << ")\n";
        actual = actual->siguiente;
    }
}
