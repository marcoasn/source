#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define INT_MIN  (-2147483648)

struct FilaArray {
    int frente;
    int tras;
    int elementos[10];
};

bool vazia(struct FilaArray* fila) {
    if (fila->frente == -1 && fila->tras == -1) {
        return true;
    }
    if (fila = NULL) {
        return true;
    }
    else {
        return false;
    }
}
void enfileirar(struct FilaArray* fila, int val) {
    int n = sizeof(fila->elementos) / sizeof(int);
    if (fila == NULL) {
        return;
    }
    if (vazia(fila) == 1) {
        
        fila->frente = 0;
        fila->tras = 0;
        fila->elementos[fila->tras] = val;
        return;

    }
    if ((fila->tras + 1 % n) == fila->frente) {//fila cheia
        return;
    }

    else {

        fila->tras = (fila->tras + 1) % n;
        
    }
    fila->elementos[fila->tras] = val;

}




void desenfileirar(struct FilaArray* fila) {
    int n = sizeof(fila->elementos) / sizeof(int);
    if (fila == NULL) {
        return;
    }
    if (vazia(fila) == 1) {
        return;
    }
    if (fila->tras == fila->frente) {
        fila->frente = -1;
        fila->tras = -1;
    }
    else {
        fila->frente = (fila->frente + 1) % n;
    }
}


int tamanho(struct FilaArray* fila) {
    int x = fila->tras;
    int y = fila->frente;

    int f = 0;

    int res = (fila->tras + 1) - fila->frente;
    if (fila->tras == -1 && fila->frente == -1) {
        return 0;
    }
    if (fila = NULL) {
        return 0;
    }
    if (y <= x) {

        return res;
    }
    else {
        return fila->tras + 11 - fila->frente;
    }
}

int frente(struct FilaArray* fila) {
    if (fila == NULL) {
        return INT_MIN;
    }
    if (vazia(fila)) {
        return INT_MIN;
    }
    else {
        return fila->elementos[fila->frente];
    }
}