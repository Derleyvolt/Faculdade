#include "cadeia.h"

int str_tamanho(char* s) {
	int it = 0;
	while(s[it++] != '\0');
	return it;
}

void str_concatena(char* s, char* d) {
	int length = str_tamanho(s);
	int it = 0;
	do {
        s[length+it-1] = d[it];
	} while(d[it++] != '\0');
}

void str_copia(char* s, char* d) {
	int length = str_tamanho(d);
	for(int i = 0; i < length; i++)
		s[i] = d[i];
}