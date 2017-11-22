#include <bits/stdc++.h>
#define MAX 60

using namespace std;
int d[MAX][MAX];

int main(){
	int n, x, y, t = 1;	
	char w;
	cin >> n >> w >> x >> y;
	while(t <= n * n){
		d[x][y] = t;
		if(w == 's'){
			if(x < n - 1 && !d[x + 1][y])
				x++;
			else if(y > 0 && !d[x][y - 1])
				y--;
			else if(y < n - 1 && !d[x][y + 1])
				y++;
			else if(x > 0 && !d[x - 1][y])
				x--;
		}
		else if(w == 'e'){
			if(y < n - 1 && !d[x][y + 1])
				y++;
			else if(x > 0 && !d[x - 1][y])
				x--;
			else if(x < n - 1 && !d[x + 1][y])
				x++;
			else if(y > 0 && !d[x][y - 1])
				y--;
		}
		else if(w == 'n'){
			if(x > 0 && !d[x - 1][y])
				x--;
			else if(y > 0 && !d[x][y - 1])
				y--;
			else if(y < n - 1 && !d[x][y + 1])
				y++;
			else if(x < n - 1 && !d[x + 1][y])
				x++;
		}
		else {
			if(y > 0 && !d[x][y - 1])
				y--;
			else if(x > 0 && !d[x - 1][y])
				x--;
			else if(x < n - 1 && !d[x + 1][y])
				x++;
			else if(y < n - 1 && !d[x][y + 1])
				y++;
		}
		t++;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			printf("%d ", d[i][j]);
		printf("\n");
	}
	return 0;
}
