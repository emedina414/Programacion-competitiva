#include <iostream>
#include <cmath>
using namespace std;

int main(){

	int nums[2][1000000];
	int j = 1;
	int k = 0;

	while(scanf("%d", &nums[k][j]) == 1){
		char c = getchar();
		j++;

		if( c == '\n'){
			if(k == 0){
				nums[k][0] = j - 1;
				k++;
				j = 1;
			}else{
				nums[k][0] = j - 1;
				k = 0;
				j = 1;

				for(int i = 0; i < 1; i++){
					for(int l = 1; l <= nums[i+1][0]; l++){
						int aux = nums[i][0];
						int n = 0;
						for(int m = 1; m <= nums[i][0]; m++){
							n += nums[i][m]*pow(nums[i+1][l], aux-1);
							aux--;
						}
						if(l == nums[i+1][0]){
							cout << n << endl;
						}else{
							cout << n << " ";
						}
					}
				}
			}
		}
	}

	return 0;
}