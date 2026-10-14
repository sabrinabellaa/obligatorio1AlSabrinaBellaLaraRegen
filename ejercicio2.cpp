#include <string>
#include <iostream>

using namespace std;

const int ALFABETO = 26;

class HashAbierto {
    private:

    struct Clave {
        int conteo[ALFABETO]; // letras del alfabeto
        bool operator==(const Clave& otra) const {  // sonIguales??? const????
            for(int i=0; i<lfBETO; i++) {
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

    Clave arrayClave (const string& palabra) {
        Clave c;
        for(int i=0; i<ALFABETO; i++) {
            c.conteo[i] = 0;
        }
        for(char letra : palabra) {
            c.conteo[letra - 'a'] ++;
        }
        return c;
    }

    int fHash(const Clave& c) {
        int h = 0;
        int base = 31;
        for(int i=0; i<ALFABETO; i++) {
            h = (h*base + c.conteo[i]) % cantBuckets;
        }
        return h;
    }

    NodoHash* buscarNodo(const Clave& c) {
        int cajon = fhash(c);
        NodoHash* aux = tabla[cajon];
        while(aux) {
            if(aux.->lave == c) {
                return aux;
            }
            aux=aux->sig;
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

    destruir() {
        for(int i=0; i<cantBuckets; i++) {
            NodoHash *actual = tabla[i];
            while(actual) {
                NodoHash *siguiente = actual->sig;
                delete actual; 
                actual = siguiente
            }
        }
        delete[] tabla;
    }

    registrar(const &string palabra) {
        Clave clave = arrayClave(palabra);
        int cajon = fhash(clave);
        NodoHash *act = tabla[cajon];
        bool encontrado = false;

        while(act && !encontrado) {
            if(act->clave == clave) {
                act->contador ++;
                encontrado = true;
                if(act->contador > cantCajonMasGrande) {
                    cantCajonMasGrande = act->contador
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
                    cantCajonMasGrande = nuevo->contador
            }
        }

    }

    int consultar(const string& palabra) {
        Clave clave = arrayClave(palabra);
        NodoHash* nodo = buscarNodo(clave);
        return nodo ? nodo->contador : 0;
    }

};

int main() {
    HashAbierto hash(10); // cantBuckets chico, solo para probar

    hash.registrar("roma");
    hash.registrar("amor");
    hash.registrar("mora");
    hash.registrar("sol");
    hash.registrar("los");
    hash.registrar("casa");

    cout << hash.consultar("ramo") << endl;   // esperado: 3
    cout << hash.consultar("sol") << endl;    // esperado: 2
    cout << hash.consultar("perro") << endl;  // esperado: 0

    return 0;
}