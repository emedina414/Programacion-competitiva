#include <stdio.h>
#include <math.h>

int main(){
	int dp[1000001];
	dp[0] = 1;

	for(int i = 1; i < 1000001; i++){
		int x, y , z;
		x = (int)(i - sqrt(i));
		y = (int)log(i);
		z = (int)(i*sin(i)*sin(i));
		dp[i] = dp[x]%1000000 + dp[y]%1000000 + dp[z]%1000000;
	}

	int n;
	while(scanf("%d", &n)){
		if(n == -1) break;
		printf("%d\n", dp[n]%1000000);
	}
	return 0;
}