#include <bits/stdc++.h>

using namespace std;
bool d[3][10];

int main(){
	int n, a;
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < 6; j++){
			cin >> a;
			d[i][a] = true;
		}
	int i = 1;
	for(; i < 10000; i++){
		if(i >= 100 && n == 3 && d[0][i % 10] && d[1][(i / 10) % 10] && d[2][(i / 100) % 10])
			continue;
		if(i >= 100 && n == 3 && d[0][i % 10] && d[2][(i / 10) % 10] && d[1][(i / 100) % 10])
			continue;
		if(i >= 100 && n == 3 && d[1][i % 10] && d[0][(i / 10) % 10] && d[2][(i / 100) % 10])
			continue;
		if(i >= 100 && n == 3 && d[1][i % 10] && d[2][(i / 10) % 10] && d[0][(i / 100) % 10])
			continue;
		if(i >= 100 && n == 3 && d[2][i % 10] && d[0][(i / 10) % 10] && d[1][(i / 100) % 10])
			continue;
		if(i >= 100 && n == 3 && d[2][i % 10] && d[1][(i / 10) % 10] && d[0][(i / 100) % 10])
			continue;
			
		if(i >= 10 && i < 100 && n == 3 && d[0][i % 10] && d[1][(i / 10) % 10])
			continue;
		if(i >= 10 && i < 100  && n == 3 && d[0][i % 10] && d[2][(i / 10) % 10])
			continue;
		if(i >= 10 && i < 100  && n == 3 && d[1][i % 10] && d[0][(i / 10) % 10])
			continue;
		if(i >= 10 && i < 100  && n == 3 && d[1][i % 10] && d[2][(i / 10) % 10])
			continue;
		if(i >= 10 && i < 100  && n == 3 && d[2][i % 10] && d[0][(i / 10) % 10])
			continue;
		if(i >= 10 && i < 100  && n == 3 && d[2][i % 10] && d[1][(i / 10) % 10])
			continue;
			
		if(i < 10 && n == 3 && d[0][i % 10])
			continue;
		if(i < 10  && n == 3 && d[1][i % 10])
			continue;
		if(i < 10  && n == 3 && d[2][i % 10])
			continue;
			
		if(i < 100 && n == 2 && d[0][i % 10] && d[1][(i / 10) % 10])
			continue;
		if(i < 100 && n == 2 && d[1][i % 10] && d[0][(i / 10) % 10])
			continue;
				
		if(i < 10 && n == 2 && d[0][i % 10])
			continue;
		if(i < 10 && n == 2 && d[1][i % 10])
			continue;
				
		if(i < 10 && n == 1 && d[0][i % 10])
			continue;
		
		break;
	}
	cout << (i - 1);
	return 0;
}
