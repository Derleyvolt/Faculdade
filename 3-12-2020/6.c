// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int atual_ano, atual_mes, atual_dia;
    int ano, mes, dia;
    scanf("%d%d%d", &atual_ano, &atual_mes, &atual_dia);
    scanf("%d%d%d", &ano, &mes, &dia);
    
    int qtd_dias_18_anos = 365 * 18;
    int qtd_dias_66_anos = 365 * 66;
    
    int qtd_dias_usuario = (atual_ano - ano) * 365 + (atual_mes - mes) * 30 + (atual_dia - dia);
    
    if(qtd_dias_usuario >= qtd_dias_18_anos && qtd_dias_usuario < qtd_dias_66_anos)
        printf("eleitor obrigatorio");
    else
        printf("eleitor facultativo");
    return 0;
}