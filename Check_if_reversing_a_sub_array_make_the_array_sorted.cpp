#include <bits/stdc++.h>
using  namespace std;
bool sorted(){
    vector<int> arr={1, 2, 5, 3,4, 1, 2};
    int n=7;
    int start=-1, end=-1;
    for(int i=0; i<n-1; i++){
        if(arr[i+1]<arr[i]){
            // cout<<"hello";
            if(start==-1) start=i;
            else end=i;
        }
        else if(arr[i+1]>arr[i] && start!=-1){
            cout<<"i="<<i<<endl;
            break;
        }
    }
    if(end==-1) end=start;
    end+=2;
    cout<<"start = "<<start<<endl<<"end= "<<end<<endl;
    sort(arr.begin()+start, arr.begin()+end);
   
    for(int i=0; i<n-1; i++){
        
        if(arr[i+1]<arr[i]){
            return false;
        }
    }
    return true;
} 

int main(){
    if(sorted()) cout<<"Yes";
    else cout<<"No";

    //Time complexity: O(nlogn)
    //Space complexity: O(1)
    return 0;
}