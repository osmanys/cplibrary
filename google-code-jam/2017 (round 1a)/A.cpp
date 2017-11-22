#include <bits/stdc++.h>
#define fi "A-large.in"
#define fo "A-large.out"
#define MAX 25

using namespace std;

int main(){
    freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);    
    // code here
    int t, r, c, max, max_i, max_j;
    string line;
    char cur_ini, max_ini;
    vector<char> initial;
    vector<int> coord;
    char cake[MAX][MAX];
    bool mark[MAX][MAX];
    bool used_ini[26];
    scanf("%d", &t);
    for(int tt = 1; tt <= t; tt++){
    	printf("Case #%d:\n", tt);
		scanf("%d %d", &r, &c);
		initial.clear();
		coord.clear();
		memset(mark, false, sizeof mark);
		memset(used_ini, false, sizeof used_ini);
		for(int i = 0 ; i < r; i++){
			cin >> line;
			for(int j = 0; j < c; j++){
				cake[i][j] = line[j];
				if(line[j] != '?'){
					initial.push_back(line[j]);
					coord.push_back(i);
					coord.push_back(j);
				}
			}
		}
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				if(!mark[i][j]){
					max = 0;
					for(int ii = i; ii < r; ii++){
						for(int jj = j; jj < c; jj++){
							if(!mark[ii][jj]){
								cur_ini = 0;
								for(int k = 0; k < initial.size(); k++){
									if(!used_ini[initial[k] - 65] && coord[2*k] >= i && coord[2*k] <= ii && coord[2*k+1] >= j && coord[2*k+1] <= jj){
										if(cur_ini == 0){
											cur_ini = initial[k];
										}
										else{
											cur_ini = 1;
											break;
										}
									}
								}
								for(int iii = i; iii <= ii; iii++){
									int jjj = j;
									for(; jjj <= jj; jjj++){
										if(mark[iii][jjj]){
											cur_ini = 1;
											break;
										}
									}
									if(jjj <= jj)
										break;
								}
								if(cur_ini != 0 && cur_ini != 1 && max < (ii - i + 1) * (jj - j + 1)){
									max = (ii - i + 1) * (jj - j + 1);
									max_i = ii;
									max_j = jj;
									max_ini = cur_ini;
								}
							}
						}
					}
					used_ini[max_ini - 65] = true;
					for(int ii = i; ii <= max_i; ii++){
						for(int jj = j; jj <= max_j; jj++){
							cake[ii][jj] = max_ini;
							mark[ii][jj] = true;
						}
					}
				}
			}
		}
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				printf("%c", cake[i][j]);
			}
			printf("\n");
		}
	}
    
	return 0;
}
