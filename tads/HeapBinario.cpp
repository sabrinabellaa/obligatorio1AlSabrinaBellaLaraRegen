#ifndef TADHEAPBINARIO_H
#define TADHEAPBINARIO_H

#include <cassert>

template<typename T>
class Heap {
    private:
    T* arr;
    int capacidad;
    int ultimoOcupado;
    bool (*comparar)(T, T);

    int padre(int pos) {
        return pos / 2;
    }

    int izq(int pos) {
        return pos * 2;
    }

    int der(int pos) {
        return (pos * 2) + 1;
    }

    void swap(int posA, int posB) {
        T aux = arr[posA];
        arr[posA] = arr[posB];
        arr[posB] = aux;
    }

    void flotar(int posActual) {
        if(posActual == 1) return;

        int posPadre = padre(posActual);

        if(comparar(arr[posActual], arr[posPadre])) {
            swap(posActual, posPadre);
            flotar(posPadre);
        }
    }

    void hundir(int posActual) {
        int posHijoIzq = izq(posActual);
        int posHijoDer = der(posActual);

        if(posHijoIzq > ultimoOcupado) return;

        int posElegido = posHijoIzq;

        if(posHijoDer <= ultimoOcupado && comparar(arr[posHijoDer], arr[posHijoIzq])) {
            posElegido = posHijoDer;
        }

        if(comparar(arr[posElegido], arr[posActual])) {
            swap(posElegido, posActual);
            hundir(posElegido);
        }
    }

    public:
    Heap(int unaCapacidad, bool (*unComparar)(T, T)) {
        arr = new T[unaCapacidad + 1]();
        capacidad = unaCapacidad;
        comparar = unComparar;
        ultimoOcupado = 0;
    }

    ~Heap() {
        delete[] arr;
    }

    bool esVacio() {
        return ultimoOcupado == 0;
    }

    bool estaLleno() {
        return ultimoOcupado == capacidad;
    }

    T tope() {
        assert(!esVacio());
        return arr[1];
    }

    void eliminarTope() {
        assert(!esVacio());
        arr[1] = arr[ultimoOcupado];
        ultimoOcupado--;
        hundir(1);
    }

    void insertar(T elem) {
        assert(!estaLleno());
        arr[++ultimoOcupado] = elem;
        flotar(ultimoOcupado);
    }
};

#endif