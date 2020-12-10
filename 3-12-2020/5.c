// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int ano;
    scanf("%d", &ano);
    if(ano % 4 == 0 && (ano % 100 != 0 || (ano % 100 == 0 && ano % 400 == 0)))
        printf("o ano %d%s", ano, " e bisexto");
    else
        printf("o ano %d%s", ano, " nao e bisexto");
}