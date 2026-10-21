#include <string>
#include <iostream>
#include "tads/definiciones.cpp"
#include "tads/HeapBinario.cpp"
#include "tads/MFSet.cpp"

using namespace std;

bool compararAristas(Arista a, Arista b) {
    return a.peso < b.peso;
}

int main() {
    int V, A;
    cin >> V >> A;

    Heap<Arista> cp(A, compararAristas);
    for (int i = 0; i < A; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        cp.insertar(Arista(u, v, w));
    }

    MFSet mfset(V + 1);
    long long costoTot = 0;         
    int eleg = 0;

    while (!cp.esVacio() && eleg < V - 1) {
        Arista a = cp.tope();
        cp.eliminarTope();
        if (mfset.find(a.origen) != mfset.find(a.destino)) {
            mfset.merge(a.origen, a.destino);
            costoTot += a.peso;
            eleg++;
        }
    }

    if (eleg == V - 1) {
        cout << costoTot << endl;
    } else {
        cout << "imposible" << endl;
    }

    return 0;
}