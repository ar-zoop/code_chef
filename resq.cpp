#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int mini=INT_MAX;
		for (int i=1;i<=sqrt(n);i++){
			if(n%i==0){
				int breadth=n/i;
				mini=min(mini,abs(breadth-length));
			}
		}
		cout<<mini<<endl;
	}
}