#include <bits/stdc++.h>
#define fi "C-large-practice.in"
#define fo "C-large-practice.out"
#define MAX 1000

using namespace std;

int main(){
    freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);    
    // code here
    int t, n, b, k, c, max, dcount;
    int bff[MAX];
    int count[MAX], connected[MAX];
    bool mark[MAX];
    vector<int> garbage;
    vector<int> diconnected;
    scanf("%d", &t);
    for(int tt = 1; tt <= t; tt++){
    	printf("Case #%d: ", tt);
		memset(count, 0, sizeof count);
		memset(connected, 0, sizeof connected);
		memset(mark, false, sizeof mark);
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%d", &b);
			bff[i] = b - 1;
			count[b - 1]++;
		}
		for(int i = 0; i < n; i++){
			if(!count[i])
				garbage.push_back(i);
		}
		while(!garbage.empty()){
			k = garbage.back();
			garbage.pop_back();
			mark[k] = true;
			count[bff[k]]--;
			if(!count[bff[k]]){
				garbage.push_back(bff[k]);
			}
			if(connected[bff[k]] < connected[k] + 1)
				connected[bff[k]] = connected[k] + 1;
		}
		max = 0;
		diconnected.clear();
		for(int i = 0; i < n; i++){
			if(!mark[i]){
				c = 0;
				mark[i] = true;
				k = i;
				do{
					k = bff[k];
					mark[k] = true;
					c++;
				} while(k != i);
				if(c == 2){
					diconnected.push_back(i);
					diconnected.push_back(bff[i]);
				}
				if(c > max)
					max = c;
			}
		}
		dcount = 0;
		if(!diconnected.empty()){
			for(vector<int>::iterator it = diconnected.begin(); it != diconnected.end(); it++){
				dcount += connected[*it] + 1;
			}			
		}
		if(dcount > max)
			max = dcount;
		printf("%d\n", max);
	}
    
	return 0;
}
