#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <stdlib.h>

using namespace std;

int main(){

	map<string,char> _map;
	
  _map[".-"] = 'A';
  _map["-..."] = 'B';
  _map["-.-."] = 'C';
  _map["-.."] = 'D';
  _map["."] = 'E';
  _map["..-."] = 'F';
  _map["--."] = 'G';
  _map["...."] = 'H';
  _map[".."] = 'I';
  _map[".---"] = 'J';
  _map["-.-"] = 'K';
  _map[".-.."] = 'L';
  _map["--"] = 'M';
  _map["-."] = 'N';
  _map["---"] = 'O';
  _map[".--."] = 'P';
  _map["--.-"] = 'Q';
  _map[".-."] = 'R';
  _map["..."] = 'S';
  _map["-"] = 'T';
  _map["..-"] = 'U';
  _map["...-"] = 'V';
  _map[".--"] = 'W';
  _map["-..-"] = 'X';
  _map["-.--"] = 'Y';
  _map["--.."] = 'Z';

  _map["-----"] = '0';
  _map[".----"] = '1';
  _map["..---"] = '2';
  _map["...--"] = '3';
  _map["....-"] = '4';
  _map["....."] = '5';
  _map["-...."] = '6';
  _map["--..."] = '7';
  _map["---.."] = '8';
  _map["----."] = '9';

  _map[".-.-.-"] = '.';
  _map["--..--"] = ',';
  _map["..--.."] = '?';
  _map[".----."] = '\'';
  _map["-.-.--"] = '!';
  _map["-..-."] = '/';
  _map["-.--."] = '(';
  _map["-.--.-"] = ')';
  _map[".-..."] = '&';
  _map["---..."] = ':';
  _map["-.-.-."] = ';';
  _map["-...-"] = '=';
  _map[".-.-."] = '+';
  _map["-....-"] = '-';
  _map["..--.-"] = '_';
  _map[".-..-."] = '\"';
  _map[".--.-."] = '@';


	int n;
	cin >> n;
	getchar();

	int j = 1;
	while(n > 0){
		cout << "Message #" << j << endl;
		j++;
		vector<string> _vector;
		string str;
		getline(cin, str);
		char cstr[str.length()+1];
		strcpy(cstr, str.c_str());

		int dspace = 1;
		for(int i = 0; i < strlen(cstr)-1; i++){
			if(cstr[i] == ' ' && cstr[i+1] == ' '){
				dspace++;
				cstr[i+1] = '*';
			}
		}

		int k = 0;
		char* aux[dspace];
		aux[k] = strtok(cstr, "*");
		while(1){
			k++;
			if(k == dspace) break;
			aux[k] = strtok(NULL, "*");
		}
		
		for(int i = 0; i < dspace; i++){
			int space = 1;
			if(aux[i][strlen(aux[i])-1] == ' ') aux[i][strlen(aux[i])-1] = '\0';
			for(int j = 0; j < strlen(aux[i]); j++){
				if(aux[i][j] == ' ') space++;
			}

			k = 0;
			char* letter[space];
			letter[k] = strtok(aux[i], " ");
			while(1){
				k++;
				if(k == space) break;
				letter[k] = strtok(NULL, " ");
			}

			char word[space+1];
			word[space] = '\0';
			for(int l = 0; l < space; l++){
				string _c = letter[l];
				word[l] = _map[_c];
			}
			string _c1 = word;
			_vector.push_back(word);
			if(i != dspace-1) _vector.push_back(" ");
		}
		
		for(int i = 0; i < _vector.size(); i++) cout << _vector[i];
		cout << endl;
		if(n != 1) cout << endl;
		n--;
	}

	return 0;
}