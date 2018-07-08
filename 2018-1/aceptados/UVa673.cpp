#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

bool parenth_bal(string buff){
	stack<char> st;
	for(int i = 0; i < buff.length(); i++){
		if(buff[i] == '(' || buff[i] == '['){
			st.push(buff[i]);
		}else if(buff[i] == ')'){
			if(st.empty()) return false;
			else if(st.top() != '(') return false;
			else st.pop();
		}else if(buff[i] == ']'){
			if(st.empty()) return false;
			else if(st.top() != '[') return false;
			else st.pop();
		}
	}
	if(st.empty()) return true;
	else return false;
}

int main(){
	int n;
	scanf("%d", &n);
	getchar();

	while(n > 0){
		string buff;
		getline(cin, buff);

		if(parenth_bal(buff)) cout << "Yes" << endl;
		else cout << "No" << endl;

		n--;
	}

	return 0;
}