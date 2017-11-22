#include <bits/stdc++.h>

using namespace std;
int a[1000005];
int b[1000005];

int main(){
    int n;
    scanf("%d", &n);
    long d, ha = 0, hb = 0;
    for(int i = 0; i < n; i++){
        scanf("%ld", &d);
      	ha = max(ha, d);
        a[d]++;
    }
    for(int i = 0; i < n; i++){
        scanf("%ld", &d);
      	hb = max(hb, d);
        b[d]++;
    }
    long ca, cb, ma, mb, i = min(ha, hb);
    for(; i > 1; i--){
        ca = 0;
        cb = 0;
        for(long j = i; j <= max(ha, hb); j += i){
	        ca += a[j];
	        cb += b[j];
	        if(a[j])
	        	ma = j;
	        if(b[j])
	        	mb = j;
	    }
        if(ca && cb)
            break;
    }
    printf("%ld\n", (i > 1) ? (ma + mb) : (ha + hb));	    
    return 0;
}
