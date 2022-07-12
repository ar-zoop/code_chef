#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    int c[m];
        int chairs[n]={0};
	    map<int,int>map_c;
	    for(int i=0;i<m;i++){
	        cin>>c[i];
	        if(map_c.find(c[i])!=map_c.end()){
	            map_c[c[i]]++;
	        }
	        else{
	            map_c[c[i]]=1;
	        }
	    }
        int count=0;
        for(int i=0;i<m;i++){
            int mini=INT_MAX,j,ele;
            for(j=0;j<n;j++){                
                if(mini>map_c[chairs[j]]){
                    mini=map_c[chairs[j]];
                    ele=j;
                }
            }
            chairs[j]=c[i];
            map_c[c[i]]--;
            count++;     
        }
        cout<<count<<endl;
	}
	return 0;
}
