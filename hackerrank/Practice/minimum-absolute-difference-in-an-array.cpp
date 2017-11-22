#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
    freopen("minimum-absolute-difference-in-an-array.in", "r", stdin);
    clock_t exc = clock();
    #endif    
    // Code here
    long n;
    long long d, min;
    scanf("%ld", &n);
    vector<long long> nums(n);
    for(int i = 0; i < n; i++){
    	scanf("%lld", &d);
    	nums[i] = d;
	}
	sort(nums.begin(), nums.end());
	min = LLONG_MAX;
    for(int i = 1; i < n; i++){
    	if(min > nums[i] - nums[i - 1])
    		min = nums[i] - nums[i - 1];
    }
    printf("%lld", min);
    
    #ifndef ONLINE_JUDGE
    cout << endl << (double)(clock()-exc)/CLOCKS_PER_SEC*1000 << "ms.\n";
    #endif
	return 0;
}
