#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 50005;
const int MAXM = 50005;
const int LN = 19;
 
int N, M, K, cur, LVL[MAXN], DP[LN][MAXN];
long IND[MAXN], A[MAXN], d[MAXN], ANS[MAXM];
int BL[MAXN << 1], ID[MAXN << 1], VAL[MAXN];
int l[MAXN], r[MAXN];
bool VIS[MAXN];
vector <int> adjList[MAXN];

struct Node{
    int key, key2, count, lcount;
    struct Node *left;
    struct Node *right;
    int height;
};
struct Node* root;

int height(struct Node *N){
    if (N == NULL)
        return 0;
    return N->height;
}

struct Node* newNode(int key, int key2){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->key2 = key2;
    node->count = 1;
    node->lcount = 0;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct Node *rightRotate(struct Node *y){
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    
    y->count -= (x->count - (T2 ? T2->count : 0));
    x->count += (y->count - (T2 ? T2->count : 0));
    y->lcount = (T2 ? T2->count : 0);
    
    return x;
}

struct Node *leftRotate(struct Node *x){
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    
    x->count -= (y->count - (T2 ? T2->count : 0));
    y->count += (x->count - (T2 ? T2->count : 0));
    y->lcount = x->count;
    
    return y;
}

int getBalance(struct Node *N){
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
struct Node* insert(struct Node* node, int key, int key2){
    if (node == NULL)
        return(newNode(key, key2));
    
    if (key > node->key || (key == node->key && key2 > node->key2)){
        node->left = insert(node->left, key, key2);
        node->lcount++;
    }
    else if (key < node->key || (key == node->key && key2 < node->key2))
        node->right = insert(node->right, key, key2);
    else
        return node;
    
    node->height = 1 + max(height(node->left), height(node->right));
    node->count++;
    
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && (key > node->left->key || (key == node->left->key && key2 > node->left->key2)))
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && (key < node->right->key || (key == node->right->key && key2 < node->right->key2)))
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && (key < node->left->key || (key == node->left->key && key2 < node->left->key2))){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && (key > node->right->key || (key == node->right->key && key2 > node->right->key2))){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    return node;
}

struct Node * maxValueNode(struct Node* node){
    struct Node* current = node;    
    while (current->left != NULL)
        current = current->left; 
    return current;
}

struct Node* deleteNode(struct Node* root, int key, int key2){
    if (root == NULL)
        return root;
    
    if (key > root->key || (key == root->key && key2 > root->key2)){
        root->left = deleteNode(root->left, key, key2);
        root->lcount--;
    }
    else if(key < root->key || (key == root->key && (key2 < root->key2)))
        root->right = deleteNode(root->right, key, key2);
    else{
        if((root->left == NULL) || (root->right == NULL)){
            struct Node *temp = root->left ? root->left : root->right;            
            if (temp == NULL){
                temp = root;
                root = NULL;
            }
            else
             *root = *temp;
            free(temp);
        }
        else{
            struct Node* temp = maxValueNode(root->right);
            root->key = temp->key;
            root->key2 = temp->key2;
            root->right = deleteNode(root->right, temp->key, temp->key2);
        }
    }
    
    if (root == NULL)
      return root;
    
    root->height = 1 + max(height(root->left), height(root->right));
    root->count--;
    
    int balance = getBalance(root);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
 
    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
 
    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}

int k_largest(struct Node* root, int k){
    int ret = -1; 
    if(root){
        Node* pTraverse = root;
        while(pTraverse){
            if((pTraverse->lcount + 1) == k){
                ret = pTraverse->key2;
                break;
            }
            else if(k > pTraverse->lcount){
                k = k - (pTraverse->lcount + 1);
                pTraverse = pTraverse->right;
            }
            else
                pTraverse = pTraverse->left;
        }
    } 
    return ret;
}
 
struct query{
	int id, l, r, lc, k;
	bool operator < (const query& rhs){
		return (BL[l] == BL[rhs.l]) ? (r < rhs.r) : (BL[l] < BL[rhs.l]);
	}
} Q[MAXM];

void dfs(){
	int u, par, i, v;
	pair<int, int> s;
	stack<pair<int, int> > stack;
    stack.push(make_pair(1, -1)); 
    while (!stack.empty()){
    	s = stack.top();
        stack.pop();        
    	u = s.first;
    	par = s.second;
    	if(u == -1){
			r[par] = ++cur; ID[cur] = par;
    		continue;
		}
    	stack.push(make_pair(-1, u));
    	
		l[u] = ++cur; 
		ID[cur] = u;
		for (i = 1; i < LN; i++) DP[i][u] = DP[i - 1][DP[i - 1][u]];
		for (i = 0; i < adjList[u].size(); i++){
			v = adjList[u][i];
			if (v == par) continue;
			LVL[v] = LVL[u] + 1;
			DP[0][v] = u;
			stack.push(make_pair(v, u));
		}
	}
}

inline int lca(int u, int v){
	if (LVL[u] > LVL[v]) swap(u, v);
	for (int i = LN - 1; i >= 0; i--)
		if (LVL[v] - (1 << i) >= LVL[u]) v = DP[i][v];
	if (u == v) return u;
	for (int i = LN - 1; i >= 0; i--){
		if (DP[i][u] != DP[i][v]){
			u = DP[i][u];
			v = DP[i][v];
		}
	}
	return DP[0][u];
}
 
inline void check(int x){
	if (VIS[x]){
		root = deleteNode(root, VAL[A[x]], A[x]);
		--VAL[A[x]];
		root = insert(root, VAL[A[x]], A[x]);
	}
	else if (!VIS[x]){
		root = deleteNode(root, VAL[A[x]], A[x]);
		VAL[A[x]]++;
		root = insert(root, VAL[A[x]], A[x]);
	}
	VIS[x] ^= 1;
}
 
void compute(){
	int curL = Q[0].l, curR = Q[0].l - 1, res = 0, u, v, k;
 
	for (int i = 0; i < M; i++){
 
		while (curL < Q[i].l) check(ID[curL++]);
		while (curL > Q[i].l) check(ID[--curL]);
		while (curR < Q[i].r) check(ID[++curR]);
		while (curR > Q[i].r) check(ID[curR--]);
 
		u = ID[curL];
		v = ID[curR];
		
		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc);

		k = k_largest(root, Q[i].k);
		ANS[Q[i].id] = IND[k];
 
		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc);
	}
 
	for (int i = 0; i < M; i++) printf("%ld\n", ANS[i]);
}
 
int main(){ 
	int u, v, x, k;
 
	scanf("%d %d", &N, &M);
	
	for (int i = 1; i <= N; i++) scanf("%ld", &A[i]);
	memcpy(d + 1, A + 1, sizeof(long) * N);

	sort(d + 1, d + N + 1);
	K = unique(d + 1, d + N + 1) - d - 1;
	for (int i = 1; i <= N; i++){
		u = lower_bound(d + 1, d + K + 1, A[i]) - d;
		IND[u] = A[i];
		A[i] = u;
	}
	for (int i = 1; i <= K; i++)
		root = insert(root, 0, i);	
	
	for (int i = 1; i < N; i++){
		scanf("%d %d", &u, &v);
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	
	DP[0][1] = 1;
	dfs();
	int size = sqrt(cur);

	for (int i = 1; i <= cur; i++) BL[i] = (i - 1) / size + 1;

	for (int i = 0; i < M; i++){
		scanf("%d %d %d", &u, &v, &k);
		Q[i].lc = lca(u, v);
		if (l[u] > l[v]) swap(u, v);
		if (Q[i].lc == u) Q[i].l = l[u], Q[i].r = l[v];
		else Q[i].l = r[u], Q[i].r = l[v];
		Q[i].id = i;
		Q[i].k = k;
	}

	sort(Q, Q + M);
	compute();
}
