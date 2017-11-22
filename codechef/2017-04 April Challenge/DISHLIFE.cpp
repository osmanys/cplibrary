#include <bits/stdc++.h>
//#define fi "DISHLIFE.in"
//#define fo "DISHLIFE.out"
#define MAX 100000

using namespace std;

int main(){
    //freopen(fi, "r", stdin);
	//freopen(fo, "w", stdout);    
    // code here
    int t;
    long n, k, temp, count, last;
    bool mark[MAX];
    string raw;
    scanf("%d", &t);
    while(t--){
    	scanf("%ld %ld\n", &n, &k);
    	memset(mark, false, sizeof mark);
    	count = 0;
    	for(long i = 0; i < n; i++){
    		getline(cin, raw);
    		if(count < k){
	    		istringstream is(raw);
	    		while(is >> temp){
	    			temp--;
	    			if(!mark[temp]){
		    			count++;
		    			if(count == k)
		    				last = i + 1;
						mark[temp] = true;
		    		}
				}
			}
		}
		if(count < k)
			printf("sad\n");
		else if(last < n)
			printf("some\n");
		else
			printf("all\n");
	}
    
	return 0;
}
