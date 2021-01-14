#include <stdio.h>

int main(void) {
	int cartela[6];
	for(int i = 0; i<6; i++) scanf("%d", &cartela[i]);
	int resultado[6];
	for(int i = 0; i<6; i++) scanf("%d", &resultado[i]);
	
	int ans = 0;
	
	for(int i = 0; i < 6; i++) {
		for(int j = 0; j < 6; j++) {
			if(cartela[i] == resultado[j]) {
				ans++;
				break;
			}
		}
	}
	
	if(ans == 6)
		printf("O usuario acertou %d e fez a mega-sena", ans);
	else if(ans == 5)
		printf("O usuario acertou %d e fez a quina", ans);
	else if(ans == 4)
		printf("O usuario acertou %d e fez a quadra", ans);
	else
		printf("O usuario acertou %d", ans);	
	
	return 0;
}
