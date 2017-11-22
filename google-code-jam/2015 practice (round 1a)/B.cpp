#include <bits/stdc++.h>
#define fi "B-small-practice.in"
#define fo "B-small-practice.out"
#define MAX 100000
#define MAX_BARBERS 1000

using namespace std;

class Barber{
	public:
		int index;
		int rest;
};

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long lcm(long arr[], int n)
{
    long long ans = arr[0];
    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) / (gcd(arr[i], ans))); 
    return ans;
}

bool comparer(Barber a, Barber b){ return (a.rest < b.rest) || (a.rest == b.rest && a.index < b.index); }

int main(){
    freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);    
    // code here
    int t, b;
    long n, m, tot, ftot, v;
    long mb[MAX];
    Barber bar[MAX_BARBERS];
    long long l;
    scanf("%d", &t);
    for(int tt = 1; tt <= t; tt++){
    	printf("Case #%d: ", tt);
		scanf("%d %ld", &b, &n);
		for(int i = 0; i < b; i++){
			scanf("%d", &m);
			mb[i] = m;
		}
		l = lcm(mb, b);
		tot = 0;
		for(int i = 0; i < b; i++)
			tot += l / mb[i];
		n %= tot;		
		ftot = 0;
		for(int i = 0; i < b; i++){
			v = (l * n) / tot;
			ftot += v / mb[i];
			bar[i].index = i + 1;
			bar[i].rest = v % mb[i];			
		}
		sort(bar, bar + b, comparer);		
		printf("%d\n", bar[(b + n - ftot - 1) % b].index);
	}
    
	return 0;
}
