#include <stdio.h>
#include <vector>

using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	getchar();
	while(N--){
		int P;
		scanf("%d", &P);
		vector<int> v[P];
		int i = 0;
		int min = 1001;

		vector<int> cases(P, 0);
		while(P--){
			int aux;
			while(scanf("%d", &aux) == 1){
				char c = getchar();
				if(c != '\n'){
					v[i].push_back(aux);
				}else{
					v[i].push_back(aux);
					if(v[i].size() == min){
						cases.push_back(i+1);
					}else if(v[i].size() < min){
						min = v[i].size();
						cases.clear();
						cases.push_back(i+1);
					}
					i++;
					break;
				}
			}
		}
		for(int k = 0; k < cases.size(); k++){
			if(k == cases.size() - 1) printf("%d\n", cases[k]);
			else printf("%d ", cases[k]);
		}
	}

	return 0;
}