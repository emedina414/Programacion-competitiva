#include <iostream>
#include <cstring>

using namespace std;

typedef struct{
	char* name;
	int cnt;
} COUNTRY;

int main(){

	int n;
	cin >>n;
	getchar();

	char line[n][76];
	char* cntry[n];
	int k = 0;
	while(n > 0){
		string str;
		getline(cin, str);
		strcpy(line[k], str.c_str());
		cntry[k] = strtok(line[k], " ");
		k++; n--;
	}

	bool verif[k];
	for(int i = 0; i < k; i++) verif[i] = false;

	int cnt = 0;
	for(int i = 0; i < k; i++){
		if(!verif[i]){
			char aux[strlen(cntry[i])+1];
			strcpy(aux, cntry[i]);
			verif[i] = true;
			cnt++;

			for(int j = i+1; j < k; j++){
				if(strcmp(aux, cntry[j]) == 0){
					verif[j] = true;
				}
			}
		}
	}

	COUNTRY c[cnt];
	for(int i = 0; i < k; i++) verif[i] = false;

	int m = 0;
	for(int i = 0; i < k; i++){
		if(!verif[i]){
			int cnt1 = 0;
			char aux[strlen(cntry[i])+1];
			strcpy(aux, cntry[i]);
			c[m].name = cntry[i];
			verif[i] = true;
			cnt1++;

			for(int j = i+1; j < k; j++){
				if(strcmp(aux, cntry[j]) == 0){
					verif[j] = true;
					cnt1++;
				}
			}
			c[m].cnt = cnt1;
			m++;
			cnt1 = 0;
		}
	}

	for(int i = 0; i < cnt-1; i++){
		for(int j = i+1; j < cnt; j++){
			for(int l = 0; l < min(strlen(c[i].name), strlen(c[j].name)); l++){
				if((int)tolower(c[j].name[l]) < (int)tolower(c[i].name[l])){
					swap(c[i], c[j]);
					break;
				}else if((int)tolower(c[j].name[l]) > (int)tolower(c[i].name[l])){
					break;
				}
			}
		}
	}

	for(int i = 0; i < cnt; i++) cout << c[i].name << " " << c[i].cnt << endl;


	return 0;
}