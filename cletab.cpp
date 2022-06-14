#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        map <int, int> mpp;
        map<int,int>::iterator itr;
        int n,m;
        cin>>n>>m;
        int arr[400], e_counter=0,count=0;
        for(int i=0;i<m;i++){
            cin>>arr[i];
        }
        for (int i=0;i<n;i++){
            if(!mpp.find(arr[i])){
                mpp[arr[i]]=1;
                count++;
            }
        }
    }
    return 0;
}