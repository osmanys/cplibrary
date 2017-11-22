#include <bits/stdc++.h>
#define MAX 100

using namespace std;
int n, m;
int colors[MAX];
int candies[MAX][MAX];
int boxes[MAX];
int penalty[MAX];
int diff[MAX][MAX];
int temp[MAX];
int kmin[MAX];
bool deleted[MAX][MAX];

int partition(int arr[], int l, int r, int k);

int findMedian(int arr[], int n){
    sort(arr, arr+n);
    return arr[n/2];
}

int kthLargest(int arr[], int l, int r, int k){
    if (k > 0 && k <= r - l + 1){
        int n = r-l+1;
        int i, median[(n+4)/5];
        for (i=0; i<n/5; i++)
            median[i] = findMedian(arr+l+i*5, 5);
        if (i*5 < n){
            median[i] = findMedian(arr+l+i*5, n%5); 
            i++;
        }
        int medOfMed = (i == 1)? median[i-1]: kthLargest(median, 0, i-1, i/2);
        int pos = partition(arr, l, r, medOfMed);
        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)
            return kthLargest(arr, l, pos-1, k);
        return kthLargest(arr, pos+1, r, k-pos+l-1);
    }
    return INT_MAX;
}
 
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r, int x){
    int i;
    for (i=l; i<r; i++)
        if (arr[i] == x)
           break;
    swap(&arr[i], &arr[r]);
    i = l;
    for (int j = l; j <= r - 1; j++){
        if (arr[j] >= x){
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

long solve(){	
    for(int j = 0; j < m; j++){
    	if(n > boxes[j])
    		penalty[j] = 2 * (n - boxes[j]) - 1;
    }
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < m; j++)
    		diff[i][j] = candies[i][j] - penalty[j];    
	int min, mindiff, mini, minj, t, total = 0;
    while(total < m * n){
	    for(int i = 0; i < n; i++){
	    	t = 0;
	    	for(int j = 0; j < m; j++){
	    		if(!deleted[i][j]){
		    		temp[t] = diff[i][j];
		    		t++;
		    	}
		    }
		    kmin[i] =  kthLargest(temp, 0, t - 1, (t < colors[i]) ? t : colors[i]);
		}
	    min = INT_MAX;
		mindiff = INT_MAX;
	    for(int i = 0; i < n; i++){
	    	for(int j = 0; j < m; j++){
	    		if(!deleted[i][j] && (min > diff[i][j] - kmin[i] || (min == diff[i][j] - kmin[i] && mindiff > diff[i][j]))){
	    			min = diff[i][j] - kmin[i];
	    			mindiff = diff[i][j];
	    			mini = i;
	    			minj = j;
				}
	    	}
	    }
	    if(min < 0 || (!min && mindiff < 0)){
	    	deleted[mini][minj] = true;
	    	penalty[minj] -= 2;
	    	if(penalty[minj] < 0)
	    		penalty[minj] = 0;
	    	for(int i = 0; i < n; i++)
	    		diff[i][minj] += 2;
	    	total++;
	    	continue;
		}
	 	break;
	}	
	long result = 0;
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < m; j++)
    		if(!deleted[i][j])
    			result += candies[i][j];
    for(int j = 0; j < m; j++)
    	if(penalty[j])
    		result -= (penalty[j] + 1) * (penalty[j] + 1) / 4;
	return result;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
       cin >> colors[i];
    for(int i = 0; i < m; i++)
       cin >> boxes[i];
    for(int i = 0; i < n; i++)
       for(int j = 0; j < m; j++)
          cin >> candies[i][j];
    printf("%ld", solve());
    return 0;
}
