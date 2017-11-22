#include <bits/stdc++.h>
#define MX 1000
#define MAXV 2000000
 
using namespace std;
long C[MX][MX];
long H[MX][MX];
long parent[MX];
long key[MX];
long cnt[MX];
struct Graph* graph;
 
struct Node{
    long dest;
    long weight;
    struct Node* next;
};
 
struct AdjList{
    struct Node *head;
};
 
struct Graph{
    long V;
    struct AdjList* array;
};
 
struct Node* createAdjList(long dest, long weight){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}
 
struct Graph* createGraph(long V){
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
    for (long i = 0; i < V; ++i)
        graph->array[i].head = NULL; 
    return graph;
}
 
void addEdge(struct Graph* graph, long src, long dest, long weight){
    struct Node* newNode = createAdjList(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    
    newNode = createAdjList(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}
 
struct MinHeapNode{
    long  v;
    long key;
};
 
struct MinHeap{
    long size;
    long capacity;
    long *pos;
    struct MinHeapNode **array;
};
 
struct MinHeapNode* newMinHeapNode(long v, long key){
    struct MinHeapNode* minHeapNode = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->key = key;
    return minHeapNode;
}
 
struct MinHeap* createMinHeap(long capacity){
    struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->pos = (long*)malloc(capacity * sizeof(long));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**) malloc(capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}
 
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b){
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}
 
void minHeapify(struct MinHeap* minHeap, long idx){
    long smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2; 
    
    if (left < minHeap->size && minHeap->array[left]->key < minHeap->array[smallest]->key )
      smallest = left;
	   
    if (right < minHeap->size && minHeap->array[right]->key < minHeap->array[smallest]->key )
      smallest = right;
 
    if (smallest != idx){
        MinHeapNode *smallestNode = minHeap->array[smallest];
        MinHeapNode *idxNode = minHeap->array[idx];
        
        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;
        
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
 
        minHeapify(minHeap, smallest);
    }
}
 
bool isEmpty(struct MinHeap* minHeap){
    return minHeap->size == 0;
}
 
struct MinHeapNode* extractMin(struct MinHeap* minHeap){
    if (isEmpty(minHeap))
        return NULL;
        
    struct MinHeapNode* root = minHeap->array[0];
    
    struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;
    
    minHeap->pos[root->v] = minHeap->size-1;
    minHeap->pos[lastNode->v] = 0;
    
    --minHeap->size;
    minHeapify(minHeap, 0);
 
    return root;
}
 
void decreaseKey(struct MinHeap* minHeap, long v, long key){
    long i = minHeap->pos[v];
    
    minHeap->array[i]->key = key;
    
    while (i && minHeap->array[i]->key < minHeap->array[(i - 1) / 2]->key){
        minHeap->pos[minHeap->array[i]->v] = (i-1)/2;
        minHeap->pos[minHeap->array[(i-1)/2]->v] = i;
        swapMinHeapNode(&minHeap->array[i],  &minHeap->array[(i - 1) / 2]);
        
        i = (i - 1) / 2;
    }
}
 
bool isInMinHeap(struct MinHeap *minHeap, long v){
   if (minHeap->pos[v] < minHeap->size)
     return true;
   return false;
}
 
void PrimMST(struct Graph* graph){
    long v, u, V = graph->V;    
    struct MinHeap* minHeap = createMinHeap(V);
    struct MinHeapNode* minHeapNode;
    struct Node* pCrawl;
    for (long v = 0; v < V; ++v){
    	cnt[v] = 0;
        parent[v] = -1;
        key[v] = MAXV + H[v][1] + 1;
        minHeap->array[v] = newMinHeapNode(v, LONG_MAX);
        minHeap->pos[v] = v;
    }
    for (long v = 0; v < V; ++v)
    	decreaseKey(minHeap, v, key[v]);
    minHeap->size = V;    
    while (!isEmpty(minHeap)){
        minHeapNode = extractMin(minHeap);
        u = minHeapNode->v;
        cnt[u]++;
        pCrawl = graph->array[u].head;
        while (pCrawl != NULL){
            v = pCrawl->dest;
            if (isInMinHeap(minHeap, v) && pCrawl->weight + H[v][1] + H[u][cnt[u] + 1] < key[v]){
                key[v] = pCrawl->weight + H[v][1] + H[u][cnt[u] + 1];
                parent[v] = u;
                decreaseKey(minHeap, v, key[v]);
            }
            pCrawl = pCrawl->next;
        }
        
        u = parent[minHeapNode->v];
        if(u != -1){
	        cnt[u]++;
	        pCrawl = graph->array[u].head;
	        while (pCrawl != NULL){
	            v = pCrawl->dest;
	            if (isInMinHeap(minHeap, v) && pCrawl->weight + H[v][1] + H[u][cnt[u] + 1] < key[v]){
	                key[v] = pCrawl->weight + H[v][1] + H[u][cnt[u] + 1];
	                parent[v] = u;
	                decreaseKey(minHeap, v, key[v]);
	            }
	            pCrawl = pCrawl->next;
	        }
	    }
    }
}
 
unsigned long long s[2];
unsigned long long xorshift128plus() {
	unsigned long long x = s[0];
	const unsigned long long y = s[1];
	x ^= x << 23;
	s[1] = x ^ y ^ (x >> 17) ^ (y >> 26);
	return s[0] = y;
}
 
int main(){
	int t, n;	
	long Cmax, Hmax;
	scanf("%d", &t);
	while(t--){
		scanf("%d %ld %ld", &n, &Cmax, &Hmax);
		graph = createGraph(n);
		for(int i = 0; i < n; i++){
			C[i][i] = 0;
			scanf("%llu %llu", &s[0], &s[1]);
			for (int j = i + 1; j < n; j++){
				C[i][j] = C[j][i] = xorshift128plus() % (Cmax + 1);
				addEdge(graph, i, j, C[i][j]);
				addEdge(graph, j, i, C[j][i]);
			}
		}
		for(int i = 0; i < n; i++){
			scanf("%llu %llu", &s[0], &s[1]);
			for(int j = 0; j < n; j++)
				H[i][j] = xorshift128plus() % (Hmax + 1);
		}
		PrimMST(graph);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				printf("%d", (i != j && (parent[i] == j || parent[j] == i)) ? 1 : 0);
			printf("\n");
		}
	}	
	return 0;
}
