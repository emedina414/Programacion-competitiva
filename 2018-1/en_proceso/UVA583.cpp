#include <iostream>
#include <cmath>
using namespace std;

bool* criba(int n){

	bool* primos = new bool[n+1];
	for(int i = 0; i < n+1; i++) primos[i] = true;
	primos[0] = false;
	primos[1] = false;

	for(int i = 2; i <= (int)sqrt(n); i++){
		if(primos[i]){
			for(int j = i*i; j <= n; j += i){
				primos[j] = false;
			}
		}
	}
	
	return primos;
}

int main(){

	int n;
	cin >> n;
	while(n != 0){

		int k;
		int fact[1000000];
		if(n < 0){
			fact[0] = -1;
			k = 1;
			n *= -1;
		}else{
			k = 0;
		}

		bool* primos = criba(n);

		int aux = n;
		for(int i = 2; i <= n; i++){
			if(primos[aux]){
				fact[k] = aux;
				break;
			}else if(primos[i] && aux == (int)pow(2, primos[i])){
				fact[k] = (int)pow(2, primos[i]);
			}else{
				while(primos[i] && aux%i == 0){
					fact[k] = i;
					aux = aux/i;
					if(aux != 1) k++;
				}
			}
		}

		for(int i = 0; i <= k; i++){
			if(i == 0) cout << n << " = ";
			if(i != k) cout << fact[i] << " x ";
			if(i == k) cout << fact[i] << endl;
		} 

		delete primos;
		cin >> n;
	}

	return 0; 
}