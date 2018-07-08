#include <iostream>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>

using namespace std;

struct project{
	string name;
	map<string,int> stud;
	int num;

	void init(){ num = 0;}
};

bool sort_func(project a, project b){
	if(a.num != b.num) return a.num > b.num;
	return a.name < b.name;
}

int main(){

	while(1){
		project proj[100];
		for(int j = 0; j < 100; j++) proj[j].init();
		map<string,int> map;
		string str;
		int i = -1;
		getline(cin, str);

		if(str != "0"){
			while(1){
				if(str == "1"){
					sort(proj, proj + i+1, sort_func);
					for(int j = 0; j < i+1; j++) cout << proj[j].name << " " << proj[j].num << endl;
					break;
				}
				if(str == "0") break;

				if(islower(str[0]) == 0){
					i++;
					proj[i].name = str;
					getline(cin, str);
				}else if(islower(str[0])){
					bool aux = false;
					if(map.count(str) != 0){
						aux = true;
						for(int j = 0; j < i; j++){
							if(proj[j].stud.count(str) != 0){
								proj[j].num--;
								proj[j].stud.erase(str);
							}
						}
					}

					if(!aux){
						proj[i].stud.insert(make_pair(str,0));
						proj[i].num++;
						map.insert(make_pair(str,0));
					}
					getline(cin, str);
				}
			}
		}else{
			break;
		}
	}

	return 0;
}