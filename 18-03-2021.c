#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Agenda {
    char*  nome;
    int    matricula;
    int    telefone;
    int    ddd;
    char   tipo;
};

struct List {
    struct Agenda agenda;
    struct List *ante, *prox;
};

// pointer to pointer: addr -> mem -> mem -> value

struct List* agd_inserir_inicio(struct List* list, struct Agenda agenda) {
    if(list == NULL) {
        list = (struct List*)malloc(sizeof(struct List));
        list->ante   = NULL;
        list->prox   = NULL;
        list->agenda = agenda;
        return list;
    } else {
        struct List* temp = (struct List*)malloc(sizeof(struct List));
        temp->prox   = list;
        temp->ante   = NULL;
        temp->agenda = agenda;
        list->ante   = temp; 
        return temp;
    }   
}

struct List* agd_inserir_final(struct List* list, struct Agenda agenda) {
    struct List* aux;
    if(list == NULL) {
        aux         = (struct List*)malloc(sizeof(struct List));
        aux->ante   = NULL;
        aux->prox   = NULL;
        aux->agenda = agenda; // verifica uma coisa..
        return aux;
    } else {
        struct List* temp = list;
        while(temp->prox != NULL)
            temp = temp->prox;
        temp->prox         = (struct List*)malloc(sizeof(struct List));
        temp->prox->agenda = agenda;
        temp->prox->ante   = temp;
        temp->prox->prox   = NULL;
        return list;
    }
}

struct List* agd_remover(struct List* list, char *nome) {
    struct List* temp = list;
    while(temp != NULL) {
        if(strcmp(temp->agenda.nome, nome) == 0) {
            free(temp->agenda.nome);
            // 4 casos possíveis
            if(temp->prox == NULL && temp->ante == NULL) {
                free(temp);
                return NULL;
            } else if(temp->prox == NULL) {
                temp->ante->prox = NULL;
                free(temp);
                return list;
            } else if(temp->ante == NULL) {
                if(temp->prox->prox != NULL) {
                    temp->prox             = temp->prox->prox;
                    temp->prox->prox->ante = temp;
                }
                struct List* aux = temp->prox;
                temp->prox->ante = NULL;
                free(temp);
                return aux;
            } else { // prox != NULL and ante != NULL
                struct List* aux = temp->ante;
                aux->prox = temp->prox;
                temp->prox->ante = aux;
                free(temp);
                return list;
            }
        } else
            temp = temp->prox;
    }
    return list;
}

void agd_ordenar(struct List* list) {
    for(struct List* ptr = list; ptr != NULL; ptr = ptr->prox) {
        for(struct List* inner_ptr = ptr->prox; inner_ptr != NULL; inner_ptr = inner_ptr->prox) {
            if(strcmp(ptr->agenda.nome, inner_ptr->agenda.nome) > 0) {
                char* temp             = ptr->agenda.nome;
                ptr->agenda.nome       = inner_ptr->agenda.nome;
                inner_ptr->agenda.nome = temp;
            }
        }
    }
}

void mostrar_lista(struct List* list) {
    if(list != NULL) {
        printf("%s\n", list->agenda.nome);
        printf("%d\n", list->agenda.telefone);
        printf("%d\n", list->agenda.matricula);
        printf("%d\n", list->agenda.ddd);
        printf("%c\n", list->agenda.tipo);
        mostrar_lista(list->prox);
    }
}

int main() {
    struct List* lista = NULL;

    int n; printf("Digite o numero de registros que serão inseridos:\n");
    scanf("%d", &n);

    struct Agenda *agenda = (struct Agenda*)malloc(n * sizeof(struct List));

    char buff[1000];

    for(int i = 0; i < n; i++) {
        getchar(); // consumindo o newline deixado pelo scanf..
        printf("digite o nome:\n");
        fgets(buff, 1000, stdin);
        buff[strlen(buff)-1] = 0;
        agenda[i].nome = (char*)malloc(strlen(buff)+1);
        strcpy(agenda[i].nome, buff);
        printf("digite telefone:\n");
        scanf("%d", &agenda[i].telefone);
        printf("digite matricula:\n");
        scanf("%d", &agenda[i].matricula);
        printf("digite ddd:\n");
        scanf("%d", &agenda[i].ddd);
        printf("digite tipo:\n");
        scanf(" %c", &agenda[i].tipo);
        printf("\n");
    }

    for(int i = 0; i < n; i++) 
        lista = agd_inserir_inicio(lista, agenda[i]);
    lista = agd_remover(lista, (char*)"Urubu cuspidor");
    agd_ordenar(lista);
    mostrar_lista(lista);
}
