/*
 ============================================================================
 Name        : minhas_estruturas.h
 Author      : Felipe Costa Garcia
 Version     :
 Copyright   :
 Description : Estruturas de Dados
 ============================================================================
 */

#ifndef MINHAS_ESTRUTURAS
#define MINHAS_ESTRUTURAS

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minhas_estruturas.c"


// Lista Ligada
// Define a estrutura DADOS para nosso tipo de dado
typedef struct DADOS;

//ler do ficheiro os valores e armazena-los em memoria
DADOS *Ler();

//Realiza Inicialização da Lista
DADOS *Init(DADOS *L, DADOS *aux, int entrada);

// Realiza a inserção de dados
DADOS *Add(DADOS *aux, int entrada);

// Realiza Remoção de Um Elemento
DADOS * Rmv(DADOS *L, int pos);

// Realiza a Remoção de Multiplos Elementos em Sequência
//DADOS * Rmvs(DADOS *L, int pos, int fim);

// Remove Lista Inteira
//DADOS * Rmva(DADOS *L)

// Exibe Todas os Dados na Lista
void ShowList(DADOS *L);

// Exibe Elemento Especificado na Lista
void ShowElement(DADOS *L, int pos);

#endif
