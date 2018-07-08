#include <iostream>
#include <cmath>
#include <cstring>
#include <stdlib.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	getchar();

	while(n > 0){
		getchar();
		string str1;
		getline(cin, str1);
		char cstr1[str1.length()+1];
		strcpy(cstr1, str1.c_str());

		int j = 1;
		for(int i = 0; i < strlen(cstr1); i++){
			if(cstr1[i] == ' ') j++;
		}

		int pos[j];
		int k = 0;
		int l = 0;
		int m = 0;
		int p = 0;
		while(k <= strlen(cstr1)){
			if(cstr1[k] != ' ' && cstr1[k] != '\0'){
				l++;
			}else{
				pos[m] = 0;
				for(int i = p; i < p+l; i++){
					pos[m] += (cstr1[i] - 48)*pow(10, p+l-i-1);
				}
				l = 0;
				p = k+1;
				m++;
			}

			k++;
		}

		string str2;
		getline(cin, str2);
		char cstr2[str2.length()+1];
		strcpy(cstr2, str2.c_str());

		int q = 0;
		char* nums[j];
		nums[q] = strtok(cstr2, " ");
		while(nums[q] != NULL){
			q++;
			if(q == j) break;
			nums[q] = strtok(NULL, " ");
		}
		
		for(int i = 0; i < j; i++){
			m = i+1;
			for(int r = 0; r < j; r++){
				if(pos[r] == m) cout << nums[r] << endl;
			}
		}

		if(n > 1) cout << endl;
		n--;
	}

	return 0;
}