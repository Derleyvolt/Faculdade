// Online C compiler to run C program online
#include <stdio.h>

int main() {
    char nome[200]; 
    int filhos;
    float horas, hora_trab;
    
    fgets(nome, 200, stdin);
    scanf("%f", &horas);
    scanf("%f", &hora_trab);
    scanf("%i", &filhos);
    
    float salario_bruto = horas * hora_trab;
    float acrescimo = 0;
    
    if(filhos > 3) {
        acrescimo     = filhos * 0.03;
        salario_bruto = salario_bruto * (1 + filhos * 0.03);
    }
    
    printf("%s", nome);
    printf("%f\n", salario_bruto);
    printf("%f\n", acrescimo);
    return 0;
}