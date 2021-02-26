/*
 ============================================================================
 Name        : bub.c
 Author      : Felipe Costa Garcia
 Version     :
 Copyright   :
 Description : BubbleSort
 ============================================================================
 */

// Implementação do BubbleSort
#include<stdio.h>
#include<stdlib.h>

// Elemento da Lista
struct Node
{
    int data;
    struct Node *next;
};


// Declaração da Função de Bubble SOrt
void bubbleSort(struct Node *inicio);

/* Function to swap data of two nodes a and b*/
void swap(struct Node *a, struct Node *b);



/* Bubble sort the given linked list */
void bubbleSort(struct Node *inicio)
{
    int swapped, i;
    struct Node *ptr1;
    struct Node *lptr = NULL;

    /* Checking for empty list */
    if (inicio == NULL) // Verifica se existe elemento 0
        return;

    do
    {
        swapped = 0;
        ptr1 = inicio; //  Recebe Inicio da Lista Solicitada Para Ordenação

        while (ptr1->next != lptr) // Enquanto Houver elementos na Lista
        {
            if (ptr1->data > ptr1->next->data) // Verifica Qual o Maior Elemento
            {
                swap(ptr1, ptr1->next); // Chama Swap Para Troca
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}


void swap(struct Node *a, struct Node *b)
{
    int temp = a->data; // Temporio, armazena o dado antes da troca
    a->data = b->data; // troca de posição
    b->data = temp; // Recebe valor anteriormente em a
}
