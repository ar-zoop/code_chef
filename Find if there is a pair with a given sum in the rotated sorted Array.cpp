#include <bits/stdc++.h>
using namespace std;

bool sub(int ele, int arr[], int n){
    int low=0, high= n-1;
    if(arr[0]<arr[n-1]){
        int mid;
        while(low<=high){
            if(arr[mid]==ele) return true;
            else if(arr[mid]>ele){
                low=mid-1;
            }
            else high=mid+1;
        }
    }
    else{
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==ele) return true;
            if(arr[0]<arr[mid]){
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
    }
    return false;
}

int main() {
	int arr[] = {11, 15, 26, 38, 9, 10}, X = 35;
	int n=sizeof(arr)/sizeof(int);
	int flag=0;
	for(int i=0;i<n;i++){
	    int ele=X-arr[i];
	    if(ele<0) continue;
	    
	    else if(sub(ele, arr, n)){
	        cout<<"true";
	        flag=1;
	        break;
	    }
	    else continue;
	}
	if(flag==0) cout<<"false";
	return 0;
}