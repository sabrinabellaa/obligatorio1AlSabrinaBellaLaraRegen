#include <iostream>
#ifndef DEFINICIONES_H
#define DEFINICIONES_H

struct Arista {
    int origen;
    int destino;
    int peso;
    Arista* sig;

    Arista() {}

    Arista(int unOrigen, int unDestino, int unPeso, Arista* unSig = NULL){
        this->origen = unOrigen;
        this->destino = unDestino;
        this->peso = unPeso;
        this->sig = unSig;
    }
};

#endif