#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define INT_MIN  (-2147483648)


void inicializar(int** pilha, int capacidade)
{
    (*pilha) = (int*)calloc(capacidade, sizeof(int));
    //capacidade=sizeof(lista);
}

void empilhar(int** pilha, int valor, int* tam, int* capacidade)
{
    //printf ("The integer is: %d\n", sizeof (**lista));
    const int yv = 2 * (*capacidade);
    if ((*tam) == (*capacidade))
    {
        //(*lista) = (int *) realloc ((*lista), 2 * sizeof (lista) * sizeof (int));
        //
        int* temp;
        temp = (int*)calloc(yv, sizeof(int));
        for (int i = 0; i < (*capacidade); i++) {
            temp[i] = (*pilha)[i];
        }
        // free(lista);
        (*pilha) = temp;
        (*capacidade) = 2 * (*capacidade);

        
    }

    (*pilha)[(*tam)] = valor;
    (*tam)++;

}



int topo(int* pilha, int tam)
{
    if (tam != 0)
    {
        return pilha[tam - 1];
    }

    else {
        return INT_MIN;
    }
}

bool vazio(int tam) {
    if (tam > 0) {
        return 0;
    }
    else {
        return 1;
    }

}


int desempilharRetornando(int* pilha, int* tam) {
    if ((*tam) > 0) {
        (*tam)--;
        return pilha[(*tam)];
    }
    else {
        return INT_MIN;
    }
}



void desempilhar(int* tam) {
    if (*tam > 0) {
        (*tam)--;
    }
}