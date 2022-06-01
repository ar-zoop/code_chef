#include <bits/stdc++.h>
using namespace std;


//fibonacci
int f(int n){
    if(n<=1)return n;
    return f(n-1)+f(n-2);
}


int arr[3]={1,2,1};
int n=3;
//subsequence printing
void sub(vector<int>&v ,int idx){
    if(idx>=n) {
        for (auto x: v) cout<<x<<" ";
        cout<<endl;
        return;
    }
    v.push_back(arr[idx]);
    sub(v, idx+1);
    v.pop_back();
    sub(v,idx+1);
}

//all subsequence printing with sum=3
void sub2(vector<int>&v ,int idx,int sum){
    if(idx>=n) {
        if(sum==3) {
            for(auto x: v) cout<<x<<" ";
             cout<<endl;
           
        }
       
        return;
    }
    v.push_back(arr[idx]);
    sum+=arr[idx];
    sub2(v, idx+1,sum);
    v.pop_back();
    sum-=arr[idx];
    sub2(v,idx+1,sum);
}

// only 1 subsequence printing with sum=3
bool sub3(){
    
    return false;
}

int main(){
    // int res=f(4);
    // cout<<res;
    vector <int> v;
    // sub(v,0);
    sub2(v,0,0);
    return 0;
}