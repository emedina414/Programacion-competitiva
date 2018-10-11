#include <stdio.h>
#include <vector>

using namespace std;

int main(){
	int n;
	vector<unsigned> dp(51, 0);
	dp[0] = dp[1] = 1;
	while(1){
		scanf("%d", &n);
		if(n == 0) break;
		if(dp[n-2] == 0 || dp[n-1] == 0){
			for(int i = 2; i <= n; i++){
				dp[i] = dp[i-1] + dp[i-2];
			}
			printf("%u\n", dp[n]);
		}else{
			printf("%u\n", dp[n-1] + dp[n-2]);
		}
	}
}