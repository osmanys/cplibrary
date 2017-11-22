#include <bits/stdc++.h>
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define MAX 300000

using namespace std;

struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];
};

struct TrieNode *getNode(void){
    struct TrieNode *pNode = NULL; 
    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode)); 
    if (pNode){
        int i;
        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }
    return pNode;
}

long insert(struct TrieNode *root, const string key){
    int level;
    int length = key.length();
    int index;
    long result = 0;
    struct TrieNode *pCrawl = root; 
    for (level = 0; level < length; level++){
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index]){
            pCrawl->children[index] = getNode();
			result++;
		}
        pCrawl = pCrawl->children[index];
    }
    return result;
}

TrieNode *palindromes[MAX];
long nodeCounts[MAX];
vector<long> indexes;

void solve(long n, string s){
	long prefixes = 0, i, j, t, d;
	int index;
	struct TrieNode *odd = getNode(), *even = getNode(), *prefixTrie = getNode();
	for(i = 0; i < n; i++){
        index = CHAR_TO_INDEX(s[i]);
        t = indexes.size();
		if(t > 0){
			j = 0;
			d = 0;
			while(j < t - 1){
				if(indexes[j - d] && s[indexes[j - d] - 1] == s[i]){				
			        if (!palindromes[indexes[j - d]]->children[index]){
			            palindromes[indexes[j - d]]->children[index] = getNode();
			        	prefixes += insert(prefixTrie, s.substr(indexes[j - d] - 1, nodeCounts[indexes[j - d]] + 2));
			        }
					palindromes[indexes[j - d] - 1] = palindromes[indexes[j - d]]->children[index];
					nodeCounts[indexes[j - d] - 1] = nodeCounts[indexes[j - d]] + 2;
					indexes[j - d]--;
				}
				else{
					indexes.erase(indexes.begin() + j - d);
					d++;
				}
				j++;
			}
			if(i > 1 && s[i - 2] == s[i]){				
		        if (!palindromes[i - 1]->children[index]){
		            palindromes[i - 1]->children[index] = getNode();
		        	prefixes += insert(prefixTrie, s.substr(i - 2, 3));
		        }
				palindromes[i - 2] = palindromes[i - 1]->children[index];
				nodeCounts[i - 2] = 3;
				indexes.push_back(i - 1);
				indexes[t - 1] = i - 2;
			}
			if(s[i] == s[i - 1]){				
		        if (!even->children[index]){
		        	prefixes += insert(prefixTrie, s.substr(i - 1, 2));
		            even->children[index] = getNode();
		        }
				palindromes[i - 1] = even->children[index];
				nodeCounts[i - 1] = 2;
			}
			else
				indexes.erase(indexes.begin() + indexes.size() - 1);			
		}
        if (!odd->children[index]){
		    prefixes += insert(prefixTrie, s.substr(i, 1));
            odd->children[index] = getNode();
        }
		palindromes[i] = odd->children[index];
		nodeCounts[i] = 1;
		indexes.push_back(i);
		
		printf("%ld\n", prefixes);
	}
}

int main() {
    long n;
    cin >> n;
    string s;
    cin >> s;
    solve(n, s);    

    return 0;
}
