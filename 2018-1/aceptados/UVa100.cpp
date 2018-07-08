#include <iostream>

using namespace std;

int main(){

	int n1, n2;
	int aux1, aux2;

	while(scanf("%d %d", &n1, &n2) != EOF){

		int max = 1;
		bool verif = false;
		if(n1 > n2){
			int aux = n1;
			n1 = n2;
			n2 = aux;
			verif = true;
		}
		for(int i = n1; i <= n2 ; i++){
			int aux = i;
			int contador = 1;

			while(aux != 1){
				if(aux%2 != 0){
					aux = 3*aux + 1;
					contador++;
					continue;
				}else{
					aux = aux/2;
					contador++;
				}
			}
			if(contador > max) max = contador;
		}
		if(verif){
			int aux = n1;
			n1 = n2;
			n2 = aux;
		}
		cout << n1 << " " << n2 << " " << max << endl;
	}

	return 0;
}