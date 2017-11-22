#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
    freopen("787b.in", "r", stdin);
    clock_t exc = clock();
    #endif
    
    // Code here
    set<long> data, data2;
    int n, m, k, c;
	long t;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
    	scanf("%d", &k);
		if(k == 1){
			printf("%s", "YES");
			return 0;
		}
    	data.clear();
    	for(int j = 0; j < k; j++){
    		scanf("%d", &t);
    		data.insert(t);
		}
		data2.clear();
		for(set<long>::iterator it = data.begin(); it != data.end(); it++){
			data2.insert((*it > 0 ? 1 : -1) * *it);
		}
		if(data.size() == data2.size()){
			printf("%s", "YES");
			return 0;
		}
	}
	printf("%s", "NO");
    
    #ifndef ONLINE_JUDGE
    cout << endl << (double)(clock()-exc)/CLOCKS_PER_SEC*1000 << "ms.\n";
    #endif
	return 0;
}
