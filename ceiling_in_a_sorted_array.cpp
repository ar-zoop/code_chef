#include <bits/stdc++.h>
using  namespace std;

void search(){
    int arr[]={1, 2, 8, 10, 10, 12, 19};
    int ele=13, low=0, high=7, mid;
    if(ele<arr[0]){
        cout<<"floor= Non existent"<<endl;
        cout<<"ceil= "<<arr[0]<<endl;
        return;
    }
    else if(ele>arr[high-1]){
        cout<<"floor= "<<arr[high-1]<<endl;
        cout<<"ceil= Non existent"<<endl;
        return;
    }
    else{
        while(low<high && (high-low)>1){
            mid=(low+high)/2;
            if(ele==arr[mid]){
                cout<<"floor= "<<ele<<endl;
                cout<<"ceil= "<<ele<<endl;
                return;
            }
            else if(arr[mid]<ele){
                low=mid;
            }
            else{
                high=mid;
            }
        }
        cout<<"floor= "<<arr[low]<<endl;
        cout<<"ceil= "<<arr[high]<<endl;
        return;
    }
}
int main(){
    search();
    return 0;
} 