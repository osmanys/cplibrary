#include <bits/stdc++.h>
#define MAX 1000
 
using namespace std;
vector<pair< int, int> > p;
int d[MAX];

void generate(){
	int a, b, c, d, e, f;
	for(int i = 1; i <= 6; i++){
		a = 1;
		for(int i2 = 1; i2 <= 6; i2++){
			if(i2 != a){
				b = i2;
				for(int i3 = 1; i3 <= 6; i3++){
					if(i3 != a && i3 != b){
						c = i3;
						for(int i4 = 1; i4 <= 6; i4++){
							if(i4 != a && i4 != b && i4 != c){
								d = i4;
								for(int i5 = 1; i5 <= 6; i5++){
									if(i5 != a && i5 != b && i5 != c && i5 != d){
										e = i5;
										for(int i6 = 1; i6 <= 6; i6++){
											if(i6 != a && i6 != b && i6 != c && i6 != d && i6 != e){
												f = i6;
												p.push_back(make_pair(a, b));
												p.push_back(make_pair(c, d));
												p.push_back(make_pair(e, f));
											}
										}
									}
								}								
							}
						}
					}
				}
			}
		}		
	}
}
 
int main() {
	pair<int, int> p1, p2, p3, pr1, pr2, pr3;bool found, rfound;
	generate();
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i++)
			scanf("%d", &d[i]);
		rfound = true;
		for(int i = 1; i < n; i++)
			if(d[i - 1] == d[i]){
				rfound = false;
				break;
			}
		if(!rfound){
			printf("-1\n");
			continue;
		}
		rfound = false;
		for(long k = 0; k < p.size(); k+=3){
			p1 = p[k];
			p2 = p[k + 1];
			p3 = p[k + 2];
			if(p1.first == 4 && p2.first == 6 && p3.first == 2)
				found = true;
			found = true;
			for(int i = 1; i < n; i++){
				if(((d[i - 1] == p1.first) && (d[i] == p1.second)) || ((d[i - 1] == p1.second) && (d[i] == p1.first))){
					found = false;						
					break;
				}
				if(((d[i - 1] == p2.first) && (d[i] == p2.second)) || ((d[i - 1] == p2.second) && (d[i] == p2.first))){
					found = false;						
					break;
				}
				if(((d[i - 1] == p3.first) && (d[i] == p3.second)) || ((d[i - 1] == p3.second) && (d[i] == p3.first))){
					found = false;						
					break;
				}
			}
			if(found){
				rfound = true;
				pr1 = p1;
				pr2 = p2;
				pr3 = p3;
				break;
			}
		}
		if(!rfound)
			printf("-1\n");
		else{
			int pos[7];
			pos[pr1.first] = pr1.second;
			pos[pr1.second] = pr1.first;
			pos[pr2.first] = pr2.second;
			pos[pr2.second] = pr2.first;
			pos[pr3.first] = pr3.second;
			pos[pr3.second] = pr3.first;
			for(int i = 1; i <= 6; i++)
				printf("%d ", pos[i]);
			printf("\n");
		}
	}
    return 0;
}
