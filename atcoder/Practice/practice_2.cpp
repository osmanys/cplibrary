#include <bits/stdc++.h>

using namespace std;
int comp[26][26];

int partition (string &s, int low, int high){	
    char pivot = s[low], ans;
    int i = low - 1, j = high + 1;
    while (true){
        do{
            i++;
            if(s[i] == pivot)
            	break;
            else{
            	if(!comp[s[i] - 'A'][pivot - 'A']){
					printf("? %c %c\n", s[i], pivot);
					fflush(stdout);
					scanf(" %c", &ans);
					comp[s[i] - 'A'][pivot - 'A'] = (ans == '<') ? -1 : 1;
					comp[pivot - 'A'][s[i] - 'A'] = (ans == '<') ? -1 : 1;
				}
			}
        } while (comp[s[i] - 'A'][pivot - 'A'] == -1);
        do{
            j--;
            if(s[j] == pivot)
            	break;
            else{
            	if(!comp[s[j] - 'A'][pivot - 'A']){
					printf("? %c %c\n", s[j], pivot);
					fflush(stdout);
					scanf(" %c", &ans);
					comp[s[j] - 'A'][pivot - 'A'] = (ans == '<') ? -1 : 1;
					comp[pivot - 'A'][s[j] - 'A'] = (ans == '<') ? -1 : 1;
				}
			}
        } while (comp[s[j] - 'A'][pivot - 'A'] == 1);
        if (i >= j)
            return j;  
        swap(s[i], s[j]);
    }
}

void quickSort(string &s, int low, int high){
    if (low < high){
        int pi = partition(s, low, high);
        quickSort(s, low, pi);
        quickSort(s, pi + 1, high);
    }
}

int main(){
	int N, Q, i, j;
	scanf("%d %d", &N, &Q);
	string s;
	char ans;
	for(i = 0; i < N; i++)
		s += (char)('A' + i);
	quickSort(s, 0, N - 1);
	printf("! %s\n", s.c_str());
	fflush(stdout);
	
	return 0;
}
