#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


struct no {
    int val;
    struct no* prox;
    struct no* ant;
};

void inserirElementoNoFim(struct no** cabeca, int valor, int* tamanho) {
    struct no* temp;
    temp = (struct no*)malloc(sizeof(struct no));
    temp->val = valor;
    temp->prox = NULL;
    temp->ant = NULL;
    if ((*cabeca) == 0) {
        (*cabeca) = temp;
        
    }
    else {
        
        struct no* aux = (*cabeca);
        while (aux->prox != NULL) {
            aux = aux->prox;
            
        }
        temp->ant = aux;
        aux->prox = temp;

    }
    //tamanho++;
    (*tamanho)++;
}

int obterElementoEmPosicao(struct no** cabeca, int posicao) {
    // if(posicao>=0 && posicao<=(*tamanho)){
    struct no* aux = (*cabeca);
    for (int i = 0; i != posicao; i++) {
        aux = aux->prox;
    }
    // }
    return aux->val;
}

void inserirElementoNoInicio(struct no** cabeca, int valor, int* tamanho) {
    struct no* temp;
    temp = (struct no*)malloc(sizeof(struct no));
    temp->val = valor;
    temp->prox = NULL;
    temp->ant = NULL;
    if ((*cabeca) == NULL) {
        (*cabeca) = temp;
        
    }
    else {
        (*cabeca)->ant = temp;
        temp->prox = (*cabeca);
        (*cabeca) = temp;
        
    }
    (*tamanho)++;
}

void inserirElementoEmPosicao(struct no** cabeca, int valor, int posicao, int* tamanho) {
    struct no* temp;
    temp = (struct no*)malloc(sizeof(struct no));
    temp->val = valor;
    temp->prox = NULL;
    temp->ant = NULL;
    if ((*cabeca) == NULL && posicao == 0) {
        (*cabeca) = temp;
        
    }
    else {
        struct no* aux = (*cabeca);

        if (posicao != 0) {

            for (int i = 0; i < posicao - 1; i++) {

                aux = aux->prox;
                
            }
            if (aux->prox != NULL) {
                temp->ant = aux;
                temp->prox = aux->prox;
                aux->prox = temp;
                struct no* fut = temp->prox;
                fut->ant = temp;
            }
            if (aux->prox == NULL) {
                temp->ant = aux;
                temp->prox = aux->prox;
                aux->prox = temp;
            }
        }
        else {
            
            temp->prox = aux;
            (*cabeca) = temp;
        }
    }
    (*tamanho)++;
}


void removerElementoEmPosicao(struct no** cabeca, int posicao, int* tamanho) {
    struct no* aux = (*cabeca);
    if (posicao == 0 && (*tamanho) != 1) {
        (*cabeca) = (*cabeca)->prox;
        (*cabeca)->ant = NULL;
        free(aux);
        (*tamanho)--;
        return;
    }
    else if (posicao == 0 && (*tamanho) == 1) {
        (*cabeca) = NULL;
        (*tamanho)--;
        return;
    }
    else if (posicao == 1 && (*tamanho) == 2) {
        (*cabeca)->prox = NULL;
        (*cabeca)->ant = NULL;

        (*tamanho)--;

        return;
    }
    for (int i = 0; i < posicao - 1 && aux->prox != NULL; i++) {
        aux = aux->prox;
    }
    if ((*tamanho) - posicao != 1) {
        struct no* ale = aux->prox;
        aux->prox = ale->prox;
        struct no* tes = ale->prox;
        tes->ant = aux;
        free(ale);
        (*tamanho)--;
    }
    else {
        struct no* ale = aux->prox;
        aux->prox = ale->prox;
        free(ale);
        (*tamanho)--;
    }


}


