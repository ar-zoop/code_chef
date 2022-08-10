vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector <int> res;
    vector <long long int> freq(A.size()+1, 0);
    for(long long int i=0;i<A.size();i++){
        freq[A[i]]++;
    }
    long long int a,b;
    for(long long int i=1;i<A.size()+1;i++){
        // cout<<freq[i];
        if(freq[i]>1){
            a=i;
        }
        if(freq[i]==0){
            b=i;
        }
    }
    res.push_back(a);
    res.push_back(b);
    return res;
}