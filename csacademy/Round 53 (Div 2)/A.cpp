#include <bits/stdc++.h>

using namespace std;

int main(){
	int t[3][3];
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			cin >> t[i][j];
	int m = 300;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			if(j != i){
				for(int k = 0; k < 3; k++)
					if(k != i && k != j){
						if(m > t[0][i] + t[1][j] + t[2][k])
							m = t[0][i] + t[1][j] + t[2][k];
					}
			}
	cin >> m;
	return 0;
}
