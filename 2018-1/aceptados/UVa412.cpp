#include <iostream>
#include <cmath>

using namespace std;

int euclidean_gcd(int num1, int num2){

	if(num1 == num2) return num1;

	while(num1 != num2){

		if(num1 > num2){
			num1 -= num2;
		}else{
			num2 -= num1;
		}
	}

	return num1;
}

int main(int argc, char* argv[]){

	int nums[10000][51];

	int index = 0;
	
	while(true){

		int n;
		cin >> n;

		if(n == 0) break;

		nums[index][0] = n;

		for(int i = 1; i < n+1; i++) cin >> nums[index][i];

		index++;
	}

	for(int i = 0; i < index; i++){

		int n = nums[i][0];
		int max = (n*(n-1))/2;
		int count = 0;

		for(int j = 1; j < n; j++){
			for(int k = j+1; k < n+1; k++){

				if(euclidean_gcd(nums[i][j], nums[i][k]) == 1){
					count++;
				}
			}
		}

		if( count != 0){
			double pi = sqrt( 6*(double)max/(double)count );
			printf("%.6lf\n", pi);
		}else{
			printf("No estimate for this data set.\n");
		}
	}

	return 0;
}