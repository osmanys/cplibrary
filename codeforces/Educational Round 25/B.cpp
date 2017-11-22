#include <bits/stdc++.h>

using namespace std;

bool win(int t[][10]){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(j < 6 && t[i][j] == 1 && t[i][j + 1] == 1 && t[i][j + 2] == 1 && t[i][j + 3] == 1 && t[i][j + 4] == 1)
				return true;
			if(i < 6 && t[i][j] == 1 && t[i + 1][j] == 1 && t[i + 2][j] == 1 && t[i + 3][j] == 1 && t[i + 4][j] == 1)
				return true;
			if(i < 6 && j < 6 && t[i][j] == 1 && t[i + 1][j + 1] == 1 && t[i + 2][j + 2] == 1 && t[i + 3][j + 3] == 1 && t[i + 4][j + 4] == 1)
				return true;
			if(i > 3 && j < 6 && t[i][j] == 1 && t[i - 1][j + 1] == 1 && t[i - 2][j + 2] == 1 && t[i - 3][j + 3] == 1 && t[i - 4][j + 4] == 1)
				return true;
		}
	}
	return false;
}

int main(){
	int t[10][10];
	string s;
	for(int i = 0; i < 10; i++){
		cin >> s;
		for(int j = 0; j < 10; j++){
			if(s[j] == 'X')
				t[i][j] = 1;
			else if(s[j] == 'O')
				t[i][j] = -1;
			else
				t[i][j] = 0;
		}
	}
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(!t[i][j]){
				t[i][j] = 1;
				if(win(t)){
					printf("YES");
					return 0;
				}
				t[i][j] = 0;
			}
		}
	}
	printf("NO");	
	return 0;
}
