#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct contestant{
	int num;
	int ps;
	int time;
	bool disp;
	int probs[9];

	void init(int i){
		num = i;
		ps = time = 0;
		disp = false;
		for(int i = 0; i < 9; i++) probs[i] = 0;
	}
};

bool sort_func(contestant a, contestant b){
	if(a.ps != b.ps) return a.ps > b.ps;
	if(a.time != b.time) return a.time < b.time;
	return a.num < b.num;
}

int main(){
	int n;
	scanf("%d", &n);
	getchar();
	getchar();

	while(n > 0){
		contestant cont[101];
		for(int i = 0; i < 101; i++) cont[i].init(i);

		while(1){
			string str;
			getline(cin, str);
			if(str.length() < 7) break;
			int a, b, c;
			char d;
			sscanf(str.c_str(),"%d %d %d %c", &a, &b, &c, &d);

			cont[a].disp = true;
			if(cont[a].probs[b-1] == -1) continue;
			if(d == 'C'){
				cont[a].ps++;
				cont[a].time += c;
				if(cont[a].probs[b-1] > 0) cont[a].time += cont[a].probs[b-1]*20;
				cont[a].probs[b-1] = -1;
			}
			if(d == 'I') cont[a].probs[b-1] += 1;
		}

		stable_sort(cont, cont + 101, sort_func);

		for(int i = 0; i < 101; i++){
			if(cont[i].disp){
				cout << cont[i].num << " " << cont[i].ps << " " << cont[i].time << endl;
			}
		}
		if(n > 1) cout << endl;

		n--;
	}

	return 0;
}