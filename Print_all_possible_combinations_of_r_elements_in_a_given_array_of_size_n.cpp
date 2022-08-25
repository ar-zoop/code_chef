    #include <bits/stdc++.h>
    using namespace std;

    void sub(int idx, vector<int> ds, int r, int arr[], int n){
        if(ds.size()==r){
            vector<int>::iterator itr;
            for(itr=ds.begin(); itr!=ds.end();itr++){
                cout<<*itr;
            }
            cout<<endl;
            return;
        }
        
        if(idx==n) return;
        
        //take
        ds.push_back(arr[idx]);
        sub(idx+1, ds, r, arr, n);
        ds.pop_back();
        sub(idx+1, ds, r, arr, n);
    }

    int main(){
        int arr[] = {1, 2, 3, 4, 5};
        int r = 3;
        int n = sizeof(arr)/sizeof(arr[0]);
        vector<int> ds;
        sub(0,ds, r, arr, n);
        return 0;
    }