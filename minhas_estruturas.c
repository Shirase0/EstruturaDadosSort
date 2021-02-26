/*
 ============================================================================
 Name        : minhas_estruturas.c
 Author      : Felipe Costa Garcia
 Version     :
 Copyright   :
 Description : Funções de Estruturas de Dados
 ============================================================================
 */

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minhas_estruturas.h"

// Lista Ligada
// Define o Elemento de Dados Para Nossa Entradas
typedef struct DADOS{
   int entrada;
   struct DADOS *next; // este é o apontador para o próximo nodo
}DADOS;

// Código Para Leitura Por Arquivo de Entrada
// DADOS *Ler(){
//
//     // L: Elemento 0, Referência da Lista; aux: struct auxiliar
//     DADOS *L=NULL,*aux; // Elementos Para Dados na Lista
//     FILE *f; // Arquivo de Entrada de Dados
//     char buff[50]; // Recebe String em Arquivo
//     // Abre Ficheiro com Dados Para Adição à Lista
//     f=fopen("dados.txt","r");
//     // Verifica Existência do Ficheiro
//     if(f==NULL)
//             return(NULL);
//
//      while(fscanf (f, "%s%d", buff, &entrada)!=EOF){ // EOF =  EndOfFIle
//
//             //Se Lista Vazia Cria Posição 0
//             if(L==NULL){
//                     //reservar memoria do tipo de estruct DADOS
//                     L=(DADOS*)malloc (1*sizeof(DADOS));
//                     //enviar nome para o nodo criado em memoria
//                     strcpy(L->nome,buff);
//                     //enviar entrada para nodo criado em memoria
//                     L->entrada = entrada;
//                     //declarar "a seta"/ponteiro do proximo nodo a NULL (vazio)
//                     L->next=NULL;
//                     //a partir de agr o aux é a nossa lista (L -> cabeca da lista)
//                     aux=L;
//             }
//             // Novas Posições
//             else {
//                     aux->next=(DADOS*)malloc (1*sizeof(DADOS));
//                     aux=aux->next;
//                     strcpy(aux->nome,buff);
//                     aux->entrada=entrada;
//                     aux->next=NULL;
//             }
//     }
//
//     return(L); // Retorna Lista Montada a Partir e Arquivo
// }

DADOS *Init(DADOS *L, DADOS *aux, int entrada){

    // Gera Posição 0 de Referência da Lista
    if(L==NULL){
            //reservar memoria do tipo de estruct DADOS
            L=(DADOS*)malloc (1*sizeof(DADOS));
            //enviar entrada para nodo criado em memoria
            L->entrada = entrada;
            //declarar "a seta"/ponteiro do proximo nodo a NULL (vazio)
            L->next=NULL;
            //a partir de agr o aux é a nossa lista (L -> cabeca da lista)
            aux=L;

    }
    return L;
}

// Realiza a inserção de dados
DADOS *Add(DADOS *aux, int entrada){

    // Cria Nova Posição e Coloca Como Referência de Ponteiro na Anterior
    aux->next=(DADOS*)malloc (1*sizeof(DADOS));
    aux=aux->next; //
    // strcpy(aux->nome,entrada); // Copia String do Novo Elemento
    aux->entrada=entrada; // Armazena Inteiro da Nova Entrada
    aux->next=NULL; // Cria Ponteiro Nulo Para Criação de Futura Posição

    return(aux); // Retorna a Posição mais Recente (fim da lista)
}


// Realiza Remoção de Dados
DADOS * Rmv(DADOS *L, int pos){
  int c = 0; // Incia Contagem e posição

  if(L==NULL){ // Verifica Lista Vazia
          printf("A Lista está vazia!\n");

  }
  else{
          // Enquanto Houver Nodos
          while(c!=pos){ // Vai Até Posição SOlicitada
                  if (c == pos -1){
                    //printf("%s\n", L->next->nome);
                    printf("Item Removido: %d\n", L->next->entrada );
                    free(L->next);
                    L->next = L->next->next;

                  }
                  c++;
                  L=L->next;
          }
  }

return L;
}

// Realiza Remoção de Dados
// DADOS * Rmvs(DADOS *L, int pos){
//   int c = 0; // Incia Contagem e posição
//   int position;
//   if(L==NULL){ // Verifica Lista Vazia
//           printf("A Lista está vazia!\n");
//           return;
//   }
//   else{
//           // Enquanto Houver Nodos
//           while(c!=fim){ // Vai Até Posição SOlicitada
//                   if (c >= pos -1 && c<=fim){
//                     //printf("%s\n", L->next->nome);
//                     printf("Item Removido: %d\n", L->next->entrada );
//                     free(L->next);
//                     L->next = L->next->next;
//
//                   }
//                   c++;
//                   L=L->next;
//           }
//   }
//
// return L;
// }

// mostrar dados da lista ligada
void ShowList(DADOS *L){
        if(L==NULL){
                printf("A Lista está vazia!\n");
                return;
        }
        else {
                //enquanto houver nodos..
                while(L!=NULL){
                        printf("%d ",L->entrada);
                        L=L->next;
                }
        }
        return;
}

void ShowElement(DADOS *L, int pos){

    int c = 0; // Incia Contagem e posição
    if(L==NULL){ // Verifica Lista Vazia
            printf("A Lista está vazia!\n");
            return;
    }
    else{
            // Enquanto Houver Nodos
            while(c!=pos){ // Vai Até Posição SOlicitada
                    c++;
                    L=L->next;
            }
            printf("%d",L->entrada); // Exibe Dados na Posição
    }
    return;
}
