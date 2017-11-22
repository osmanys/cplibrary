#include <bits/stdc++.h>
#define MAX 10000

using namespace std;
int d[MAX];

int main(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < k; i++)
		cin >> d[i];
	int r, t4 = n;
	int t2 = 2 * n;
	int t1 = 0;
	for(int i = 0; i < k; i++){
		r = d[i];
		if(t4){
			t4 -= r / 4;
			r = r % 4;
		}
		if(t4 < 0){
			r -= 4 * t4;
			t4 = 0;
		}
		if(t2){
			t2 -= r / 2;
			r = r % 2;
		}
		if(t2 < 0){
			r -= 2 * t2;
			t2 = 0;
		}
		if(r){
			if(r < 2 * t2){
				t2 -= r / 2;
				if(r & 1){
					if(t1)
						t1--;
					else{
						t2--;
					}
				}
				r = 0;
			}
			else if(r < 4 * t4){
				t4 -= r / 4;
				if(r % 4 == 3){
					t4--;
				}
				else if(r % 4 == 2){
					t4--;
					t1++;
				}
				else if(r % 4 == 1){
					t4--;
					t2++;
				}
				r = 0;
			}
			else
				break;
		}
	}	
	if(r)
		cout << "NO";
	else
		cout << "YES";
	return 0;
}
