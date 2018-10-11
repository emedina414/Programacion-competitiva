#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	bool f = false;
	while(n){
		if(f) printf("\n");
		f = true;
		bool flag = false;
		for(int i = 1234; i <= 98765/n; i++){
			int a = i*n;
			bool verif[10];
			bool flag1 = false;
			for(int j = 0; j < 10; j++) verif[j] = false;

			int aux = a;
			while(aux){
				if(verif[aux%10] == false){
					verif[aux%10] = true;
					aux /= 10;
				}else{
					flag1 = true;
					break;
				}
			}

			if(!flag1){
				aux = i;
				while(aux){
					if(verif[aux%10] == false){
						verif[aux%10] = true;
						aux /= 10;
					}else{
						flag1 = true;
						break;
					}
				}
			}

			if(a < 10000 || i < 10000){
				if(verif[0] == false) verif[0] = true;
				else flag1 = true;
			}

			if(!flag1){
				for(int k = 0; k < 10; k++){
					if(!verif[k]){
						flag1 = true;
						break;
					}
				}
			}

			if(!flag1){
				printf("%.5d / %.5d = %d\n", a, i, n);
				flag = true;
			}
		}
		if(!flag) printf("There are no solutions for %d.\n", n);
		scanf("%d", &n);
	}

	return 0;
}