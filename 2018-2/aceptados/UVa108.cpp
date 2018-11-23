/* Idea extraida de: 
			https://www.redgreencode.com/three-ways-solve-uva-108/
*/

/*Se usa el algoritmo de Kadane para dos dimensiones.*/

/*Se modelan los subrectangulos como un vector de una dimensión
	sumando verticalmente las columnas de la matriz, sobre esto se
	aplica el algoritmo de Kadane para encontrar la suma máxima*/
#include <stdio.h>

int main(){
	int N;
	scanf("%d", &N);

	int m[N][N];
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			scanf("%d", &m[i][j]);

	int max = -150, sum, aux;
	for(int i = 0; i < N; i++){
		int m2[N] = {};
		for(int j = i; j < N; j++){
			for(int k = 0; k < N; k++){
				m2[k] += m[j][k];
				sum = 0;
				aux = 0;
			}
			for(int k = 0; k < N; k++){
				aux += m2[k]; 
				if(aux > sum) sum = aux;
				if(aux < 0) aux = 0;
			}
			if(sum > max) max = sum;
		}
	}
	printf("%d\n", max);

	return 0;
}