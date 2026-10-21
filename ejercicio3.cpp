#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/HeapBinario.cpp"

using namespace std;

bool comparar(long long a, long long b) {
    return a < b;
}

int main() {
    
    int cantLineas;
    cin >> cantLineas;

    Heap<long long> heap(cantLineas, comparar);

    for(int i=0; i<cantLineas; i++) {
        long long tam;
        cin >> tam;
        heap.insertar(tam);
    }

    long long costoTotal = 0;
    int restantes = cantLineas;

    while (restantes > 1) {
        long long a = heap.tope();
        heap.eliminarTope();
        long long b = heap.tope();
        heap.eliminarTope();

        long long nuevo = a + b;
        costoTotal += nuevo;
        heap.insertar(nuevo);

        restantes--;
    }

    cout << costoTotal << endl;

    return 0;
}