#include <bits/stdc++.h>
#define MAX 500

using namespace std;

bool temple[2][MAX];

bool solve(int n, bool visited[2][MAX], int row, int column){
	if(column && ((temple[0][column -1] && !visited[0][column -1]) || (temple[1][column -1] && !visited[1][column -1])))
		return false;
	bool r = false;
	bool travel = false;
	if(row){
		if(!r && (column + 1 < n) && temple[1][column + 1] && !visited[1][column + 1]){
			travel = true;
			visited[1][column + 1] = true;
			r = solve(n, visited, 1, column + 1);
			visited[1][column + 1] = false;
		}
		if(!r && temple[0][column] && !visited[0][column]){
			travel = true;
			visited[0][column] = true;
			r = solve(n, visited, 0, column);
			visited[0][column] = false;
		}
	}
	else{
		if(!r && (column + 1 < n) && temple[0][column + 1] && !visited[0][column + 1]){
			travel = true;
			visited[0][column + 1] = true;
			r = solve(n, visited, 0, column + 1);
			visited[0][column + 1] = false;
		}
		if(!r && temple[1][column] && !visited[1][column]){
			travel = true;
			visited[1][column] = true;
			r = solve(n, visited, 1, column);
			visited[1][column] = false;
		}
	}
	if(!travel){
		int i = row;
		for(; i < n; i++)
			if((temple[0][i] && !visited[0][i]) || (temple[1][i] && !visited[1][i]))
				break;
		if(i == n)
			r = true;
	}
	return r;
}

int main(){
	int t, n, find, init;
	string line1, line2;
	bool visited[2][MAX];
	bool r;
	cin >> t;
	while(t--){
		cin >> n;
		cin >> line1 >> line2;
		for(int i = 0; i < n; i++){
			temple[0][i] = line1[i] == '#';
			temple[1][i] = line2[i] == '#';
		}
		memset(visited, false, sizeof visited);
		init = 0;
		while(init < n){
			if(temple[0][init] || temple[1][init])
				break;
			init++;
		}
		r = false;
		if(temple[0][init]){
			visited[0][init] = true;
			r = solve(n, visited, 0, init);
			visited[0][init] = false;
		}
		if(!r && temple[1][init]){
			visited[1][init] = true;
			r = solve(n, visited, 1, init);
			visited[1][init] = false;
		}
		cout << (r ? "yes" : "no") << endl;
	}
	
	return 0;
}
