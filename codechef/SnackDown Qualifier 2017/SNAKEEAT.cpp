#include <bits/stdc++.h>

using namespace std;

int main() {
	long t;
	long long x11, y11, x12, y12, x21, y21, x22, y22;
	scanf("%ld", &t);
	while(t--){
		cin >> x11 >> y11 >> x12 >> y12 >> x21 >> y21 >> x22 >> y22;
		if(x11 == x12){
			if(x21 == x22){
				if(x12 != x21){
					printf("no\n");
					continue;
				}
				else if((y11 == y12 && y12 == y21 && y21 == y22) || (y11 < y21 && y11 < y22 && y12 < y21 && y12 < y22) || (y11 > y21 && y11 > y22 && y12 > y21 && y12 > y22)){
					printf("no\n");
					continue;
				}
			}
			else if((x11 != x21 || y11 != y21) && (x11 != x22 || y11 != y22) && (x12 != x21 || y12 != y21) && (x12 != x22 || y12 != y22)){
				printf("no\n");
				continue;
			}
		}
		else{
			if(y21 == y22){
				if(y12 != y21){
					printf("no\n");
					continue;
				}
				else if((x11 == x12 && x12 == x21 && x21 == x22) || (x11 < x21 && x11 < x22 && x12 < x21 && x12 < x22) || (x11 > x21 && x11 > x22 && x12 > x21 && x12 > x22)){
					printf("no\n");
					continue;
				}
			}
			else if((x11 != x21 || y11 != y21) && (x11 != x22 || y11 != y22) && (x12 != x21 || y12 != y21) && (x12 != x22 || y12 != y22)){
				printf("no\n");
				continue;
			}
		}
		printf("yes\n");
	}
	
    return 0;
}
