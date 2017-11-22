#include <bits/stdc++.h>
#define MAX 10000000

using namespace std;
long level[MAX];
long r[MAX];

long circularWalk(long n, long s, long t, long r_0, long g, long seed, long p){
    if(s == t)
        return 0;
    r[0] = r_0;
    long i;
    for(i = 1; i < n; i++)
        r[i] = ((long long) r[i - 1] * g + seed) % p;
    long c, right = 0, left = 0, dright, dleft;
    list<long> queue;
    queue.push_back(s);
    level[s] = 0;
    while(!queue.empty()){
        c = queue.front();
        if(c == t)
            break;
        queue.pop_front();
        dright = c - s;
        if(dright > right)
        	dright -= n;
        else if(n + dright <= right)
        	dright += n;
        for(i = right + 1; (i <= dright + r[c]) && (i + left < n); i++){
            level[(s + i) % n] = level[c] + 1;
            queue.push_back((s + i) % n);
        }
        right = i - 1;
        dleft = s - c;
        if(dleft > left)
        	dleft -= n;
        else if(n + dleft <= left)
        	dleft += n;
        for(i = left + 1; (i <= dleft + r[c]) && (i + right < n); i++){
            level[(n + s - i) % n] = level[c] + 1;
            queue.push_back((n + s - i) % n);
        }
        left = i - 1;
    }
    if(queue.empty())
        return -1;
    return level[t];
}

int main() {
    long n, s, t;
    scanf("%ld %ld %ld", &n, &s, &t);
    long r_0, g, seed, p;
    scanf("%ld %ld %ld %ld", &r_0, &g, &seed, &p);
    printf("%ld", circularWalk(n, s, t, r_0, g, seed, p));
    return 0;
}
