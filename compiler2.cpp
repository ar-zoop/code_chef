# include <bits/stdc++.h>
using namespace std;
# define ll long long int

int main(){
	ll testcases;
	cin >> testcases;
	while(testcases--){
		string s;
		cin >> s;
		stack<char> st;
		ll ans = 0;
		for(ll i = 0; i < s.length(); i++){
			if(s[i] == '<')st.push(s[i]);
			else{
				if(st.empty()){
				 	break;
				}
				else{
					st.pop();
				}
				if(st.empty()){
					ans = i + 1;
				}
			}
		}
		cout << ans << "\n";
  	}
	return 0;
}