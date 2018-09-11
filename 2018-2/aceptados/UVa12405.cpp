#include <stdio.h>

int main(){
	int t, n;
	scanf("%d", &t);

	char buffer[102];
	int c = 1;
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < 102; i++) buffer[i] = '#';
		scanf("%s", buffer);

		int cnt = 0;
		for(int i = 0; i < n; i++){
			if(buffer[i] == '#') continue;
			if(buffer[i+1] == '.' || (buffer[i+1] == '#' && buffer[i+2] == '.')){
				buffer[i] = '#';
				buffer[i+1] = '#';
				buffer[i+2] = '#';
				cnt++;
			}
		}

		for(int i = 0; i < n; i++){
			if(buffer[i] == '.'){
				buffer[i] = '#';
				buffer[i+1] = '#';
				if(i > 0) buffer[i-1] = '#';
				cnt++;
			}
		}

		printf("Case %d: %d\n", c, cnt);
		c++;
	}

	return 0;
}