#include <bits/stdc++.h>
#define fi "CLIQUED.in"
#define fo "CLIQUED.out"
#define MAX 100000

using namespace std;

struct AdjListNode{
    long dest;
    long long weight;
    struct AdjListNode* next;
};

struct AdjList{
    struct AdjListNode *head;
};

struct Graph{
    long V;
    struct AdjList* array;
};

struct AdjListNode* newAdjListNode(long dest, long long weight){
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
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

void addEdge(struct Graph* graph, long src, long dest, long long weight){
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

struct MinHeapNode{
    long  v;
    long long dist;
};

struct MinHeap{
    long size;
    long capacity;
    long *pos;
    struct MinHeapNode **array;
};

struct MinHeapNode* newMinHeapNode(long v, long long dist){
    struct MinHeapNode* minHeapNode = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->dist = dist;
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
    if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
      smallest = left; 
    if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
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

int isEmpty(struct MinHeap* minHeap){
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

void decreaseKey(struct MinHeap* minHeap, long v, long long dist){
    long i = minHeap->pos[v];
    minHeap->array[i]->dist = dist;
    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist){
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

void dijkstra(struct Graph* graph, long src, long long dist[]){
    long V = graph->V;    
    struct MinHeap* minHeap = createMinHeap(V);
    for (long v = 0; v < V; ++v){
        dist[v] = LLONG_MAX;
        minHeap->array[v] = newMinHeapNode(v, dist[v]);
        minHeap->pos[v] = v;
    }
    minHeap->array[src] = newMinHeapNode(src, dist[src]);
    minHeap->pos[src]   = src;
    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);
    minHeap->size = V;
    while (!isEmpty(minHeap)){
        struct MinHeapNode* minHeapNode = extractMin(minHeap);
        long u = minHeapNode->v;
        struct AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl != NULL){
            long v = pCrawl->dest;
            if (isInMinHeap(minHeap, v) && dist[u] != LLONG_MAX && pCrawl->weight + dist[u] < dist[v]){
                dist[v] = dist[u] + pCrawl->weight;
                decreaseKey(minHeap, v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }
}

int main(){
    /*freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);*/
    // code here
    int t;
    long n, k, m, s, a, b, e;
    long long x, c;
    long long minw[MAX];
    set<int> old;
	struct Graph* graph;
    scanf("%d", &t);
    while(t--){
    	scanf("%ld %ld %lld %ld %ld", &n, &k, &x, &m, &s);
    	s--;
    	graph = createGraph(n);
    	old.clear();
    	for(long i = 0; i < m; i++){
    		scanf("%ld %ld %lld", &a, &b, &c);
    		a--; b--;
			addEdge(graph, a, b, c);
			addEdge(graph, b, a, c);
			//printf("%ld %ld %lld\n", a, b, c);
			if(a < k)
				old.insert(a);
			if(b < k)
				old.insert(b);
		}
		if(s < k)
			old.insert(s);
		/*if(s < k){
			for(set<int>::iterator it = old.begin(); it != old.end(); it++){
				addEdge(graph, *it, s, x);
				addEdge(graph, s, *it, x);
		    }
		}
		else{
			for(set<int>::iterator it = old.begin(); it != old.end(); it++){
		    	for(set<int>::iterator it2 = old.begin(); it2 != old.end(); it2++){
					addEdge(graph, *it, *it2, x);
					addEdge(graph, *it2, *it, x);
		    	}
		    }
		}*/
		memset(minw, 0, sizeof minw);
		dijkstra(graph, s, minw);
		c = LLONG_MAX;
    	for(long i = 0; i < k; i++){
    		if(c > minw[i]){
    			c = minw[i];
    			e = i;
    		}
    	}
		for(set<int>::iterator it = old.begin(); it != old.end(); it++){
			addEdge(graph, *it, e, x);
			addEdge(graph, e, *it, x);
	    }
		memset(minw, 0, sizeof minw);
		dijkstra(graph, s, minw);
		c = LLONG_MAX;
    	for(long i = 0; i < k; i++){
    		if(c > minw[i]){
    			c = minw[i];
    			e = i;
    		}
    	}
    	for(long i = 0; i < n; i++){
    		if((i < k) && (minw[i] > c + x))
    			minw[i] = c + x;
    		printf("%lld ", minw[i]);
    	}
    	printf("\n");
	}
    
	return 0;
}
