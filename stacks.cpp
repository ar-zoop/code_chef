#include <bits/stdc++.h>
using namespace std;


int placeEle(int size,int x, vector <int> &a){
    int l=0, h=size-1, ans=size;
    while(l<=h){
        int mid = (l+h)/2;
        if(a[mid]>x){
            ans = mid;
            h=mid-1;
        } else {
            l=mid+1;
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int  n;
        cin>>n;
        int testCase[n];
        for (int i=0;i<n;i++){
            cin>>testCase[i];
        }
        vector <int> res;
        for (int i=0;i<n;i++){
            // sort(res.begin(), res.end());
            int pos=placeEle(res.size(),testCase[i],res);
            if (pos>=res.size()){
                res.push_back(testCase[i]);
            }
            else{
                res[pos]=testCase[i];            
            }
        }
        vector <int> :: iterator itr;
        cout<<res.size()<<" ";
        for (itr=res.begin();itr!=res.end();itr++){
            cout<<*itr<<" ";
        }
        cout<<endl;
    }
    return 0;
}