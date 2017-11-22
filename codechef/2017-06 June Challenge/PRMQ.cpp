#include <bits/stdc++.h>
#define MAX 100000
#define MAX_SIZE 1000001
 
using namespace std;
long d[MAX];
 
vector<long long> isprime(MAX_SIZE , true);
vector<long long> primes;
vector<long long> SPF(MAX_SIZE);
 
void manipulated_seive(long n){
    isprime[0] = isprime[1] = false ;
    for (long long i = 2; i < n; i++){
        if (isprime[i]){
            primes.push_back(i);
            SPF[i] = i;
        }
        for (long long j = 0; j < primes.size() && i * primes[j] < n && primes[j] <= SPF[i]; j++){
            isprime[i * primes[j]] = false;
            SPF[i * primes[j]] = primes[j];
        }
    }
}
 
pair<vector<long>, vector<int> > generatePrimeFactors(long n){
	vector<long> f;
	vector<int> p;
    long curr = SPF[n];
    int cnt = 1;
    while (n > 1){
        n /= SPF[n];
        if (curr == SPF[n]){
            cnt++;
            continue;
        }
        f.insert(f.begin(), curr);
        p.insert(p.begin(), cnt);
        //f[curr] = cnt;
        curr = SPF[n];
    }
    return make_pair(f, p);
}
 
int main(){
	long n, i, q, l, r, x, y, itlow, itup;
	vector<pair<vector<long>, vector<int> > > factors;
	vector<long> tl;
	vector<int> ti;
	long long result;
	manipulated_seive(MAX_SIZE);
	scanf("%ld", &n);
	for(i = 0; i < n; i++){
		scanf("%ld", &d[i]);
		factors.push_back(generatePrimeFactors(d[i]));
	}
	scanf("%ld", &q);
	while(q--){
		scanf("%ld %ld %ld %ld", &l, &r, &x, &y);
		result = 0;
		for(i = l - 1; i < r; i++){
			tl = factors[i].first;
			ti = factors[i].second;			
			itlow = lower_bound(tl.begin(), tl.end(), x) - tl.begin();
			itup = lower_bound(tl.begin(), tl.end(), y) - tl.begin();
			if(itlow < tl.size()){
				if(itup == itlow){
					if(tl[itlow] >= x)
						result += ti[itlow];
					if(itlow)
						result -= ti[itlow - 1];
				}
				else{					
					if(itup == tl.size())
						itup--;
					result += ti[itup] - ti[itlow];
					if(itlow)
						result -= ti[itlow - 1];
				}
			}
		}
		printf("%lld\n", result);
	}
	return 0;
}
