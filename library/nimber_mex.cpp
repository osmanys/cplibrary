int mex(vector<int> nimbers){
    int s = -1;
    for(set<int>::iterator i=nimbers.begin();i!=sets.end();i++){
        if(*i-s>1)
            break;
        s=*i;
    }
    return s+1;
}