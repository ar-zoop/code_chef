//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    int arr[26]={0};
		    queue<char> q;
		    string res="";
		    int len=A.length();
		    for(int i=0; i<len; i++){
		        if(arr[A[i]-'a']==0){
		            q.push(A[i]);
		        }
		        arr[A[i]-'a']++;
		        
		       while(!q.empty() && arr[q.front()-'a']>1){
		                q.pop();
		       }
		       if(q.empty()){
		            res+="#";
		        }
		        else{
	                res+=q.front();
		        }
		       
		    }
		    return res;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends