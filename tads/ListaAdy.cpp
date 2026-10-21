#include <iostream>
#include <cassert>
#include "definiciones.cpp"
#ifndef LISTAADY_H
#define LISTAADY_H
using namespace std;

class GrafoLista {

    private:
        bool dirigido;
        bool ponderado;
        int cantidadVertices;
        Arista** vertices;

    public:
        GrafoLista(bool esDirigido, bool esPonderado, int cantV){

            this->dirigido = esDirigido;
            this->ponderado = esPonderado;
            this->cantidadVertices = cantV;
            vertices = new Arista*[cantV + 1];

            for (int i = 0; i <= cantV; i++){
                vertices[i] = NULL;
            }
        }

        void agregarArista(int origen, int destino, int peso = 1){

            assert(ponderado || peso == 1);

            Arista* nuevaArista = new Arista(origen, destino, peso);
            nuevaArista->sig = vertices[origen];
            vertices[origen] = nuevaArista;      


            if (!dirigido){
                vertices[destino] = new Arista(destino, origen, peso, vertices[destino]);
            }
        }

        Arista* adyacentes(int vertice) {
            return vertices[vertice];
        }

        int cantVertices() {
            return this->cantidadVertices;
        }
};

#endif