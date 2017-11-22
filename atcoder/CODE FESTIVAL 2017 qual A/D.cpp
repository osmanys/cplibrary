#include <bits/stdc++.h>
#define MAX 500

using namespace std;
char res[MAX][MAX];

int main(){
	int r, c, d;char cur;
	cin >> r >> c >> d;
	for(int i = 0; i * d < r; i++){
		for(int j = 0; j * d < c; j++){
			if((i + j) % 4 == 0)
			cur = 'R';
			else if((i + j) % 4 == 1)
			cur = 'Y';
			else if((i + j) % 4 == 2)
			cur = 'G';
			else if((i + j) % 4 == 3)
			cur = 'B';
			for(int ii = 1; ii < d - 1; ii++){
				for(int jj = 1; jj < d - 1; jj++){
					res[i * d + ii][j * d + jj] = cur;
				}
			}
			res[i * d][j * d] = 'R';			
			for(int ii = 0; ii < d - 1; ii++){
				res[i * d][j * d + ii] = 'R';
			}
			res[i * d + d - 1][j * d + d - 1] = 'Y';
			for(int ii = 1; ii < d; ii++){
				res[i * d + d - 1][j * d + ii] = 'Y';
			}
			res[i * d + d - 1][j * d] = 'G';
			for(int ii = 1; ii < d; ii++){
				res[i * d + ii][j * d] = 'G';
			}
			res[i * d][j * d + d - 1] = 'B';
			for(int ii = 0; ii < d - 1; ii++){
				res[i * d + ii][j * d + d - 1] = 'B';
			}
		}
	}
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cout << res[i][j];
		}
		cout << "\n";
	}
	return 0;
}
