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



int topo(struct no* cabeca) {
    if (cabeca != NULL) {
        return cabeca->val;
    }
    else {
        return INT_MIN;
    }
}

void empilhar(struct no** cabeca, int valor, int* tamanho) {
    struct no* temp;
    temp = (struct no*)malloc(sizeof(struct no));
    temp->val = valor;
    temp->prox = NULL;
    if ((*cabeca) == NULL) {
        (*cabeca) = temp;
        
    }
    else {
        temp->prox = (*cabeca);
        (*cabeca) = temp;
        
    }
    (*tamanho)++;
}




void desempilhar(struct no** cabeca, int* tamanho) {
    struct no* aux = (*cabeca);
    if ((*cabeca) != NULL) {
        (*cabeca) = (*cabeca)->prox;
        free(aux);
        (*tamanho)--;
        return;
    }
}

int desempilharRetornando(struct no** cabeca, int* tamanho) {
    struct no* aux = (*cabeca);
    if ((*cabeca) != NULL) {
        (*cabeca) = (*cabeca)->prox;
        (*tamanho)--;
        return aux->val;
    }
    else {
        return INT_MIN;
    }


}

bool vazio(struct no* cabeca) {
    if (cabeca == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}
