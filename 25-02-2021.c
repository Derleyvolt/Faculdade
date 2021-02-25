#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct info {
   char nome[100];
   int  matricula;
   int  DDD;
   int  telefone;
   char tipo;
};

int read_file(struct info* reg, int argc, char ** argv) {
    int cnt = 0;
    if(argc > 1) {
        FILE* file = fopen(argv[1], "r");
        while(fscanf(file, "%s", reg[cnt].nome) == 1) {
            fscanf(file, "%d",  &reg[cnt].matricula);
            fscanf(file, "%d",  &reg[cnt].DDD);
            fscanf(file, "%d",  &reg[cnt].telefone);
            fscanf(file, " %c", &reg[cnt].tipo);
            cnt++;
        }

        fclose(file);
    }
    return cnt;
}

void menu() {
    printf("Menu:\n");
    printf("Buscar terlefone pelo nome: B\n");
    printf("Inserir novo registro: I\n");
    printf("Apagar registro pelo nome: A\n");
    printf("Listar nomes na agenda: L\n");
}

int main(int argc, char *argv[]) {
    struct info registros[1000];

    for(int i = 0; i < 1000; i++)
        registros[i].DDD = -1;

    read_file(registros, argc, argv);

    menu();

    char cmd;

    while(scanf("%c", &cmd)) {
        if(tolower(cmd) == 'b') {
            char nome[100];
            printf("digite um nome:\n");
            scanf("%s", nome);

            int is = 1;

            for(int i = 0; i < 1000; i++) {
                if(registros[i].DDD != -1 && strcmp(nome, registros[i].nome) == 0) {
                    printf("%s - (%d) %d (celular)\n", registros[i].nome, registros[i].DDD, registros[i].telefone);
                    is = 0;
                    break;
                }
            }

            if(is)
                printf("o usuario nao foi encontrado\n");
            sleep(1);
            system("clear");
            menu();
        } else if (tolower(cmd) == 'i') {
            int aux = -1;
            for(int i = 0; i < 1000; i++) {
                if(registros[i].DDD == -1) {
                    aux = i;
                    break;
                }
            }

            if(aux == -1) {
                printf("a lista esta cheia!!!");
                sleep(2);
                system("clear");
                menu();
                continue;
            }

            printf("digite um nome:\n");
            scanf("%s", registros[aux].nome);

            printf("digite uma matricula:\n");
            scanf("%d", &registros[aux].matricula);

            printf("digite um DDD:\n");
            scanf("%d", &registros[aux].DDD);

            printf("digite um telefone:\n");
            scanf("%d", &registros[aux].telefone);

            printf("digite um tipo:\n");
            scanf("%c", &registros[aux].tipo);

            sleep(2);
            system("clear");
            menu();
        } else if (tolower(cmd) == 'a') {
            char nome[100];
            printf("digite o nome a ser apagado:\n");
            scanf("%s", nome);
            int is = 1;
            for(int i =0; i < 1000; i++) {
                if(registros[i].DDD != -1 && strcmp(registros[i].nome, nome) == 0) {
                    registros[i].DDD = -1;
                    is = 0;
                    break;
                }
            }

            if(is)
                printf("nome não encontrado.\n");
            else
                printf("registro deletado.\n");

            sleep(1);
            system("clear");
            menu();
        } else if(tolower(cmd) == 'l') {
            for(int i = 0; i < 1000; i++) {
                if(registros[i].DDD != -1)
                    printf("%s\n", registros[i].nome);
            }
            sleep(2);
            system("clear");
            menu();
        }
    }
    return 0;
}
