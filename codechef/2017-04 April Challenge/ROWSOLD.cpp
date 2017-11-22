#include <bits/stdc++.h>
#define fi "ROWSOLD.in"
#define fo "ROWSOLD.out"

using namespace std;

int main(){
	//test();
    /*freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);*/
    // code here
    int t;
    string line;
    long long size, count, last;
    long long total;
    scanf("%d", &t);
    while(t--){
    	cin >> line;
    	size = line.size();
    	last = size;
    	long i = 0;
    	for(; i < size; i++){
    		if(line[i] == '1'){
				last = i;
				i++;
				break;
			} 			
		}
    	count = 1;
    	total = 0;
    	for(; i < size; i++){
    		if(line[i] == '1'){
    			total += (((i - last) > 1) ? count * (i - last) : 0);
    			last = i;
    			count++;
    		}
    	}
    	total += (((i - last) > 1) ? count * (i - last) : 0);
    	printf("%lld\n", total);
	}
    
	return 0;
}
