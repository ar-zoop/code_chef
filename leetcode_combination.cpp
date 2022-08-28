class Solution {
public:
    void sub(int idx, vector<int>& ds, int r, int n, vector<vector<int>> &res ){
        if(ds.size()==r){
            res.push_back(ds);
            return ;
        }
        if(idx>n) return;
        
        //take
        ds.push_back(idx);
        sub(idx+1, ds, r, n, res);
        //not take
        ds.pop_back();
        sub(idx+1, ds, r, n, res);
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> ds;
        sub(1,ds, k,n, res);
        return res;
    }
};