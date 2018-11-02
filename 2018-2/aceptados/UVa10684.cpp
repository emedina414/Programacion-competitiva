#include <stdio.h>

int main(){
	int N, max, tmp, aux;
	while(1){
		scanf("%d", &N);
		if(N){
			max = 0;
			aux = 0;
			for(int i = 0; i < N; i++){
				scanf("%d", &tmp);
				aux += tmp;
				if(max < aux) max = aux;
				if(aux < 0) aux = 0;
			}
			if(max == 0) printf("Losing streak.\n");
			else printf("The maximum winning streak is %d.\n", max);
		}else{
			break;
		}
	}


	return 0;
}