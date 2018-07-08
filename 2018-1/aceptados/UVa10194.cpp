#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

struct team{
	string name;
	int p;
	int gp;
	int gs;
	int ga;
	int w;
	int t;
	int l;
};

struct tournament{
	string name;
	team teams[30];
};

bool teams_sort(team a, team b){
	if(a.p != b.p) return a.p > b.p;
	if(a.w != b.w) return a.w > b.w;
	if((a.gs - a.ga) != (b.gs - b.ga)) return (a.gs - a.ga) > (b.gs - b.ga);
	if(a.gs != b.gs) return a.gs > b.gs;
	if(a.gp != b.gp) return a.gp < b.gp;
	char buff1[a.name.length()], buff2[b.name.length()];
	for(int i = 0; i < a.name.length(); i++) buff1[i] = tolower(a.name[i]);
	for(int i = 0; i < b.name.length(); i++) buff2[i] = tolower(b.name[i]);
	return strcmp(buff1 , buff2) < 0;
}

int main(){

	int n;
	scanf("%d", &n);
	getchar();

	while(n > 0){
		int nt, nt_aux, g;
		tournament t;
		for(int i = 0; i < 30; i++){
			t.teams[i].p = 0;
			t.teams[i].gp = 0;
			t.teams[i].gs = 0;
			t.teams[i].ga = 0;
			t.teams[i].w = 0;
			t.teams[i].t = 0;
			t.teams[i].l = 0;
		}

		getline(cin, t.name);
		scanf("%d", &nt);
		getchar();
		nt_aux = 0;
		while(nt_aux < nt){
			getline(cin, t.teams[nt_aux].name);
			nt_aux++;
		}

		scanf("%d", &g);
		getchar();
		while(g > 0){
			int k = 0;
			string str;
			getline(cin, str);
			char cstr[str.length()], *info[4];
			strcpy(cstr, str.c_str());

			info[k] = strtok(cstr, "#@");
			k++;
			while(k < 4){
				info[k] = strtok(NULL, "#@");
				k++;
			}

			for(int i = 0; i < nt; i++){
				if(strcmp(info[0],t.teams[i].name.c_str()) == 0){
					t.teams[i].gp++;
					int gs = 0;
					int ga = 0;
					for(int i = 0; i < strlen(info[1]); i++){
						gs += (info[1][i] - 48)*pow(10,strlen(info[1]) - i - 1);
					}
					for(int i = 0; i < strlen(info[2]); i++){
						ga += (info[2][i] - 48)*pow(10,strlen(info[2]) - i - 1);
					}
					t.teams[i].gs += gs;
					t.teams[i].ga += ga;

					if(gs > ga){
						t.teams[i].w++;
						t.teams[i].p += 3;
					}else{
						if(gs == ga){
							t.teams[i].t++;
							t.teams[i].p += 1;
						}else{
							if(gs < ga){
								t.teams[i].l++;
							}
						}
					}
					break;
				}
			}

			for(int i = 0; i < nt; i++){
				if(strcmp(info[3],t.teams[i].name.c_str()) == 0){
					t.teams[i].gp++;
					int gs = 0;
					int ga = 0;
					for(int i = 0; i < strlen(info[2]); i++){
						gs += (info[2][i] - 48)*pow(10,strlen(info[2]) - i - 1);
					}
					for(int i = 0; i < strlen(info[1]); i++){
						ga += (info[1][i] - 48)*pow(10,strlen(info[1]) - i - 1);
					}
					t.teams[i].gs += gs;
					t.teams[i].ga += ga;
					if(gs > ga){
						t.teams[i].w++;
						t.teams[i].p += 3;
					}else{
						if(gs == ga){
							t.teams[i].t++;
							t.teams[i].p += 1;
						}else{
							if(gs < ga){
								t.teams[i].l++;
							}
						}
					}
					break;
				}
			}
			g--;
		}

		stable_sort(t.teams, t.teams + nt, teams_sort);

		cout << t.name << endl;
		for(int i = 0; i < nt; i++){
			cout << i+1 << ") " << t.teams[i].name << " " << t.teams[i].p << "p, ";
			cout << t.teams[i].gp << "g " << "(" << t.teams[i].w << "-" << t.teams[i].t;
			cout << "-" << t.teams[i].l << "), " << t.teams[i].gs - t.teams[i].ga;
			cout << "gd " << "(" << t.teams[i].gs << "-" << t.teams[i].ga << ")" << endl;
		}
		if(n > 1) cout << endl;
		n--;
	}

	return 0;
}