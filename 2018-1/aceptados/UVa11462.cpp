#include <iostream>
#include <algorithm>

using namespace std;

int main(){

	while(1){
		int n;
		scanf("%d", &n);
		if(n == 0) break;

		int ages[n];
		int aux = 0;
		while(aux < n){
			scanf("%d", &ages[aux]);
			aux++;
		}

		sort(ages, ages + n);
		for(int i = 0; i < n; i++){
			printf("%d", ages[i]);
			if(i < n-1) printf(" ");
		}
		printf("\n");
	}

	return 0;
}