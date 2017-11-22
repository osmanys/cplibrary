#include <bits/stdc++.h>
#define MAX 100001
 
using namespace std;

struct teacher{
	long d;
	long i;
	long s;
};
teacher ts[MAX];
long teach[MAX];

void swap(teacher *x, teacher *y);

class Heap{
    teacher *harr;
    long capacity;
    long heap_size;
public:
    Heap(long capacity);
    void Heapify(long );
    long parent(long i) { return (i - 1) / 2; }
    long left(long i) { return (2 * i + 1); }
    long right(long i) { return (2 * i + 2); }
    long size() { return heap_size; }
    teacher extract();
    teacher get() { return harr[0]; }
    void insertKey(teacher k);
};

Heap::Heap(long cap){
    heap_size = 0;
    capacity = cap;
    harr = new teacher[cap];
}

void Heap::insertKey(teacher k){
    heap_size++;
    long i = heap_size - 1;
    harr[i] = k;    
    while (i != 0 && harr[parent(i)].s < harr[i].s){
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}

teacher Heap::extract(){
    if (heap_size == 1){
        heap_size--;
        return harr[0];
    }
    teacher root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    Heapify(0); 
    return root;
}

void Heap::Heapify(long i){
    long l = left(i);
    long r = right(i);
    long greater = i;
    if (l < heap_size && harr[l].s > harr[i].s)
        greater = l;
    if (r < heap_size && harr[r].s > harr[greater].s)
        greater = r;
    if (greater != i){
        swap(&harr[i], &harr[greater]);
        Heapify(greater);
    }
}

void swap(teacher *x, teacher *y){
    teacher temp = *x;
    *x = *y;
    *y = temp;
}

bool dcomparer(teacher a, teacher b){ return a.d < b.d; }

int main() {
	int t;
	long n, d, diff;
	teacher m;
	long long r;
	Heap h(MAX);
	scanf("%d", &t);
	while(t--){
		scanf("%ld %ld", &n, &d);
		for(long i = 0; i < n; i++){
			scanf("%ld %ld %ld", &ts[i].d, &teach[i], &ts[i].s);
			ts[i].i = i;
		}
		sort(ts, ts + n, dcomparer);
		for(long i = 0; i < n; i++){
			h.insertKey(ts[i]);
			while(i + 1 < n && ts[i + 1].d == ts[i].d){
				i++;
				h.insertKey(ts[i]);
			}
			if(i + 1 < n)
				diff = ts[i + 1].d - ts[i].d;
			else
				diff = d + 1 - ts[i].d;
			while(diff){
				if(!h.size())
					break;
				m = h.get();
				if(teach[m.i] <= diff){
					diff -= teach[m.i];
					h.extract();
				}
				else{
					teach[m.i] -= diff;
					diff = 0;
				}
			}
		}
		r = 0;
		while(h.size()){
			m = h.extract();
			r += 1LL * teach[m.i] * m.s;
		}
		cout << r << "\n";
	}
    return 0;
}
