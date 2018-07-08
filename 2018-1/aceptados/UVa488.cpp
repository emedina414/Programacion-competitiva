#include <iostream>

using namespace std;

int main(int argc, char* argv[]){

	int n;
	cin >> n;

	while(n > 0){

		int amp, freq;
		cin >> amp;
		cin >> freq;

		for(int i = 0; i < freq; i++){
			for(int j = 1; j <= amp; j++){
				for(int k = 0; k < j; k++){
					cout << j;
				}
				cout << endl;
			}

			for(int j = amp-1; j > 0; j--){
				for(int k = 0; k < j; k++){
					cout << j;
				}
				cout << endl;
			}

			if(i != freq - 1) cout << endl;
		}
		if(n != 1) cout << endl;

		n--;
	}

	return 0;
}