#include <bits/stdc++.h>
using namespace std;
#define INT_MIN 
int take=0,not_take=0;
int recur(int idx, int w){
    //base cases
    if(idx==0){
        if(wt[idx]<=w){
            return val[0];
        }
        else return 0;
    }
    //exploring all possibilities
    //not take
    not_take= 0 +recur(idx-1, w);
    //take
    take=INT_MIN;
    if(wt[idx]<=w){
        take=val[idx]+recur(idx-1, w-wt[idx]);
    }

    // returning the max of the possibilities
    return max(not_take, take);
}

int main(){

    for (int i=0;i<n;i++){
        recur(idx,n-1);
    }
    return 0;
}