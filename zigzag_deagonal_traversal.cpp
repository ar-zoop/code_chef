#include <bits/stdc++.h>
using namespace std;

vector <int> upper_half(vector<vector<int>>& mat) {
    vector <int> res;
    for(int i=0; i<mat.size(); i++){
        int s=i;
        for(int j=0; j<=i; j++){
            res.push_back(mat[s][j]);
            s--;
        }
    }
    return res;    
}

vector <int> lower_half(vector<vector<int>>& mat) {
    vector <int> res;
    for(int i=1; i<mat.size(); i++){
        int s=i;
        for(int j=mat.size()-1; j>=i; j--){
            res.push_back(mat[j][s]);
            s++;
        }
    }
    return res;    
}

int main(){
    vector<int> res, temp;
    vector<vector<int>> a={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    res= upper_half(a);
    temp=lower_half(a);
    for(int i=0 ;i <temp.size(); i++){
        res.push_back(temp[i]);
    }
    for(int i=0 ;i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    return 0;

}