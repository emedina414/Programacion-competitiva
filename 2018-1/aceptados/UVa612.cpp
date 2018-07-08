#include <iostream>
#include <algorithm>

using namespace std;

struct DNA{
	char str[51];
	int sort;

	void init(){ sort = 0;}
};

bool sort_func(DNA a, DNA b){ return a.sort < b.sort;}

int main(){
	int n;
	scanf("%d", &n);
	getchar();
	getchar();

	while(n > 0){
		int m, num;
		scanf("%d%d", &m, &num);
		DNA dna[num];
		for(int i = 0; i < num; i++) dna[i].init();

		int aux = 0;
		while(aux < num){
			scanf("%s", dna[aux].str);
			aux++;
		}

		for(int i = 0; i < num; i++){
			for(int j = 0; j < m; j++){
				for(int k = j+1; k < m; k++){
					if(dna[i].str[j] > dna[i].str[k]) dna[i].sort++;
				}
			}
		}

		stable_sort(dna, dna + num, sort_func);

		for(int i = 0; i < num; i++){
			cout << dna[i].str << endl;
		}
		if(n > 1) cout << endl;

		n--;
	}

}