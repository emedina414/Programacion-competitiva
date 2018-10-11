#include <stdio.h>
#include <ctype.h>

int main(){
	int N;
	scanf("%d", &N);
	while(N--){
		int r, c, x, y;
		scanf("%d %d", &r, &c);
		getchar();

		char maze[r][c], ornt, comm;
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				scanf("%c", &maze[i][j]);
			}
			getchar();
		}
		scanf("%d %d", &x, &y);

		x--; y--;
		ornt = 'N';
		while(scanf("%c", &comm) != EOF){
			if(isblank(comm)) continue;
			if(comm == 'R'){
				if(ornt == 'N') ornt = 'E';
				else if(ornt == 'E') ornt = 'S';
				else if(ornt == 'S') ornt = 'W';
				else if(ornt == 'W') ornt = 'N';
			}else if(comm == 'L'){
				if(ornt == 'N') ornt = 'W';
				else if(ornt == 'W') ornt = 'S';
				else if(ornt == 'S') ornt = 'E';
				else if(ornt == 'E') ornt = 'N';
			}else if(comm == 'F'){
				if(ornt == 'N'){
					if(x > 0 && maze[x-1][y] != '*') x--;
				}else if(ornt == 'E'){
					if(y < c-1 && maze[x][y+1] != '*') y++;
				}else if(ornt == 'S'){
					if(x < r-1 && maze[x+1][y] != '*') x++;
				}else if(ornt == 'W'){
					if(y > 0 && maze[x][y-1] != '*') y--;
				}
			}else if(comm == 'Q'){
				printf("%d %d %c\n", x+1, y+1, ornt);
				if(N >= 1) printf("\n");
				break;
			}
		}
	}

	return 0;
}