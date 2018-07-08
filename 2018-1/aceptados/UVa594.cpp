#include <iostream>
#include <climits>

using namespace std;

int main(){

	int num;
	while(scanf("%d", &num) != EOF){
		signed int a, b, c, d, aux;
		a = b = c = d = num;
		aux = 255;

		a = (a << 24)&(aux << 24);
		d = (d >> 24)&(aux);
		b = (b << 8)&(aux << 16);
		c = (c >> 8)&(aux << 8);

		a = (((a|b)|c)|d);
		cout << num << " converts to " << a << endl;
	} 

	return 0;
}