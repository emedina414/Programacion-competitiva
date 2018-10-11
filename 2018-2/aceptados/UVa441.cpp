#include <stdio.h>

int main(){
	int k;
	scanf("%d", &k);
	bool f = false;
	while(k){
		if(f) printf("\n");
		f = true;
		int s[k];
		for(int i = 0; i < k; i++) scanf("%d", &s[i]);
		getchar();

		for(int j = 0; j < k-5; j++){
			for(int l = j+1; l < k-4; l++){
				for(int m = l+1; m < k-3; m++){
					for(int n = m+1; n < k-2; n++){
						for(int o = n+1; o < k-1; o++){
							for(int p = o+1; p < k; p++){
								printf("%d %d %d %d %d %d\n", s[j], s[l], s[m], s[n], s[o], s[p]);
							}
						}
					}
				}
			}
		}
		scanf("%d", &k);
		getchar();
	}

	return 0;
}