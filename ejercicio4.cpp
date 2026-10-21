#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/ListaAdy.cpp"
#include "tads/HeapBinario.cpp"

using namespace std;

struct Modulo {
    int prioridad;
    int numero;
};

bool compararModulos(Modulo a, Modulo b) {
    if (a.prioridad < b.prioridad) {
        return true;
    } else if (a.prioridad == b.prioridad) {
        return a.numero < b.numero;
    }
    return false;
}

int main()
{
    int V, A;
    cin >> V >> A;

    int* prioridad = new int[V + 1];
    for (int i = 1; i <= V; i++) {
        cin >> prioridad[i];
    }

    GrafoLista grafo(true, false, V);
    int* ge = new int[V + 1]();
    for (int i = 0; i < A; i++) {
        int u, v;
        cin >> u >> v;
        grafo.agregarArista(u, v);
        ge[v]++;
    }

    Heap<Modulo> listos(V, compararModulos);
    for (int v = 1; v <= V; v++) {
        if (ge[v] == 0) {
            Modulo m;
            m.prioridad = prioridad[v];
            m.numero = v;
            listos.insertar(m);
        }
    }

    int* orden = new int[V];
    int procesados = 0;
    while (!listos.esVacio()) {
        int w = listos.tope().numero;
        listos.eliminarTope();
        orden[procesados] = w;
        procesados++;

        Arista* ady = grafo.adyacentes(w);
        while (ady) {
            ge[ady->destino]--;
            if (ge[ady->destino] == 0) {
                Modulo m;
                m.prioridad = prioridad[ady->destino];
                m.numero = ady->destino;
                listos.insertar(m);
            }
            ady = ady->sig;
        }
    }

    if (procesados == V) {
        for (int i = 0; i < V; i++) {
            cout << orden[i] << endl;
        }
    } else {
        cout << "imposible" << endl;
    }

    delete[] prioridad;
    delete[] ge;
    delete[] orden;

    return 0;
}