/*
 ============================================================================
 Name        : main.c
 Author      : Felipe Costa Garcia
 Version     :
 Copyright   :
 Description : Principal
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minhas_estruturas.h"
#include "bub.c"

// Exibe o comando de entrada
void print_entry(char *entry) {
	printf("You entered: %s\n", entry);
}

int main(int argc, char *argv[]) {
  DADOS *L=NULL, *aux;
  int my_interger, tam=0;

  char input[201];
	int c = 1;

	while(1) {

		printf("prompt>");

		if (fgets(input, 200, stdin) == NULL) {
			printf("An error ocurred.\n");
			break;
		}


		if (strncmp(input, "exit\n", 5) == 0) {
      ShowList(L);
      printf("%d\n", strncmp(input, "exit\n", 5) == 0);
      printf("Leaving. Good bye.\n");
			break;
		}

		// Verifica Comando de Adição à Lista
    if (strncmp(input, "put\n", 3) == 0) {
      tam++; // Incrementa Info com Tamanho da Lista
      if(L==NULL){  // Verifica Se  Posição 0 de Referencia da Lista
        L = Init(L,aux,(int)input[4]-48); // Inicializa Lista
        aux = L;
      }
      else{
      	aux = Add(aux,(int)input[4]-48); // Adiciona Novos Elementos
      }
      ShowList(L); // Exibe Lista completa com o novo elemento

    }


		// Comando Para Remoção de Elemento
		if (strncmp(input, "remove\n", 6) == 0) {
      Rmv(L, (int)input[7]-49);
			ShowList(L);
			tam--;
    }
		// Comando para listagem dos valores

		if (strncmp(input, "list\n", 4) == 0) {
			ShowList(L);
    }

		// Exibe Primeiro Elemento
    if (strncmp(input, "first\n", 5) == 0) {
      if (tam > 0) ShowElement(L, 0);
    }

		// Exibe Ultimo Elemento
    if (strncmp(input, "last\n", 4) == 0) {
      if (tam > 0) ShowList(aux);

    }

		// Exibe Único Elemento Solicitado
    if (strncmp(input, "get\n", 3) == 0) {
      if (L != NULL) ShowElement(L, (int)input[4]-49);
    }

    if (strncmp(input, "sort\n", 4) == 0) {
      if (L != NULL) bubbleSort(L);
			ShowList(L);
    }
		printf("\n");
	}

	return EXIT_SUCCESS;
}
