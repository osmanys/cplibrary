#include <bits/stdc++.h>
#define MAX 300

using namespace std;
int d[MAX][3];

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
		scanf("%d %d %d", &d[i][0], &d[i][1], &d[i][2]);
	int t, dc, maxv = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			t = 0;
			for(int k = 0; k < m; k++){
				dc = max(abs(i - d[k][0]), abs(j - d[k][1]));
				t += ((d[k][2] - dc) > 0 ? (d[k][2] - dc) : 0);
			}
			if(maxv < t)
				maxv = t;			
		}
	}
	cout << maxv;
	return 0;
}
