#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int mayor(int n1, int n2, int n3){
	if(n1 > n2 && n1 > n3) return n1;
	if(n2 > n1 && n2 > n3) return n2;
	if(n3 > n1 && n3 > n2) return n3;
}

int main(){
	int n;
	cin >> n;

	int cases[20];
	int l = 0;
	while(n > 0){
		int i_aux[3];
		scanf("%d%d%d", &i_aux[0], &i_aux[1], &i_aux[2]);

		int i_aux2[2];
		int m = 0;
		for(int i = 0; i < 3; i++){
			if(i_aux[i] != mayor(i_aux[0], i_aux[1], i_aux[2])){
				i_aux2[m] = i_aux[i];
				m++;
			}
		}

		if(i_aux2[0] > i_aux2[1]) cases[l] = i_aux2[0];
		else cases[l] = i_aux2[1];

		l++;
		n--;
	}

	for(int i = 0; i < l; i++){
		printf("Case %d: %d\n", i+1, cases[i]);
	}

	return 0;
}