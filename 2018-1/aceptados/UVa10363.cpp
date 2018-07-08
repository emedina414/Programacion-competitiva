#include <iostream>

using namespace std;

int main(){

	int n;
	cin >> n;

	char grid[3][4];
	while(n > 0){
		scanf("%s", grid[0]);
		scanf("%s", grid[1]);
		scanf("%s", grid[2]);

		bool flag = true;
		int x = 0, o = 0;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				if(grid[i][j] == 'X') x++;
				if(grid[i][j] == 'O') o++;
			}
		}

		if(x == o){
			if(grid[0][0] == 'X' && grid[0][1] == 'X' && grid[0][2] == 'X') flag = false;
			if(grid[1][0] == 'X' && grid[1][1] == 'X' && grid[1][2] == 'X') flag = false;
			if(grid[2][0] == 'X' && grid[2][1] == 'X' && grid[2][2] == 'X') flag = false;
			if(grid[0][0] == 'X' && grid[1][0] == 'X' && grid[2][0] == 'X') flag = false;
			if(grid[0][1] == 'X' && grid[1][1] == 'X' && grid[2][1] == 'X') flag = false;
			if(grid[0][2] == 'X' && grid[1][2] == 'X' && grid[2][2] == 'X') flag = false;
			if(grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X') flag = false;
			if(grid[0][2] == 'X' && grid[1][1] == 'X' && grid[2][0] == 'X') flag = false;
		}

		if(x == o+1){
			if(grid[0][0] == 'O' && grid[0][1] == 'O' && grid[0][2] == 'O') flag = false;
			if(grid[1][0] == 'O' && grid[1][1] == 'O' && grid[1][2] == 'O') flag = false;
			if(grid[2][0] == 'O' && grid[2][1] == 'O' && grid[2][2] == 'O') flag = false;
			if(grid[0][0] == 'O' && grid[1][0] == 'O' && grid[2][0] == 'O') flag = false;
			if(grid[0][1] == 'O' && grid[1][1] == 'O' && grid[2][1] == 'O') flag = false;
			if(grid[0][2] == 'O' && grid[1][2] == 'O' && grid[2][2] == 'O') flag = false;
			if(grid[0][0] == 'O' && grid[1][1] == 'O' && grid[2][2] == 'O') flag = false;
			if(grid[0][2] == 'O' && grid[1][1] == 'O' && grid[2][0] == 'O') flag = false;
		}

		if(o > x || o > 4 || x > 5 || x-o > 1) flag = false;

		if(flag) cout << "yes" << endl;
		else cout << "no" << endl;

		n--;
	}

	return 0;
}