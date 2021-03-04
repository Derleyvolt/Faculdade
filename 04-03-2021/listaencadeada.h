#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Agenda {
    char nome[30];
    char email[50];
    int  telefone;
    int  matricula;
    int  DDD;
    char tipo;
};

struct list {
    struct Agenda data;
    struct list *next;
};

void inserir(struct Agenda agenda, struct list* lista);
void mostrar(struct Agenda agenda, FILE* file);
void percorrer(struct list* lista);
void carregar(char* arquivo, struct list* lista);
void salvar(char* arquivo, struct list* lista);

#endif // LISTAENCADEADA_H
