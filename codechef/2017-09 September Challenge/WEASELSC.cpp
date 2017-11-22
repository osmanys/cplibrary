#include <bits/stdc++.h>
#define MAX 100000
 
using namespace std;
long d[MAX], nle[MAX], ble[MAX];

void getNLE(long n){
    long index, i;
    stack<long> s;
    s.push(0);    
    for (i = 1; i < n; i++){ 
        if (!s.empty()){
            index = s.top();
            s.pop();
            while (d[index] > d[i]){
            	nle[index] = i;
                if(s.empty())
                   break;
                index = s.top();
				s.pop();
            }            
            if (d[index] <= d[i])
                s.push(index);
        }        
        s.push(i);
    }    
    while (!s.empty()){
        index = s.top();
        s.pop();
        nle[index] = n;
    }
}

void getBLE(long n){
    long index, i;
    stack<long> s;
    s.push(n - 1);    
    for (i = n - 2; i >= 0; i--){ 
        if (!s.empty()){
            index = s.top();
            s.pop();
            while (d[index] > d[i]){
            	ble[index] = i;
                if(s.empty())
                   break;
                index = s.top();
				s.pop();
            }            
            if (d[index] <= d[i])
                s.push(index);
        }        
        s.push(i);
    }    
    while (!s.empty()){
        index = s.top();
        s.pop();
        ble[index] = -1;
    }
}
 
int main() {
	int t, k;
	long n, r, m;
	scanf("%d", &t);
	while(t--){
		scanf("%ld %d", &n, &k);
		for(long i = 0; i < n; i++)
			scanf("%ld", &d[i]);
		getNLE(n);
		getBLE(n);
		m = 0;
		for(long i = 0; i < n; i++)
			if(m < d[i] * (nle[i] - ble[i] - 1))
				m = d[i] * (nle[i] - ble[i] - 1);
		printf("%ld\n", m);
	}
    return 0;
}
