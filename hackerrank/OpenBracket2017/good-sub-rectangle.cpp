#include <bits/stdc++.h>
#define MAX 4000000

using namespace std;
long d[MAX], c[MAX];

long binarySearch(long arr[], long l, long r, long x){
  while (l <= r){
    long m = l + (r - l) / 2;
    if (arr[m] == x) 
        return m;
    if (arr[m] < x) 
        l = m + 1; 
    else
        r = m - 1; 
  }
  return l; 
}

struct mapper{
	private:
		long index;
		long *value, *sum, *count;
	public:
		mapper(long capacity){
			index = 0;
			value = new long[capacity];
			sum = new long[capacity];
			count = new long[capacity];
		}
		void reset(){
			index = 0;
		}
		long total(){
			return index ? sum[index - 1] : 0;
		}
		void insert(long v){
			if(index){
				if(v == value[index - 1]){
					count[index - 1]++;
					sum[index - 1] += v;
				}
				else if(v > value[index - 1]){
					count[index] = count[index - 1] + 1;
					sum[index] = sum[index - 1] + v;
					value[index] = v;
					index++;
				}
				else{
					long b = binarySearch(value, 0, index - 1, v);
					sum[b] = (b ? sum[b - 1] : 0) + v * (count[index - 1] - (b ? count[b - 1] : 0) + 1);
					count[b] = count[index - 1] + 1;
					value[b] = v;
					index = b + 1;
				}
			}
			else{
				value[0] = v;
				sum[0] = v;
				count[0] = 1;
				index++;
			}
		}
		void prune(long v){
			if(index){
				if(v < value[index - 1]){
					long b = binarySearch(value, 0, index - 1, v);
					sum[b] = (b ? sum[b - 1] : 0) + v * (count[index - 1] - (b ? count[b - 1] : 0));
					count[b] = count[index - 1];
					value[b] = v;
					index = b + 1;
				}
			}
		}
};
vector<mapper> mapp;

int main(){
	long n, m, u;
	scanf("%ld %ld", &n, &m);
	long long r = 0;
	for(long j = 0; j < m; j++){
		scanf("%ld", &d[j]);
		if(j && d[j] >= d[j - 1])
			c[j] = c[j - 1] + 1;
		mapp.push_back(mapper(n));
		mapp[j].insert(c[j] + 1);
		r += mapp[j].total();
	}
	for(long i = 1; i < n; i++){
		for(long j = 0; j < m; j++){
			scanf("%ld", &d[i * m + j]);
			if(j && d[i * m + j] >= d[i * m + j - 1])
				c[i * m + j] = c[i * m + j - 1] + 1;
			long red = d + i * m + j + 1 - lower_bound(d + i * m + j - c[i * m + j], d + i * m + j + 1, d[(i - 1) * m + j]);
			if(red){
				mapp[j].prune(red);
				mapp[j].insert(c[i * m + j] + 1);
			}
			else{
				mapp[j].reset();
				mapp[j].insert(c[i * m + j] + 1);
			}
			r += mapp[j].total();
		}
	}
	cout << r;
	return 0;
}
