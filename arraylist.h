#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>



void inicializar(int** lista, int capacidade)
{
    (*lista) = (int*)calloc(capacidade, sizeof(int));
    //capacidade=sizeof(lista);
}

void inserirElementoNoFim(int** lista, int valor, int* tam, int* capacidade)
{
    //printf ("The integer is: %d\n", sizeof (**lista));
    
    const int yv = 2 * (*capacidade);
    if ((*tam) == (*capacidade))
    {
        
        int* temp;
        temp = (int*)calloc(yv, sizeof(int));
        for (int i = 0; i < (*capacidade); i++) {
            temp[i] = (*lista)[i];
        }
        // free(lista);
        (*lista) = temp;
        (*capacidade) = 2 * (*capacidade);

        
    }

    (*lista)[(*tam)] = valor;
    (*tam)++;

}

void inserirElementoEmPosicao(int** lista, int valor, int pos, int* tam, int* capacidade) {
    const int yv = 2 * (*capacidade);

    if ((*tam) == sizeof(lista))
    {
        int* temp;
        temp = (int*)calloc(yv, sizeof(int));
        for (int i = 0; i < (*capacidade); i++) {
            temp[i] = (*lista)[i];
        }
        // free(lista);
        (*lista) = temp;
        (*capacidade) = 2 * (*capacidade);

        
    }
    if (pos >= 0 && pos <= (*tam))
    {
        for (int i = (*tam); i > pos; i--) {
            (*lista)[i] = (*lista)[i - 1];
        }
        (*lista)[pos] = valor;
        (*tam)++;

    }

}

int obterElementoEmPosicao(int* lista, int pos, int tam)
{
    if (pos >= 0 && pos < tam)
    {
        return lista[pos];
    }
}

void removerElementoEmPosicao(int* lista, int pos, int* tam)
{
    if (pos >= 0 && pos < (*tam))
    {
        for (int i = pos; i < (*tam) - 1; i++)
        {
            lista[i] = lista[i + 1];
        }
        //lista [pos] = valor;
        (*tam)--;
        //capacidade = sizeof (lista);
    }
}

void atualizarElemento(int* lista, int valor, int pos, int tam) {
    if (pos >= 0 && pos < tam) {
        lista[pos] = valor;
    }
}

void removerElementoNoFim(int* tam) {
    (*tam)--;
}
