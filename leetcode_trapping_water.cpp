class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>leftMax(height.size(),0);
        vector<int>rightMax(height.size(),0);
        int left=0, right=0;
        for(int i=0;i<height.size();i++){
            leftMax[i]=max(left,height[i]);
            left=leftMax[i];
            rightMax[height.size()-i-1]=max(right, height[height.size()-i-1]);
            right=rightMax[height.size()-i-1];            
        }
        int water=0;
        for(int i=0; i<height.size(); i++){
            water+=(min(leftMax[i],rightMax[i])-height[i]);
        }
        return water;
        return 0;
    }
};