#include <bits/stdc++.h>
#define fi "D.in"
#define fo "D.out"
#define MAX 100

using namespace std;

int main(){
    freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);    
    // code here
    int t, n, m, r, c, total;
    char type;
    bool colrow, diag;
    int grid[MAX][MAX];
    vector<int> changes;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
    	scanf("%d %d", &n, &m);
    	memset(grid, 0, sizeof grid);
    	total = 0;
    	for(int j = 0; j < m; j++){
    		cin >> type >> r >> c;
    		if(type == '+'){
    			grid[r - 1][c - 1] = 1;
    			total++;
    		}
    		else if(type == 'x'){
    			grid[r - 1][c - 1] = 2;
    			total++;
    		}
    		else{
    			grid[r - 1][c - 1] = 3;
    			total += 2;
    		}
		}
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				type = grid[j][k] == 3 ? 'o' : (grid[j][k] == 2 ? 'x' : (grid[j][k] == 1 ? '+' : '.'));
				printf("%c", type);
			}
			printf("\n");
		}
    	printf("Case #%d: ", i);
		changes.clear();
		for(int k = 0; k < n; k++){
			for(int j = 0; j < n; j++){
				if(grid[j][k] != 3){
					colrow = true;
					diag = true;
					for(int l = 0; l < n; l++){
						if(l != j){
							if(grid[l][k] != 0 && grid[l][k] != 1){
								colrow = false;
								break;
							}
						}
					}
					if(colrow){
						for(int l = 0; l < n; l++){
							if(l != k){
								if(grid[j][l] != 0 && grid[j][l] != 1)
									colrow = false;
							}
						}
					}
					for(int l = -min(j, k); l < n; l++){
						if(j + l >= n || k + l >= n)
							break;
						if(l != 0){
							if(grid[j + l][k + l] != 0 && grid[j + l][k + l] != 2)
								diag = false;
						}
					}
					for(int l = -min(j, n - k - 1); l < n; l++){
						if(j + l >= n || k - l < 0)
							break;
						if(l != 0){
							if(grid[j + l][k - l] != 0 && grid[j + l][k - l] != 2)
								diag = false;
						}
					}
					if(colrow && diag){
						changes.push_back(3);
						changes.push_back(j + 1);
						changes.push_back(k + 1);
						total += grid[j][k] ? 1 : 2;
						grid[j][k] = 3;
					}
					else if(!grid[j][k]){
						if(colrow){
							changes.push_back(2);
							changes.push_back(j + 1);
							changes.push_back(k + 1);
							total++;
							grid[j][k] = 2;
						}
						else if(diag){
							changes.push_back(1);
							changes.push_back(j + 1);
							changes.push_back(k + 1);
							total++;							
							grid[j][k] = 1;
						}
					}
				}
			}
		}
		int size = changes.size();
		printf("%d %d", total, size / 3);
		for(int j = 0; j < size; j += 3){
			type = changes[j] == 3 ? 'o' : (changes[j] == 2 ? 'x' : '+');
			printf("\n%c %d %d", type, changes[j + 1], changes[j + 2]);
		}
		printf("\n");
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				type = grid[j][k] == 3 ? 'o' : (grid[j][k] == 2 ? 'x' : (grid[j][k] == 1 ? '+' : '.'));
				printf("%c", type);
			}
			printf("\n");
		}
	}
	
	return 0;
}
