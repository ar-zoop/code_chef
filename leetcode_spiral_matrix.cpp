class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>>::iterator ivr;
        vector <int> res, v;
        ivr=matrix.begin(); 
        v=*(ivr);     
        // cout<<matrix.size();
        int left=0, right=v.size()-1, top=0, bottom=matrix.size()-1;
        while(bottom>=top && left<=right){
            for(int i=left; i<=right;i++ ){
                res.push_back(matrix[top][i]);
            }
            top++;
            if(bottom>=top && left<=right)
                {for(int i=top; i<=bottom;i++){
                    res.push_back(matrix[i][right]);
                }}
            right--;
            if(bottom>=top && left<=right)
                {for(int i=right;i>=left;i--){
                    res.push_back(matrix[bottom][i]);
                }}
            bottom--;
            if(bottom>=top && left<=right)
            {for(int i=bottom; i>=top;i--){
                res.push_back(matrix[i][left]);
            }}
            left++;
        }
        return res;
    }
};