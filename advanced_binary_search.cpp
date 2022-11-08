#include <bits/stdc++.h>
using  namespace std;
/*
BINARY SEARCH 

int main(){
    int n, k;
    cin>>n>>k;
    vector <int> arr(n);
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    int ele;
    while(k--){
        cin>>ele;
        int start=0, end=n;
        int mid;
        int flag=0;
        while(start<=end){
            mid=(start+end)/2;
            if(arr[mid]==ele){
                cout<<"YES"<<endl;
                flag=1;
                break;
            }
            else if(arr[mid]<ele){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        if(flag==0) cout<<"NO"<<endl;
    }
    return 0;
} 
*/

/*
CLOSEST TO LEFT ELEMENT
int left_bin_search(int q, int arr[], int n)
{
    int left = -1, right = n, mid;

    while ((left+1) < right)
    {
        mid = (left + right) / 2;
        
        
        if (arr[mid] <= q)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
     return left+1;
}

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    long long int q;
    while(k--){
        cin>>q;
        cout << left_bin_search(q, arr, n)<<endl;
    }
    return 0;
}
*/

/*
//CLOSEST TO RIGHT ELEMENT
int right_bin_search(int q, int arr[], int n)
{
    int left = -1, right = n, mid;

    while ((left + 1) < right)
    {
        mid = (left + right) / 2;

        if (arr[mid] < q)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    return right + 1;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long int q;
    while (k--)
    {
        cin >> q;
        cout << right_bin_search(q, arr, n) << endl;
    }
    return 0;
}
*/

//FAST QUERIES

int main(){
    
    return 0;
}