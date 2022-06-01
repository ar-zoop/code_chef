#include <bits/stdc++.h>
using namespace std;
int target;

int summation(set<int>s,int ele, int size){
    int left, right;
    for (itr = s.begin(); itr!=s.find(ele); itr++) {
        left=*itr;
    }
    itr++;
    right=*(++itr);

    if(left==s.end()&&right==s.end()){
        return ele+size-ele+1;
    }
    else if(left==s.end()){
        return ele+right-ele;
    }
    else if (right==s.end()){
        return ele-left+size-ele+1;
    }
    
    else{
        return ele-left + right- ele;
    }
}

bool f(int idx, int sum, vector <int> &ds, int arr[],int n, set<int>s){
    if(idx==n){
        if(sum==target){
            for(auto x: ds) cout<<x<<" ";
            cout<<endl;
            return true;
        }
        return false;
    }
    ds.push_back(arr[idx]);
    s.insert(arr[idx]);
    //sum calcs 
    sum=summation(s,arr[idx],n);
    if(f(idx+1, sum,ds,arr,n,s))return true;
        
   
    ds.pop_back();
    s.erase(arr[idx]);
   //sum calcs
   sum=summation(s,arr[idx],n);
    if(f(idx+1, sum, ds, arr,n,s))return true;
        

    return false;
}



int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int>ds;
        set<int>s;
        int n;
        cin>>n>>target;
        int arr[31];
        for(int i=0;i<n;i++){
            arr[i]=i;
        }
        if(f(0,0,ds,arr,n,s)) cout<<1;
        else cout<<0;
    }
 ;
    return 0;
}