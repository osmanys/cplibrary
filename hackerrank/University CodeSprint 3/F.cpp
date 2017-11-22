#include <bits/stdc++.h>
#define M 8
#define N 8

using namespace std;
char boggle[M][N];
bool visited[M][N];
string s;
int sz;
long long r;

void findWordsUtil(int i, int j, int c){
    visited[i][j] = true;
    if(s[c] == boggle[i][j]){
	    if(c == sz - 1)
	    	r++;    
	    for(int row = i - 1; row <= i + 1 && row < M; row++)
	      for(int col = j - 1; col <= j + 1 && col < N; col++)
	        if(row >= 0 && col >= 0 && !visited[row][col] && c < sz)
	          findWordsUtil(row, col, c + 1);
    }
    visited[i][j] = false;
}

long findWords(){
    r = 0;
    for (int i = 0; i < M; i++)
       for (int j = 0; j < N; j++)
            findWordsUtil(i, j, 0);
    return r;
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	string sl;
	cin >> sz >> s;
	getline(cin, sl);
	for(int i = 0; i < M; i++){
		getline(cin, sl);
		for(int j = 0; j < N; j++)
			boggle[i][j] = sl[j];
	}
	findWords();
	cout << r;
	return 0;
}

