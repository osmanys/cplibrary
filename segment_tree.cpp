
long *st;
long *stpos;

long getMid(long s, long e) {  return s + (e - s) / 2;  }

long updateST(long *st, long *stpos, long ss, long se, long index, long val, long si){
    if (index < ss || index > se)
        return st[si];
	if (ss == se){
        st[si] = val;
        stpos[si] = ss;
        return val;
    }
	long mid = getMid(ss, se);
	long rm1 = updateST(st, stpos, ss, mid, index, val, 2 * si + 1);
	long rm2 = updateST(st, stpos, mid + 1, se, index, val, 2 * si + 2);	
    if(rm1 < rm2){
    	st[si] = rm1;
    	stpos[si] = stpos[si * 2 + 1];
	}
	else{
    	st[si] = rm2;
    	stpos[si] = stpos[si * 2 + 2];
	}
    return st[si];
}

long RMQ(long *st, long *stpos, long qs, long qe, long ss, long se, long index, long &rindex){
	rindex = stpos[index];
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return LONG_MAX;
    long mid = getMid(ss, se);
    long rindex1, rindex2;
    long rm1 = RMQ(st, stpos, qs, qe, ss, mid, 2 * index + 1, rindex1);
    long rm2 = RMQ(st, stpos, qs, qe, mid + 1, se, 2 * index + 2, rindex2);
    if(rm1 < rm2){
    	rindex = rindex1;
    	return rm1;
	}
	else{
    	rindex = rindex2;
		return rm2;
	}
}

long constructSTUtil(long *st, long *stpos, long arr[], long ss, long se, long si){
    if (ss == se){
        st[si] = arr[ss];
        stpos[si] = ss;
        return arr[ss];
    }
    long mid = getMid(ss, se);
    long rm1 = constructSTUtil(st, stpos, arr, ss, mid, si * 2 + 1);
    long rm2 = constructSTUtil(st, stpos, arr, mid+1, se, si * 2 + 2);
    if(rm1 < rm2){
    	st[si] = rm1;
    	stpos[si] = stpos[si * 2 + 1];
	}
	else{
    	st[si] = rm2;
    	stpos[si] = stpos[si * 2 + 2];
	}
    return st[si];
}

pair<long*, long*>  constructST(long arr[], long n){
    long x = (int)(ceil(log2(n))); 
    long max_size = 2 * (long)pow(2, x) - 1; 
    long *st = new long[max_size]; 
    long *stpos = new long[max_size]; 
    constructSTUtil(st, stpos, arr, 0, n - 1, 0);
    return make_pair(st, stpos);
}
