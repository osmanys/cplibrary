#include <bits/stdc++.h>

using namespace std;

void swap(long *x, long *y);
 
class MinHeap{
    long *harr;
    long capacity;
public:
    long heap_size;
    MinHeap(long capacity);
    MinHeap();
    
    void MinHeapify(long );
 
    long parent(long i) { return (i - 1) / 2; }
    
    long left(long i) { return (2 * i + 1); }
    
    long right(long i) { return (2 * i + 2); }
    
    long extractMin();
    
    void decreaseKey(long i, long new_val);
    
    long getMin() { return harr[0]; }
    
    void deleteKey(long i);
    
    void insertKey(long k);
};

MinHeap::MinHeap(long cap){
    heap_size = 0;
    capacity = cap;
    harr = new long[cap];
}

MinHeap::MinHeap(){
	MinHeap(1000);
}

void MinHeap::insertKey(long k){
    if (heap_size == capacity){
    	long *temp = new long[capacity * 100];
    	for(long i = 0; i < heap_size; i++)
    		temp[i] = harr[i];
    	harr = temp;
    	capacity *= 100;
    }
    
    heap_size++;
    long i = heap_size - 1;
    harr[i] = k;
    
    while (i != 0 && harr[parent(i)] > harr[i]){
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}

void MinHeap::decreaseKey(long i, long new_val){
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]){
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}

long MinHeap::extractMin(){
    if (heap_size <= 0)
        return LONG_MAX;
    if (heap_size == 1){
        heap_size--;
        return harr[0];
    }
    
    long root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
 
    return root;
}

void MinHeap::deleteKey(long i){
    decreaseKey(i, LONG_MIN);
    extractMin();
}

void MinHeap::MinHeapify(long i){
    long l = left(i);
    long r = right(i);
    long smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i){
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

void swap(long *x, long *y){
    long temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
	long t, d;
	string cmd, param1, param2;
	map<string, MinHeap> data;
	cin >> t;
	while(t--){
		cin >> cmd;
		if(cmd == "crt"){
			cin >> param1;
			if(data.find(param1) == data.end()){
				printf("+ %s\n", param1.c_str());
				MinHeap m(1000);
				m.insertKey(1);
				data.insert(pair<string, MinHeap>(param1, m));
			}
			else{
				d = data[param1].extractMin();
				if(d)
					printf("+ %s(%ld)\n", param1.c_str(), d);
				else
					printf("+ %s\n", param1.c_str());
				if(!data[param1].heap_size)
					data[param1].insertKey(d + 1);
			}
		}
		else if(cmd == "del"){
			cin >> param1;
			if(param1[param1.size() - 1] == ')')
				data[param1.substr(0, param1.size() - 3)].insertKey(param1[param1.size() - 2] - '0');
			else
				data[param1].insertKey(0);
			printf("- %s\n", param1.c_str());
		}
		else if(cmd == "rnm"){
			cin >> param1 >> param2;
			if(param1[param1.size() - 1] == ')')
				data[param1.substr(0, param1.size() - 3)].insertKey(param1[param1.size() - 2] - '0');
			else
				data[param1].insertKey(0);
			if(data.find(param2) == data.end()){
				printf("r %s -> %s\n", param1.c_str(), param2.c_str());
				MinHeap m;
				m.insertKey(1);
				data.insert(pair<string, MinHeap>(param2, m));
			}
			else{
				d = data[param2].extractMin();
				if(d)
					printf("r %s -> %s(%ld)\n", param1.c_str(), param2.c_str(), d);
				else
					printf("r %s -> %s\n", param1.c_str(), param2.c_str());
				if(!data[param2].heap_size)
					data[param2].insertKey(d + 1);
			}			
		}
	}
	
	return 0;
}
