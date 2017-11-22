#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

struct Snake{
	long long HX;
	long long HY;
	long long TX;
	long long TY;
};

bool compareY(Snake a, Snake b){ return max(a.HY, a.TY) > max(b.HY, b.TY); }

bool compareX(Snake a, Snake b){ return max(a.HX, a.TX) > max(b.HX, b.TX); }

Snake s[MAX];

int main(){
	int t;
	long long n, k, curr;
	long m, count, i;
	bool valid;
	cin >> t;
	while(t--){
		cin >> n >> k >> m;
		for(i = 0; i < m; i++)
			cin >> s[i].HX >> s[i].HY >> s[i].TX >> s[i].TY;		
		count = 0;
		sort(s, s + m, compareY);
		curr = (n - k) / 2 + 1;
		valid = true;
		while(curr <= (n + k) / 2){
			i = 0;
			for(; i < m; i++){
				if(curr > max(s[i].HY, s[i].TY)){
					valid = false;
					break;
				}					
				else if(curr >= min(s[i].HY, s[i].TY)){
					curr = max(s[i].HY, s[i].TY) + 1;
					count++;
					break;
				}
			}
			if(!valid || i == m)
				break;			
		}
		if(curr <= (n + k) / 2){
			cout << -1 << endl;
			continue;
		}
		sort(s, s + m, compareX);
		curr = (n - k) / 2 + 1;
		valid = true;
		while(curr <= (n + k) / 2){
			i = 0;
			for(; i < m; i++){
				if(curr > max(s[i].HX, s[i].TX)){
					valid = false;
					break;
				}					
				else if(curr >= min(s[i].HX, s[i].TX)){
					curr = max(s[i].HX, s[i].TX) + 1;
					count++;
					break;
				}
			}
			if(!valid || i == m)
				break;			
		}
		if(curr <= (n + k) / 2){
			cout << -1 << endl;
			continue;
		}
		cout << count << endl;
	}
	
	return 0;
}
