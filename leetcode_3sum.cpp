void Print_Vector(vector<int> Vec)
{
    for (int i = 0; i < Vec.size(); i++) {
        cout << Vec[i] << " ";
    }
    cout << endl;
    return;
}

void sub(int idx, vector <int> &v, int sum, vector<int> arr, int n, int target,vector<vector<int>>& vt){
    //base cases
    if(v.size()==3){
        if (sum==target){
            vt.pAush_back(v);            
            return;
        }
        return;
    }   
    if(idx==n)return;
     //take
    v.push_back(arr[idx]);
    sub(idx+1, v, sum+arr[idx],arr, n, target, vt);
    v.pop_back();

    //not take
    sub(idx+1, v, sum, arr,  n, target, vt);

}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector <int> v;
        vector<vector<int>>vt;
        set<vector<int>> temp_res;        
        
        sub(0,v,0 ,nums,nums.size(),0,vt);
        v.clear();
        vector<vector<int>>::iterator itr;
        vector<int>::iterator ivr;
        for (itr=vt.begin();itr!=vt.end();itr++){            
            v=(*itr);
            sort(v.begin(),v.end());
            temp_res.insert(v);
        }
        vt.clear();
        set<vector<int>>::iterator isr;
        for(isr=temp_res.begin();isr!=temp_res.end();isr++){
            vt.push_back(*isr);
        }
        // st.clear();
        return vt;
        // v.clear();
    }
    
    
};