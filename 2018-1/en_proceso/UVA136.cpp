#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

bool* criba( ull n ){

	bool* primos = new bool[n+1];
	for( ull i = 0; i < n+1; i++ ) primos[i] = true;
	primos[0] = false;
	primos[1] = false;

	for( ull i = 2; i <= (ull)sqrt(n); i++ ){
		if( primos[i] == true ){
			for(ull j = i*i; j <= n; j += i ){
				primos[j] = false;
			}
		}
	}
	
	return primos;
}

int uglyNumbers( bool* primos, ull n ){

	int contador = 0;

	bool* ugly = new bool[n*5 + 1];
	for(ull i = 0; i < n*5 + 1; i++ ) ugly[i] = false;
	ugly[1] = true;
	ugly[2] = true;
	ugly[3] = true;
	ugly[5] = true;
	ugly[4] = true;
	ugly[6] = true;
	ugly[10] = true;
	ugly[9] = true;
	ugly[15] = true;
	ugly[25] = true;
 
	for( ull i = 2; i <= n; i++ ){
		if( !primos[i] ){
			ugly[i*2] = true;
			ugly[i*3] = true;
			ugly[i*5] = true;
		} 
	}

	for( ull i = 2; i <= n; i++ ){
		if( primos[i] && i != 2 && i != 3 && i != 5 ){
			for( ull j = 2; true ; j++ ){
				if( i*j > n*5 ) break;
				ugly[i*j] = false;
			}
		}
	}

	for( ull i = 0; i <= n; i++ ){
		if( ugly[i] ) contador++;
	}

	delete ugly;
	return contador;
}

int main( int argc, char* argv[] ){

	ull n;
	cin >> n;

	ull contador = 0;
	bool* primos = criba( n );

	int feos = uglyNumbers( primos, n );
	cout << feos << endl;

	delete primos;

	return 0;
}