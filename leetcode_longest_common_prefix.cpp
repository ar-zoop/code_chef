#include <bits/stdc++.h>
using namespace std;
vector<string> strs={"flower","flow","flight"};
string longestCommonPrefix() {
   
    string s="";
    char a= strs[0][0];
    int flag=0;
    for(int i=0 ; i< strs.size() ; i++){
        // cout<<"pass1";
        int j=0;
        while(j<3){
            // cout<<"pass2";
            if(a==strs[i][j] && i==strs.size()-1){
                s+=a;
                j++;
            }
            else if(a==strs[i][j] ){
                j++;
                continue;
            }
            else{
                flag=1;
                break;
            }
        }
        if (flag==1) break;
    }
    return s;
}

int main(){
    // Solution obj1;
    string s;
    s=longestCommonPrefix();
    cout<<s;

}