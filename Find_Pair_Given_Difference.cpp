bool findPair(int arr[], int size, int n){
    //code
    map<int,int> freq;
    for(int i=0; i<size ;i++){
        freq[arr[i]]++;
    }
    int temp;
    for(auto &x: freq){
        if(n==0 && x.second > 1) return true;
        if(freq.find(temp=abs(n-x.first))!=freq.end() && x.first!=(x.first-n)){
            // cout<<x.first<< " "<<temp<<endl;
            return true;
        }
    }
    return false;
}