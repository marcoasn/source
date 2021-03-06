#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define INT_MIN  (-2147483648)


struct no {
    int val;
    struct no* prox;
};

struct FilaLigada {
    int tamanho;
    struct no* frente;
    struct no* tras;
};


bool vazia(struct FilaLigada* fila) {
    if (fila->frente == NULL && fila->tras == NULL) {
        return true;
    }
    if (fila = NULL) {
        return true;
    }
    else {
        return false;
    }
}

void enfileirar(struct FilaLigada** fila, int valor) {
    struct no* temp;
    temp = (struct no*)malloc(sizeof(struct no));
    temp->val = valor;
    temp->prox = NULL;

    if ((*fila)->frente == NULL) {
       
        (*fila)->frente = temp;
        (*fila)->tras = temp;
    }
    else {
        struct no* ale = (*fila)->tras;
        ale->prox = temp;
        (*fila)->tras = temp;

    }
    (*fila)->tamanho++;
    return;
}



void desenfileirar(struct FilaLigada* fila) {
    if (fila == NULL) {
        return;
    }
    if (vazia(fila) == 1) {
        return;
    }
    if (fila->tras == fila->frente) {
        free(fila->frente);
        fila->frente = NULL;
        fila->tras = NULL;
        fila->tamanho--;
        return;
    }
    else {
        struct no* aux = fila->frente;
        fila->frente = aux->prox;
        free(aux);
        fila->tamanho--;
        return;
    }



}

int frente(struct FilaLigada* fila) {
    if (fila == NULL) {
        return INT_MIN;
    }
    if (vazia(fila)) {
        return INT_MIN;
    }
    else {
        return fila->frente->val;
    }
}