#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        char str[1000];
        int count[26]={0};
        cin>>str;
        for (int i=0;i<strlen(str)/2;i++){           
            count[((int)str[i])-97]++;
            count[((int)str[strlen(str)-i-1])-97]--;
        }
        int flag=0;
        for (int i=0;i<26;i++){
            if (count[i]!=0){
                flag=1;
                printf("NO\n");
                break;
            }

        }
        if (flag==0)printf("YES\n");
    }
    return 0;
}