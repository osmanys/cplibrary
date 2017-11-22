#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	string s;
	int count = 0, minx = INT_MAX, maxx = INT_MIN, miny = INT_MAX, maxy = INT_MIN;
	scanf("%d %d", &n, &m);
	getline(cin, s);
	for(int i = 0; i < n; i++){
		getline(cin, s);
		for(int j = 0; j < m; j++){
			if(s[j] == 'B'){
				count++;
				if(miny > i)
					miny = i;
				if(maxy < i)
					maxy = i;
				if(minx > j)
					minx = j;
				if(maxx < j)
					maxx = j;				
			}
		}
	}
	if(!count)
		printf("1");
	else{
		int x = maxx - minx + 1;
		int y = maxy - miny + 1;
		int _max = max(x, y);
		if(x < _max){
			if(minx + (m - maxx - 1) - (_max - x) < 0)
				printf("-1");
			else
				printf("%d", _max * _max - count);
		}
		else{
			if(miny + (n - maxy - 1) - (_max - y) < 0)
				printf("-1");
			else
				printf("%d", _max * _max - count);			
		}
	}
	return 0;
}
