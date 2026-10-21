#ifndef MFSET_H
#define MFSET_H

class MFSet {

    private:
    int *padre;
    int *altura;
    int tam;

    public:
    MFSet(int tam) {
        padre = new int[tam]();
        altura = new int[tam]();
        this->tam = tam;
        for (int i = 0; i < tam; i++) {
        padre[i] = -1;
        altura[i] = 1;
        }
    }

    ~MFSet() {
        delete[] padre;
        delete[] altura;
    }

    int find(int v) {
        if (padre[v] == -1) {
        return v;
        }
        padre[v] = find(padre[v]);
        return padre[v];
    }

    void merge(int v, int w) {
        int padreV = find(v);
        int padreW = find(w);
        if (padreV != padreW) {
            if (altura[padreV] > altura[padreW]) {
                padre[padreW] = padreV;
            } else if (altura[padreV] < altura[padreW]) {
                padre[padreV] = padreW;
            } else {
                padre[padreW] = padreV;
                altura[padreV]++;
            }
        }
    }
};

#endif