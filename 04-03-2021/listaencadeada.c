#include "listaencadeada.h"

void inserir(struct Agenda agenda, struct list* lista) {
    // tratamento pro primeiro nó
    if(lista->data.DDD == -1) {
        lista->data = agenda;
        return;
    } else {
        if(strcmp(agenda.nome, lista->data.nome) < 0) {
            struct Agenda temp = agenda;
            agenda = lista->data;
            lista->data = temp;
        }
    }

    if(lista->next == NULL) {
        lista->next       = malloc(sizeof(struct list));
        lista->next->data = agenda;
        lista->next->next = NULL;
    } else
        inserir(agenda, lista->next);
}

void mostrar(struct Agenda agenda, FILE* file) {
    if(file == NULL)
        file = stdout;

    fprintf(file, "%s\n", agenda.nome);
    fprintf(file, "%s\n", agenda.email);
    fprintf(file, "%d\n", agenda.telefone);
    fprintf(file, "%d\n", agenda.matricula);
    fprintf(file, "%d\n", agenda.DDD);
    fprintf(file, "%c\n", agenda.tipo);
}

void percorrer(struct list* lista) {
    if(lista->data.DDD != -1) {
        mostrar(lista->data, NULL);
        printf("\n");
    }

    if(lista->next == NULL)
        return;

    percorrer(lista->next);
}

void carregar(char* arquivo, struct list* lista) {
    FILE* file = fopen(arquivo, "r");
    struct Agenda aux;
    char arg[100];
    while(fgets(aux.nome, 100, file) != NULL) {
        if(strlen(aux.nome) == 1)
            break;
        fgets(aux.email, 100, file);
        fgets(arg, 100, file);
        sscanf(arg, "%d", &aux.telefone);
        fgets(arg, 100, file);
        sscanf(arg, "%d", &aux.matricula);
        fgets(arg, 100, file);
        sscanf(arg, "%d", &aux.DDD);
        fgets(arg, 100, file);
        sscanf(arg, " %c", &aux.tipo);

        aux.nome[strlen(aux.nome)-1]   = 0;
        aux.email[strlen(aux.email)-1] = 0;
        inserir(aux, lista);
    }
    fclose(file);
}

void salvar(char* arquivo, struct list* lista) {
    FILE* file = fopen(arquivo, "w");

    if(lista->data.DDD != -1)
        mostrar(lista->data, file);

    while(lista->next != NULL) {
        mostrar(lista->next->data, file);
        lista = lista->next;
    }

    fclose(file);
}
