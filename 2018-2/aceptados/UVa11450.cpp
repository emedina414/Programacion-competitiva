#include <stdio.h>

int main(){
	int N, M, C, p[21][21], mon[20][200];
	scanf("%d", &N);
	while(N--){
		scanf("%d %d", &M, &C);
		for(int i = 0; i < C; i++){
			scanf("%d", &p[i][0]);
			for(int j = 1; j <= p[i][0]; j++){
				scanf("%d", &p[i][j]);
			}
		}

		for(int i = 0; i < 20; i++){
			for(int j = 0; j < 200; j++){
				mon[i][j] = 0;
			}
		}

		for(int i = 1; i <= p[0][0]; i++){
			if(M - p[0][i] >= 0) mon[0][M - p[0][i]] = 1;
		}

		for(int i = 1; i < C; i++){
			for(int j = 0; j < M; j++){
				if(mon[i-1][j]){
					for(int k = 1; k <= p[i][0]; k++){
						if(j - p[i][k] >= 0){
							mon[i][j - p[i][k]] = 1;
						}
					}
				}
			}
		}

		int money;
		for(int i = 0; i < M; i++){
			if(mon[C-1][i]){
				money = i;
				break;
			}
			if(i == M-1) money = -1;
		}

		if(money != -1){
			printf("%d\n", M - money);
		}else{
			printf("no solution\n");
		}
	}

	return 0;
}
