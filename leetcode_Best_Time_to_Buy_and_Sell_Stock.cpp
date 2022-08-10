class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int start=0,end=1,ans=INT_MIN;
        for(int i=0;i<prices.size()-1; i++){
            ans=max(prices[end]-prices[start], ans);
            cout<<ans<<" ";
            if(prices[start]>prices[end]){
                start=end;
            }
            end++;
        }
        if(ans<0)return 0;
        return ans;
    }
};