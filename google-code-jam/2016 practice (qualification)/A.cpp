#include <bits/stdc++.h>
#define fi "A-large-practice.in"
#define fo "A-large-practice.out"
#define MAX 1000000

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
    freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);
    clock_t exc = clock();
    #endif
    
    // Code here
    int t, n, r, c, div;
    bool mark[10];
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
    	memset(mark, false, sizeof mark);
    	scanf("%d", &n);    	
    	if(n){
    		c = 0;
    		for(r = 1; r < MAX; r++){
    			div = 1;
    			while(n * r / div){
    				if(!mark[n * r / div % 10]){
    					mark[n * r / div % 10] = true;
    					c++;
					}
					div *= 10;
				}
				if(c == 10)
					break;
    		}
    		if(c == 10)
    			cout << "Case #" << i << ": " << (n * r) << endl;
    		else
    			cout << "Case #" << i << ": INSOMNIA" << endl;
    			
		}
    	else
    		cout << "Case #" << i << ": INSOMNIA" << endl;
	}
    
    #ifndef ONLINE_JUDGE
    cout << endl << (double)(clock()-exc) / CLOCKS_PER_SEC * 1000 << "ms.\n";
    #endif
	return 0;
}
