#include <bits/stdc++.h>
using namespace std;

int memo[45];
int climb(int idx){
   
    if (idx==0)return 1;
    if (idx==1)return 1;
    int left,right;
    if(memo[idx]==-1){
        // printf("hi");
        left= climb(idx-1);
        right=climb(idx-2);
    }
    else{
        return memo[idx];
    }
    memo[idx]=left+right;
    return left+right;
}


    int main() {
        int n;
        cin>>n;
        memset(memo, -1, sizeof(memo));
        int res=climb(n);
        cout<<res;
        return 0;
    }
