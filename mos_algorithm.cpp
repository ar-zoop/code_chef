#include <bits/stdc++.h>
using namespace std;

int rootN;

struct query_struct{
    int l;
    int r;
    int idx;
};

bool compare(query_struct A, query_struct B){
    if(A.l/rootN == B.l/rootN) {
        return A.r > B.r;
    }
    else return A.l < B.l;
}

int main(){
    //input number of elements in array and the array
    int n;
    cin>>n;
    vector <int> arr(n);
    for (int i=0; i<n;i++){
        cin>>arr[i];
    }
    rootN=sqrtl(n);

    //input number of queries and the lefts and rights of the queries
    int queries;
    cin>>queries;
    struct query_struct Q[queries];

    for(int i=0 ;i<queries;i++){
        int l, r;
        cin>>l>>r;
        Q[i].idx=i;
        Q[i].l=--l;
        Q[i].r=--r;
    }
    //Time to sort the array of queries
    sort(Q, Q+queries, compare);

    //Lets evaluate the queries
    vector <int> ans(queries);
    int curr_l=0, curr_r=-1, l , r, idx, sum=0;
    for(int i=0;i<queries;i++){
        l= Q[i].l;
        r=Q[i].r;
        idx=Q[i].idx;

        //case 1: curr_r < r || adding elements to 0 sum
        while(curr_r < r){
            curr_r++;
            sum+=arr[curr_r];            
        }
        
        //case 2: curr_l > l|| adding elements to sum 0
        while(curr_l > l){
            curr_l--;
            sum+=arr[curr_l];            
        }

        //case 3: curr_l < l
        
        while(curr_l < l){
            sum-=arr[curr_l];
            curr_l++;
            
            
        }
        //case 4: curr_r > r
        while(curr_r > r){
            sum-=arr[curr_r];
            curr_r--;
            
            
        }
        ans[idx]=sum;
    }

    for(int i=0 ;i<queries;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}