#include <bits/stdc++.h>

using namespace std;

const int ALPHABET_SIZE = 10;

struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
    long count;
};

struct TrieNode *getNode(void){
    struct TrieNode *pNode =  new TrieNode;
 
    pNode->isEndOfWord = false;
    pNode->count = 0;
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
 
    return pNode;
}

void insert(struct TrieNode *root, string key){
    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++){
        int index = key[i] - '0';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
 
        pCrawl = pCrawl->children[index];
    }
    
    pCrawl->isEndOfWord = true;
    pCrawl->count++;
}

long search(struct TrieNode *root, string key){
    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++){
        int index = key[i] - '0';
        if (!pCrawl->children[index])
            return 0;
 
        pCrawl = pCrawl->children[index];
    }
 
    return ((pCrawl != NULL && pCrawl->isEndOfWord) ? pCrawl->count : 0);
}

int main(){
    struct TrieNode *root = getNode();
    TrieNode *croot;
	int n;long c;bool find;
	string s, t;
	vector<string> ss;
	cin >> n;
	getline(cin, s);
	for(int i = 0; i < n; i++){
		getline(cin, s);
		croot = getNode();
		for(int i = 0; i < 9; i++){
			t = "";
			for(int j = i; j < 9; j++){
				t += s[j];
				c = search(croot, t);
				if(!c){
					insert(root, t);
					insert(croot, t);
				}
			}
		}
		ss.push_back(s);
	}
	for(int i = 0; i < n; i++){
		s = ss[i];
		find = false;
		for(int k = 1; k <= 9; k++){
			for(int i = 0; i + k <= 9; i++){
				t = "";
				for(int j = i; j < i + k; j++)
					t += s[j];					
				c = search(root, t);
				if(c == 1){
					find = true;
					break;
				}
			}
			if(find)
				break;
		}
		cout << t << "\n";
	}
	return 0;
}
