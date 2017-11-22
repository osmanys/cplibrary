#include <bits/stdc++.h>
#define fi "A-small-attempt1.in"
#define fo "A-small-attempt1.out"
#define PI 3.141592653589793238L
#define MAX 100

using namespace std;

class PanCake{
	public:
		long long radius;
		long long height;
};

bool compare(PanCake a, PanCake b){ return (a.radius * a.radius + 2 * a.radius * a.height > b.radius * b.radius + 2 * b.radius * b.height); }

int main(){
    freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);    
    // code here
    int t, n, k;
    long long r, h, result, maxd;
    vector<PanCake> data(MAX);
    vector<long long> rows;
    scanf("%d", &t);
    for(int tt = 1; tt <= t; tt++){
    	printf("Case #%d: ", tt);
		scanf("%d %d", &n, &k);
		data.clear();
		for(int i = 0; i < n; i++){
			scanf("%lld %lld", &r, &h);
			data[i].radius = r;
			data[i].height = h;
		}
		sort(data.begin(), data.begin() + n, compare);
		result = 0;
		rows.clear();
		for(int i = 0; i < k; i++){
			result += data[i].radius * data[i].height;
			rows.push_back(data[i].radius);
		}
		sort(rows.begin(), rows.end());
		printf("%.6LF\n", floor(1000000 * (PI * rows[k - 1] * rows[k - 1] + 2 * PI * result)) / 1000000);
	}
    
	return 0;
}
