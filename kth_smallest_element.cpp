//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        return(count_sort(arr,r+1,k-1));
    }
    int count_sort(int input_arr[], int size, int pos){
        int count_arr[100001]={0};
        for(int i=0; i<size;i++){
            count_arr[input_arr[i]]++;
        }
        for(int i=1;i<100001;i++){
            count_arr[i]+=count_arr[i-1];
        }
        int output_arr[count_arr[100000]]={0};
        for(int i=0;i<size;i++){
            output_arr[--count_arr[input_arr[i]]]=input_arr[i];
        }
        return output_arr[pos];
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends