#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

class HashAbierto {
    private:

    struct Clave {
        int conteo[26]; // letras del alfabeto
        bool sonIguales(Clave otra) {
            for(int i=0; i<26; i++) {
                if(conteo[i] != otra.conteo[i]) return false;
            }
            return true;
        }
    };

    struct NodoHash {
        Clave clave;
        int contador;
        NodoHash* sig;

        NodoHash(Clave c) {
            clave = c;
            contador = 1;
            sig = NULL;
        }
    };

    NodoHash **tabla;
    int cantBuckets;
    int cantCajones;
    int cantCajonMasGrande;

    Clave arrayClave ( string palabra) {
        Clave c;
        for(int i=0; i<26; i++) {
            c.conteo[i] = 0;
        }
        for(char letra : palabra) {
            c.conteo[letra - 'a'] ++;
        }
        return c;
    }

    int fHash(Clave c) {
        int h = 0;
        int base = 31;
        for(int i=0; i<26; i++) {
            h = (h*base + c.conteo[i]) % cantBuckets;
        }
        return h;
    }

    NodoHash* buscarNodo(Clave c) {
        int cajon = fHash(c);
        NodoHash* aux = tabla[cajon];
        while(aux) {
            if(aux->clave.sonIguales(c)) {
                return aux;
            }
            aux = aux->sig;
        }
        return NULL;
    }

    public:
    HashAbierto(int cantBucketsParam) {
        cantBuckets = cantBucketsParam;
        tabla = new NodoHash*[cantBuckets](); //() inicializan todos los buckets en NULL
        cantCajones = 0;
        cantCajonMasGrande = 0;
    }

    void destruir() {
        for(int i=0; i<cantBuckets; i++) {
            NodoHash *actual = tabla[i];
            while(actual) {
                NodoHash *siguiente = actual->sig;
                delete actual;
                actual = siguiente;
            }
        }
        delete[] tabla;
    }

    void registrar(string palabra) {
        Clave clave = arrayClave(palabra);
        int cajon = fHash(clave);
        NodoHash *act = tabla[cajon];
        bool encontrado = false;

        while(act && !encontrado) {
            if(act->clave.sonIguales(clave)) {
                act->contador++;
                encontrado = true;
                if(act->contador > cantCajonMasGrande) {
                    cantCajonMasGrande = act->contador;
                }
            }
            act = act->sig;
        }

        if(!encontrado) {
            NodoHash* nuevo = new NodoHash(clave);
            nuevo->sig = tabla[cajon];
            tabla[cajon] = nuevo;
            cantCajones++;
            if(nuevo->contador > cantCajonMasGrande) {
                cantCajonMasGrande = nuevo->contador;
            }
        }
    }

    int consultar(string palabra) {
        Clave clave = arrayClave(palabra);
        NodoHash* nodo = buscarNodo(clave);
        if (nodo) {
            return nodo->contador;
        } else {
            return 0;
        }
    }

    int getCantCajonMasGrande() {
        return cantCajonMasGrande;
    }

    int getCantCajones() {
        return cantCajones;
    }
};


int main() {
    int cantRegistros;
    cin >> cantRegistros;

    int buckets = 2 * cantRegistros + 1;
    HashAbierto hash(buckets);

    for(int i=0; i<cantRegistros; i++) {
        string palabraR;
        cin >> palabraR;
        hash.registrar(palabraR);
    }

    int cantConsultas;
    cin >> cantConsultas;
    for(int i=0; i<cantConsultas; i++) {
        string palabraC;
        cin >> palabraC;
        int cantCaj = hash.consultar(palabraC);
        cout << cantCaj << endl;
    }

    cout << hash.getCantCajones() << " " << hash.getCantCajonMasGrande() << endl;
    hash.destruir();
    return 0;
}