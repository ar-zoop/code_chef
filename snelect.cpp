#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int n=str.length();
        int m=0;
        for (int i=0;i<str.length();i++){
            if (str[i]=='m'){
                m++;
                if(str[i-1]=='s' && (i-1)>=0){
                    str[i-1]='x';
                    n--;
                }
                else if(str[i+1]=='s' && (i+1)<str.length()){
                    str[i+1]='x';
                    n--;
                }
            }
        }
        if((n-m)>m){
            cout<<"snakes\n";
        }
        else if((n-m)<m){
            cout<<"mongooses\n";
        }
        else if((n-m)==m){
            cout<<"tie\n";
        }
    }
	return 0;
}
