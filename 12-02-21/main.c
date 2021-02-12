#include "cadeia.h"

char arr[901][30];

void iniciar() {
	str_copia(arr[1],   "um");
	str_copia(arr[2],   "dois");
	str_copia(arr[3],   "tres");
	str_copia(arr[4],   "quatro");
	str_copia(arr[5],   "cinco");
	str_copia(arr[6],   "seis");
	str_copia(arr[7],   "sete");
	str_copia(arr[8],   "oito");
	str_copia(arr[9],   "nove");
	str_copia(arr[10],  "dez");
	str_copia(arr[11],  "onze");
	str_copia(arr[12],  "doze");
	str_copia(arr[13],  "treze");
	str_copia(arr[14],  "catorze");
	str_copia(arr[15],  "quinze");
	str_copia(arr[16],  "dezesseis");
	str_copia(arr[17],  "dezessete");
	str_copia(arr[18],  "dezoito");
	str_copia(arr[19],  "dezenove");
	str_copia(arr[20],  "vinte");
	str_copia(arr[30],  "trinta");
	str_copia(arr[40],  "quarenta");
	str_copia(arr[50],  "cinquenta");
	str_copia(arr[60],  "sessenta");
	str_copia(arr[70],  "setenta");
	str_copia(arr[80],  "oitenta");
	str_copia(arr[90],  "noventa");
	str_copia(arr[100], "cem");
	str_copia(arr[0],   "cento");
	str_copia(arr[200], "duzentos");
	str_copia(arr[300], "trezentos");
	str_copia(arr[400], "quatrocentos");
	str_copia(arr[500], "quinhentos");
	str_copia(arr[600], "seicentos");
	str_copia(arr[700], "setecentos");
	str_copia(arr[800], "oitocentos");
	str_copia(arr[900], "novecentos");
}

void parse(int n) { // 349
	if (n > 9 && n < 20) {
		printf("%s", arr[n]);
		return;
	}
	int dig_cnt = floor(log10(n)) + 1;
	int index[dig_cnt];
	int aux = 1, i = 0;
	while (n) {
		index[i++] = (n % 10) * aux;
		aux *= 10;
		n   /= 10;
	}

	if(dig_cnt == 3 && index[1] == 10) {
		if(index[2] == 100)
			printf("%s %s %s", arr[0], "e", arr[10+index[0]]);
		else
			printf("%s %s %s", arr[index[dig_cnt - 1]], "e", arr[10+index[0]]);
		return;
	}

	if (index[dig_cnt - 1] == 100) {
		if(index[0] != 0 || index[1] != 0)
		    printf("%s ", arr[0]);
		else {
			printf("cem");
			return;
		}
	} else
		printf("%s", arr[index[dig_cnt - 1]]);

	for (int i = dig_cnt - 2; i >= 0; i--) {
		if (index[i] != 0)
			printf(" e %s", arr[index[i]]);
	}
}

int main(void) {
	iniciar();
	int n; scanf("%d", &n);
	parse(n);
	return 0;
}