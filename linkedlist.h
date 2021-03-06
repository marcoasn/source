#pragma once
///////////linkedlits

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


struct no {
    int val;
    struct no* prox;
};

void inserirElementoNoFim(struct no** cabeca, int valor, int* tamanho) {
    struct no* temp;
    temp = (struct no*)malloc(sizeof(struct no));
    temp->val = valor;
    temp->prox = NULL;
    if ((*cabeca) == 0) {
        (*cabeca) = temp;
        
    }
    else {
        
        struct no* aux = (*cabeca);
        for(int i=0; i<(*tamanho)-1;i++){
            aux = aux->prox;
           
        }
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
    if ((*cabeca) == NULL) {
        (*cabeca) = temp;
       
    }
    else {
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
    if ((*cabeca) == NULL && posicao == 0) {
        (*cabeca) = temp;
        
    }
    else {
        struct no* aux = (*cabeca);
        if (posicao != 0) {

            for (int i = 0; i < posicao - 1; i++) {
                aux = aux->prox;
                
            }
            temp->prox = aux->prox;
            aux->prox = temp;
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
    if (posicao == 0) {
        (*cabeca) = (*cabeca)->prox;
        free(aux);
        (*tamanho)--;
        return;
    }
    for (int i = 0; i < posicao - 1 && aux->prox != NULL; i++) {
        aux = aux->prox;
    }
    struct no* ale = aux->prox;
    aux->prox = ale->prox;
    free(ale);
    (*tamanho)--;

}
