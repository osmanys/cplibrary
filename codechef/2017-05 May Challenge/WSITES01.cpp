#include <bits/stdc++.h>
 
using namespace std;
 
struct TrieNode{
    map<char, struct TrieNode*> childrens;
    bool blockedLeaf;
    bool blocked;
};
 
struct TrieNode *getNode(){
    struct TrieNode *pNode = new TrieNode;
    pNode->blockedLeaf = false;
    pNode->blocked = true;
    return pNode;
}
 
void insert(struct TrieNode *root, string key, bool blocked){
    struct TrieNode *pCrawl = root; 
    for(string::iterator it = key.begin(); it != key.end(); it++){
        if (!pCrawl->childrens[*it])
            pCrawl->childrens[*it] = getNode();
        if(!blocked)
        	pCrawl->childrens[*it]->blocked = false;
        pCrawl = pCrawl->childrens[*it];
    }
    if(blocked)
    	pCrawl->blockedLeaf = true;
}
 
bool findFilters(struct TrieNode *root, vector<string> &filters, string path){
    struct TrieNode *node = root;
    for(map<char, TrieNode*>::iterator it = node->childrens.begin(); it != node->childrens.end(); it++){
    	if(it->second->blocked)
    		filters.push_back(path + it->first);
		else{
	    	if(it->second->blockedLeaf){
	    		filters.clear();
	    		return false;
			}
			if(!findFilters(it->second, filters, path + it->first))
				return false;
		}
    }
    return true;
}
 
void constructTrie(string arr[], bool blocked[], long n, struct TrieNode *root){
    for(long i = 0; i < n; i++)
        insert(root, arr[i], blocked[i]);
}
 
bool filterPrefix(string arr[], bool blocked[], long n, vector<string> &filters){
    struct TrieNode *root = getNode();
    constructTrie(arr, blocked, n, root);
    return findFilters(root, filters, "");
}
 
int main() {
	long n, size;
	scanf("%ld\n", &n);
	string arr[n];
	string s;
	bool blocked[n];
	for(long i = 0; i < n; i++){
		getline(cin, s);
		if(s[0] == '+')
			blocked[i] = false;
		else
			blocked[i] = true;
		arr[i] = s.substr(2, s.size() - 2);
	}
    vector<string> filters;
	if(!filterPrefix(arr, blocked, n, filters))
		printf("%d", -1);
	else{
		size = filters.size();
	    printf("%ld\n", size);
	    for(long i = 0; i < size; i++){
	    	printf("%s\n", filters[i].c_str());
		}
	}
	
    return 0;
}
