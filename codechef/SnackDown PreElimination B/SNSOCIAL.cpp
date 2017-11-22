#include <bits/stdc++.h>
#define MAX 500

using namespace std;
bool marked[MAX][MAX];
long d[MAX][MAX];

int main(){
	int t, max, n, m, it;
	vector<pair<int, int> > p, temp;
	cin >> t;
	while(t--){
		cin >> n >> m;
		p.clear();
		max = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> d[i][j];
				if(max < d[i][j]){
					max = d[i][j];
					p.clear();
					p.push_back(make_pair(i, j));
				}
				else if(max == d[i][j]){
					p.push_back(make_pair(i, j));
				}
			}
		}
		memset(marked, false, sizeof marked);
		for(int i = 0; i < p.size(); i++)
			marked[p[i].first][p[i].second] = true;
		it = -1;
		while(!p.empty()){
			temp.clear();
			for(int i = 0; i < p.size(); i++){
				if(p[i].first > 0){
					if(p[i].second > 0 && !marked[p[i].first - 1][p[i].second - 1]){
						temp.push_back(make_pair(p[i].first - 1, p[i].second - 1));
						marked[p[i].first - 1][p[i].second - 1] = true;
					}
					if(!marked[p[i].first - 1][p[i].second]){
						temp.push_back(make_pair(p[i].first - 1, p[i].second));
						marked[p[i].first - 1][p[i].second] = true;
					}
					if(p[i].second < m - 1 && !marked[p[i].first - 1][p[i].second + 1]){
						temp.push_back(make_pair(p[i].first - 1, p[i].second + 1));
						marked[p[i].first - 1][p[i].second + 1] = true;
					}
				}
				if(p[i].first < n - 1){
					if(p[i].second > 0 && !marked[p[i].first + 1][p[i].second - 1]){
						temp.push_back(make_pair(p[i].first + 1, p[i].second - 1));
						marked[p[i].first + 1][p[i].second - 1] = true;
					}
					if(!marked[p[i].first + 1][p[i].second]){
						temp.push_back(make_pair(p[i].first + 1, p[i].second));
						marked[p[i].first + 1][p[i].second] = true;
					}
					if(p[i].second < m - 1 && !marked[p[i].first + 1][p[i].second + 1]){
						temp.push_back(make_pair(p[i].first + 1, p[i].second + 1));
						marked[p[i].first + 1][p[i].second + 1] = true;
					}
				}
				if(p[i].second > 0 && !marked[p[i].first][p[i].second - 1]){
					temp.push_back(make_pair(p[i].first, p[i].second - 1));
					marked[p[i].first][p[i].second - 1] = true;
				}
				if(p[i].second < m - 1 && !marked[p[i].first][p[i].second + 1]){
					temp.push_back(make_pair(p[i].first, p[i].second + 1));
					marked[p[i].first][p[i].second + 1] = true;
				}
			}
			p = temp;
			it++;
		}
		cout << it << endl;
	}
	
	return 0;
}
