//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int maxHistogram(int arr[], int n){

        // Your code here
        int ps[n], ns[n];
        stack<int> sorted;
        
        //for ps
        for(int i=0; i<n ;i++){
            if(sorted.empty()){
                ps[i]=-1;
                sorted.push(i);
            }
            else if(arr[i]>arr[sorted.top()]){
                ps[i]=sorted.top();
                sorted.push(i);
            }
            else{
                while(!sorted.empty() && arr[i]<=arr[sorted.top()]){
                    sorted.pop();
                }
                if(sorted.empty()){
                    ps[i]=-1;
                    sorted.push(i);
                }
                else if(arr[i]>arr[sorted.top()]){
                    ps[i]=sorted.top();
                    sorted.push(i);
                }
            }
        }
        while(!sorted.empty()){
            sorted.pop();
        }
        
        //for ns
         for(int i=n-1; i>=0 ;i--){
            if(sorted.empty()){
                ns[i]=n;
                sorted.push(i);
            }
            else if(arr[i]>arr[sorted.top()]){
                ns[i]=sorted.top();
                sorted.push(i);
            }
            else{
                while(!sorted.empty() && arr[i]<=arr[sorted.top()]){
                    sorted.pop();
                }
                if(sorted.empty()){
                    ns[i]=n;
                    sorted.push(i);
                }
                else if(arr[i]>arr[sorted.top()]){
                    ns[i]=sorted.top();
                    sorted.push(i);
                }
            }
        }
        int cur=0, max=INT_MIN;
        for(int i=0; i<n ;i++){
            cur=(ns[i]-ps[i]-1)*arr[i];
            if(cur>max){
                max=cur;
            }
        }
        
        return max;
    }

    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int cur_row[m], cur=0, max=0;
        for(int j=0; j<m; j++){
            cur_row[j]=M[0][j];
            // cout<<cur_row[j]<<" ";
        }
        max= maxHistogram(cur_row, m);
        // cout<<max<<endl;
        for(int i=1; i<n; i++){
            // cout<<"printing cur_row= ";
            for(int j=0; j<m; j++){
                if(M[i][j]==0){
                    cur_row[j]=0;
                }
                else{
                    cur_row[j]++;
                }
                // cout<<cur_row[j]<<" ";
            }
            cur=maxHistogram(cur_row, m);
            // cout<<endl<<"cur= "<<cur<<endl;
            if(cur>max) max=cur;
        }
        return max;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends