#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> getKMax(int arr[], int n, int k){
	vector<int> result;
	deque<int>  Qi(k);
    int i;
    for (i = 0; i < k; ++i){
        while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();            
        Qi.push_back(i);
    }
    for (; i < n; ++i){
    	result.push_back(arr[Qi.front()]);
        while ( (!Qi.empty()) && Qi.front() <= i - k)
            Qi.pop_front();
        while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();
        Qi.push_back(i);
    }
    result.push_back(arr[Qi.front()]);
    
    return result;
}
 
int main() {
	int n, k, p, d, shift;
	vector<int> maximal;
	string s;
	scanf("%d %d %d", &n, &k, &p);
	if(n < k)
		k = n;
	int data[n + k - 1];
	int count[2 * n - k];
	for(int i = 0; i < n; i++){
		scanf("%d", &d);
		data[k - 1 + i] = d;
	}
	for(int i = 0; i < k - 1; i++)
		data[i] = data[n + i];
	count[n - k] = 0;
	for(int i = 0; i < k; i++){
		if(data[i])
			count[n - k]++;
	}
	for(int i = 1; i < n; i++)
		count[n - k + i] = count[n - k + i - 1] - data[i - 1] + data[k + i - 1];
	for(int i = 0; i < n - k; i++)
		count[i] = count[n + i];
	
	maximal = getKMax(count, 2 * n - k, n - k + 1);
	
	scanf("\n");
	getline(cin, s);
	shift = n - 1;
	for(string::iterator it = s.begin(); it != s.end(); it++){
		if(*it == '!'){
			if(shift)
				shift--;
			else
				shift = n - 1;
		}
		else
			printf("%d\n", maximal[shift]);
	}
	
    return 0;
}
