//Time complexity= O(n/2)
//Space complexity= O(26)

#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    getline(cin, str);
    int freq[26]={0};
    int len=str.length();
    int h=len/2;    
    for(int i=0 ;i<h;i++){
        if(isalpha(str[i]))
            freq[str[i]-97]++;
        if(isalpha(str[len-i-1]))
            freq[str[len-i-1]-97]++;        
    }
    //account for the middle element in case of odd length
    if(len%2!=0){
        freq[str[h]-97]++;
    }
    for(int i=0;i<26;i++){
        if(freq[i]>1){
            printf("%c ",i+97);
            cout<<freq[i]<<endl;
        }
        
    }
}