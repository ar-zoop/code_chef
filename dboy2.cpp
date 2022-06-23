#include<bits/stdc++.h>
using namespace std;

void sub(int idx, int sum, int target, int nums[], int n, int count, vector<int>&count_vec){
    int left=INT_MAX, right=INT_MAX, mid=INT_MAX;
    //base cases
    if(target==sum){
        count_vec.push_back(count);
        count--;
        return;
    }
    // if (target>sum)return -1;
    // cout<<sum+nums[idx]<<endl;
    if((sum+nums[idx])<=target){
        sub(idx, sum+nums[idx],target, nums, n, count+1, count_vec);

        sub(idx+1, sum+nums[idx], target, nums, n, count+1, count_vec);

        sub(idx+1, sum, target, nums, n, count, count_vec);
    }
    count--;
    return;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a;
        
        cin>>n;
        int h[n],k[n];
        for(int i=0;i<n;i++){
            cin>>a;
            h[i]=2*a;
        }
        for(int i=0;i<n;i++){
            cin>>k[i];
        }
        sort(k,k+n);
        int count=0;
        for(int i=0;i<n;i++){
            vector<int> count_vec;
            
            sub(0, 0, h[i], k, n,0,count_vec);       

            vector<int>::iterator itr;
            sort(count_vec.begin(), count_vec.end());
            itr=count_vec.begin();
            count+=*itr;
            
            
        }
        cout<<count;
       
    }
    return 0;
}