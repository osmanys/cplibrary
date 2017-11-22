#include <bits/stdc++.h>
#define fi "D-small-attempt1.in"
#define fo "D-small-attempt1.out"
#define MAX 100

using namespace std;

int main(){
    freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);    
    // code here
    int t, n, m, r, c, total, total2;
    char type;
    bool colrow, diag;
    int grid[MAX][MAX], grid2[MAX][MAX];
    vector<int> changes, changes2;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
    	scanf("%d %d", &n, &m);
    	memset(grid, 0, sizeof grid);
    	memset(grid2, 0, sizeof grid2);
    	total = 0;
    	total2 = 0;
    	for(int j = 0; j < m; j++){
    		cin >> type >> r >> c;
    		if(type == '+'){
    			grid[r - 1][c - 1] = 1;
    			grid2[r - 1][c - 1] = 1;
    			total++;
    			total2++;
    		}
    		else if(type == 'x'){
    			grid[r - 1][c - 1] = 2;
    			grid2[r - 1][c - 1] = 2;
    			total++;
    			total2++;
    		}
    		else{
    			grid[r - 1][c - 1] = 3;
    			grid2[r - 1][c - 1] = 3;
    			total += 2;
    			total2 += 2;
    		}
		}
		/*for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				type = grid[j][k] == 3 ? 'o' : (grid[j][k] == 2 ? 'x' : (grid[j][k] == 1 ? '+' : '.'));
				printf("%c", type);
			}
			printf("\n");
		}*/
    	printf("Case #%d: ", i);
    	//version
		changes.clear();
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
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
		//version 2
		changes2.clear();
		for(int k = 0; k < n; k++){
			for(int j = 0; j < n; j++){
				if(grid2[j][k] != 3){
					colrow = true;
					diag = true;
					for(int l = 0; l < n; l++){
						if(l != j){
							if(grid2[l][k] != 0 && grid2[l][k] != 1){
								colrow = false;
								break;
							}
						}
					}
					if(colrow){
						for(int l = 0; l < n; l++){
							if(l != k){
								if(grid2[j][l] != 0 && grid2[j][l] != 1)
									colrow = false;
							}
						}
					}
					for(int l = -min(j, k); l < n; l++){
						if(j + l >= n || k + l >= n)
							break;
						if(l != 0){
							if(grid2[j + l][k + l] != 0 && grid2[j + l][k + l] != 2)
								diag = false;
						}
					}
					for(int l = -min(j, n - k - 1); l < n; l++){
						if(j + l >= n || k - l < 0)
							break;
						if(l != 0){
							if(grid2[j + l][k - l] != 0 && grid2[j + l][k - l] != 2)
								diag = false;
						}
					}
					if(colrow && diag){
						changes2.push_back(3);
						changes2.push_back(j + 1);
						changes2.push_back(k + 1);
						total2 += grid2[j][k] ? 1 : 2;
						grid2[j][k] = 3;
					}
					else if(!grid2[j][k]){
						if(diag){
							changes2.push_back(1);
							changes2.push_back(j + 1);
							changes2.push_back(k + 1);
							total2++;							
							grid2[j][k] = 1;
						}
						else if(colrow){
							changes2.push_back(2);
							changes2.push_back(j + 1);
							changes2.push_back(k + 1);
							total2++;
							grid2[j][k] = 2;
						}
					}
				}
			}
		}
		if(total > total2){
			int size = changes.size();
			printf("%d %d", total, size / 3);
			for(int j = 0; j < size; j += 3){
				type = changes[j] == 3 ? 'o' : (changes[j] == 2 ? 'x' : '+');
				printf("\n%c %d %d", type, changes[j + 1], changes[j + 2]);
			}
			printf("\n");
			/*for(int j = 0; j < n; j++){
				for(int k = 0; k < n; k++){
					type = grid[j][k] == 3 ? 'o' : (grid[j][k] == 2 ? 'x' : (grid[j][k] == 1 ? '+' : '.'));
					printf("%c", type);
				}
				printf("\n");
			}*/
		}
		else{
			int size = changes2.size();
			printf("%d %d", total2, size / 3);
			for(int j = 0; j < size; j += 3){
				type = changes2[j] == 3 ? 'o' : (changes2[j] == 2 ? 'x' : '+');
				printf("\n%c %d %d", type, changes2[j + 1], changes2[j + 2]);
			}
			printf("\n");
			/*for(int j = 0; j < n; j++){
				for(int k = 0; k < n; k++){
					type = grid2[j][k] == 3 ? 'o' : (grid2[j][k] == 2 ? 'x' : (grid2[j][k] == 1 ? '+' : '.'));
					printf("%c", type);
				}
				printf("\n");
			}*/			
		}
	}
	
	return 0;
}
