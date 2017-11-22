#include <bits/stdc++.h>
#define MAX 300000
 
using namespace std;
 
map<long, long> indexes;
long tree[MAX];
long keys[MAX];
long n;
 
void addStation(long u, long v, long k){
	indexes[u] = n;
	tree[n] = indexes[v];
	keys[n] = k;
	n++;	
}
 
pair<long, long> test(long v, long k){
	long min_answer = LONG_MAX, max_answer = LONG_MIN, vi, c;
	vi = indexes[v];
	while(vi != -1){
		c = (keys[vi] ^ k);
		if(c > max_answer)
			max_answer = c;			
		if(c < min_answer)
			min_answer = c;
		vi = tree[vi];
	}
	
	return make_pair(min_answer, max_answer);
}
 
int main() {
	long q, r, k, t, u, v;
	scanf("%ld %ld", &n, &q);
	scanf("%ld %ld", &r, &k);
	indexes[r] = 0;
	tree[0] = -1;
	keys[0] = k;
	current = 1;
	for(long i = 1; i < n; i++){
		scanf("%ld %ld %ld", &u, &v, &k);
		indexes[u] = i;
		tree[i] = indexes[v];
		keys[i] = k;
	}
	long last_answer = 0;
	for(long i = 0; i < q; i++){
		scanf("%ld", &t);
    	t ^= last_answer;
    	if (!t){
    		scanf("%ld %ld %ld", &v, &u, &k);
	        addStation(u ^ last_answer, v ^ last_answer, k ^ last_answer);
	    }
	    else{
    		scanf("%ld %ld", &v, &k);
	        pair<long, long> r = test(v ^ last_answer, k ^ last_answer);
	        last_answer = r.first ^ r.second;  
	        printf("%ld %ld\n", r.first, r.second);
	    }
	}
	
    return 0;
}
