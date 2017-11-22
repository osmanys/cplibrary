#include <bits/stdc++.h>
#define MAX 1000

using namespace std;
int d[MAX][MAX];
vector<pair<int, int> > k;

int main(){
	int q, n, t;
	long r;
	string s;
	cin >> q;
	while(q--){
		cin >> n;
		getline(cin, s);
		memset(d, 0, sizeof d);
		k.clear();
		for(int i = 0; i < n; i++){
			getline(cin, s);
			for(int j = 0; j < n; j++){
				if(s[j] == 'K')
					k.push_back(make_pair(i, j));
				else if(s[j] == 'X')
					d[i][j] = -1;
			}
		}
		for(int i = 1; i < n; i++)
			if(d[0][i] != -1 && !d[0][i - 1])
				d[0][i] = 1;
		for(int i = 1; i < n; i++)
			if(d[i][0] != -1 && !d[i - 1][0])
				d[i][0] = 1;		
		for(int i = 1; i < n; i++){			
			for(int j = 1; j < n; j++){
				if(d[i][j] == -1 || (d[i][j - 1] != 0 && d[i - 1][j - 1] != 0 && d[i - 1][j] != 0))
					continue;
				if(d[i][j - 1] != 1 && d[i - 1][j - 1] != 1 && d[i - 1][j] != 1)
					d[i][j] = 1;
				else if(d[i][j - 1] != 2 && d[i - 1][j - 1] != 2 && d[i - 1][j] != 2)
					d[i][j] = 2;
				else
					d[i][j] = 3;
			}
		}
		t = 0;
		for(vector<pair<int, int> >::iterator it = k.begin(); it != k.end(); it++)
			t ^= d[(*it).first][(*it).second];
		r = 0;
		for(vector<pair<int, int> >::iterator it = k.begin(); it != k.end(); it++){
			if((*it).first && d[(*it).first - 1][(*it).second - 1] != -1 && (*it).second && !(t ^ d[(*it).first][(*it).second] ^ d[(*it).first - 1][(*it).second - 1]))
				r++;
			if((*it).first && d[(*it).first - 1][(*it).second] != -1 && !(t ^ d[(*it).first][(*it).second] ^ d[(*it).first - 1][(*it).second]))
				r++;
			if((*it).second && d[(*it).first][(*it).second - 1] != -1 && !(t ^ d[(*it).first][(*it).second] ^ d[(*it).first][(*it).second - 1]))
				r++;
		}
		printf(r ? "WIN %ld\n" : "LOSE\n", r);
	}
	return 0;
}
