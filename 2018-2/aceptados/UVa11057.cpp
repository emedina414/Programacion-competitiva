#include <stdio.h>
#include <queue>

using namespace std;

int main(){

	int n, m;
	while(scanf("%d", &n) != EOF){
		int arr[n];
		priority_queue<int> pq;

		for(int i = 0; i < n; i++){
			int aux;
			scanf("%d", &aux);
			getchar();
			pq.push(aux);
		}

		for(int i = n - 1; i >= 0; i--){
			arr[i] = pq.top();
			pq.pop();
		}
		scanf("%d", &m);
		getchar();

		int a, b, d;
		d = 0;
		for(int i = 0; i < n - 1; i++){
			for(int j = i + 1; j < n; j++){
				if(arr[i] + arr[j] > m){
					break;
				}else if(arr[i] + arr[j] == m){
					if(d != 0){
						if(arr[j] - arr[i] < d){
							d = arr[j] - arr[i];
							a = arr[i];
							b = arr[j];
						}
					}else{
						d = arr[j] - arr[i];
						a = arr[i];
						b = arr[j];
					}
				}
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n", a, b);
	}

	return 0;
}