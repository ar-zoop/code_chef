#include <bits/stdc++.h>
using namespace std;

long long int min_sub(int idx, vector<int> &pos, long long int nums[], int n){
    int right=INT_MAX;
    //base cases
    // cout<<"l= "<<l<<" k= "<<k<<endl;
    if(idx>n-1){
        return 0;
    }
    //continue the subsequence
    pos.push_back(nums[idx]);
    int left=min_sub(idx+1,pos,nums,n)+nums[idx];
    pos.pop_back();
    //make new subsequence
    if(idx<n){
        pos.clear();
        right=min_sub(idx+1, pos,nums,n)+0;
    }
    //return best
    return min(left,right);

}

int main(){
    int t;
    cin>>t;
    while(t--){
        vector <int> pos;
        int n;
        cin>>n;
        long long int arr[n];
        for (int i=0;i<n;i++){
            cin>>arr[i];
        }
        long long int min=min_sub(0,pos,arr,n);
        cout<<min;
        vector<int>::iterator itr;
        for(itr=pos.begin();itr!=pos.end();itr++){
            cout<<*itr<<" ";
        }
    }
    return 0;
}