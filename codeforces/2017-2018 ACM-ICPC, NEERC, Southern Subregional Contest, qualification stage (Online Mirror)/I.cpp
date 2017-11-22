#include <bits/stdc++.h>
#define MAX 250

using namespace std;
long d[MAX][MAX];
long v[MAX][MAX];
long vf[MAX][MAX];
long h[MAX][MAX];
long hf[MAX][MAX];
long t[MAX];

int main(){
	int n, m;
	long q, p;
	cin >> n >> m >> q >> p;
	string s;
	getline(cin, s);
	for(int i = 0; i < n; i++){
		getline(cin, s);
		for(int j = 0; j < m; j++){
			if(s[j] == '*')
				d[i][j] = -1;
			else if(s[j] != '.')
				d[i][j] = (s[j] - 'A' + 1) * q;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(d[i][j] == -1)
				t[j] = 0;
			else{
				t[j] = t[j] / 2 + d[i][j];
				v[i][j] += t[j] - d[i][j];
			}
		}
	}
	memset(t, 0, sizeof t);
	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j < m; j++){
			if(d[i][j] == -1)
				t[j] = 0;
			else{
				t[j] = t[j] / 2 + d[i][j];
				v[i][j] += t[j] - d[i][j];
			}
		}
	}
	memset(t, 0, sizeof t);
	for(int j = 0; j < m; j++){
		for(int i = 0; i < n; i++){
			if(d[i][j] == -1)
				t[i] = 0;
			else{
				t[i] = t[i] / 2 + v[i][j];
				vf[i][j] += t[i] - v[i][j];
			}
		}
	}
	memset(t, 0, sizeof t);
	for(int j = m - 1; j >= 0; j--){
		for(int i = 0; i < n; i++){
			if(d[i][j] == -1)
				t[i] = 0;
			else{
				t[i] = t[i] / 2 + v[i][j];
				vf[i][j] += t[i] - v[i][j];
			}
		}
	}
	memset(t, 0, sizeof t);
	for(int j = 0; j < m; j++){
		for(int i = 0; i < n; i++){
			if(d[i][j] == -1)
				t[i] = 0;
			else{
				t[i] = t[i] / 2 + d[i][j];
				h[i][j] += t[i] - d[i][j];
			}
		}
	}
	memset(t, 0, sizeof t);
	for(int j = m - 1; j >= 0; j--){
		for(int i = 0; i < n; i++){
			if(d[i][j] == -1)
				t[i] = 0;
			else{
				t[i] = t[i] / 2 + d[i][j];
				h[i][j] += t[i] - d[i][j];
			}
		}
	}
	memset(t, 0, sizeof t);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(d[i][j] == -1)
				t[j] = 0;
			else{
				t[j] = t[j] / 2 + h[i][j];
				hf[i][j] += t[j] - h[i][j];
			}
		}
	}
	memset(t, 0, sizeof t);
	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j < m; j++){
			if(d[i][j] == -1)
				t[j] = 0;
			else{
				t[j] = t[j] / 2 + h[i][j];
				hf[i][j] += t[j] - h[i][j];
			}
		}
	}	
	int r = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			r += (d[i][j] + v[i][j] + vf[i][j] + h[i][j] + hf[i][j] > p);
			cout << (d[i][j] + v[i][j] + vf[i][j] + h[i][j] + hf[i][j]) << " ";
		}
		cout << "\n";
	}
	cout << r;
	return 0;
}
