#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

template<typename T>
struct NodoAVL {
    T dato;
    int altura;
    NodoAVL *izq;
    NodoAVL *der;

    NodoAVL(T elem) {
        dato = elem;
        altura =1;
        izq = NULL;
        der = NULL;
    }
};

template<typename T>
class AVL {
private:
    NodoAVL<T> *raiz;

    int getAltura(NodoAVL<T> *nodo){
        if(!nodo) return 0;
        return nodo->altura;
    }

    int getBalance(NodoAVL<T> *nodo) {
        if(!nodo) return 0;
        return getAltura(nodo->der) - getAltura(nodo->izq);
    }

    int calcularAltura(NodoAVL<T>* nodo) {
        if(!nodo) return 0;
        return 1 + max(getAltura(nodo->izq), getAltura(nodo->der));
    } // esta bien hacerlo aca?

    int max(){} // hacer???

    NodoAVL<T>* insertarRec (NodoAVL<T>*& nodo, T elem) {

        if (!nodo) return new NodoAVL<T>(elem);

        if (elem < nodo->dato) {
            nodo->izq = insertarRec(nodo->izq, elem);
        } else if (elem > nodo->dato) {
            nodo->der = insertarRec(nodo->der, elem);
        } else {
            return nodo; // No se permiten elementos duplicados
        }

        nodo->altura = calcularAltura(nodo);
        cout << "Nodo: " << nodo->dato << endl;
        int balance = getBalance(nodo);
        cout << "Balance: " << balance << endl;

        // Rotaciones para mantener el equilibrio
        if (balance < -1 && elem < nodo->izq->dato) {
            return rotacionDerecha(nodo); // I-I
        } 
        if (balance > 1 && elem > nodo->der->dato) {
            return rotacionIzquierda(nodo); // D-D
        } 
        if (balance < -1 && elem > nodo->izq->dato) {
            nodo->izq = rotacionIzquierda(nodo->izq);
            return  rotacionDerecha(nodo); // I-D
        } 
        if (balance > 1 && elem < nodo->der->dato) {
            nodo->der = rotacionDerecha(nodo->der);
            return rotacionIzquierda(nodo); // D-I 
        }

        return nodo;
    }

    bool existeRec(NodoAVL<T>* nodo, T elem) {
        if(!nodo) return false;
        if(elem == nodo->dato) return true;

        if (elem < nodo->dato) {
            return existeRec(nodo->izq, elem);
        } else {
            return existeRec(nodo->der, elem);
        }

    }

    void rangoRec(NodoAVL<T>* nodo, T desde, T hasta) {
        if(!nodo) return;

        if(nodo->dato > desde) {
            rangoRec(nodo->izq, desde, hasta);
        }

        if(nodo->dato >= desde && nodo->dato <= hasta){
            cout << nodo->dato << endl;
        }
        
        if(nodo->dato < hasta) {
            rangoRec(nodo->der, desde, hasta);
        }
    }

    NodoAVL<T>* rotacionDerecha(NodoAVL<T>* B) {
        NodoAVL<T>* A = B->izq;
        NodoAVL<T>* t2 = A->der;

        B->izq = t2;
        A->der = B;

        B->altura = calcularAltura(B);
        A->altura = calcularAltura(A);

        return A;
    }

    NodoAVL<T>* rotacionIzquierda(NodoAVL<T>* A) {
        NodoAVL<T>* B = A->der;
        NodoAVL<T>* t2 = B->izq;

        A->der = t2;
        B->izq = A;

        A->altura = calcularAltura(A);
        B->altura = calcularAltura(B);

        return B;
    }

    public:
    AVL(){
        raiz = NULL;
    }

    void insertar(T elem) {
        raiz = insertarRec(raiz, elem);
    }

    bool existe(T elem) {
        return existeRec(raiz, elem);
    }

    void rango(T desde, T hasta) {
        rangoRec(raiz, desde, hasta);
    }
    
};