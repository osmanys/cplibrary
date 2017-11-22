#include <bits/stdc++.h>
#define INC 0
#define COPY 1
#define DEC 2
#define ZERO 0
#define ONE 1
 
using namespace std;
int n;
int m[7][7];
int m3[3][3] = {{1, 0, 0}, {2, 1, 0}, {0, 2, 1}};
int m5[5][5] = {{1, 0, 0, 0, 0}, {2, 1, 0, 0, 0}, {3, 2, 1, 0, 0}, {4, 3, 2, 0, 0}, {0, 4, 3, 0, 0}};
int m7[7][7] = {{1, 0, 0, 0, 0, 0, 0}, {2, 1, 0, 0, 0, 0, 0}, {3, 2, 1, 0, 0, 0, 0}, {4, 3, 2, 0, 0, 0, 0}, {5, 4, 3, 0, 0, 0, 0}, {6, 5, 4, 0, 0, 0, 0}, {0, 6, 5, 0, 0, 0, 0}};
vector<pair<pair<long, long>, long> > moves;
long cur;
vector<pair<string, vector<pair<pair<long, long>, long> > > > groups;
long group;

void add_group(string name){
	group++;
	vector<pair<pair<long, long>, long> > g;
	groups.push_back(make_pair(name, g));
}

void init(){
	moves.clear();
	cur = 100;
	group = -1;
	if(n == 3){		
		for(int i1 = 0; i1 < n; i1++){
			for(int i2 = 0; i2 < n; i2++){
				m[i1][i2] = m3[i1][i2];
			}
		}
	}
	else if(n == 5){		
		for(int i1 = 0; i1 < n; i1++){
			for(int i2 = 0; i2 < n; i2++){
				m[i1][i2] = m5[i1][i2];
			}
		}
	}
	else{		
		for(int i1 = 0; i1 < n; i1++){
			for(int i2 = 0; i2 < n; i2++){
				m[i1][i2] = m7[i1][i2];
			}
		}
	}
	add_group("begin");
}

long get_mem(){
	long m = cur;
	cur += 10;
	return m;
}

void move(long a, long b, long c){
	moves.push_back(make_pair(make_pair(a, b), c));
	groups[group].second.push_back(make_pair(make_pair(a, b), c));
}

void inc(long a){
	moves.push_back(make_pair(make_pair(a, INC), a));
	groups[group].second.push_back(make_pair(make_pair(a, INC), a));
}

void inc(long a, long c){
	moves.push_back(make_pair(make_pair(a, INC), c));
	groups[group].second.push_back(make_pair(make_pair(a, INC), c));
}

void dec(long a){
	moves.push_back(make_pair(make_pair(a, DEC), a));
	groups[group].second.push_back(make_pair(make_pair(a, DEC), a));
}

void dec(long a, long c){
	moves.push_back(make_pair(make_pair(a, DEC), c));
	groups[group].second.push_back(make_pair(make_pair(a, DEC), c));
}

void copy(long a, long c){
	moves.push_back(make_pair(make_pair(a, COPY), c));
	groups[group].second.push_back(make_pair(make_pair(a, COPY), c));
}

void test(){
	int t[100000];
	int x, y, _r;
	for(int i1 = 0; i1 < n; i1++){
		for(int i2 = 0; i2 < n; i2++){
			for(int i3 = 0; i3 < n; i3++){
				for(int i4 = 0; i4 < n; i4++){
					for(int i = 0; i < n; i++)
						t[i] = i;
					t[n] = i1;
					t[n + 1] = i2;
					t[n + 2] = i3;
					t[n + 3] = i4;
					x = n * i1 + i2;
					y = n * i3 + i4;
					if(x == 19 && y == 24)
						n = 5;
					for(long i = 0; i <= group; i++){
						//printf("%s\n", groups[i].first.c_str());			
						for(vector<pair<pair<long, long>, long> >::iterator it = groups[i].second.begin(); it != groups[i].second.end(); it++){
							//printf("%ld %ld %ld\n", (*it).first.first, (*it).first.second, (*it).second);
							t[(*it).second] = m[t[(*it).first.first]][t[(*it).first.second]];
						}
					}
					_r = n * n * n * t[n + 4] + n * n * t[n + 5] + n * t[n + 6] + t[n + 7];
					if(x * y != _r)
						printf("%d * %d != %d\n", x, y, _r);
				}		
			}		
		}		
	}
}

void increment(long a, long idx, int iteration){
	long t = get_mem();
	
	copy(idx, t + 1);
	copy(a, t);
	for(int j = 0; j < iteration; j++)
		dec(t);
	for(int j = 0; j < n - 1; j++)
		inc(t);
	for(int j = 0; j < n - 2; j++)
		dec(t);
	move(idx, t, idx);
	
	for(int j = 0; j < n - 2; j++)
		dec(t + 1);
	move(t + 1, t, t + 1);
	dec(t + 1);
	for(int j = 0; j < n - 1; j++)
		inc(t + 1);
	for(int j = 0; j < n - 2; j++)
		dec(t + 1);
	move(idx + 1, t + 1, idx + 1);
}

void sum(long a, long b, long idx){
	char name[256];
	sprintf(name, "sum: %ld %ld %ld", a, b, idx);
	add_group(name);
	
	copy(b, idx);
	copy(ZERO, idx + 1);
	for(int i = 0; i < n - 1; i++)
		increment(a, idx, i);
}

void sum_acumulative(long a, long b, long idx){
	char name[256];
	sprintf(name, "sum: %ld %ld %ld", a, b, idx);
	add_group(name);
	
	copy(b, idx);
	//copy(ZERO, idx + 1);
	for(int i = 0; i < n - 1; i++)
		increment(a, idx, i);
}

void mult(long a, long b, long idx){
	char name[256];
	sprintf(name, "mult3: %ld %ld %ld", a, b, idx);
	add_group(name);
	
	long t = get_mem(), t2 = get_mem();	
	copy(ZERO, idx);
	copy(ZERO, idx + 1);	
	for(int i = 0; i < n - 1; i++){
		copy(a, t);
		for(int j = 0; j < i; j++)
			dec(t);
		for(int j = 0; j < n - 1; j++)
			inc(t);
		for(int j = 0; j < n - 2; j++)
			dec(t);
		inc(t);
		copy(b, t2);
		for(int j = 0; j < n - 1; j++)
			move(t2, t, t2);
		
		sum_acumulative(t2, idx, idx);		
	}
}

void f(){	
	init();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			printf("%d ", m[i][j]);
		printf("\n");
	}
	long m1 = get_mem(), m2 = get_mem(), m3 = get_mem(), m4 = get_mem(), c = get_mem(), c2 = get_mem(), c3 = get_mem();
	
	mult(n, n + 2, m1);
	mult(n + 1, n + 2, m2);
	mult(n, n + 3, m3);
	mult(n + 1, n + 3, m4);
	copy(m4, n + 7);
	sum(m2, m3, c);
	sum(c, m4 + 1, c + 2);
	copy(c + 2, n + 6);
	sum(c + 1, c + 3, c2);
	sum(m2 + 1, m3 + 1, c2 + 2);
	sum(c2, c2 + 2, c);
	sum(c, m1, c + 2);
	copy(c + 2, n + 5);
	sum(c + 1, c + 3, c3);
	sum(c3, m1 + 1, c3 + 1);
	sum(c3 + 1, c2 + 1, c3 + 2);
	sum(c3 + 2, c2 + 3, c3 + 3);
	copy(c3 + 3, n + 4);
	
	printf("%ld\n", moves.size());
	for(vector<pair<pair<long, long>, long> >::iterator it = moves.begin(); it != moves.end(); it++){
		printf("%ld %ld %ld\n", (*it).first.first, (*it).first.second, (*it).second);
	}
	//test();
}
 
int main() {
	scanf("%d", &n);
	f();
    return 0;
}
