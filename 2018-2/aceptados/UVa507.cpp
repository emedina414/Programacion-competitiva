#include <stdio.h>

int main(){
	int b, s, m1[20001], n;
	scanf("%d", &b);
	n = 1;
	while(b--){
		scanf("%d", &s);
		for(int i = 0; i < s-1; i++){
			scanf("%d", &m1[i]);
		}

		int max = 0, aux = 0, aux1 = 1, x1 = 1, x2 = 1, verif = 1;
		for(int i = 0; i < s-1; i++){
			aux += m1[i];
			if(aux < 0){
				aux = 0;
				aux1 = i + 2;
			}else if(aux > max){
				verif = 0;
				max = aux;
				x1 = aux1;
				x2 = i + 2;
			}else if(aux == max){
				verif = 0;
				if((i+2 - aux1) > (x2 - x1)){
					x1 = aux1;
					x2 = i + 2;
				}
			}
		}

		if(verif) printf("Route %d has no nice parts\n", n);
		else printf("The nicest part of route %d is between stops %d and %d\n", n, x1, x2);
		n++;
	}

	return 0;
}